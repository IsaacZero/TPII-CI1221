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

Nodo* GDListaAdy::nodoNulo = nullptr;

GDListaAdy::GDListaAdy() {
}

GDListaAdy::GDListaAdy(const GDListaAdy& orig) {
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

Nodo* GDListaAdy::agregarVertice(int e){
}

void GDListaAdy::eliminarVertice(Nodo* v){
}

void GDListaAdy::modificarEtiqueta(int newE, Nodo* v){
    v->elemento = newE;
}

int GDListaAdy::etiqueta(Nodo* v){
    return v->elemento;
}

void GDListaAdy::agregarArista(int p, Nodo* v1, Nodo* v2){
}

void GDListaAdy::eliminarArista(Nodo* v1, Nodo* v2){
}

void GDListaAdy::modificarPeso(int newP, Nodo* v1, Nodo* v2){
}

int GDListaAdy::peso(Nodo* v1, Nodo* v2){
}

Nodo* GDListaAdy::primerVertice(){
    return inicio;
}

Nodo* GDListaAdy::siguienteVertice(Nodo* v){
    return v->siguiente;
}

Nodo* GDListaAdy::primerVerticeAdy(Nodo* v1){
}

Nodo* GDListaAdy::sigVerticeAdy(Nodo* v1, Nodo* v2){
}

int GDListaAdy::numVertices(){
    return cantElem;
}