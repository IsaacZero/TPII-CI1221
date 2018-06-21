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

void Algoritmos::dijkstra(Vertice V, GDirigido grafo){
    
}

void Algoritmos::floyd(GDirigido grafo){
    
}

void Algoritmos::listarRPP(GDirigido grafo){
    
}

void Algoritmos::elimVertNA(Vertice v, GDirigido& grafo){
    
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
                
            }
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

void Algoritmos::prim(GNDGD grafo){
    
}

void Algoritmos::vendedor(GNDGD grafo){
    
}