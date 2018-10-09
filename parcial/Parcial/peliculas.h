#ifndef PELICULAS_H_INCLUDED
#define PELICULAS_H_INCLUDED
#define VACIO 0
#define LLENO 1
#define CANTIDAD_PELICULAS 3

typedef struct
{
    char titulo[21];
    int fecha;
    char nacionalidad[21];
    char director[21];
    int estado;
    int id;

}ePelicula;

int menu();
int agregarUnaPelicula(ePelicula[],int);
void inicializarPelicula(ePelicula[],int,int);
int buscarLibre(ePelicula[],int,int);
int idF();
int buscarPeliculaPorId(ePelicula[],int,int);
int siguienteId(ePelicula[],int);
int modificarPelicula(ePelicula[],int);
int darPeliculaDeBaja(ePelicula[],int,int);
void mostrarPelicula(ePelicula[],int);

#endif // PELICULAS_H_INCLUDED
