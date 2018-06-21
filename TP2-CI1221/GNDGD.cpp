/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   GNDGD.cpp
 * Author: Isaac
 * 
 * Created on 7 de junio de 2018, 09:40 PM
 */

#include "GNDGD.h"

GNDGD::GNDGD() {
}

GNDGD::GNDGD(const GNDGD& orig) {
}

GNDGD::~GNDGD() {
}

void GNDGD::crear(){
    grafoND.crear();
}

void GNDGD::destruir(){
    grafoND.destruir();
}

void GNDGD::vaciar(){
    grafoND.vaciar();
}

bool GNDGD::vacio(){
    return grafoND.vacio();
}

Vertice GNDGD::agregarVertice(int e){
    return grafoND.agregarVertice(e);
}

void GNDGD::eliminarVertice(Vertice v){
    grafoND.eliminarVertice(v);
}

void GNDGD::modificarEtiqueta(int newE, Vertice v){
    grafoND.modificarEtiqueta(newE, v);
}

int GNDGD::etiqueta(Vertice v){
    return grafoND.etiqueta(v);
}
void GNDGD::agregarArista(int p, Vertice v1, Vertice v2){
    grafoND.agregarArista(p, v1, v2);
    grafoND.agregarArista(p, v2, v1);
}

void GNDGD::eliminarArista(Vertice v1, Vertice v2){
    grafoND.eliminarArista(v1, v2);
    grafoND.eliminarArista(v2, v1);
}

void GNDGD::modificarPeso(int newP, Vertice v1, Vertice v2){
    grafoND.modificarPeso(newP, v1, v2);
    grafoND.modificarPeso(newP, v2, v1);
}

int GNDGD::peso(Vertice v1, Vertice v2){
    return grafoND.peso(v1, v2);
}

Vertice GNDGD::primerVertice(){
    return grafoND.primerVertice();
}

Vertice GNDGD::siguienteVertice(Vertice v){
    return grafoND.siguienteVertice(v);
}

Vertice GNDGD::primerVerticeAdy(Vertice v1){
    return grafoND.primerVerticeAdy(v1);
}

Vertice GNDGD::sigVerticeAdy(Vertice v1, Vertice v2){
    return grafoND.sigVerticeAdy(v1, v2);
}

int GNDGD::numVertices(){
    return grafoND.numVertices();
}

int GNDGD::numAristas(Vertice v){
    return grafoND.numAristas(v);
}

bool GNDGD::existeArista(Vertice v1, Vertice v2){
    return grafoND.existeArista(v1, v2);
}