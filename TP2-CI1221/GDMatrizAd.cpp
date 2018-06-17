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

GDMatrizAd::GDMatrizAd() {
}

GDMatrizAd::GDMatrizAd(const GDMatrizAd& orig) {
}

GDMatrizAd::~GDMatrizAd() {
}

void GDMatrizAd::crear(){
    ultimo = -1;
}

void GDMatrizAd::destruir(){
    ultimo = -1;
}

void GDMatrizAd::vaciar(){
    ultimo = -1;
}

bool GDMatrizAd::vacio(){
    bool empty = false;
    if(ultimo == -1)
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
    return 0;
}

int GDMatrizAd::siguienteVertice(int v){
    return v+1;
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
    return vertAdy;
}

int GDMatrizAd::numVertices(){
    return ultimo + 1;
}