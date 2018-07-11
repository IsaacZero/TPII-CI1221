/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Isaac
 *
 * Created on 7 de junio de 2018, 09:28 PM
 */

#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <time.h>

#include "Algoritmos.h"
#include "GDirigido.h"
#include "GNDGD.h"
typedef std::vector<Vertice> vectorV;
#define MAX 5
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    
    GNDGD grafo;
    Algoritmos algoritmos;
    grafo.crear();
    vectorV vector;
    vector.reserve(MAX);
    clock_t aStart, aStop, oStart, oStop;
    float secs, secsOp;
    float acmlpt = 0;
    //int aristaRand = 0;
    string b = "bitacora";
    ofstream archivoSalida(b + ".txt");
    for(int i = 0; i < MAX; i++){
        oStart = clock();
        vector.push_back(grafo.agregarVertice(i*2));
        oStop = clock();
        acmlpt += ((float)oStop - (float)oStart)/ CLOCKS_PER_SEC;
    }
    
    for(int i = 0; i < MAX; i++){
        for(int j = 0; j < MAX; j++){
            if(i != j)
                grafo.agregarArista((j+1)*2, vector[i], vector[j]);
        }
    }

    //GDirigido G2;
    //G2.crear();
    aStart = clock();
    //algoritmos.listarRPP(grafo);
    //algoritmos.copiar(grafo, G2);
    algoritmos.vendedor(grafo, vector[0]);
    aStop = clock();
    
    secs = ((float)aStop - (float)aStart)/ CLOCKS_PER_SEC;
    secsOp = ((float)oStop - (float)oStart)/ CLOCKS_PER_SEC;
    archivoSalida << "Tiempo OP = " << secsOp << endl;
    archivoSalida << "Tiempo total OP = " << acmlpt << endl;
    archivoSalida << "Tiempo algo = " << secs << endl;
    grafo.destruir();
    //G2.destruir();
    return 0;
}

