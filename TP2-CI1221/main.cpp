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
        cout << "Las etiquetas de los grafos solo pueden ser ENTEROS." << endl;
        cout << "1. Grafo Dirigido." << endl;
        cout << "2. Grafo No Dirigido." << endl;
        cout << "0. Salir." << endl;
        cin >> desicion;
        switch(desicion){
            case 1:
            {
                GDirigido grafo;
                GDirigido G2;
                Algoritmos algo;
                Vertice v1;
                Vertice v2;
                int desicion2 = 0;
                bool continuar2 = true;
                while (continuar2){
                    cout << "¿Que desea hacer?\n (Ingrese un numero)" << endl;
                    cout << "1. Aplicar Operadores Básicos." << endl;
                    cout << "2. Aplicar Algoritmos. (RECUERDE LLENAR EL GRAFO ANTES DE APLICAR ALGORITMOS)" << endl;
                    cout << "0. Salir." << endl;
                    switch(desicion2){
                        case 1:
                        {
                            int desicion3 = 0;
                            bool continuar3 = true;
                            while(continuar3){
                                cout << "¿Que Operador Básico desea aplicar?\n (Ingrese un numero)" << endl;//19
                                cout << "1. Crear Grafo." << endl;
                                cout << "2. Dstruir Grafo." << endl;
                                cout << "3. Vaciar." << endl;
                                cout << "4. Vacio." << endl;
                                cout << "5. Agregar Vertice." << endl;
                                cout << "6. Eliminar Vertice." << endl;
                                cout << "7. Modificar Etiqueta." << endl;
                                cout << "8. Etiqueta." << endl;
                                cout << "9. Agregar Arista." << endl;
                                cout << "10. Eliminar Arista." << endl;
                                cout << "11. Modificar Peso." << endl;
                                cout << "12. Peso." << endl;
                                cout << "13. Primer Vertice." << endl;
                                cout << "14. Siguiente Vertice." << endl;
                                cout << "15. Primer Vertice Adyacente." << endl;
                                cout << "16. Siguiente Vertice Adyacente." << endl;
                                cout << "17. NumVertices." << endl;
                                cout << "0. Salir." << endl;
                                cin >> desicion3;
                                switch(desicion3){
                                    case 0:
                                    {
                                        continuar3 = false;
                                    }
                                    break;
                                    case 1:
                                    {
                                        grafo.crear();
                                    }
                                    break;
                                    case 2:
                                    {
                                        grafo.destruir();
                                        cout << "El Grafo se ha destruido." << endl;
                                        desicion3 = false;
                                        desicion2 = false;
                                    }
                                    break;
                                    case 3:
                                    {
                                        grafo.vaciar();
                                    }
                                    break;
                                    case 4:
                                    {
                                        bool empty = grafo.vacio();
                                        if(empty)
                                            cout << "El Grafo esta Vacio." << endl;
                                        else
                                            cout << "El Grafo NO esta vacio." << endl;
                                    }
                                    break;
                                    case 5:
                                    {
                                        cout << "Digite la etiqueta del vertice." << endl;
                                        cin >> desicion3;
                                        grafo.agregarVertice(desicion3);
                                        cout << "Vertice Agregado." << endl;
                                    }
                                    break;
                                    case 6:
                                    {
                                        cout << "Digite la etiqueta del vertice." << endl;
                                        cin >> desicion3;
                                        v1 = algo.buscarEtiq(desicion3, grafo);
                                        if(v1 == nullptr)
                                            cout << "No existe el vertice en el grafo." << endl;
                                        else{
                                            grafo.eliminarVertice(v1);
                                            cout << "El Vertice se ha eliminado." << endl;
                                        }
                                    }
                                    break;
                                    case 7:
                                    {
                                        cout << "Digite la etiqueta del vertice." << endl;
                                        cin >> desicion3;
                                        v1 = algo.buscarEtiq(desicion3, grafo);
                                        if(v1 == nullptr)
                                            cout << "No existe el vertice en el grafo." << endl;
                                        else{
                                            cout << "Digite la nueva etiqueta." << endl;
                                            cin >> desicion3;
                                            grafo.modificarEtiqueta(desicion3, v1);
                                            cout << "Se modifico la etiqueta." << endl;
                                        }
                                    }
                                    break;
                                    case 8:
                                    {
                                        cout << "Digite la etiqueta del vertice." << endl;
                                        cin >> desicion3;
                                        v1 = algo.buscarEtiq(desicion3, grafo);
                                        if(v1 == nullptr)
                                            cout << "No existe el vertice en el grafo." << endl;
                                        else{
                                            desicion3 = grafo.etiqueta(v1);
                                            cout << "La Etiqueta es: " << desicion3 << endl;
                                        }
                                    }
                                    break;
                                    case 9:
                                    {
                                        cout << "Digite la etiqueta del vertice 1." << endl;
                                        cin >> desicion3;
                                        v1 = algo.buscarEtiq(desicion3, grafo);
                                        if(v1 == nullptr)
                                            cout << "No existe el vertice en el grafo." << endl;
                                        else{
                                            cout << "Digite la etiqueta del vertice 2." << endl;
                                            cin >> desicion3;
                                            v2 = algo.buscarEtiq(desicion3, grafo);
                                            if(v2 == nullptr)
                                                cout << "No existe el vertice en el grafo." << endl;
                                            else{
                                                cout << "Digite el peso de la arista." << endl;
                                                cin >> desicion3;
                                                grafo.agregarArista(desicion3, v1, v2);
                                            }
                                        }
                                    }
                                    break;
                                    case 10:
                                    {
                                        cout << "Digite la etiqueta del vertice 1." << endl;
                                        cin >> desicion3;
                                        v1 = algo.buscarEtiq(desicion3, grafo);
                                        if(v1 == nullptr)
                                            cout << "No existe el vertice en el grafo." << endl;
                                        else{
                                            cout << "Digite la etiqueta del vertice 2." << endl;
                                            cin >> desicion3;
                                            v2 = algo.buscarEtiq(desicion3, grafo);
                                            if(v2 == nullptr)
                                                cout << "No existe el vertice en el grafo." << endl;
                                            else{
                                                grafo.eliminarArista(v1, v2);
                                                cout << "Se Elimino la Arista." << endl;
                                            }
                                        }
                                    }
                                    break;
                                    case 11:
                                    {
                                        cout << "Digite la etiqueta del vertice 1." << endl;
                                        cin >> desicion3;
                                        v1 = algo.buscarEtiq(desicion3, grafo);
                                        if(v1 == nullptr)
                                            cout << "No existe el vertice en el grafo." << endl;
                                        else{
                                            cout << "Digite la etiqueta del vertice 2." << endl;
                                            cin >> desicion3;
                                            v2 = algo.buscarEtiq(desicion3, grafo);
                                            if(v2 == nullptr)
                                                cout << "No existe el vertice en el grafo." << endl;
                                            else{
                                                cout << "Digite el nuevo peso." << endl;
                                                cin >> desicion3;
                                                grafo.modificarPeso(desicion3, v1, v2);
                                                cout << "Se modifico el peso correctamente." << endl;
                                            }
                                        }
                                    }
                                    break;
                                    case 12:
                                    {
                                        cout << "Digite la etiqueta del vertice 1." << endl;
                                        cin >> desicion3;
                                        v1 = algo.buscarEtiq(desicion3, grafo);
                                        if(v1 == nullptr)
                                            cout << "No existe el vertice en el grafo." << endl;
                                        else{
                                            cout << "Digite la etiqueta del vertice 2." << endl;
                                            cin >> desicion3;
                                            v2 = algo.buscarEtiq(desicion3, grafo);
                                            if(v2 == nullptr)
                                                cout << "No existe el vertice en el grafo." << endl;
                                            else{
                                                desicion3 = grafo.peso(v1, v2);
                                                cout << "El Peso de la Arista es:" << desicion3 << endl;
                                            }
                                        }
                                    }
                                    break;
                                    case 13:
                                    {
                                        v1 = grafo.primerVertice();
                                        desicion3 = grafo.etiqueta(v1);
                                        cout << "La etiqueta del nodo es: " << desicion3 << endl;
                                    }
                                    break;
                                    case 14:
                                    {
                                        cout << "Digite la etiqueta del Nodo del que desea el siguiente." << endl;
                                        cin >> desicion3;
                                        v1 = algo.buscarEtiq(desicion3, grafo);
                                        if(v1 == nullptr)
                                            cout << "No existe el vertice en el grafo." << endl;
                                        else{
                                            v1 = grafo.siguienteVertice(v1);
                                            desicion3 = grafo.etiqueta(v1);
                                            cout << "La Etiqueta del Vertice es: " << desicion3 << endl;
                                        }
                                    }
                                    break;
                                    case 15:
                                    {
                                        cout << "Digite la etiqueta del Nodo que desea el adyacente." << endl;
                                        cin >> desicion3;
                                        v1 = algo.buscarEtiq(desicion3, grafo);
                                        if(v1 == nullptr)
                                            cout << "No existe el vertice en el grafo." << endl;
                                        else{
                                            v1 = grafo.primerVerticeAdy(v1);
                                            desicion3 = grafo.etiqueta(v1);
                                            cout << "La Etiqueta del Vertice es: " << desicion3 << endl;
                                        }
                                    }
                                    break;
                                    case 16:
                                    {
                                        cout << "Digite la etiqueta del vertice 1." << endl;
                                        cin >> desicion3;
                                        v1 = algo.buscarEtiq(desicion3, grafo);
                                        if(v1 == nullptr)
                                            cout << "No existe el vertice en el grafo." << endl;
                                        else{
                                            cout << "Digite la etiqueta del vertice 2." << endl;
                                            cin >> desicion3;
                                            v2 = algo.buscarEtiq(desicion3, grafo);
                                            if(v2 == nullptr)
                                                cout << "No existe el vertice en el grafo." << endl;
                                            else{
                                                v2 = grafo.sigVerticeAdy(v1, v2);
                                                desicion3 = grafo.etiqueta(v2);
                                                cout << "La Etiqueta del Vertice es: " << desicion3 << endl;
                                            }
                                        }
                                    }
                                    break;
                                    case 17:
                                    {
                                        desicion3 = grafo.numVertices();
                                        cout << "Cantidad de Vertices = " << desicion3 << endl;
                                    }
                                    break;
                                    default:
                                    {
                                        cout << "Ingrese un número valido." << endl;
                                    }
                                }
                            }
                        }
                        break;
                        case 2:
                        {
                            int desicion3 = 0;
                            bool continuar3 = true;
                            while(continuar3){
                                cout << "¿Que Algoritmo desea aplicar?\n (Ingrese un numero)" << endl;//19
                                cout << "1. Dijkstra." << endl;
                                cout << "2. Floyd." << endl;
                                cout << "3. Listar Recorrido por Profundidad Primero." << endl;
                                cout << "4. Eliminar Vertice No Aislado." << endl;
                                cout << "5. Copiar Grafo." << endl;
                                cout << "6. Grafos Iguales." << endl;
                                cout << "0. Salir." << endl;
                                cin >> desicion3;
                                switch(desicion3){
                                    case 0:
                                    {
                                        continuar3 = false;
                                    }
                                    break;
                                    case 1:
                                    {
                                        cout << "Digite la etiqueta del vertice." << endl;
                                        cin >> desicion3;
                                        v1 = algo.buscarEtiq(desicion3, grafo);
                                        algo.dijkstra(v1, grafo);
                                    }
                                    break;
                                    case 2:
                                    {
                                        algo.floyd(grafo);
                                    }
                                    break;
                                    case 3:
                                    {
                                        algo.listarRPP(grafo);
                                    }
                                    break;
                                    case 4:
                                    {
                                        cout << "Digite la etiqueta del vertice." << endl;
                                        cin >> desicion3;
                                        v1 = algo.buscarEtiq(desicion3, grafo);
                                        algo.elimVertNA(v1, grafo);
                                    }
                                    break;
                                    case 5:
                                    {
                                        algo.copiar(grafo, G2);
                                        cout << "¿Desea Listar el segundo grafo? \n 1 = SI, 2 = NO." << endl;
                                        cin >> desicion3;
                                        if (desicion3 == 1)
                                            algo.listarRPP(G2);
                                    }
                                    break;
                                    case 6:
                                    {
                                        bool equal = algo.iguales(grafo, G2);
                                        if(equal)
                                            cout << "Los Grafos SON Iguales." << endl;
                                        else
                                            cout << "Los Grafos NO SON Iguales." << endl;
                                    }
                                    break;
                                    default:
                                    {
                                        cout << "Digite un numero valido." << endl;
                                    }
                                    break;
                                }
                            }
                        }
                        break;
                        case 0:
                        {
                            continuar2 = false;
                        }
                        break;
                        default:
                        {
                            cout << "Digite un numero valido." << endl;
                        }
                    }
                }
            }
            break;
            case 2:
            {
                GNDGD grafo;
                GNDGD G2;
                Algoritmos algo;
                Vertice v1;
                Vertice v2;
                int desicion2 = 0;
                bool continuar2 = true;
                while (continuar2){
                    cout << "¿Que desea hacer?\n (Ingrese un numero)" << endl;
                    cout << "1. Aplicar Operadores Básicos." << endl;
                    cout << "2. Aplicar Algoritmos. (RECUERDE LLENAR EL GRAFO ANTES DE APLICAR ALGORITMOS)" << endl;
                    cout << "0. Salir." << endl;
                    switch(desicion2){
                        case 1:
                        {
                            int desicion3 = 0;
                            bool continuar3 = true;
                            while(continuar3){
                                cout << "¿Que Operador Básico desea aplicar?\n (Ingrese un numero)" << endl;//19
                                cout << "1. Crear Grafo." << endl;
                                cout << "2. Dstruir Grafo." << endl;
                                cout << "3. Vaciar." << endl;
                                cout << "4. Vacio." << endl;
                                cout << "5. Agregar Vertice." << endl;
                                cout << "6. Eliminar Vertice." << endl;
                                cout << "7. Modificar Etiqueta." << endl;
                                cout << "8. Etiqueta." << endl;
                                cout << "9. Agregar Arista." << endl;
                                cout << "10. Eliminar Arista." << endl;
                                cout << "11. Modificar Peso." << endl;
                                cout << "12. Peso." << endl;
                                cout << "13. Primer Vertice." << endl;
                                cout << "14. Siguiente Vertice." << endl;
                                cout << "15. Primer Vertice Adyacente." << endl;
                                cout << "16. Siguiente Vertice Adyacente." << endl;
                                cout << "17. NumVertices." << endl;
                                cout << "0. Salir." << endl;
                                cin >> desicion3;
                                switch(desicion3){
                                    case 0:
                                    {
                                        continuar3 = false;
                                    }
                                    break;
                                    case 1:
                                    {
                                        grafo.crear();
                                    }
                                    break;
                                    case 2:
                                    {
                                        grafo.destruir();
                                        cout << "El Grafo se ha destruido." << endl;
                                        desicion3 = false;
                                        desicion2 = false;
                                    }
                                    break;
                                    case 3:
                                    {
                                        grafo.vaciar();
                                    }
                                    break;
                                    case 4:
                                    {
                                        bool empty = grafo.vacio();
                                        if(empty)
                                            cout << "El Grafo esta Vacio." << endl;
                                        else
                                            cout << "El Grafo NO esta vacio." << endl;
                                    }
                                    break;
                                    case 5:
                                    {
                                        cout << "Digite la etiqueta del vertice." << endl;
                                        cin >> desicion3;
                                        grafo.agregarVertice(desicion3);
                                        cout << "Vertice Agregado." << endl;
                                    }
                                    break;
                                    case 6:
                                    {
                                        cout << "Digite la etiqueta del vertice." << endl;
                                        cin >> desicion3;
                                        v1 = algo.buscarEtiqND(desicion3, grafo);
                                        if(v1 == nullptr)
                                            cout << "No existe el vertice en el grafo." << endl;
                                        else{
                                            grafo.eliminarVertice(v1);
                                            cout << "El Vertice se ha eliminado." << endl;
                                        }
                                    }
                                    break;
                                    case 7:
                                    {
                                        cout << "Digite la etiqueta del vertice." << endl;
                                        cin >> desicion3;
                                        v1 = algo.buscarEtiqND(desicion3, grafo);
                                        if(v1 == nullptr)
                                            cout << "No existe el vertice en el grafo." << endl;
                                        else{
                                            cout << "Digite la nueva etiqueta." << endl;
                                            cin >> desicion3;
                                            grafo.modificarEtiqueta(desicion3, v1);
                                            cout << "Se modifico la etiqueta." << endl;
                                        }
                                    }
                                    break;
                                    case 8:
                                    {
                                        cout << "Digite la etiqueta del vertice." << endl;
                                        cin >> desicion3;
                                        v1 = algo.buscarEtiqND(desicion3, grafo);
                                        if(v1 == nullptr)
                                            cout << "No existe el vertice en el grafo." << endl;
                                        else{
                                            desicion3 = grafo.etiqueta(v1);
                                            cout << "La Etiqueta es: " << desicion3 << endl;
                                        }
                                    }
                                    break;
                                    case 9:
                                    {
                                        cout << "Digite la etiqueta del vertice 1." << endl;
                                        cin >> desicion3;
                                        v1 = algo.buscarEtiqND(desicion3, grafo);
                                        if(v1 == nullptr)
                                            cout << "No existe el vertice en el grafo." << endl;
                                        else{
                                            cout << "Digite la etiqueta del vertice 2." << endl;
                                            cin >> desicion3;
                                            v2 = algo.buscarEtiqND(desicion3, grafo);
                                            if(v2 == nullptr)
                                                cout << "No existe el vertice en el grafo." << endl;
                                            else{
                                                cout << "Digite el peso de la arista." << endl;
                                                cin >> desicion3;
                                                grafo.agregarArista(desicion3, v1, v2);
                                            }
                                        }
                                    }
                                    break;
                                    case 10:
                                    {
                                        cout << "Digite la etiqueta del vertice 1." << endl;
                                        cin >> desicion3;
                                        v1 = algo.buscarEtiqND(desicion3, grafo);
                                        if(v1 == nullptr)
                                            cout << "No existe el vertice en el grafo." << endl;
                                        else{
                                            cout << "Digite la etiqueta del vertice 2." << endl;
                                            cin >> desicion3;
                                            v2 = algo.buscarEtiqND(desicion3, grafo);
                                            if(v2 == nullptr)
                                                cout << "No existe el vertice en el grafo." << endl;
                                            else{
                                                grafo.eliminarArista(v1, v2);
                                                cout << "Se Elimino la Arista." << endl;
                                            }
                                        }
                                    }
                                    break;
                                    case 11:
                                    {
                                        cout << "Digite la etiqueta del vertice 1." << endl;
                                        cin >> desicion3;
                                        v1 = algo.buscarEtiqND(desicion3, grafo);
                                        if(v1 == nullptr)
                                            cout << "No existe el vertice en el grafo." << endl;
                                        else{
                                            cout << "Digite la etiqueta del vertice 2." << endl;
                                            cin >> desicion3;
                                            v2 = algo.buscarEtiqND(desicion3, grafo);
                                            if(v2 == nullptr)
                                                cout << "No existe el vertice en el grafo." << endl;
                                            else{
                                                cout << "Digite el nuevo peso." << endl;
                                                cin >> desicion3;
                                                grafo.modificarPeso(desicion3, v1, v2);
                                                cout << "Se modifico el peso correctamente." << endl;
                                            }
                                        }
                                    }
                                    break;
                                    case 12:
                                    {
                                        cout << "Digite la etiqueta del vertice 1." << endl;
                                        cin >> desicion3;
                                        v1 = algo.buscarEtiqND(desicion3, grafo);
                                        if(v1 == nullptr)
                                            cout << "No existe el vertice en el grafo." << endl;
                                        else{
                                            cout << "Digite la etiqueta del vertice 2." << endl;
                                            cin >> desicion3;
                                            v2 = algo.buscarEtiqND(desicion3, grafo);
                                            if(v2 == nullptr)
                                                cout << "No existe el vertice en el grafo." << endl;
                                            else{
                                                desicion3 = grafo.peso(v1, v2);
                                                cout << "El Peso de la Arista es:" << desicion3 << endl;
                                            }
                                        }
                                    }
                                    break;
                                    case 13:
                                    {
                                        v1 = grafo.primerVertice();
                                        desicion3 = grafo.etiqueta(v1);
                                        cout << "La etiqueta del nodo es: " << desicion3 << endl;
                                    }
                                    break;
                                    case 14:
                                    {
                                        cout << "Digite la etiqueta del Nodo del que desea el siguiente." << endl;
                                        cin >> desicion3;
                                        v1 = algo.buscarEtiqND(desicion3, grafo);
                                        if(v1 == nullptr)
                                            cout << "No existe el vertice en el grafo." << endl;
                                        else{
                                            v1 = grafo.siguienteVertice(v1);
                                            desicion3 = grafo.etiqueta(v1);
                                            cout << "La Etiqueta del Vertice es: " << desicion3 << endl;
                                        }
                                    }
                                    break;
                                    case 15:
                                    {
                                        cout << "Digite la etiqueta del Nodo que desea el adyacente." << endl;
                                        cin >> desicion3;
                                        v1 = algo.buscarEtiqND(desicion3, grafo);
                                        if(v1 == nullptr)
                                            cout << "No existe el vertice en el grafo." << endl;
                                        else{
                                            v1 = grafo.primerVerticeAdy(v1);
                                            desicion3 = grafo.etiqueta(v1);
                                            cout << "La Etiqueta del Vertice es: " << desicion3 << endl;
                                        }
                                    }
                                    break;
                                    case 16:
                                    {
                                        cout << "Digite la etiqueta del vertice 1." << endl;
                                        cin >> desicion3;
                                        v1 = algo.buscarEtiqND(desicion3, grafo);
                                        if(v1 == nullptr)
                                            cout << "No existe el vertice en el grafo." << endl;
                                        else{
                                            cout << "Digite la etiqueta del vertice 2." << endl;
                                            cin >> desicion3;
                                            v2 = algo.buscarEtiqND(desicion3, grafo);
                                            if(v2 == nullptr)
                                                cout << "No existe el vertice en el grafo." << endl;
                                            else{
                                                v2 = grafo.sigVerticeAdy(v1, v2);
                                                desicion3 = grafo.etiqueta(v2);
                                                cout << "La Etiqueta del Vertice es: " << desicion3 << endl;
                                            }
                                        }
                                    }
                                    break;
                                    case 17:
                                    {
                                        desicion3 = grafo.numVertices();
                                        cout << "Cantidad de Vertices = " << desicion3 << endl;
                                    }
                                    break;
                                    default:
                                    {
                                        cout << "Ingrese un número valido." << endl;
                                    }
                                }
                            }
                        }
                        break;
                        case 2:
                        {
                            int desicion3 = 0;
                            bool continuar3 = true;
                            while(continuar3){
                                cout << "¿Que Algoritmo desea aplicar?\n (Ingrese un numero)" << endl;//19
                                cout << "1. Prim." << endl;
                                cout << "2. Problema del Vendedor." << endl;
                                cout << "0. Salir." << endl;
                                cin >> desicion3;
                                switch(desicion3){
                                    case 0:
                                    {
                                        continuar3 = false;
                                    }
                                    break;
                                    case 1:
                                    {
                                        algo.prim(grafo);
                                    }
                                    break;
                                    case 2:
                                    {
                                        cout << "Digite la etiqueta del vertice de origen." << endl;
                                        cin >> desicion3;
                                        v1 = algo.buscarEtiqND(desicion3, grafo);
                                        algo.vendedor(grafo, v1);
                                    }
                                    break;
                                    default:
                                    {
                                        cout << "Digite un numero valido." << endl;
                                    }
                                    break;
                                }
                            }
                        }
                        break;
                        case 0:
                        {
                            continuar2 = false;
                        }
                        break;
                        default:
                        {
                            cout << "Digite un numero valido." << endl;
                        }
                    }
                }
            }
            break;
            case 0:
            {
                continuar = false;
            }
            break;
            default:
            {
                cout << "Digite un numero valido." << endl;
            }
        }
    }
    cout << "Gracias por su tiempo :D" << endl;
    return 0;
}

