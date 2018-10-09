#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "peliculas.h"
/*
#define CANTIDAD_DIRECTORES 2
#include "directores.h"
*/

int menu()
{
    int opcion;
    int auxLibre;
    int auxId;
    int bandera;

    bandera=0;

    ePelicula listado[CANTIDAD_PELICULAS];
    inicializarPelicula(listado,CANTIDAD_PELICULAS,-1);

    do
    {
        printf("1. Alta de pelicula\n2. Modificar pelicula\n3. Dar de baja una pelicula\n6. Mostrar listado\n7. Salir\n");
        printf("\nIngrese una opcion: ");
        fflush(stdin);
        opcion= getchar();

        switch(opcion)
        {
            case '1':
                auxLibre=buscarLibre(listado,CANTIDAD_PELICULAS,-1);
                if(auxLibre==-1)
                {
                    printf("\nNo hay mas lugar disponible\n");
                    system("pause");
                    system("cls");
                }
                else
                {
                    system("pause");
                    system("cls");
                    agregarUnaPelicula(listado,auxLibre);
                    bandera=1;
                }
                break;

            case '2':
                if(bandera==1)
                {
                    system("pause");
                    system("cls");
                    auxId=idF();
                    buscarPeliculaPorId(listado,CANTIDAD_PELICULAS,auxId);
                }
                else
                {
                    printf("\nError. Primero debe dar de alta una pelicula\n\n");
                    system("pause");
                    system("cls");
                }
                break;

            case '3':
                if(bandera==1)
                {
                    system("pause");
                    system("cls");
                    auxId=idF();
                    darPeliculaDeBaja(listado,CANTIDAD_PELICULAS,auxId);
                }
                else
                {
                    printf("\nError. Primero debe dar de alta una pelicula.\n\n");
                    system("pause");
                    system("cls");
                }
                break;

            case '6':
                if(bandera==1)
                {
                    system("pause");
                    system("cls");
                    mostrarPelicula(listado,CANTIDAD_PELICULAS);
                }
                else
                {
                    printf("\nError. Primero debe dar de alta una pelicula\n\n");
                    system("pause");
                    system("cls");
                }
                break;

            case '7':
                break;

            default:
                printf("\nPor favor ingrese una opcion valida\n\n");
                system("pause");
                system("cls");
        }

    }while(opcion!='7');

    return 0;
}

int idF()
{
    int id;
    printf("\nIngrese el ID: ");
    scanf("%d",&id);
    return id;
}

void inicializarPelicula(ePelicula listado[],int tam,int valor)
{
    int i;
    for(i=1;i<=tam;i++)
    {
        listado[i].estado=valor;
    }
}

int buscarLibre(ePelicula listado[],int tam,int valor)
{
    int i;
    for(i=1;i<=tam;i++)
    {
        if(listado[i].estado==valor)
        {
            return i;
        }
    }
    return -1;
}

int agregarUnaPelicula(ePelicula listado[],int auxLibre)
{
    int i;

    i=auxLibre;
    listado[i].id=auxLibre;

    printf("\nEl id de la pelicula es: %d\n",auxLibre);
    fflush(stdin);

    printf("\nIngrese titulo: ");
    fflush(stdin);
    gets(listado[i].titulo);

    printf("\nIngrese fecha: ");
    scanf("%d",&listado[i].fecha);

    while(listado[i].fecha<1850||listado[i].fecha>2018)
    {
        printf("\nError.Reingrese fecha: ");
        scanf("%d",&listado[i].fecha);
    }

    printf("\nIngrese nacionalidad: ");
    fflush(stdin);
    gets(listado[i].nacionalidad);

    printf("\nIngrese director: ");
    fflush(stdin);
    gets(listado[i].director);

    printf("\nLa pelicula fue dada de alta correctamente.\n\n");

    system("pause");
    system("cls");

    listado[i].estado=0;

    return 0;
}

int buscarPeliculaPorId(ePelicula listado[],int tam,int id)
{
    int i;
    int opcion;

    for(i=1;i<tam;i++)
    {
        if(id==listado[i].id&&listado[i].estado==0)
        {
            printf("\nSe puede modificar la pelicula.\n");

            do
            {
                printf("\n1. Modificar titulo\n2. Modificar fecha\n3. Modificar nacionalidad\n4. Modificar director\n");
                printf("\nQue desea modificar? Elija una opcion: ");
                fflush(stdin);
                opcion=getchar();

                switch(opcion)
                {
                    case '1':
                        printf("\nIngrese el nuevo titulo: ");
                        fflush(stdin);
                        gets(listado[i].titulo);
                        printf("\nEl titulo se ha modificado correctamete\n");
                        system("pause");
                        system("cls");
                        break;

                    case '2':
                        printf("\nIngrese la nueva fecha: ");
                        fflush(stdin);
                        scanf("%d",&listado[i].fecha);
                        printf("\nLa fecha se ha modificado correctamete\n");
                        system("pause");
                        system("cls");
                        break;

                    case '3':
                        printf("\nIngrese la nueva nacionalidad: ");
                        fflush(stdin);
                        gets(listado[i].nacionalidad);
                        printf("\nLa nacionalidad se ha modificado correctamete\n");
                        system("pause");
                        system("cls");
                        break;

                    case '4':
                        printf("\nIngrese el nuevo director: ");
                        fflush(stdin);
                        gets(listado[i].director);
                        printf("\nEl director se ha modificado correctamete\n");
                        system("pause");
                        system("cls");
                        break;

                    default:
                        printf("\nPor favor ingrese una opcion valida\n\n");
                        system("pause");
                        system("cls");
                }

            }while(opcion<'1'||opcion>'4');
        }
    }
    return 0;
}

int darPeliculaDeBaja(ePelicula listado[],int tam,int id)
{
    int i;
    for(i=1;i<tam;i++)
    {
        if(id==listado[i].id&&listado[i].estado==0)
        {
            printf("\nLa pelicula %s fue dada de baja.\n",listado[i].titulo);
            listado[i].estado=1;
        }
    }
    system("pause");
    system("cls");
    return 0;
}

void mostrarPelicula(ePelicula listado[],int tam)
{
    int i;

     printf("\n---%4s---%7s---%6s---%20s---%20s\n","ID","Nombre","Apellido","Salario","Sector");

    for(i=1;i<tam;i++)
    {
        printf("\n---%4d---%7s---%6d---%20s---%20s\n",listado[i].id,listado[i].titulo,listado[i].fecha,listado[i].nacionalidad,listado[i].director);
    }
    system("pause");
    system("cls");
}


