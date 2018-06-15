/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   GDirigido.cpp
 * Author: Isaac
 * 
 * Created on 14 de junio de 2018, 09:37 PM
 */

#include "GDirigido.h"

GDirigido::GDirigido() {
}

GDirigido::GDirigido(const GDirigido& orig) {
}

GDirigido::~GDirigido() {
}

void GDirigido::crear(){
    grafo.crear();
}

void GDirigido::destruir(){
    grafo.destruir();
}

void GDirigido::vaciar(){
    grafo.vaciar();
}

bool GDirigido::vacio(){
    return grafo.vacio();
}

Vertice GDirigido::agregarVertice(int e){
    return grafo.agregarVertice(e);
}

void GDirigido::eliminarVertice(Vertice v){
    grafo.eliminarVertice(v);
}

void GDirigido::modificarEtiqueta(int newE, Vertice v){
    grafo.modificarEtiqueta(newE, v);
}

int GDirigido::etiqueta(Vertice v){
    return grafo.etiqueta(v);
}
void GDirigido::agregarArista(int p, Vertice v1, Vertice v2){
    grafo.agregarArista(p, v1, v2);
}

void GDirigido::eliminarArista(Vertice v1, Vertice v2){
    grafo.eliminarArista(v1, v2);
}

void GDirigido::modificarPeso(int newP, Vertice v1, Vertice v2){
    grafo.modificarPeso(newP, v1, v2);
}

int GDirigido::peso(Vertice v1, Vertice v2){
    return grafo.peso(v1, v2);
}

Vertice GDirigido::primerVertice(){
    return grafo.primerVertice();
}

Vertice GDirigido::siguienteVertice(Vertice v){
    return grafo.siguienteVertice(v);
}

Vertice GDirigido::primerVerticeAdy(Vertice v1){
    return grafo.primerVerticeAdy(v1);
}

Vertice GDirigido::sigVerticeAdy(Vertice v1, Vertice v2){
    return grafo.sigVerticeAdy(v1, v2);
}

int GDirigido::numVertices(){
    return grafo.numVertices();
}