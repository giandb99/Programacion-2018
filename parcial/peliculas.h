typedef struct
{
    char titulo[51];
    int fecha;
    char nacionalidad[51];
    char director[51];
    int estado;
    int id;

}ePelicula;

ePelicula cargarUnaPelicula();
void cargarPelicula(ePelicula listado[],int tam);
void mostrarPelicula(ePelicula listado[],int tam);
void modificarPelicula(ePelicula listado[], int tam);
void iniciarPelicula(ePelicula listado[],int tam, int valor);
int buscarLibre(ePelicula listado[],int tam);
int siguienteId(ePelicula listado[],int tam);
int buscarPorId(ePelicula listado[] ,int tam, int id);
