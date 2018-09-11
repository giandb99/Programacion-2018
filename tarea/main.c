#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char nombre[20];
    char apellido[20];
    char nombreCompleto[41]="";
    char aux[1024]; // o "buffer"
    int i;

    printf("Ingrese el nombre: ");
    fflush(stdin);
    gets(aux);
    while(strlen(aux)>19)
    {
        printf("\nReingrese el nombre: ");
        fflush(stdin);
        gets(aux);
    }

    strcpy(nombre,aux);

    printf("\nIngrese el apellido: ");
    fflush(stdin);
    gets(aux);
    while(strlen(aux)>19)
    {
        printf("\nReingrese el apellido: ");
        fflush(stdin);
        gets(aux);
    }

    strcpy(apellido,aux);

    strcat(nombreCompleto,apellido);
    strcat(nombreCompleto, ", ");
    strcat(nombreCompleto,nombre);

    strlwr(nombreCompleto);

    nombreCompleto[0]=toupper(nombreCompleto[0]);

    for(i=0;i<strlen(nombreCompleto);i++)
    {
        if(nombreCompleto[i]==' ')
        {
            nombreCompleto[i+1]=toupper(nombreCompleto[i+1]);
        }
    }

    printf("\n");

    puts(nombreCompleto);










    return 0;
}
/*

declarar 3 variables tipo cadena (char)
primeras 2 variables nombre y apellido (20 caracteres cada una)
la tercer variable se muestra apellido y nombre y despues mostrar;

(nombre Juan Carlos)
(apellido Gomez)
(apellidoynombre Gomez Juan Carlos)

*/
