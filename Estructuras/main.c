#include <stdio.h>
#include <stdlib.h>
#include "stAlumno.h"
#include <conio.h>
#define DIM 30
#define IN 1
#define OUT 0

/**1.Hacer una función que cargue un arreglo de alumnos, hasta que el usuario lo decida*/
void cargarAlumnos(stAlumno arr[],int *validos){
    char nombre[DIM];
    int matricula,status=IN;
    char genero;
    char option;
    while(status){
    printf("Ingrese nombre del alumno\n");
    fflush(stdin);
    gets(nombre);
    printf("Ingrese matricula\n");
    scanf("%i",&matricula);
    printf("Ingrese genero m/f/o\n");
    fflush(stdin);
    scanf("%c",&genero);
    arr[*validos]=crearAlumno(matricula,nombre,genero);
    (*validos)++;
    printf("desea cargar otro alumno?\n0\tSalir\n1\tCargar nuevo\n");
    option=getch();
    if(option=='0')status=OUT;
    }
}
/**
*2.Hacer una función que muestre un arreglo de alumnos por pantalla. Modularizar.
*/
void mostrarArreglo(stAlumno arr[],int validos,int posInicial){
    for(int i=posInicial;i<validos;i++){
        alumnoToString(arr[i]);
    }

}
/**
*3.Hacer una función que muestre por pantalla los datos de un alumno, conociendo su matrícula. Modularizar.
*/
int buscarPorLegajo(stAlumno arr[],int validos,int legajo){
    int i=0;
    while(i<validos && )
}
int main()
{
    stAlumno alumnos[DIM];
    int validosAlumnos=0;
    cargarAlumnos(alumnos,&validosAlumnos);
    mostrarArreglo(alumnos,validosAlumnos,0);
    return 0;
}
