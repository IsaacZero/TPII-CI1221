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
    
    int desicion = 0;
    bool continuar = true;
    while(continuar){
        cout << "MENU DE OPCIONES\n" << endl;
        cout << "¿Cual Estructura desea usar?\n (Ingrese un numero)" << endl;
        cout << "1. Grafo Dirigido." << endl;
        cout << "2. Grafo No Dirigido." << endl;
        cin >> desicion;
        switch(desicion){
            case 1:
            {
                GDirigido grafo;
                GDirigido G2;
                int desicion2 = 0;
                bool continuar2 = true;
                while (continuar2){
                    cout << "¿Que desea hacer?\n (Ingrese un numero)" << endl;
                    cout << "1. Aplicar Operadores Básicos." << endl;
                    cout << "2. Aplicar Algoritmos. (RECUERDE LLENAR EL GRAFO ANTES DE APLICAR ALGORITMOS)" << endl;
                    cout << "Salir." << endl;
                    switch(desicion2){
                        case 1:
                        {
                            int desicion3 = 0;
                            bool continuar3 = true;
                            while(continuar3){
                                cout << "¿Que Operador Básico desea aplicar?\n (Ingrese un numero)" << endl;//19
                                cout << "1. Grafo Dirigido." << endl;
                                cout << "2. Grafo No Dirigido." << endl;
                                cout << "3. Grafo No Dirigido." << endl;
                                cout << "4. Grafo No Dirigido." << endl;
                                cout << "5. Grafo No Dirigido." << endl;
                                cout << "6. Grafo No Dirigido." << endl;
                                cout << "7. Grafo No Dirigido." << endl;
                                cout << "8. Grafo No Dirigido." << endl;
                                cout << "9. Grafo No Dirigido." << endl;
                                cout << "10. Grafo No Dirigido." << endl;
                                cout << "11. Grafo No Dirigido." << endl;
                                cout << "12. Grafo No Dirigido." << endl;
                                cout << "13. Grafo No Dirigido." << endl;
                                cout << "14. Grafo No Dirigido." << endl;
                                cout << "15. Grafo No Dirigido." << endl;
                                cout << "16. Grafo No Dirigido." << endl;
                                cout << "17. Grafo No Dirigido." << endl;
                                cout << "18. Grafo No Dirigido." << endl;
                                cout << "19. Grafo No Dirigido." << endl;
                                cin >> desicion3;
                                switch(desicion3){
                                    case 1:
                                    {
                                        
                                    }
                                    break;
                                    case 2:
                                    {
                                        
                                    }
                                    break;
                                    case 3:
                                    {
                                        
                                    }
                                    break;
                                    case 4:
                                    {
                                        
                                    }
                                    break;
                                    case 5:
                                    {
                                        
                                    }
                                    break;
                                    case 6:
                                    {
                                        
                                    }
                                    break;
                                    case 7:
                                    {
                                        
                                    }
                                    break;
                                    case 8:
                                    {
                                        
                                    }
                                    break;
                                    case 9:
                                    {
                                        
                                    }
                                    break;
                                    case 10:
                                    {
                                        
                                    }
                                    break;
                                    case 11:
                                    {
                                        
                                    }
                                    break;
                                    case 12:
                                    {
                                        
                                    }
                                    break;
                                    case 13:
                                    {
                                        
                                    }
                                    break;
                                    case 14:
                                    {
                                        
                                    }
                                    break;
                                    case 15:
                                    {
                                        
                                    }
                                    break;
                                    case 16:
                                    {
                                        
                                    }
                                    break;
                                    case 17:
                                    {
                                        
                                    }
                                    break;
                                    case 18:
                                    {
                                        
                                    }
                                    break;
                                    case 19:
                                    {
                                        
                                    }
                                    break;
                                    
                                }
                            }
                        }
                        break;
                    }
                }
            }
            break;
            case 2:
            {
                
            }
            break;
        }
    }
    /*GNDGD grafo;
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
    //G2.destruir();*/
    return 0;
}

