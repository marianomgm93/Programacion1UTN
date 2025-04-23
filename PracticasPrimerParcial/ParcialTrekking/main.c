#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pila.h"
#define IN 1
#define OUT 0
#define DIM 30
/**
1_carga kms
*/
void cargarDias(Pila* pila)
{
    char option;
    int aux;
    int status=IN;
    while(status)
    {
        printf("1\tIngresar KMs\n2\tTerminar Dia\n0\tSalir\n");
        fflush(stdin);
        scanf("%c",&option);
        switch(option)
        {
        case '0':
            status=OUT;
            break;
        case '1':
            printf("Ingresar cantidad de kilometros\n");
            scanf("%i",&aux);
            apilar(pila,aux);
            break;
        case '2':
            printf("Terminando el dia\n");
            apilar(pila,-1);
            break;
        }
    }

}
/**
2_Calcular recorridos
*/
void calcularDias(Pila* pila,int arr[],int* validos)
{
    Pila pilaAux;
    inicpila(&pilaAux);
    int suma=0, dia=0;
    while(!pilavacia(pila))
    {
        apilar(&pilaAux,desapilar(pila));
    }
    while(!pilavacia(&pilaAux))
    {
        if(tope(&pilaAux)!=-1)
        {
            suma+=tope(&pilaAux);
        }
        else
        {
            arr[dia]=suma;
            suma=0;
            dia++;
            (*validos)++;
        }
        apilar(pila,desapilar(&pilaAux));
    }

}
void masLargo(int arr[],int validos)
{

    int mayorRecorrido=arr[0];
    int mayorDia=0;
    for(int i=1; i<validos; i++)
    {
        if(mayorRecorrido<arr[i])
        {
            mayorRecorrido=arr[i];
            mayorDia=i;
        }
    }
    printf("El mayor recorrido fue de %i Kms, y se realizo el dia %i\n",mayorRecorrido,mayorDia+1);
}
/**
*3_Mostrar pila
*/
void mostrarPila(Pila* pila)
{
    Pila pilaAux;
    inicpila(&pilaAux);
    int dia=1;
    while(!pilavacia(pila))
    {
        apilar(&pilaAux,desapilar(pila));
    }

    printf("Dia %i:",dia);
    while(!pilavacia(&pilaAux))
    {
        if(tope(&pilaAux)!=-1)
        {
            printf(" %i",tope(&pilaAux));
            apilar(pila,desapilar(&pilaAux));
        }
        else
        {
            dia++;
            apilar(pila,desapilar(&pilaAux));
            if(!pilavacia(&pilaAux))
            {
                printf("\nDia %i:",dia);
            }
        }

    }
    printf("\nFin...\n");
}
void mostrarArreglo(int arr[],int validos)
{
    printf("kilometros totales por dia:{");
    for(int i=0; i<validos; i++)
    {
        printf(" %i",arr[i]);
    }
    printf(" }\n");
}
int validarNombre(char arr[][DIM],int validos,char palabra[])
{

    int flag=1,i=0;
    while(i<validos && flag==1)
    {
        if(strcmpi(arr[i],palabra)==0)
        {
            flag=0;
        }
        i++;
    }
    return flag;
}
void cargarPersonas(char arr[][DIM],int* validos)
{
    char option;
    char nombre[DIM];
    int status=IN;
    while(status)
    {
        printf("Desea cargar una nueva persona?\n1\tCargar nueva\n0\tSalir\n");
        fflush(stdin);
        scanf("%c",&option);
        switch(option)
        {
        case '0':
            status=OUT;
            break;
        case '1':
            printf("Ingrese el nombre a agregar:\n");
            fflush(stdin);
            gets(nombre);
            if(validarNombre(arr,*validos,nombre))
            {
                strcpy(arr[*validos],nombre);
                (*validos)++;
            }
            else
            {
                printf("Ese nombre ya esta en la lista\n");
            }
        }
    }
}
void mostrarPersonas(char arr[][DIM],int validos){
    printf("Personas:\n");
    for (int i=0;i<validos;i++){
        printf("%i: %s\n",i,arr[i]);
        printf("%i: %s\n",i,arr[i]);
        printf("%i: %s\n",i,arr[i]);
    }
    printf("Fin...\n");
}
void insertar(char arr[][DIM],int validos,char palabra[]){
    int u=validos;
    while(u>=0 && strcmpi(arr[u],palabra)){
        strcpy(arr[u+1],arr[u]);
        u--;
    }
    strcpy(arr[u+1],palabra);
}
void ordenarPorInsercion(char arrDesordenado[][DIM],char arrOrdenado[][DIM],int validos){
    for(int i=0;i<validos;i++){
        insertar(arrOrdenado,i,arrDesordenado[i]);
    }
}
int main()
{
    Pila pila;
    inicpila(&pila);
    int arregloDias[DIM];
    int validos=0;
    char personas[DIM][DIM];
    char personasOrdenado[DIM][DIM];
    int validosPersonas=0;
    //1
    cargarDias(&pila);
    mostrar(&pila);
    //2
    calcularDias(&pila,arregloDias,&validos);
    masLargo(arregloDias,validos);
    //3
    mostrarPila(&pila);
    //4
    mostrarArreglo(arregloDias,validos);
    //5
    cargarPersonas(personas,&validosPersonas);
    mostrarPersonas(personas,validosPersonas);
    //6
    ordenarPorInsercion(personas,personasOrdenado,validosPersonas);
    mostrarPersonas(personasOrdenado,validosPersonas);
    return 0;
}
