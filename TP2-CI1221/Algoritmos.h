/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Algoritmos.h
 * Author: Isaac
 *
 * Created on 7 de junio de 2018, 09:41 PM
 */

#include "GDirigido.h"
#include "GNDGD.h"
#include "DicLSE.h"
#include "R11.h"
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

typedef DicLSE<Vertice> DicV;
typedef R11<Vertice, Vertice> R11V;
typedef R11<Vertice, int> R11PesoV;
typedef std::vector<Vertice> vectorV;
typedef std::vector<int> vectorP;
#define INFINITO 1000000

#ifndef ALGORITMOS_H
#define ALGORITMOS_H

using namespace std;
        
class Algoritmos {
public:
    Algoritmos();
    Algoritmos(const Algoritmos& orig);
    virtual ~Algoritmos();
    
    //ALGORITMOS PARA GRAFO DIRIGIDO.
    
    //EFE: Retorna el vertice con esa etiqueta o en caso de no encrontrarlo un nodoNulo.
    //REQ:
    //MOD:
    Vertice buscarEtiq(int etiqueta, GDirigido grafo);
    
    //EFE: Retorna el vertice adyacente con menor peso.
    //REQ: V incluido en el grafo.
    //MOD: 
    Vertice min(DicV dicc, R11PesoV r11, GDirigido grafo);
    
    //EFE: Realiza Dijkstra para encontrar el camino más corto entre el vértice y los demás.
    //REQ: V incluido en el grafo.
    //MOD: 
    void dijkstra(Vertice V, GDirigido grafo);
    
    //EFE: Realiza Floyd para encontrar el camino más corto entre todo par de vértices.
    //REQ: 
    //MOD:
    void floyd(GDirigido grafo);
    
    //EFE: Lista el Grafo realizando un recorrido en profundidad primero.
    //REQ:
    //MOD:
    void listarRPP(GDirigido grafo);
    
    //EFE: Lista el Grafo realizando un recorrido en profundidad primero, parte recursiva.
    //REQ:
    //MOD:
    void listarRPPR(Vertice v, DicV &dicV, GDirigido grafo);
    
    //EFE: Elimina un vertice no aislado en el Grafo.
    //REQ: El vertice no aislado.
    //MOD: El Grafo.
    void elimVertNA(Vertice v, GDirigido &grafo);
    
    //EFE: Copia el G1 en G2.
    //REQ: G1 y G2 inicializados.
    //MOD: G2.
    void copiar(GDirigido G1, GDirigido &G2);
    
    //EFE: Retorna true si dos grafos son iguales y false en caso contrario.
    //REQ: G1 y G2 inicializados y sin etiquetas repetidas.
    //MOD:
    bool iguales(GDirigido G1, GDirigido G2);
    
    //ALGORITMOS PARA GRAFO NO DIRIGIDO.
    
    //EFE: Realiza Prim para encontrar el árbol recubridor de mínimo costo.
    //REQ:
    //MOD:
    void prim(GNDGD grafo);
    
    //EFE: Usa Busqueda Exhaustiva Pura para solucionar el problema del vendedor.
    //REQ:
    //MOD:
    void vendedor(GNDGD grafo, Vertice V);
    
    void vendedorR(GNDGD grafo, Vertice v1, Vertice v2, DicV visitados, vectorV &solOp, vectorV solAc,
                    int &solOpt, int solAct, int cantVertF, int &cantSolF);

private:
    static Vertice nodoNulo;
};

#endif /* ALGORITMOS_H */

