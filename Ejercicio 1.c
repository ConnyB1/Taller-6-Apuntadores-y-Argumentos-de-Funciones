#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int* crearArreglo(int n);
void imprimirArreglo(int *ptr, int n);
void multiplicarPorDos(int *ptr);
void sumarAElementos(int *ptr, int n, int valor);

int main() 
{
    srand(time(NULL));
    int x = 10, valorASumar = 5;
    int *ptr = &x, *arreglo;

    printf("Valor de x: %d\n", x);
    printf("ASpunta ptr: %d\n", *ptr);
    *arreglo = crearArreglo(7);

    multiplicarPorDos(ptr);
    printf("Valor de x después de multiplicar por dos: %d\n", x);
    printf("Elementos del arreglo: ");

    imprimirArreglo(arreglo, 7);
    sumarAElementos(arreglo, 7, valorASumar);
    printf("Arreglo modificado: ");
    imprimirArreglo(arreglo, 7);

    return 0;
}

int *crearArreglo(int n) 
{
    int *arr = (int*)malloc(n *sizeof(int));
    int numeros_usados[50] = {0}; 
    int contador = 0;

    while (contador < n) 
    {
        int num = 1 + rand() % 50 + 1; 
        if (!numeros_usados[num - 1]) 
        { 
            arr[contador] = num;
            numeros_usados[num - 1] = 1;
            contador++;
        }
    }
    return arr;
}

void imprimirArreglo(int *ptr, int n) 
{
    for (int i = 0; i < n; i++) 
    {
        printf("%d ", *ptr);
        ptr++;
    }
    printf("\n");
}

void multiplicarPorDos(int *ptr) 
{
    *ptr *= 2;
}

void sumarAElementos(int *ptr, int n, int valor) 
{
    for (int i = 0; i < n; i++) 
    {
        *ptr += valor;
        ptr++;
    }
}


