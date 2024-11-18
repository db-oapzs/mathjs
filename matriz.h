#ifndef MATRIZ_H
#define MATRIZ_H

class Matriz {
protected:
    double **matriz, **matrizId, **matrizInv, *vectorRt;
    double pivote;
    int filas, columnas;
    int filasAux, columnasAux;
    bool entrada;

private:
    void setDatos();
    void llenarMatrices();
    void imprimirMatriz();

public:
    void proceso();
    void liberarRecursos();
	void inicializarMatrices();
    Matriz();
    ~Matriz();
};

#endif
