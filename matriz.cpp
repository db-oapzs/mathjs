#include "matriz.h"
#include <iostream>
#include <iomanip> 
#include <cstdlib> 
using namespace std;

Matriz::Matriz() {
    this->filas = 1;
    this->columnas = 1;
    this->filasAux = 0;
	this->columnasAux = 0;
    this->inicializarMatrices();
}

Matriz::~Matriz() {
    this->liberarRecursos();
}

void Matriz::inicializarMatrices() {
    this->matriz = new double*[this->filas];
    this->matrizId = new double*[this->filas];
    this->matrizInv = new double*[this->filas];

    for (int i = 0; i < this->filas; i++) {
        this->matriz[i] = new double[this->columnas]{};
        this->matrizId[i] = new double[this->columnas]{};
        this->matrizInv[i] = new double[this->columnas]{};
    }

    this->vectorRt = new double[this->filas]{};
}

void Matriz::liberarRecursos() {
    if (this->matriz) {
        for (int i = 0; i < this->filas; i++) {
            delete[] this->matriz[i];
        }
        delete[] this->matriz;
        this->matriz = nullptr;
    }
    
    if (this->matrizId) {
        for (int i = 0; i < this->filas; i++) {
            delete[] this->matrizId[i];
        }
        delete[] this->matrizId;
        this->matrizId = nullptr;
    }

    if (this->matrizInv) {
        for (int i = 0; i < this->filas; i++) {
            delete[] this->matrizInv[i];
        }
        delete[] this->matrizInv;
        this->matrizInv = nullptr;
    }

    delete[] this->vectorRt;
    this->vectorRt = nullptr;
}

void Matriz::setDatos() {
    cout << "\n¿Su matriz es cuadrada? (S/n): ";
    char dt;
    cin >> dt;

    if (dt == 'S' || dt == 's') {
        cout << "Ingrese el tamaño de la matriz cuadrada (n x n): ";
        cin >> this->filas;
        this->columnas = this->filas;
    } else if (dt == 'N' || dt == 'n') {
        cout << "Ingrese el número de filas: ";
        cin >> this->filas;
        cout << "Ingrese el número de columnas: ";
        cin >> this->columnas;
    } else {
        cout << "\nOpción no válida. Usando matriz 1x1 por defecto.\n";
        this->filas = 1;
        this->columnas = 1;
    }

    if (this->filas <= 0 || this->columnas <= 0) {
        cout << "\nDimensiones no válidas. Usando matriz 1x1 por defecto.\n";
        this->filas = 1;
        this->columnas = 1;
    }
    
    
    
	this->filasAux = this->filas;
	this->columnasAux = this->columnas;
	
	if(this->filas > this->columnas){
		cout<<"\n filas mayores datos \n";
		this->columnas = this->filas;
	}else if(this->columnas > this->filas){
		cout<<"\n columnas mayores datos \n";
		this->filas = this->columnas;
	}else if(this->filas == this->columnas){
		cout<<"\n cuadrada datos \n";
	}
    
    int dt1Aux = this->filas;
    int dt2Aux = this->columnas;

    this->inicializarMatrices();
    
	for(int i = 0 ; i < this->filas ; i++){
		for(int j  = 0 ; j < this->columnas ; j++){
			this->matriz[i][j] = 0.0;
			this->matrizId[i][j] = 0.0;
			this->matrizInv[i][j] = 0.0;
			if(i == j) {
				this->matrizId[i][j] = 1.0;
			}
		}
			this->vectorRt[i] = 0.0;
	}
	
    
	this->filas = this->filasAux;
	this->columnas = this->columnasAux;
	this->filasAux = dt1Aux;
	this->columnasAux = dt2Aux;
}

void Matriz::llenarMatrices() {
	cout<<"\n\n\n___________________ Matriz ___________________\n\n\n";
	for(int i = 0 ; i < this->filasAux ; i++){
		for(int j  = 0 ; j < this->columnasAux ; j++){
			cout<<"  "<<this->matriz[i][j]<<"  ";
		}cout<<"\n";
	}
	cout<<"\n\n\n___________________ Matriz inverza ___________________\n\n\n";
	for(int i = 0 ; i < this->filasAux ; i++){
		for(int j  = 0 ; j < this->columnasAux ; j++){
			cout<<"  "<<this->matrizInv[i][j]<<"  ";
		}cout<<"\n";
	}
	cout<<"\n\n\n___________________ Matriz Identidad ___________________\n\n\n";
	for(int i = 0 ; i < this->filasAux ; i++){
		for(int j  = 0 ; j < this->columnasAux ; j++){
			cout<<"  "<<this->matrizId[i][j]<<"  ";
		}cout<<"\n";
	}
	cout<<"\n\n\n___________________ Vector Resultante ___________________\n\n\n";
	for(int i = 0 ; i < this->filasAux ; i++){
		cout<<"\n  "<<this->vectorRt[i]<<"  ";
	}
	cout<<"\n\n\n____________________________________________________________________________";
}

void Matriz::imprimirMatriz() {
}
void Matriz::proceso() {
    char dt;
    do {
        this->setDatos();
        this->llenarMatrices();
        
        
        
        cout << "\n¿Desea realizar un nuevo ejercicio? (S/n): ";
        cin >> dt;
        if (dt != 'S' && dt != 's' && dt != 'N' && dt != 'n') {
            cout << "\nEntrada no válida. Por favor, intente de nuevo.\n";
        }
        if (dt == 'S' || dt == 's') {
            system("cls"); 
        }
    	this->liberarRecursos();
    } while (dt == 'S' || dt == 's');
}
