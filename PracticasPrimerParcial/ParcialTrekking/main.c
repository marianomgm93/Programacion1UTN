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
void cargarDias(Pila* pila){
    char option;
    int aux;
    int status=IN;
    while(status){
            printf("1\tIngresar KMs\n2\tTerminar Dia\n0\tSalir\n");
            fflush(stdin);
            scanf("%c",&option);
        switch(option){
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
void calcularDias(Pila* pila,int arr[],int* validos){
    Pila pilaAux;
    inicpila(&pilaAux);
    int suma=0, dia=0;
    while(!pilavacia(pila)){
        apilar(&pilaAux,desapilar(pila));
    }
    while(!pilavacia(&pilaAux)){
            if(tope(&pilaAux)!=-1){
                suma+=tope(&pilaAux);
            }else{
                arr[dia]=suma;
                suma=0;
                dia++;
                (*validos)++;
            }
        apilar(pila,desapilar(&pilaAux));
    }

}
void masLargo(int arr[],int validos){

    int mayorRecorrido=arr[0];
    int mayorDia=0;
    for(int i=1;i<validos;i++){
        if(mayorRecorrido<arr[i]){
            mayorRecorrido=arr[i];
            mayorDia=i;
        }
    }
    printf("El mayor recorrido fue de %i Kms, y se realizo el dia %i",mayorRecorrido,mayorDia+1);
}

int main()
{
    Pila pila;
    inicpila(&pila);
    int arregloDias[DIM];
    int validos=0;
    //1
    cargarDias(&pila);
    mostrar(&pila);
    //2
    calcularDias(&pila,arregloDias,&validos);
    masLargo(arregloDias,validos);
    return 0;
}
