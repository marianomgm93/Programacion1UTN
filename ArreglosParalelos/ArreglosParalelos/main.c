#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define IN 1
#define OUT 0
#define DIM 30
//1
void agregarAlumno(char nombres[][DIM],int legajos[],int anios[],int* validos)
{
    char nombre[DIM];
    int edad,legajo;
    printf("Ingrese el nombre del alumno num %i:\n",*validos);
    fflush(stdin);
    scanf("%s",nombre);
    printf("Ingrese la edad del alumno num %i:\n",*validos);
    fflush(stdin);
    scanf("%i",&edad);
    printf("Ingrese el legajo del alumno num %i:\n",*validos);
    fflush(stdin);
    scanf("%d",&legajo);
    strcpy(nombres[*validos],nombre);
    anios[*validos]=edad;
    legajos[*validos]=legajo;
    (*validos)++;

}
void cargarAlumnos(char nombres[][DIM],int legajos[],int anios[],int* validos)
{
    int status=IN,option;
    while(status)
    {
        printf("1\tAgregar nuevo Alumno\n0\tSalir\n");
        scanf("%i",&option);
        switch(option)
        {
        case 0:
            status=OUT;
            break;
        case 1:
            agregarAlumno(nombres,legajos,anios,validos);
            break;
        }
    }

}
//2
void mostrarArreglo(char nombres[][DIM],int legajo[],int anios[],int validos, int posInicial)
{
    printf("NOMBRE\tEDAD\tLEGAJO\n");

    for(int i=posInicial; i<validos; i++)
    {
        printf("%s\t%i\t%d\n",nombres[i],anios[i],legajo[i]);

    }

}
//3
int buscarLegajo(int legajos[],int validos,int legajo)
{
    int i=0;
    int posicion=-1;
    while(i<validos && legajos[i]!=legajo)
    {
        i++;
    }
    if(i<validos)
    {
        posicion=i;
    }
    return posicion;

}
//4
void filtrarPorLegajo(char nombres[][DIM],int anios[],int legajos[],int validos){
    int legajoABuscar,posicion;
    printf("Ingrese el legajo a buscar\n");
    scanf("%d",&legajoABuscar);
    posicion=buscarLegajo(legajos,validos,legajoABuscar);
    if(posicion<0){
        printf("El legajo a solicitado, no se encuentra en el sistema");
    }else{
        mostrarArreglo(nombres,legajos,anios,posicion+1,posicion);
    }
}
//5
int buscarMenor(char nombres [][DIM],int validos,int posicionInicial){
    int posicionMenor=posicionInicial;

    for(int i=posicionInicial;i<validos;i++){
        if(strcmp(nombres[i],nombres[posicionMenor])<0){
            posicionMenor=i;
        }
    }
    return posicionMenor;
}
void ordenamientoPorSeleccion(char nombres[][DIM],int legajos[],int anios[],int validos){
    int posMenor;
    char nombreAux[DIM];
    int legajoAux;
    int edadAux;
    for(int i=0;i<validos;i++){
        strcpy(nombreAux,nombres[i]);
        legajoAux=legajos[i];
        edadAux=anios[i];
        posMenor=buscarMenor(nombres,validos,i);
        printf("%i\n",posMenor);
        strcpy(nombres[i],nombres[posMenor]);
        legajos[i]=legajos[posMenor];
        anios[i]=anios[posMenor];
        strcpy(nombres[posMenor],nombreAux);
        legajos[posMenor]=legajoAux;
        anios[posMenor]=edadAux;
    }

}
void ordenamientoPorInsercion(char nombres[][DIM],int legajos[],int anios[],int validos){
    for(int i=0;i<validos-1;i++){
        insertar(nombres,legajos,anios,i);
    }

}
void insertar(char nombres[][DIM],int legajos[],int anios[],int posicionInicial){
    int u=posicionInicial,legajoAux,edadAux;

    char nombreAux[DIM];
    strcpy(nombreAux,nombres[u+1]);
    legajoAux=legajos[u+1];
    edadAux=anios[u+1];
    while(u>=0 && strcmp(nombres[u],nombreAux)>0){
        strcpy(nombres[u+1],nombres[u]);
        legajos[u+1]=legajos[u];
        anios[u+1]=anios[u];
    u--;
    }
        strcpy(nombres[u+1],nombreAux);
        legajos[u+1]=legajoAux;
        anios[u+1]=edadAux;
}
int main()
{
    int legajos[20];
    char nombres[20][30];
    int anios[20];
    int validos=0;
    cargarAlumnos(nombres,legajos,anios,&validos);
    mostrarArreglo(nombres,legajos,anios,validos,0);
    //filtrarPorLegajo(nombres,anios,legajos,validos);
    //ordenamientoPorSeleccion(nombres,legajos,anios,validos);
    //mostrarArreglo(nombres,legajos,anios,validos,0);
    ordenamientoPorInsercion(nombres,legajos,anios,validos);
    mostrarArreglo(nombres,legajos,anios,validos,0);
    return 0;
}
