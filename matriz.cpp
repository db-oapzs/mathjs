#include "matriz.h"
#include <iostream>
#include <iomanip> 
#include <cstdlib> 
using namespace std;

Matriz::Matriz(int filas, int columnas) : filas(filas), columnas(columnas) {
    inicializarMatriz(filas, columnas);
}

Matriz::~Matriz() {
    for (int i = 0; i < filas; ++i) {
        delete[] matriz[i];
    }
    delete[] matriz;
}

void Matriz::inicializarMatriz(int filas, int columnas) {
    matriz = new double *[filas];
    for (int i = 0; i < filas; ++i) {
        matriz[i] = new double[columnas]();
    }
}

void Matriz::llenar() {
    for (int i = 0; i < filas; ++i) {
        for (int j = 0; j < columnas; ++j) {
            matriz[i][j] = rand() % 100 + 1;
        }
    }
}

void Matriz::mostrar() {
    for (int i = 0; i < filas; ++i) {
        for (int j = 0; j < columnas; ++j) {
            cout << setw(5) << matriz[i][j];
        }
        cout << endl;
    }
}

void Matriz::calcularInversa() {
    cout << "Método para calcular la inversa no implementado aún." << endl;
}
