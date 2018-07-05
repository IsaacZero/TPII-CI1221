/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Algoritmos.cpp
 * Author: Isaac
 * 
 * Created on 7 de junio de 2018, 09:41 PM
 */

#include "Algoritmos.h"

Vertice Algoritmos::nodoNulo = nullptr;//nodoNulo cuando esta por Lista de Adyacencias.
//Vertice Algoritmos::nodoNulo = -1;// nodoNulo cuando esta por Matriz de Adyacencias.

Algoritmos::Algoritmos() {
}

Algoritmos::Algoritmos(const Algoritmos& orig) {
}

Algoritmos::~Algoritmos() {
}

//ALGORITMOS GRAFO DIRIGIDO

Vertice Algoritmos::buscarEtiq(int etiqueta, GDirigido grafo){
    bool found = false;
    Vertice v = grafo.primerVertice();
    while(v != nodoNulo && !found){
        if(grafo.etiqueta(v) == etiqueta)
            found = true;
        else
            v = grafo.siguienteVertice(v);
    }
    if(!found)
        v = nodoNulo;
    return v;
}

Vertice Algoritmos::min(DicV dicc, R11PesoV r11, GDirigido grafo){
    Vertice iter = grafo.primerVertice();
    Vertice min = iter;
    while (iter != nodoNulo){
        if(r11.imagen(iter) < r11.imagen(min) && !dicc.pertene(iter)){
            min = iter;
            iter = grafo.siguienteVertice(iter);
        }else
            iter = grafo.siguienteVertice(iter);
    }
    return min;
}

void Algoritmos::dijkstra(Vertice V, GDirigido grafo){//R11
    R11PesoV r11;
    r11.crear();
    Vertice vIter = grafo.primerVertice();
    Vertice vAdy;
    DicV diccVisitados;
    diccVisitados.crear();
    while(vIter != nodoNulo){
        if(vIter != V && !grafo.existeArista(V, vIter)){
            r11.agregarRelacion(vIter, INFINITO);
            vIter = grafo.siguienteVertice(vIter);
        }else if(vIter != V && grafo.existeArista(V, vIter)){
            r11.agregarRelacion(vIter, grafo.peso(V, vIter));
            vIter = grafo.siguienteVertice(vIter);
        }else{
            r11.agregarRelacion(V, 0);
            vIter = grafo.siguienteVertice(vIter);
            diccVisitados.agregar(V);
        }
    }
    
    for(int i = 1; i < grafo.numVertices()- 1; i++){
        //Cambiar todo que no era asi:v
        vIter = this->min(diccVisitados, r11, grafo);
        diccVisitados.agregar(vIter);
        vAdy = grafo.primerVerticeAdy(vIter);
        while(vAdy != nodoNulo){
            if(!diccVisitados.pertene(vAdy) && (r11.imagen(vIter) + grafo.peso(vIter, vAdy) < r11.imagen(vAdy)))
                r11.modificarImagen(vAdy, r11.imagen(vIter) + grafo.peso(vIter, vAdy));
            else
                vAdy = grafo.sigVerticeAdy(vIter, vAdy);
        }
    }
    //Imprimir
}

