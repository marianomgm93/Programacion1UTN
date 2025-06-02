#include <stdio.h>
#include <stdlib.h>
#include "pelicula.h"

int main()
{
    char archivo[50]="peliculas";
    //menuConstruirPelicula(archivo);
    //altaOBaja(archivo,"leo");
    //mostrarArchivo(archivo);

    Pelicula peli=BuscarPorNombre(archivo,"Titanic");
    toString(peli);

    altaOBaja(archivo,"Titanic");
    mostrarArchivo(archivo);

    return 0;
}
