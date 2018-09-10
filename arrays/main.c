#include <stdio.h>
#include <stdlib.h>

int inicializarVector(int vectorA[],int cantidad,int valorInicial);
int mostrarVector(int vectorA[],int cantidad, int valorInicial);
void cargarYMostrar(int vectorA[],int cantidad,int valorInicial);

int main()
{
    int valorInicial=-1;
    int vector[5];
    int cantidad=5;

    cargarYMostrar(vector[5],cantidad,valorInicial);

    return 0;
}

int inicializarVector(int vectorA[],int cantidad,int valorInicial)
{
    for(; cantidad>0;cantidad--)
    {
        vectorA[cantidad]=valorInicial;
    }
}

int mostrarVector(int vectorA[],int cantidad,int valorInicial)
{
    for(; cantidad>0;cantidad--)
    {
        vectorA[cantidad]=valorInicial++;
        printf("%d\n",vectorA[cantidad]);
    }
}

void cargarYMostrar(int vectorA[],int cantidad,int valorInicial)
{
    inicializarVector(vectorA,cantidad,valorInicial);
    mostrarVector(vectorA,cantidad,valorInicial);
}
