#ifndef MATRIZ_H
#define MATRIZ_H

class Matriz {
protected:
    double **matriz, **matrizId, **matrizInv, *vectorRt;
    double pivote;
    int filas, columnas;

    void inicializarMatriz(int filas, int columnas);

public:
    Matriz(int filas, int columnas);
    ~Matriz();

    void llenar();
    void mostrar();
    void calcularInversa();
};

#endif 
