/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   GDListaAdy.h
 * Author: Isaac
 *
 * Created on 7 de junio de 2018, 09:39 PM
 */

#include <utility>

#ifndef GDLISTAADY_H
#define GDLISTAADY_H

/*struct Nodo {

    Nodo() : siguiente(nullptr) {
    }
    ~Nodo();

    Nodo(int e) : elemento(e), siguiente(nullptr) {
    }
    int elemento;
    Nodo *siguiente;

    struct ListaAdy {

        ListaAdy() : cantAdy(0), start(nullptr) {
        }
        ~ListaAdy();

        struct NodoAdy {

            NodoAdy() : sig(nullptr) {
            }
            ~NodoAdy();

            NodoAdy(int e, Nodo *n) : peso(e), vertice(n), sig(nullptr) {
            }
            Nodo* vertice;
            int peso;
            NodoAdy *sig;
        };
        NodoAdy *start;
        int cantAdy;
    };
    ListaAdy adyacencia;
};*/

class GDListaAdy {
public:

    struct Nodo{

        Nodo() : siguiente(nullptr) {
        }
        ~Nodo(){
        }
        Nodo(int e) : elemento(e), siguiente(nullptr) {
        }
        int elemento;
        Nodo *siguiente;

        struct ListaAdy {

            ListaAdy() : cantAdy(0), start(nullptr) {
            }
            ~ListaAdy(){
            }
            struct NodoAdy {

                NodoAdy() : sig(nullptr) {
                }
                ~NodoAdy(){
                }
                NodoAdy(int e, Nodo *n) : peso(e), vertice(n), sig(nullptr) {
                }
                Nodo* vertice;
                int peso;
                NodoAdy *sig;
            };
            NodoAdy *start;
            int cantAdy;
        };
        ListaAdy adyacencia;
    };
    /*
    struct ListaAdy {

        ListaAdy() : cantAdy(0), start(nullptr) {
        }
        ~ListaAdy();
        nAdy *start;
        int cantAdy;
    };

    struct Nodo {

        Nodo() : siguiente(nullptr) {
        }
        ~Nodo();

        Nodo(int e) : elemento(e), siguiente(nullptr) {
        }
        int elemento;
        Nodo *siguiente;
        ListaAdy adyacencia;
    };

    struct NodoAdy {

        NodoAdy() : sig(nullptr) {
        }
        ~NodoAdy();

        NodoAdy(int e, Nodo *n) : peso(e), vertice(n), sig(nullptr) {
        }
        Nodo* vertice;
        int peso;
        NodoAdy *sig;
    };
     */
    GDListaAdy();
    virtual ~GDListaAdy();

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
    Nodo* agregarVertice(int e);

    //EFE: Elimina un vertice del Grafo.
    //REQ: El Grafo inicializado y el vertice aislado.
    //MOD: El Grafo.
    void eliminarVertice(Nodo* v);

    //EFE: Cambia la etiqueta de un vertice por la nueva que recibe.
    //REQ: El Grafo inicializado.
    //MOD: El vertice.
    void modificarEtiqueta(int newE, Nodo* v);

    //EFE: Retorna la etiqueta del vertice.
    //REQ: El Grafo inicializado.
    //MOD: 
    int etiqueta(Nodo* v);

    //EFE: Agrega una arista a las adyacencias el vertice V1 en direccion a V2 con un peso.
    //REQ: El Grafo inicializado.
    //MOD: El Grafo y la Lista de Adyacencias.
    void agregarArista(int p, Nodo* v1, Nodo* v2);

    //EFE: Elimina la arista que conecta a V1 con V2.
    //REQ: El Grafo inicializado.
    //MOD: El Grafo.
    void eliminarArista(Nodo* v1, Nodo* v2);

    //EFE: Cambia el peso de la arista entre V1 y V2.
    //REQ: El Grafo inicializado y la existencia de la arista.
    //MOD: El peso de la Arista.
    void modificarPeso(int newP, Nodo* v1, Nodo* v2);

    //EFE: Retorna el peso de la arista.
    //REQ: El Grafo inicializado.
    //MOD: 
    int peso(Nodo* v1, Nodo* v2);

    //EFE: Retorna el primer vertice en el Grafo.
    //REQ: El Grafo inicializado.
    //MOD:
    Nodo* primerVertice();

    //EFE: Retorna el siguiente vertice a V1 saltando por el grafo.
    //REQ: El Grafo inicializado y no vacío, con V1 valido.
    //MOD:
    Nodo* siguienteVertice(Nodo* v);

    //EFE: Retorna el primer vertice adyacente a V1.
    //REQ: El Grafo inicializado y V1 valido.
    //MOD:
    Nodo* primerVerticeAdy(Nodo* v1);

    //EFE: Retorna el siguiente vertice adyacente de V1 despues de V2.
    //REQ: El Grafo inicializado y V1 y V2 validos.
    //MOD:
    Nodo* sigVerticeAdy(Nodo* v1, Nodo* v2);

    //EFE: Retorna la cantidad de elementos en el Grafo.
    //REQ: El Grafo Inicializado.
    //MOD:
    int numVertices();

private:
    Nodo* inicio;
    int cantElem;
    static Nodo *nodoNulo;
};

#endif /* GDLISTAADY_H */

