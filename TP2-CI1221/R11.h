/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   R11.h
 * Author: Isaac
 *
 * Created on 9 de junio de 2018, 08:15 PM
 */

#include <utility>

#ifndef R11_H
#define R11_H

//Lista SE, con Nodos que contienen un par.

template < typename V, typename T >
class R11 {
public:
    R11();
    virtual ~R11();

    //EFE: Inicializa la estructura R11.
    //REQ:
    //MOD:
    void crear();

    //EFE: Destruye la R11, la deja inutilizable.
    //REQ: R11 inicializada.
    //MOD: R11.
    void destruir();

    //EFE: Vacia la R11 pero se puede seguir usando.
    //REQ: R11 inicializada.
    //MOD: R11.
    void vaciar();

    //EFE: Retorna True si la R11 esta vacia y false en caso contrario.
    //REQ: R11 inicializada.
    //MOD:
    bool vacio();

    //EFE: Agrega una relacion 1:1 entre los elementos.
    //REQ: R11 inicializada y e1 y e2 no existentes en R11.
    //MOD: R11.
    void agregarRelacion(V e1, T e2);

    //EFE: Elimina la relacion entre e1 y e2 en R11.
    //REQ: R11 inicializada y e1 y e2 contenidos.
    //MOD: R11.
    void eliminarRelacion(V e1, T e2);

    //EFE: Cambia la Imagen de la relación.
    //REQ: R11 inicializada y e1 contenida en R11 y newE no contenida.
    //MOD: R11.
    void modificarImagen(V e1, T newE);

    //EFE: Retorna True si e1(en el dominio) y e2(en el codominio) estan relacionados 
    //y false en caso contrario.
    //REQ: R11 inicializado.
    //MOD: 
    bool existeRelacion(V e1, T e2);

    //EFE: Retorna la imagen de E.
    //REQ: R11 inicializado y E contenida en R11.
    //MOD:
    T imagen(V e);

    //EFE: Retorna la preimagen de E.
    //REQ: R11 inicializado y E contenida en R11.
    //MOD:
    V preImagen(T e);

    //EFE: Retorna True si e pertenece al dominio y false en caso contrario.
    //REQ: R11 inicializado.
    //MOD: 
    bool estaEnDominio(V e);

    //EFE: Retorna True si E pertenece al codominio y false en caso contrario.
    //REQ: R11 inicializado.
    //MOD:
    bool estaEnCodominio(T e);

    //EFE: Retorna la cantidad de relaciones.
    //REQ: R11 inicializado.
    //MOD:
    int numRel();

private:

    template <typename B, typename Y>
    struct NodoRel {

        NodoRel() : sig(nodoNull) {
        }
        ~NodoRel(){
        }

        NodoRel(B e1, Y e2) : relacion(e1, e2), sig(nodoNull) {
        }
        std::pair <B, Y> relacion;
        NodoRel *sig;
    };
    NodoRel<V, T> *inicio;
    int cantRel;
    static NodoRel<V, T> *nodoNull;
};

template <typename V, typename T>
R11<V, T>::NodoRel<V, T>* R11<V, T>::nodoNull = nullptr;

template <typename V, typename T>
R11<V, T>::R11() {
}

template <typename V, typename T>
R11<V, T>::~R11() {
}

template <typename V, typename T>
void R11<V, T>::crear() {
    inicio = nodoNull;
    cantRel = 0;
}

template <typename V, typename T>
void R11<V, T>::destruir() {
    while(inicio != nodoNull){
        NodoRel<V, T> *n = inicio;
        inicio = inicio->sig;
        delete n;
    }
    delete this;
}

template <typename V, typename T>
void R11<V, T>::vaciar() {
    while(inicio != nodoNull){
        NodoRel<V, T> *n = inicio;
        inicio = inicio->sig;
        delete n;
    }
    cantRel = 0;
}

template <typename V, typename T>
bool R11<V, T>::vacio() {
    bool empty = true;
    if (cantRel != 0)
        empty = false;
    return empty;
}

template <typename V, typename T>
void R11<V, T>::agregarRelacion(V e1, T e2) {
    NodoRel<V, T> *n = new NodoRel<V, T>(e1, e2);
    n->sig = inicio;
    inicio = n;
    cantRel++;
}

template <typename V, typename T>
void R11<V, T>::eliminarRelacion(V e1, T e2) {
    if(inicio->relacion.first == e1){
        NodoRel<V, T> *n = inicio;
        inicio = inicio->sig;
        delete n;
    }else{
        NodoRel<V, T> *n = inicio;
        while(n->sig->relacion.first != e1){
            n = n->sig;
        }
        NodoRel<V, T> *nSig = n->sig;
        n->sig = nSig->sig;
        delete nSig;
    }
}

template <typename V, typename T>
void R11<V, T>::modificarImagen(V e1, T newE) {
    if (inicio->relacion.first == e1)
        inicio->relacion.second = newE;
    else {
        bool found = false;
        NodoRel<V, T> *n = inicio;
        while (!found && n != nodoNull) {
            if (n->relacion.first == e1) {
                n->relacion.second = newE;
                found = true;
            } else
                n = n->sig;
        }
    }
}

template <typename V, typename T>
bool R11<V, T>::existeRelacion(V e1, T e2) {
    bool relate = false;
    if (inicio->relacion.first == e1) {
        if (inicio->relacion.second == e2)
            relate = true;
    } else {
        bool found = false;
        NodoRel<V, T> *n = inicio;
        while (!found && n != nodoNull) {
            if (n->relacion.first == e1) {
                if (n->relacion.second == e2){
                    relate = true;
                    found = true;
                }else
                    found = true;
            }
            else
                n = n->sig;
        }
    }
    return relate;
}

template <typename V, typename T>
T R11<V, T>::imagen(V e) {
    T img;
    if(inicio->relacion.first == e)
        img = inicio->relacion.second;
    else{
        bool found = false;
        NodoRel<V, T> *n = inicio;
        while(!found){
            if(n->relacion.first == e){
                img = n->relacion.second;
                found = true;
            }else
                n = n->sig;
        }
    }
    return img;
}

template <typename V, typename T>
V R11<V, T>::preImagen(T e) {
    V pimg;
    if(inicio->relacion.second == e)
        pimg = inicio->relacion.first;
    else{
        bool found = false;
        NodoRel<V, T> *n = inicio;
        while(!found){
            if(n->relacion.second == e){
                pimg = n->relacion.first;
                found = true;
            }else
                n = n->sig;
        }
    }
    return pimg;
}

template <typename V, typename T>
bool R11<V, T>::estaEnDominio(V e) {
    bool encontrado = false;
    if(inicio->relacion.first == e)
        encontrado = true;
    else{
        bool found = false;
        NodoRel<V, T> *n = inicio;
        while(!found && n != nodoNull){
            if(n->relacion.first == e){
                encontrado = true;
                found = true;
            }else
                n = n->sig;
        }
    }
    return encontrado;
}

template <typename V, typename T>
bool R11<V, T>::estaEnCodominio(T e) {
    bool encontrado = false;
    if(inicio->relacion.second == e)
        encontrado = true;
    else{
        bool found = false;
        NodoRel<V, T> *n = inicio;
        while(!found && n != nodoNull){
            if(n->relacion.second == e){
                encontrado = true;
                found = true;
            }else
                n = n->sig;
        }
    }
    return encontrado;
}

template <typename V, typename T>
int R11<V, T>::numRel() {
    return cantRel;
}
#endif /* R11_H */

