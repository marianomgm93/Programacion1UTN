#include <stdio.h>
#include "pelicula.h"
#include <string.h>
int idActual()
{
    int id=0;
    FILE* buffer=fopen(nombreArchivo,"rb");
    if(buffer)
    {
        fseek(buffer,0,SEEK_END)
        id = ftell(buffer);
    }
    return id;
}
Pelicula constructorPelicula(int idPelicula,char nombrePelicula[],char director[],char genero[],char pais[],int anio,int valoriacion, int pm)
{

    Pelicula pelicula;
    pelicula.idPelicula=idPelicula;
    strcpy(pelicula.nombrePelicula,nombrePelicula);
    strcpy(pelicula.director,director);
    strcpy(pelicula.genero,genero);
    strcpy(pelicula.pais,pais);
    pelicula.anio=anio;
    pelicula.valoracion=valoriacion;
    pelicula.pm=pm;
    pelicula.eliminado=0;
    return pelicula;
}
Pelicula menuConstruirPelicula(char nombreArchivo[])
{
    char nombrePeli[30];
    char director[20];
    char genero[20];
    char pais[20];
    int anio,valoracion,pm;
    Pelicula pelicula;
    pelicula.idPelicula=idActual();
    printf("Ingrese el nombre de la pelicula\n");
    fflush(stdin);
    gets(&nombrePeli);
    strcpy(pelicula.nombrePelicula,nombrePeli);
    printf("Ingrese el nombre del Director\n");
    fflush(stdin);
    gets(&director);
    strcpy(pelicula.director,director);

    printf("Ingrese el Genero\n");
    fflush(stdin);
    gets(&genero);
    strcpy(pelicula.genero,genero);

    printf("Ingrese el Pais\n");
    fflush(stdin);
    gets(&pais);
    strcpy(pelicula.pais,pais);

    printf("Ingrese el anio\n");
    scanf("%i",&anio);
    pelicula.anio=anio;

    printf("Ingrese la valoracion\n");
    scanf("%i",&valoracion);
    pelicula.valoracion=valoriacion;

    printf("Ingrese el PM  (0- si es ATP / 13: mayor de trece /  16: mayor de 16 / 18: mayor de 18)\n");
    scanf("%i",&pm);
    pelicula.pm=pm;
    pelicula.eliminado=0;
}
/**
*Retorna -1 si el nombre no existe en el archivo.
*/
int validarNombre(char nombrePeli[],char nombreArchivo[])
{
    FILE* buffer=fopen(nombreArchivo,"rb");
    Pelicula peli;
    int existe=-1;
    if(buffer)
    {
        while(fread(&peli,sizeof(Pelicula),1,buffer)>0 && existe==-1)
        {
            if(strcmpi(peli.nombrePelicula,nombrePeli)==0)
            {
                existe=peli.idPelicula;
            }
        }

        fclose(buffer);
    }

    return existe;
}

void toString(Pelicula peli)
{
    printf("...................................");
    printf("Pelicula: %i\n",peli.idPelicula);
    printf("Nombre: %s\n",peli.nombrePelicula);
    printf("Director: %s\n",peli.director);
    printf("Pais: %s\n",peli.pais);
    printf("Anio: %i\n",peli.anio);
    printf("Valoracion: %i\n",peli.valoracion);
    printf("Pm: %i\n",peli.pm);
    printf("...................................");
}
void archivarPelicula(char nombreArchivo[],Pelicula pelicula)
{
    FILE* buffer=fopen(nombreArchivo,"ab");
    if(buffer)
    {
        fwrite(&pelicula,sizeof(Pelicula),1,buffer);
        fclose(buffer);
    }
    else
        printf("El archivo no pudo abrirse correctamente error 334219\n");
}
