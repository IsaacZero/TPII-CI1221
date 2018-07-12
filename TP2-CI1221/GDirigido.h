    /*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   GDirigido.h
 * Author: Isaac
 *
 * Created on 14 de junio de 2018, 09:37 PM
 */
#include "GDListaAdy.h"
//#include "GDMatrizAd.h"

#ifndef GDIRIGIDO_H
#define GDIRIGIDO_H

typedef GDListaAdy Grafo;
typedef GDListaAdy::Nodo* Vertice;
typedef GDListaAdy::Nodo::ListaAdy::NodoAdy Arista;

//typedef GDMatrizAd Grafo;
//typedef int Vertice;
class GDirigido {
public:
    GDirigido();
    GDirigido(const GDirigido& orig);
    virtual ~GDirigido();
    
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
    
    //EFE: Retorna la cantidad de vertices adyacentes de V.
    //REQ: El Grafo Inicializado y V perteneciente en el grafo.
    //MOD:
    int numAristas(Vertice v);
    
    //EFE: Retorna true si v1 tiene una arista hacia v2 y false en caso contrario.
    //REQ: El Grafo Inicializado y V1 y V2 perteneciente en el grafo.
    //MOD:
    bool existeArista(Vertice v1, Vertice v2);
    
private:
    Grafo grafo;
};

#endif /* GDIRIGIDO_H */

