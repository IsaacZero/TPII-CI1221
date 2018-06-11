/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   GDListaAdy.cpp
 * Author: Isaac
 * 
 * Created on 7 de junio de 2018, 09:39 PM
 */

#include "GDListaAdy.h"

GDListaAdy::Nodo* GDListaAdy::nodoNulo = nullptr;

GDListaAdy::GDListaAdy() {
}

GDListaAdy::~GDListaAdy() {
}

void GDListaAdy::crear(){
    inicio = nodoNulo;
    cantElem = 0;
}

void GDListaAdy::destruir(){
}

void GDListaAdy::vaciar(){
}

bool GDListaAdy::vacio(){
    bool empty;
    if(cantElem == 0)
        empty = true;
    else
        empty = false;
    return empty;
}

GDListaAdy::Nodo* GDListaAdy::agregarVertice(int e){
    Nodo *nodo = new Nodo(e);
    if(inicio == nodoNulo)
        inicio = nodo;
    else{
        Nodo *n = inicio;
        inicio = nodo;
        nodo->siguiente = n;
    }
    cantElem++;
    return nodo;
}

void GDListaAdy::eliminarVertice(Nodo* v){
    if(inicio == v){
        inicio = v->siguiente;
        delete v;
    }else{
        Nodo *n = inicio;
        while(n->siguiente != v)
            n = n->siguiente;
        n->siguiente = v->siguiente;
        delete v;
    }
}

void GDListaAdy::modificarEtiqueta(int newE, Nodo* v){
    v->elemento = newE;
}

int GDListaAdy::etiqueta(Nodo* v){
    return v->elemento;
}

void GDListaAdy::agregarArista(int p, Nodo* v1, Nodo* v2){
    GDListaAdy::Nodo::ListaAdy::NodoAdy *nAdy = new GDListaAdy::Nodo::ListaAdy::NodoAdy(p, v2);
    if(v1->adyacencia.start == nullptr)
        v1->adyacencia.start = nAdy;
    else{
        GDListaAdy::Nodo::ListaAdy::NodoAdy *n = v1->adyacencia.start;
        nAdy->sig = n;
        v1->adyacencia.start = nAdy;
    }
    v1->adyacencia.cantAdy++;
}

void GDListaAdy::eliminarArista(Nodo* v1, Nodo* v2){
}

void GDListaAdy::modificarPeso(int newP, Nodo* v1, Nodo* v2){
}

int GDListaAdy::peso(Nodo* v1, Nodo* v2){
}

GDListaAdy::Nodo* GDListaAdy::primerVertice(){
    return inicio;
}

GDListaAdy::Nodo* GDListaAdy::siguienteVertice(Nodo* v){
    return v->siguiente;
}

GDListaAdy::Nodo* GDListaAdy::primerVerticeAdy(Nodo* v1){
}

GDListaAdy::Nodo* GDListaAdy::sigVerticeAdy(Nodo* v1, Nodo* v2){
}

int GDListaAdy::numVertices(){
    return cantElem;
}