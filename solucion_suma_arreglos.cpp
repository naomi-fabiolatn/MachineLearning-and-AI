
#include <iostream>
#include <omp.h>
#include <cstdlib>
#include <ctime>

#define SIZE 1000 // Tamaño del arreglo

using namespace std;

int main()
{
    int arr1[SIZE], arr2[SIZE], result[SIZE];
    int opcion;

    cout << "¿Como desea inicializar los arreglos?\n";
    cout << "1. Valores aleatorios\n";
    cout << "2. Ingresar valores manualmente\n";
    cout << "Seleccione una opcion: ";
    cin >> opcion;

    if (opcion == 1)
    {
        srand(time(0));
        for (int i = 0; i < SIZE; i++)
        {
            arr1[i] = rand() % 100;
            arr2[i] = rand() % 100;
        }
    }
    else if (opcion == 2)
    {
        cout << "Ingrese los valores para el primer arreglo: \n";
        for (int i = 0; i < SIZE; i++)
        {
            cout << "arr1[" << i << "]: ";
            cin >> arr1[i];
        }
        cout << "Ingrese los valores para el segundo arreglo:\n";
        for (int i = 0; i < SIZE; i++)
        {
            cout << "arr2[" << i << "]: ";
            cin >> arr2[i];
        }

    }
    else
    {
        cout << "Opción invalida. Saliendo del programa.\n";
        return 1;
    }
    // Sumar los arreglos en paralelo
#pragma omp parallel for 
    for (int i = 0; i < SIZE; i++)
    {
        result[i] = arr1[i] + arr2[i];
    }
    // Imprimir los primeros elementos de los arreglos para verificar
    cout << "\nPrimeros 10 elementos de arr1:\n";
    for (int i = 0; i < 10; i++)
    {
        cout << arr1[i] << " ";

    }
    cout << "\nPrimeros 10 elementos de arr2:\n";
    for (int i = 0; i < 10; i++)
    {
        cout << arr2[i] << " ";

    }
    cout << "\nPrimeros 10 elementos del arreglo resultante:\n";
    for (int i = 0; i < 10; i++)
    {
        cout << result[i] << " ";
    }

    cout << "\n\nProceso completado con exito.\n";
    return 0;
}