void Algoritmos::floyd(GDirigido grafo){
    int matriz[grafo.numVertices()][grafo.numVertices()];
    R11PesoV r11;
    Vertice v = grafo.primerVertice();
    Vertice va;
    int fila = 0;
    int columna = 0;
    for(int i = 0; i < grafo.numVertices(); i++){
        r11.agregarRelacion(v, i);
        v = grafo.siguienteVertice(v);
    }
    v = grafo.primerVertice();
    va = grafo.primerVerticeAdy(v);
    for(int i = 0; i < grafo.numVertices(); i++){
        for( int j = 0; j < grafo.numVertices(); j++){
            if(i == j)
                matriz[i][j] = 0;
            else{
                matriz[i][j] = INFINITO;
                if(va != nodoNulo){
                    fila = r11.imagen(v);
                    columna = r11.imagen(va);
                    matriz[fila][columna] = grafo.peso(v, va);
                    va = grafo.sigVerticeAdy(v, va);
                }
            }
        }
        v = grafo.siguienteVertice(v);
    }
    
    for (int k = 0; k < grafo.numVertices(); k++){
        for (int i = 0; i < grafo.numVertices(); i++){
            for ( int j = 0; j < grafo.numVertices(); j++){
                if(matriz[i][k] + matriz[k][j] < matriz[i][j])
                    matriz[i][j] = matriz[i][k] + matriz[k][j];
            }
        }
    }
    
    v = grafo.primerVertice();
    cout << "Posiciones en la Matriz de los vertices" << endl;
    while (v != nodoNulo){
        cout << r11.imagen(v) << "->" << endl;
        v = grafo.siguienteVertice(v);
    }
    
    for(int i = 0; i < grafo.numVertices(); i++){
        for( int j = 0; j < grafo.numVertices(); j++){
            cout << "(";
            if(matriz[i][j] == INFINITO)
                cout << "INF ";
            else
                cout << matriz[i][j] << " ";
        }
        cout << ")" << endl;
    }
}

void Algoritmos::listarRPP(GDirigido grafo){
    if(!grafo.vacio()){
        Vertice v = grafo.primerVertice();
        DicV dicV;
        dicV.crear();
        while(v != nodoNulo){
            if(!dicV.pertene(v))
                this->listarRPPR(v, dicV, grafo);
            v = grafo.siguienteVertice(v);
        }
        dicV.destruir();
    }
}

void Algoritmos::listarRPPR(Vertice v, DicV& dicV, GDirigido grafo){
    dicV.agregar(v);
    cout << v->elemento << endl;
    Vertice va = grafo.primerVerticeAdy(v);
    while(va != nodoNulo){
        if(!dicV.pertene(va))
            this->listarRPPR(va, dicV, grafo);
        va = grafo.sigVerticeAdy(v, va);
    }
}

void Algoritmos::elimVertNA(Vertice v, GDirigido& grafo){
    Vertice v1 = grafo.primerVertice();
    Vertice va1;
    while(v1 != nodoNulo){
        va1 = grafo.primerVerticeAdy(v1);
        while(va1 != nodoNulo){
            if(va1 == v){
                grafo.eliminarArista(v1, va1);
                va1 = nodoNulo;
            }else
                va1 = grafo.sigVerticeAdy(v1, va1);
        }
        v1 = grafo.siguienteVertice(v1);
        if(v1 == v)
            v1 = grafo.siguienteVertice(v1);
    }
    va1 = grafo.primerVerticeAdy(v);
    while(va1 != nodoNulo){
        grafo.eliminarArista(v, va1);
        va1 = grafo.primerVerticeAdy(v);
    }
    grafo.eliminarVertice(v);
}

void Algoritmos::copiar(GDirigido G1, GDirigido& G2){
    //Relaciones 1:1 con los vertices iguales de G1 y G2 similar a iguales.
    if(G1.numVertices() == 0)
        G2.vaciar();
    else{
        G2.vaciar();
        R11V R11vert;
        R11vert.crear();
        Vertice v1 = G1.primerVertice();
        Vertice v2;
        while (v1 != nodoNulo){
            v2 = G2.agregarVertice(G1.etiqueta(v1));
            R11vert.agregarRelacion(v1, v2);
            v1 = G1.siguienteVertice(v1);
        }
        v1 = G1.primerVertice();
        Vertice va1;
        while(v1 != nodoNulo){
            va1 = G1.primerVerticeAdy(v1);
            while(va1 != nodoNulo){
                G2.agregarArista(G1.peso(v1, va1), R11vert.imagen(v1), R11vert.imagen(va1));
            }
            v1 = G1.siguienteVertice(v1);
        }
    }
}

