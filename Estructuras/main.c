#include <stdio.h>
#include <stdlib.h>
#include "stAlumno.h"
#include <conio.h>
#define DIM 30
#define IN 1
#define OUT 0

/**1.Hacer una función que cargue un arreglo de alumnos, hasta que el usuario lo decida*/
void cargarAlumnos(stAlumno arr[],int *validos)
{
    char nombre[DIM];
    int matricula,status=IN;
    char genero;
    char option;
    while(status)
    {
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
void mostrarArreglo(stAlumno arr[],int validos,int posInicial)
{
    for(int i=posInicial; i<validos; i++)
    {
        alumnoToString(arr[i]);
    }

}
/**
*3.Hacer una función que muestre por pantalla los datos de un alumno, conociendo su matrícula. Modularizar.
*/
int buscarPorMatricula(stAlumno arr[],int validos,int matriculaABuscar)
{
    int i=0;
    while(i<validos && arr[i].matricula!=matriculaABuscar)
        i++;
    if(i<validos)
        return i;
    else
        return -1;
}
void buscarAlumno(stAlumno arr[],int validos)
{
    int matriculaABuscar;
    int posicion;
    printf("Ingrese la matricula del alumno que desea buscar\n");
    scanf("%i",&matriculaABuscar);
    posicion=buscarPorMatricula(arr,validos,matriculaABuscar);
    if(posicion!=-1)
        mostrarArreglo(arr,posicion+1,posicion);
    else
        printf("La matricula no existe en nuestra base de datos\n");

}
/**4.Hacer una función que ordene el arreglo de alumnos
*por medio del método de selección. El criterio de ordenación es el número de matrícula.
*/
int buscarMenorMatricula(stAlumno arr[],int validos,int posInicial)
{
    int posicionMenor=posInicial;
    for(int i=posInicial; i<validos; i++)
    {
        if(arr[i].matricula<arr[posicionMenor].matricula)
            posicionMenor=i;
    }
    return posicionMenor;
}
void ordenamientoPorSeleccion(stAlumno arr[],int validos)
{
    stAlumno aux;
    int posicion;
    for(int i=0; i<validos; i++)
    {
        aux=arr[i];
        posicion=buscarMenorMatricula(arr,validos,i);
        arr[i]=arr[posicion];
        arr[posicion]=aux;
    }
}
/**5.Hacer una función que muestre por pantalla los datos de los
*estudiantes de un género determinado (se envía por parámetro). Modularizar.
*/
void filtrarPorGenero(stAlumno arr[],int validos,char generoBuscado)
{
    for(int i=0; i<validos; i++)
    {
        if(arr[i].genero==generoBuscado)
        {
            alumnoToString(arr[i]);
        }
    }

}
/**6.Hacer una función que inserte en un arreglo ordenado por matrícula un
*nuevo dato, conservando el orden.
*/
void insertarNuevo(stAlumno arr[],int validos,stAlumno nuevoAlumno)
{
    int i=validos-1;
    while(arr[i].matricula>nuevoAlumno.matricula && i>=0)
    {
        arr[i+1]=arr[i];
        i--;
    }
    arr[i+1]=nuevoAlumno;
}
/**7.Hacer una función que ordene el arreglo de alumnos por medio
*del método de inserción. El criterio de ordenación es el nombre.
*/
void OrdenamientoPorInsercion(stAlumno arr[],int validos)
{
    stAlumno aux;
    for(int i=1; i<validos; i++)
    {
        aux=arr[i];
        insertarNuevo(arr,i,aux);
    }

}
/**8.Hacer una función que cuente y retorne la cantidad de estudiantes de
*un género determinado (se envía por parámetro) que tiene un arreglo de alumnos.
*/
int contarPorGenero(stAlumno arr[],int validos,char generoBuscado)
{
    int contador=0;
    for(int i=0; i<validos; i++)
    {
        if(arr[i].genero==generoBuscado)
        {
            contador++;
        }
    }
    return contador;
}
int main()
{

    stAlumno alumnos[DIM];
    int validosAlumnos=0,status=IN;
    char option;
    //mostrarArreglo(alumnos,validosAlumnos,0);
    mostrarArreglo(alumnos,validosAlumnos,0);
    while(status)
    {
        printf("0\tSalir\n1\tCargar Alumnos\n2\tMostrar Arreglo\n3\tBuscar Alumno\n4"
               "\tOrdenar por seleccion\n5\tFiltrar por Genero\n6\tOrdenar por Insercion\n7\tContar por genero\n");
        option=getch();
        switch(option)
        {
        case '0':
            status=OUT;
            break;
        case '1':
            cargarAlumnos(alumnos,&validosAlumnos);
            break;
        case '2':
            mostrarArreglo(alumnos,validosAlumnos,0);
            break;
        case '3':
            buscarAlumno(alumnos,validosAlumnos);
            break;
        case '4':
            ordenamientoPorSeleccion(alumnos,validosAlumnos);
            break;
        case '5':
            printf("Seleccione genero m/f/o\n");
            option=getch();
            switch(tolower(option))
            {
            case 'm':
                filtrarPorGenero(alumnos,validosAlumnos,'m');
                break;
            case 'f':
                filtrarPorGenero(alumnos,validosAlumnos,'f');
                break;
            case 'o':
                filtrarPorGenero(alumnos,validosAlumnos,'o');
                break;
            }
            break;
        case '6':
            OrdenamientoPorInsercion(alumnos,validosAlumnos);
            break;
        case '7':
            printf("Seleccione genero m/f/o\n");
            option=getch();
            switch(tolower(option))
            {
            case 'm':
                printf("%i\n",contarPorGenero(alumnos,validosAlumnos,'m'));
                break;
            case 'f':
                printf("%i\n",contarPorGenero(alumnos,validosAlumnos,'f'));
                break;
            case 'o':
                printf("%i\n",contarPorGenero(alumnos,validosAlumnos,'o'));
                break;
            }
            break;
        default:
            printf("El caracter ingresado es incorrecto, intentelo nuevamente\n");
            break;
        }
    }
    return 0;
}
