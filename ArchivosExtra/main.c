#include <stdio.h>
#include <stdlib.h>
#include "pelicula.h"

//BUGGED
int main()
{
    char archivo[50]="peliculas";
    menuConstruirPelicula(archivo);
    mostrarArchivo(archivo);
    //altaOBaja(archivo,"leo");
    //mostrarArchivo(archivo);

    return 0;
}
