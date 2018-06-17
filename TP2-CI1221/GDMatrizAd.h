/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   GDMatrizAd.h
 * Author: Isaac
 *
 * Created on 7 de junio de 2018, 09:38 PM
 */

#ifndef GDMATRIZAD_H
#define GDMATRIZAD_H

#define MAX 100
class GDMatrizAd {
public:
    GDMatrizAd();
    GDMatrizAd(const GDMatrizAd& orig);
    virtual ~GDMatrizAd();
    
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
    int agregarVertice(int e);

    //EFE: Elimina un vertice del Grafo.
    //REQ: El Grafo inicializado y el vertice aislado.
    //MOD: El Grafo.
    void eliminarVertice(int v);

    //EFE: Cambia la etiqueta de un vertice por la nueva que recibe.
    //REQ: El Grafo inicializado.
    //MOD: El vertice.
    void modificarEtiqueta(int newE, int v);

    //EFE: Retorna la etiqueta del vertice.
    //REQ: El Grafo inicializado.
    //MOD: 
    int etiqueta(int v);

    //EFE: Agrega una arista a las adyacencias el vertice V1 en direccion a V2 con un peso.
    //REQ: El Grafo inicializado.
    //MOD: El Grafo y la Lista de Adyacencias.
    void agregarArista(int p, int v1, int v2);

    //EFE: Elimina la arista que conecta a V1 con V2.
    //REQ: El Grafo inicializado.
    //MOD: El Grafo.
    void eliminarArista(int v1, int v2);

    //EFE: Cambia el peso de la arista entre V1 y V2.
    //REQ: El Grafo inicializado y la existencia de la arista.
    //MOD: El peso de la Arista.
    void modificarPeso(int newP, int v1, int v2);

    //EFE: Retorna el peso de la arista.
    //REQ: El Grafo inicializado.
    //MOD: 
    int peso(int v1, int v2);

    //EFE: Retorna el primer vertice en el Grafo.
    //REQ: El Grafo inicializado.
    //MOD:
    int primerVertice();

    //EFE: Retorna el siguiente vertice a V1 saltando por el grafo.
    //REQ: El Grafo inicializado y no vacío, con V1 valido.
    //MOD:
    int siguienteVertice(int v);

    //EFE: Retorna el primer vertice adyacente a V1.
    //REQ: El Grafo inicializado y V1 valido.
    //MOD:
    int primerVerticeAdy(int v1);

    //EFE: Retorna el siguiente vertice adyacente de V1 despues de V2.
    //REQ: El Grafo inicializado y V1 y V2 validos.
    //MOD:
    int sigVerticeAdy(int v1, int v2);

    //EFE: Retorna la cantidad de elementos en el Grafo.
    //REQ: El Grafo Inicializado.
    //MOD:
    int numVertices();
    
private:
    
    int ultimo;
    int vecVert[MAX];
    int matrizAdy[MAX][MAX];
    
};

#endif /* GDMATRIZAD_H */

