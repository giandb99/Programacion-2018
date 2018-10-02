#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define CANTIDAD_PELICULAS 2
#define CANTIDAD_DIRECTORES 2
#include "directores.h"
#include "peliculas.h"
#define LLENO 1
#define VACIO 0

ePelicula cargarUnaPelicula()
{
    ePelicula miPelicula;
    char respuesta='s';

    printf("\nIngrese titulo: ");
    fflush(stdin);
    gets(miPelicula.titulo);

    printf("\nIngrese fecha: ");
    scanf("%d",&miPelicula.fecha);
    while(miPelicula.fecha<1850||miPelicula.fecha>2018)
    {
        printf("\nError.Reingrese fecha: ");
        scanf("%d",&miPelicula.fecha);
    }
    printf("\nIngrese nacionalidad: ");
    fflush(stdin);
    gets(miPelicula.nacionalidad);

    printf("\nIngrese director: ");
    fflush(stdin);
    gets(miPelicula.director);

    printf("\nDesea ingresar otra pelicula? [s/n]: ");
    scanf("%c",&respuesta);

    while(respuesta=='s')
    {
        cargarUnaPelicula();
    }

    return miPelicula;
}

void cargarPelicula(ePelicula listado[],int tam)
{
    int i;
    for(i=0;i<tam;i++)
    {
       listado[i]=cargarUnaPelicula();
    }
}

void mostrarPelicula(ePelicula listado[],int tam)
{
    int i;
    for(i=0;i<tam;i++)
    {
        printf("\n");
        printf("El titulo es: %s\n",listado[i].titulo);
        printf("La fecha es: %d\n",listado[i].fecha);
        printf("El nacionalidad es: %s\n",listado[i].nacionalidad);
        printf("El director es: %s\n",listado[i].director);
    }
}

int inicializarPelicula(ePelicula listado[],int tam)
{
    int retorno = -1;
    int i;
    if(tam > 0 && listado != NULL)
    {
        retorno = 0;
        for(i=0; i<tam; i++)
        {
            listado[i].estado= VACIO;
            listado[i].id= 1;
        }
    }
    return retorno;
}

int buscarLibre(ePelicula listado[],int tam)
{
    int retorno = -1;
    int i;
    if(tam > 0 && listado != NULL)
    {
        retorno = -2;
        for(i=0;i<tam;i++)
        {
            if(listado[i].estado == VACIO)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}

int siguienteId(ePelicula listado[],int tam)
{
    int retorno = 0;
    int i;
    if(tam > 0 && listado != NULL)
    {
        for(i=0; i<tam; i++)
        {
            if(listado[i].estado == LLENO)
            {
                    if(listado[i].id>retorno)
                    {
                         retorno=listado[i].id;
                    }
            }
        }
    }
    return retorno+1;
}

int buscarPorId(ePelicula listado[] ,int tam, int id)
{
    int retorno = -1;
    int i;
    if(tam > 0 && listado != NULL)
    {
        retorno = -2;
        for(i=0;i<tam;i++)
        {
            if(listado[i].estado == VACIO && listado[i].id == id)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}

void modificarPelicula(ePelicula listado[], int tam)
{
    ePelicula miPelicula;
    int id;
    int i;
    int opcion;
    char respuesta='s';

    printf("\nIngrese un id a buscar: ");
    scanf("%d",&id);

    for(i=0;i<tam;i++)
    {
        do
        {
            printf("\n1. Modificar titulo\n2. Modificar fecha\n3. Modificar nacionalidad\n4. Modificar director\n");
            printf("Que desea modificar? Elija una opcion: ");
            opcion = getchar();
            switch(opcion)
            {
            case '1':
                    printf("Estas Seguro? [s/n]: ");
                    while(respuesta=='s')
                    {
                        printf("\nIngrese el nuevo titulo: ");
                        fflush(stdin);
                        gets(miPelicula.titulo);
                    }
                    break;
            case '2':
                    printf("\nIngrese la nueva fecha: ");
                    scanf("%d",&miPelicula.fecha);
                    break;
            case '3':
                    printf("\nIngrese la nueva nacionalidad: ");
                    fflush(stdin);
                    gets(miPelicula.nacionalidad);
                    break;
            case '4':
                    printf("\nIngrese el nuevo director: ");
                    fflush(stdin);
                    gets(miPelicula.director);
                    break;
                }
            } while(id==listado[i].id);
    }
}