bool Algoritmos::iguales(GDirigido G1, GDirigido G2){
    bool equal = true;
    if(G1.numVertices() != G2.numVertices())
        equal = false;
    else{
        R11V R11vert;
        R11vert.crear();
        Vertice v1 = G1.primerVertice();
        Vertice v2;
        Vertice va1;
        while (v1 != nodoNulo && equal){
            v2 = this->buscarEtiq(G1.etiqueta(v1), G2);
            if(v2 != nodoNulo){
                if(G1.numAristas(v1) != G2.numAristas(v2)){
                    R11vert.agregarRelacion(v1, v2);
                    v1 = G1.siguienteVertice(v1);
                }else
                    equal = false;
            }else
                equal = false;
        }
        if(equal){
           v1 = G1.primerVertice();
           while (v1 != nodoNulo && equal){
               va1 = G1.primerVerticeAdy(v1);
               while (va1 != nodoNulo && equal){
                   if (G2.existeArista(R11vert.imagen(v1), R11vert.imagen(va1))){
                       if(G1.peso(v1, va1) != G2.peso(R11vert.imagen(v1), R11vert.imagen(va1)))
                           equal = false;
                       else
                            va1 = G1.sigVerticeAdy(v1, va1);
                    }else
                        equal = false;
               }
               v1 = G1.siguienteVertice(v1);
           }
        }
        R11vert.destruir();
    }
    return equal;
}

//ALGORITMOS GRAFO NO DIRIGIDO

void Algoritmos::prim(GNDGD grafo){//R11
    R11V r11;
    DicV dicVisitado;
    r11.crear();
    dicVisitado.crear();
    Vertice vIter = grafo.primerVertice();
    Vertice vAdy;
    Vertice min = vIter;
    while(vIter != nodoNulo){
        if(grafo.etiqueta(vIter) < grafo.etiqueta(min)){
            min = vIter;
            r11.agregarRelacion(vIter, nodoNulo);
            vIter = grafo.siguienteVertice(vIter);
        }else{
            vIter = grafo.siguienteVertice(vIter);
            r11.agregarRelacion(vIter, nodoNulo);
        }
    }
    dicVisitado.agregar(min);
    vIter = grafo.primerVerticeAdy(min);
    while(vIter != nodoNulo){
        r11.modificarImagen(vIter, min);
        vIter = grafo.sigVerticeAdy(min, vIter);
    }
    for(int i = 1; i < grafo.numVertices(); i++){
        vIter = grafo.primerVertice();
        min = grafo.primerVerticeAdy(min);
        //ciclo para encontrar el vertice con la minima arista.
        while (vIter != nodoNulo){
            if(r11.imagen(vIter) != nodoNulo && !dicVisitado.pertene(vIter)){
                if(grafo.peso(r11.imagen(vIter), vIter) <  grafo.peso(r11.imagen(min), min)){
                    min = vIter;
                    vIter = grafo.siguienteVertice(vIter);
                }else
                    vIter = grafo.siguienteVertice(vIter);
            }else
                vIter = grafo.siguienteVertice(vIter);
        }
        dicVisitado.agregar(min);
        vAdy = grafo.primerVerticeAdy(min);
        while(vAdy != nodoNulo){
            if(r11.imagen(vAdy) != nodoNulo && !dicVisitado.pertene(vAdy)){
                if(grafo.peso(min, vAdy) <  grafo.peso(r11.imagen(vAdy), vAdy)){
                    r11.modificarImagen(vAdy, min);
                }else
                    vAdy = grafo.sigVerticeAdy(min, vAdy);
            }else if(r11.imagen(vAdy) == nodoNulo && !dicVisitado.pertene(vAdy)){
                r11.modificarImagen(vAdy, min);
            }else
                vAdy = grafo.sigVerticeAdy(min, vAdy);
        }
    }
}

void Algoritmos::vendedor(GNDGD grafo){//Diccionario
    
}