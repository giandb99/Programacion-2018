#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{//strlen, strcpy, strcmp/stricmp, strupr, strlwr, puts, strcat;

    char cadena[20]="Perro";
    char cadena2[50]="GATO";
    int estado;

    strcat(cadena2,cadena); //-> sive para concatenar las cadenas;

    puts(cadena2); //-> muestra por consola;

    return 0;
}

/*
    char cadena[21]={'h','o','l','a'}; //="hola"; -> por extension;
    printf("Ingrese texto: ");
    //scanf("%s",&cadena); -> si pones esto, al escribir las palabras separadas solo te toma la primer palabra digitada;
    fflush(stdin);
    gets(cadena); // -> esto sirve para poder escribir las palabras separadas;

    printf("\n%s\n",cadena);
*/

/*
 char cadena[20]; //="perro";
    char cadena2[50]="gato";
    int cantidad;

    //cadena="perro";
    strcpy(cadena,cadena2);

    cantidad=strlen(cadena);

    printf("%d",cantidad);
*/

/*
//strlwr(cadena2); //-> muestra la palabra en minuscula;
    //strupr(cadena2); //->muestra la palabra en mayuscula;
*/
