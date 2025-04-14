#include <stdio.h>
#include <stdlib.h>
#include "pila.h"
const int IN=1;
const int OUT=0;
const int FILAS=3;
const int COLUMNAS=3;

/**
*/
void menuCargarPila(Pila *pila)
{
    int status=IN;
    char option;
    while(status)
    {
        printf("Desea agregar 2 elementos a la pila? y/n\n");
        fflush(stdin);
        scanf(" %c",&option);
        switch(option)
        {
        case 'y':
            leer(pila);
            leer(pila);
            break;
        case 'n':
            status=OUT;
            break;
        default:
            printf("La opcion ingresada es incorrecta, intentelo nuevamente");
            break;
        }

    }
}
void copiarMultiplosDe5(Pila *pila, int arreglo[],int *validos)
{
    int aux;
    while(!pilavacia(pila))
    {
        aux=desapilar(pila);
        if(aux%5==0)
        {
            arreglo[*validos]=aux;
            (*validos)++;
        }
    }
}
void mostrarArreglo(int arreglo[], int validos)
{
    printf("Arreglo= {");
    for(int i=0; i<validos; i++)
    {
        printf(" %i",arreglo[i]);
    }
    printf(" }\n");
}

int encontrarMenor(int arr[],int validos)
{
    int menor=arr[0],posMenor;
    for(int i=1; i<validos; i++)
    {
        if(arr[i]<menor)
        {
            menor=arr[i];
            posMenor=i;
        }
    }
    return posMenor;
}
void cargarMatriz(int matriz[][COLUMNAS])
{
    for (int i=0; i<FILAS; i++)
    {
        for (int j=0; j<COLUMNAS; j++)
        {
            matriz[i][j]=rand()%10;
        }
    }

}
void mostrarMatriz(int matriz[][COLUMNAS],int filas,int columnas)
{
    for (int i=0; i<filas; i++)
    {
        for (int j=0; j<columnas; j++)
        {
            printf(" %i",matriz[i][j]);

        }
        printf("\n");
    }
}
int pedirPosicion(int arr[],int validos)
{
    int option,status=IN;
    while(status)
    {
        printf("Ingrese la posicion del arreglo deseada: \n");
        scanf("%i",&option);
        if(option>=validos||option<0)
        {
            printf("La posicion deseada no existe en el arreglo, intente nuevamente.\n");
        }
        else
        {
            status=OUT;
        }
    }
    return option;
}
void mostrarPosicion(int arr[],int validos){
    int posAMostrar=pedirPosicion(arr,validos);
    printf("El numero que se encuentra en la posicion %i, es: %i\n",posAMostrar,arr[posAMostrar]);
}
void ordenarPilaPorSeleccion(Pila *pila){
    Pila pilaAux;
    Pila pilaAux2;
    inicpila(&pilaAux);
    inicpila(&pilaAux2);
    int menor=tope(pila);
    while(!pilavacia(pila) || !pilavacia(&pilaAux)){
    while(!pilavacia(pila)){
        if(tope(pila)<menor){
            menor=tope(pila);
        }
        apilar(&pilaAux,desapilar(pila));
    }
    apilar(&pilaAux2,menor);
    }
    while(!pilavacia(&pilaAux2)){
        apilar(&pilaAux,desapilar(&pilaAux2));
        }
    while(!pilavacia(&pilaAux)){
        apilar(pila,desapilar(&pilaAux));
    }
}
int main()
{
    int arreglo[20];
    int validos=0;
    int menor;
    int posMenor;
    int matriz[FILAS][COLUMNAS];
    Pila pila;
    inicpila(&pila);
    //1
    menuCargarPila(&pila);
    //2
    copiarMultiplosDe5(&pila,arreglo,&validos);
    mostrarArreglo(arreglo,validos);
    //3
    posMenor=encontrarMenor(arreglo,validos);
    menor=arreglo[posMenor];
    printf("El menor numero encontrado es %i, se encuentra en la posicion %i del arreglo\n",menor,posMenor);
    //4
    cargarMatriz(matriz);
    mostrarMatriz(matriz,FILAS,COLUMNAS);
    //5
    mostrarPosicion(arreglo,validos);
    //6
    ordenarPilaPorSeleccion(&pila);
    mostrar(&pila);
    return 0;
}
