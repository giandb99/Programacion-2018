#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define CANTIDAD_PELICULAS 1
//#define CANTIDAD_DIRECTORES 2
#include "directores.h"
#include "peliculas.h"


int main()
{
    ePelicula listado[CANTIDAD_PELICULAS];

    int bandera=0;

    printf("1. Alta de pelicula\n2. Modificar pelicula\n6. Mostrar listado\n7. Salir\n");
    int opcion='7';
    do
    {
        printf("\nIngrese una opcion: ");
        fflush(stdin);
        opcion= getchar();

        switch(opcion)
        {
                case '1':
                    cargarPelicula(listado,CANTIDAD_PELICULAS);
                    bandera=1;
                    break;

                case '2':
                    if(bandera==0)
                    {
                        printf("\nError. Primero debe dar de alta una pelicula\n");
                    }
                    else
                    {
                        modificarPelicula(listado,CANTIDAD_PELICULAS);
                    }
                    break;

                case '6':
                    if(bandera==0)
                    {
                        printf("\nError. Primero debe dar de alta una pelicula\n");
                    }
                    else
                    {
                        mostrarPelicula(listado,CANTIDAD_PELICULAS);
                    }
                    break;
                default:
                    printf("\nPor favor ingrese una opcion valida\n");
        }

    }while(opcion!='7');

    return 0;
}
