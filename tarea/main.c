#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char nombre[20];
    char apellido[20];
    char apellidoYNombre;

    printf("Ingrese el nombre: ");
    gets(nombre);

    printf("\nIngrese el apellido: ");
    gets(apellido);

    printf("\nApellido y nombre: %s %s",apellido,nombre);
    printf("\n");

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
