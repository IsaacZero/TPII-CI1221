/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   GNDGD.h
 * Author: Isaac
 *
 * Created on 7 de junio de 2018, 09:40 PM
 */

#include "GDirigido.h"
#ifndef GNDGD_H
#define GNDGD_H

typedef GDirigido GrafoND;
class GNDGD {
public:
    GNDGD();
    GNDGD(const GNDGD& orig);
    virtual ~GNDGD();
    
    //EFE: Inicializa el Grafo.
    //REQ:
    //MOD:
    void crear();

    //EFE: Destruye el Grafo, lo deja inutilizable.
    //REQ: El Grafo inicializado.
    //MOD: El Grafo.
    void destruir();

    //EFE: Vacia el Grafo pero se puede seguir usando.
    //REQ: El Grafo inicializado.
    //MOD: El Grafo.
    void vaciar();

    //EFE: Retorna True si el grafo esta vacio y false en caso contrario.
    //REQ: El Grafo inicializado.
    //MOD:
    bool vacio();

    //EFE: Agrega un vertice al grafo y lo retorna para trabajar con el mismo.
    //REQ: El Grafo inicializado y la Etiqueta no existente en el Grafo.
    //MOD: El Grafo.
    Vertice agregarVertice(int e);

    //EFE: Elimina un vertice del Grafo.
    //REQ: El Grafo inicializado y el vertice aislado.
    //MOD: El Grafo.
    void eliminarVertice(Vertice v);

    //EFE: Cambia la etiqueta de un vertice por la nueva que recibe.
    //REQ: El Grafo inicializado.
    //MOD: El vertice.
    void modificarEtiqueta(int newE, Vertice v);

    //EFE: Retorna la etiqueta del vertice.
    //REQ: El Grafo inicializado.
    //MOD: 
    int etiqueta(Vertice v);

    //EFE: Agrega una arista a las adyacencias el vertice V1 en direccion a V2 con un peso.
    //REQ: El Grafo inicializado.
    //MOD: El Grafo y la Lista de Adyacencias.
    void agregarArista(int p, Vertice v1, Vertice v2);

    //EFE: Elimina la arista que conecta a V1 con V2.
    //REQ: El Grafo inicializado.
    //MOD: El Grafo.
    void eliminarArista(Vertice v1, Vertice v2);

    //EFE: Cambia el peso de la arista entre V1 y V2.
    //REQ: El Grafo inicializado y la existencia de la arista.
    //MOD: El peso de la Arista.
    void modificarPeso(int newP, Vertice v1, Vertice v2);

    //EFE: Retorna el peso de la arista.
    //REQ: El Grafo inicializado.
    //MOD: 
    int peso(Vertice v1, Vertice v2);

    //EFE: Retorna el primer vertice en el Grafo.
    //REQ: El Grafo inicializado.
    //MOD:
    Vertice primerVertice();

    //EFE: Retorna el siguiente vertice a V1 saltando por el grafo.
    //REQ: El Grafo inicializado y no vacío, con V1 valido.
    //MOD:
    Vertice siguienteVertice(Vertice v);

    //EFE: Retorna el primer vertice adyacente a V1.
    //REQ: El Grafo inicializado y V1 valido.
    //MOD:
    Vertice primerVerticeAdy(Vertice v1);

    //EFE: Retorna el siguiente vertice adyacente de V1 despues de V2.
    //REQ: El Grafo inicializado y V1 y V2 validos.
    //MOD:
    Vertice sigVerticeAdy(Vertice v1, Vertice v2);

    //EFE: Retorna la cantidad de elementos en el Grafo.
    //REQ: El Grafo Inicializado.
    //MOD:
    int numVertices();
    
private:
    GrafoND grafoND;
};

#endif /* GNDGD_H */

