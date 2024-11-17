#include <iostream>
#include <ctime>
#include <Windows.h>
#include "matriz.h"
using namespace std;









int main() {
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);

    srand(static_cast<unsigned int>(time(nullptr)));

    int filas = 3, columnas = 3;
    Matriz matriz(filas, columnas);

    cout << "Llenando la matriz...\n";
    matriz.llenar();

    cout << "Matriz generada:\n";
    matriz.mostrar();

    matriz.calcularInversa();

    cout << "\nPresione Enter para continuar...";
    cin.get();

    return EXIT_SUCCESS;
}