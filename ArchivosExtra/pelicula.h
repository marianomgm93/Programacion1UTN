#ifndef PELICULA_H_INCLUDED
#define PELICULA_H_INCLUDED

typedef struct Pelicula{

int idPelicula;
char nombrePelicula[30];
char director[20];
char genero[20];
char pais[20];
int anio;
int valoracion;
int pm;
int eliminado;
}Pelicula;

Pelicula constructorPelicula(int idPelicula,char nombrePelicula[],char director[],char genero[],char pais[],int anio,int valoriacion, int pm);
void toString(Pelicula peli);

#endif // PELICULA_H_INCLUDED
