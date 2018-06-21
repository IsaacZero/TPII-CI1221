/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   GDMatrizAd.cpp
 * Author: Isaac
 * 
 * Created on 7 de junio de 2018, 09:38 PM
 */

#include "GDMatrizAd.h"

int GDMatrizAd::nodoNulo = -1;

GDMatrizAd::GDMatrizAd() {
}

GDMatrizAd::GDMatrizAd(const GDMatrizAd& orig) {
}

GDMatrizAd::~GDMatrizAd() {
}

void GDMatrizAd::crear(){
    ultimo = nodoNulo;
}

void GDMatrizAd::destruir(){
    ultimo = nodoNulo;
}

void GDMatrizAd::vaciar(){
    ultimo = nodoNulo;
}

bool GDMatrizAd::vacio(){
    bool empty = false;
    if(ultimo == nodoNulo)
        empty = true;
    return empty;
}

int GDMatrizAd::agregarVertice(int e){
    vecVert[ultimo + 1] = e;
    ultimo++;
    for(int i = 0; i <= ultimo; i++){
        matrizAdy[i][ultimo] = 0;
        matrizAdy[ultimo][i]= 0;
    }
    return ultimo;
}

void GDMatrizAd::eliminarVertice(int v){
    if(v == ultimo)
        ultimo--;
    else{
        for(int i = v; i < ultimo; i++){
            for(int j = 0; j < ultimo; j++){
                matrizAdy[i][j] = matrizAdy[i+1][j];
                matrizAdy[j][i] = matrizAdy[j][i+1];
            }
        }
        ultimo--;
    }
}

void GDMatrizAd::modificarEtiqueta(int newE, int v){
    vecVert[v] = newE;
}

int GDMatrizAd::etiqueta(int v){
    return vecVert[v];
}

void GDMatrizAd::agregarArista(int p, int v1, int v2){
    matrizAdy[v1][v2] = p;
}

void GDMatrizAd::eliminarArista(int v1, int v2){
    matrizAdy[v1][v2] = 0;
}

void GDMatrizAd::modificarPeso(int newP, int v1, int v2){
    matrizAdy[v1][v2] = newP;
}

int GDMatrizAd::peso(int v1, int v2){
    return matrizAdy[v1][v2];
}

int GDMatrizAd::primerVertice(){
    int primV = nodoNulo;
    if(ultimo != nodoNulo)
        primV = 0;
    return primV;
}

int GDMatrizAd::siguienteVertice(int v){
    int sigVert = nodoNulo;
    if(v < ultimo)
        sigVert = v+1;
    return sigVert;
}

int GDMatrizAd::primerVerticeAdy(int v1){
    int vertAdy = 0;
    bool found = false;
    while(!found && vertAdy <= ultimo){
        if(matrizAdy[v1][vertAdy] != 0)
            found = true;
        else
            vertAdy++;
    }
    if(vertAdy > ultimo && !found)
        vertAdy = nodoNulo;
    return vertAdy;
}

int GDMatrizAd::sigVerticeAdy(int v1, int v2){
    int vertAdy = v2 + 1;
    bool found = false;
    while(!found && vertAdy <= ultimo){
        if(matrizAdy[v1][vertAdy] != 0)
            found = true;
        else
            vertAdy++;
    }
    if(vertAdy > ultimo && !found)
        vertAdy = nodoNulo;
    return vertAdy;
}

int GDMatrizAd::numVertices(){
    return ultimo + 1;
}

int GDMatrizAd::numAristas(int v){
    int cantAr = 0;
    for(int i = 0; i <= ultimo; i++){
        if(matrizAdy[v][i] > 0)
            cantAr++;
    }
    return cantAr;
}

bool GDMatrizAd::existeArista(int v1, int v2){
    bool existe = false;
    if(matrizAdy[v1][v2] != 0)
        existe = true;
    return existe;
}