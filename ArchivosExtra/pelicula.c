#include <stdio.h>
#include "pelicula.h"
#include <string.h>
int idActual(char nombreArchivo[])
{
    int id=0;
    FILE* buffer=fopen(nombreArchivo,"rb");
    if(buffer)
    {
        fseek(buffer,0,SEEK_END);
        id = ftell(buffer)/sizeof(Pelicula);
        fclose(buffer);
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
void menuConstruirPelicula(char nombreArchivo[])
{
    char nombrePeli[30];
    char director[20];
    char genero[20];
    char pais[20];
    int anio,valoracion,pm,idPelicula;
    Pelicula pelicula;
    idPelicula=idActual(nombreArchivo);
    printf("Ingrese el nombre de la pelicula\n");
    fflush(stdin);
    gets(&nombrePeli);

    if(validarNombre(nombrePeli,nombreArchivo)==-1)
    {
        strcpy(pelicula.nombrePelicula,nombrePeli);
        printf("Ingrese el nombre del Director\n");
        fflush(stdin);
        gets(&director);

        printf("Ingrese el Genero\n");
        fflush(stdin);
        gets(&genero);

        printf("Ingrese el Pais\n");
        fflush(stdin);
        gets(&pais);

        printf("Ingrese el anio\n");
        scanf("%i",&anio);

        printf("Ingrese la valoracion\n");
        scanf("%i",&valoracion);

        printf("Ingrese el PM  (0- si es ATP / 13: mayor de trece /  16: mayor de 16 / 18: mayor de 18)\n");
        scanf("%i",&pm);

        pelicula=constructorPelicula(idPelicula,nombrePeli,director,genero,pais,anio,valoracion,pm);
        archivarPelicula(nombreArchivo,pelicula);
    }
    else
    {
        printf("La pelicula ya se encuentra en el archivo");
    }
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
    }else{
    printf("No existe archivo\n");
    }

    return existe;
}

void toString(Pelicula peli)
{
    printf("...................................\n");
    printf("Pelicula: %i\n",peli.idPelicula);
    printf("Nombre: %s\n",peli.nombrePelicula);
    printf("Director: %s\n",peli.director);
    printf("Pais: %s\n",peli.pais);
    printf("Anio: %i\n",peli.anio);
    printf("Valoracion: %i\n",peli.valoracion);
    printf("Pm: %i\n",peli.pm);
    printf("Eliminado: %i\n",peli.eliminado);
    printf("...................................\n");
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
void altaOBaja(char nombreArchivo[],char nombrePeli[])
{
    FILE* buffer=fopen(nombreArchivo,"r+b");
    Pelicula peli;
    int flag=0;
    if(buffer)
    {
        while(fread(&peli,sizeof(Pelicula),1,buffer)>0 && flag==0)
        {
            if(strcmpi(peli.nombrePelicula,nombrePeli)==0)
            {
                peli.eliminado=(peli.eliminado>0) ? 0 : 1;
                printf("\n%s\n",nombrePeli);
                fseek(buffer,(-1)*sizeof(Pelicula),SEEK_CUR);
                fwrite(&peli,sizeof(Pelicula),1,buffer);
                flag=1;
//                toString(peli);
            }
        }
        fclose(buffer);
    }
    mostrarArchivo(nombreArchivo);
}
void mostrarArchivo(char nombreArchivo[])
{
    FILE* buffer=fopen(nombreArchivo,"rb");
    Pelicula peli;
    if(buffer)
    {
        while(fread(&peli,sizeof(Pelicula),1,buffer)>0)
        {
            //if(peli.eliminado==0)
            //{
                toString(peli);
            //}
        }
        fclose(buffer);
    }
}
