#include <stdio.h>
#include <stdlib.h>
#define IN 1
#define OUT 0
#define DIM 30;
void agregarAlumno(char nombres[][DIM],int legajos[],int anios[],int* validos){
    char nombre[];
    int edad,legajo;
    printf("Ingrese el nombre del alumno num %i\n",*validos);
    fflush(stdin);
    gets(nombre);
    printf("Ingrese la edad del alumno num %i\n",*validos);
    scanf("%i",&edad);
    printf("Ingrese el legajo del alumno num %i\n",*validos);
    scanf("%i",&legajo);
    strcpy(nombres[validos],nombre);
    anios[validos]=edad;
    legajos[validos]=legajo;
    (*validos)++;

}
void cargarAlumnos(char nombres[][DIM],int legajos[],int anios[],int* validos){
    int status=IN,option;
    while(status){
        printf("1\tAgregar nuevo Alumno\n0\tSalir\n");
        scanf("%i",&option);
    switch(option)
        case 0:
        status=OUT;
        break;
        case 1:
        agregarAlumno(nombres,legajos,anios,validos);
        break;
    }

}


int main()
{
int legajos[20];
char nombres[20][30];
int anios[20];
int validos=0;


    return 0;
}
