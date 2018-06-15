/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   DicLSE.h
 * Author: Isaac
 *
 * Created on 7 de junio de 2018, 09:40 PM
 */

#ifndef DICLSE_H
#define DICLSE_H

template < typename V >
class DicLSE {
public:
    DicLSE();
    virtual ~DicLSE();
    
    //EFE: Inicializa el diccionario.
    //REQ:
    //MOD:
    void crear();
    
    //EFE: Destruye el dicionario, lo deja inutilizable.
    //REQ:
    //MOD: El diccionario.
    void destruir();
    
    //EFE: Vacia el diccionario y se puede seguir usando.
    //REQ: El diccionario inicializado.
    //MOD: El Diccionario.
    void vaciar();
    
    //EFE: Retorna true si el diccionario esta vacio y false en caso contrario.
    //REQ: El Diccionario inicializado.
    //MOD: El Diccionario.
    bool vacio();
    
    //EFE: Agrega un elemento al diccionario.
    //REQ: El Diccionario inicializado, y el elemento si repetir.
    //MOD: El Diccionario.
    void agregar(V elem);
    
    //EFE: Elimina el elemento del diccionario.
    //REQ: El diccionario inicializado y el elemento contenido.
    //MOD: El Diccionario.
    void eliminar(V elemento);
    
    //EFE: Retorna true si el elemento pertene a la lista y false en caso contrario.
    //REQ: El diccionario inicializado.
    //MOD: 
    bool pertene(V elemento);
    
    //EFE: Retorna la cantidad de elementos en el diccionario.
    //REQ: El diccionario inicializado.
    //MOD:
    int numElem();
private:
    
    template < typename T >
    struct NodoDicc{
        NodoDicc(): sig(nodoNulo){
        }
        ~NodoDicc();
        NodoDicc(T newE): elem(newE), sig(nodoNulo){
        }
        NodoDicc *sig;
        T elem;
    };
    
    static NodoDicc* nodoNulo;
    int cantElem;
    NodoDicc* inicio;
};

template < typename V >
DicLSE<V>::NodoDicc<V>* DicLSE<V>::nodoNulo = nullptr;

template <typename V>
DicLSE<V>::DicLSE(){
    
}

template <typename V>
DicLSE<V>::~DicLSE(){
    
}

template <typename V>
void DicLSE<V>::crear(){
    cantElem = 0;
    inicio = nodoNulo;
}

template <typename V>
void DicLSE<V>::destruir(){
    while(inicio != nodoNulo){
        NodoDicc<V> *iter = inicio;
        inicio = inicio->sig;
        delete iter;
    }
    delete this;
}

template <typename V>
void DicLSE<V>::vaciar(){
    while(inicio != nodoNulo){
        NodoDicc<V> *iter = inicio;
        inicio = inicio->sig;
        delete iter;
    }
    cantElem = 0;
}

template <typename V>
bool DicLSE<V>::vacio(){
    bool empty = false;
    if(cantElem == 0)
        empty = true;
    return empty;
}

template <typename V>
void DicLSE<V>::agregar(V elem){
    if(inicio == nodoNulo){
        NodoDicc<V> *n = new NodoDicc<V>(elem);
        inicio = n;
    }else{
        NodoDicc<V> *n = new NodoDicc<V>(elem);
        n->sig = inicio;
        inicio = n;
    }
    cantElem++;
}

template <typename V>
void DicLSE<V>::eliminar(V elemento){
    NodoDicc<V> *iter;
    if(elemento == inicio->elem){
        iter = inicio;
        inicio = inicio->sig;
        delete iter;
    }else{
        iter = inicio;
        bool found = false;
        while(!found){
            if(iter->sig->elem == elemento)
                found = true;
            else
                iter = iter->sig;
        }
        NodoDicc<V> n = iter->sig;
        iter->sig = n->sig;
        delete n;
    }
    cantElem--;
}

template <typename V>
bool DicLSE<V>::pertene(V elemento){
    bool belong = false;
    NodoDicc<V> *iter = inicio;
    while(!belong && iter != nodoNulo){
        if(iter->elem == elemento)
            belong = true;
        else
            iter = iter->sig;
    }
    return belong;
}

template <typename V>
int DicLSE<V>::pertene(V elem){
    return cantElem;
}
#endif /* DICLSE_H */

