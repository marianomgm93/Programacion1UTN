#include <stdio.h>
#include <stdlib.h>
#include "pelicula.h"


int main()
{
    char archivo[]="peliculas";
    //menuConstruirPelicula(archivo);
    mostrarArchivo(archivo);
    altaOBaja(archivo,"Titanic");

    return 0;
}
