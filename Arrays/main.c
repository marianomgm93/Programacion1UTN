#include <stdio.h>
#include <stdlib.h>
#include "pila.h"
#define IN 1
#define OUT 0
const int DIMENSION=100;
void addNum(int cantidad,int arreglo[],int* validos);
void addNumFloat(int cantidad,float arreglo[],int* validos);
void showArray(int arreglo[],int validos);
void showArrayFloat(float arreglo[],int validos);
void inicArray(int arreglo[]);
void inicArrayFloat(float arreglo[]);
void menu(int arreglo[],int* validos,Pila* pila,float arregloFloat[],int* validosFloat);
void menuFloat(float arreglo[],int* validos);
void arrayToPila(int arr[],int validos,Pila* pila);
int main()
{
    int arregloInt[DIMENSION];
    float arregloFloat[DIMENSION];
    char arregloChar[DIMENSION];
    Pila pila;
    inicpila(&pila);
    int validos=0;
    int validosFloat=0;
    menu(arregloInt, &validos,&pila,arregloFloat,&validosFloat);
    return 0;
}
void menu(int arreglo[],int* validos,Pila* pila,float arregloFloat[], int* validosFloat)
{

    int option, status=IN;
    while(status)
    {
        printf("0\tSalir\n1\tMenu Enteros\n2\tMenu Float\n");
        scanf("%i",&option);
        switch(option)
        {
        case 0:
            printf("Saliendoo!");
            status=OUT;
            break;
        case 1:
            menuInt(arreglo, validos,pila);
            break;

        case 2:
            menuFloat(arregloFloat,validosFloat);
            break;
        }
    }

}
void menuInt(int arreglo[],int* validos,Pila* pila)
{
    int option,status=IN;
    while(status)
    {
        printf("0\tSalir\n1\tCargar Arreglo\n2\tSumar arreglo\n3\tArreglo a pila\n4\tMostrar arreglo\n");
        scanf("%i",&option);
        switch(option)
        {
        case 0:
            printf("Saliendoo!\n");
            status=OUT;
            break;
        case 1:
            cargarArray(arreglo,validos);
            showArray(arreglo,*validos);
            break;
        case 2:
            printf("La suma del arreglo es: %i\n",sumarArray(arreglo,*validos));
            break;
        case 3:
            arrayToPila(arreglo,*validos,pila);
            mostrar(pila);
            break;
        case 4:
            showArray(arreglo,*validos);
            break;
        }
    }
}
/**
*1.​ Hacer una función que reciba como parámetro un arreglo de números enteros y permita que
*el usuario ingrese valores al mismo por teclado. La función debe retornar la cantidad de
*elementos cargados en el arreglo (o pueden utilizar como puntero válidos).
*/
void cargarArray(int arreglo[],int* validos)
{
    int option,cantidad,status=IN;
    while(status)
    {
        printf("1\tCargar numero\n0\tSalir\n");
        scanf("%i",&option);
        switch(option)
        {
        case 0:
            status=OUT;
            break;

        case 1:
            printf("Cuantos numeros desea agregar?\n");
            scanf("%i",&cantidad);
            if((cantidad+*validos)<=DIMENSION)
            {
                addNum(cantidad,arreglo, validos);
            }
            else
            {
                printf("La cantidad de lugares disponibles en el arreglo es de: %i\n", DIMENSION-*validos);
            }

            break;

        }
    }
}
void addNum(int cantidad,int arreglo[],int* validos)
{
    int num;

    for(int i=0; i<cantidad; i++)
    {
        printf("Ingrese el numero a agregar en el lugar %i:\n",*validos+i);
        scanf("%i",&num);
        arreglo[*validos+i]=num;
    }
    *validos+=cantidad;
}
void inicArray(int arreglo[])
{

    int i;
    for( i=0; i<DIMENSION; i++)
    {
        arreglo[i]=0;
    }
}
/**
*2.​ Hacer una función que reciba como parámetro un arreglo y la cantidad de elementos (válidos)
*cargados en él y los muestre por pantalla.
*/
void showArray(int arreglo[],int validos)
{
    printf("Array:\n");
    for(int i =0; i<validos; i++)
    {
        if(i==0)
        {
            printf("{%i,",arreglo[i]);
        }
        else if(i==validos-1)
        {
            printf(" %i}\n", arreglo[i]);
        }
        else
        {
            printf(" %i,", arreglo[i]);
        }
    }
}
/**
*3.​ Hacer una función que reciba como parámetro un arreglo y la cantidad de elementos (válidos)
*cargados en él y calcule la suma de sus elementos.
*/
int sumarArray(int arr[],int validos)
{
    int sum=0;
    for(int i=0; i<validos; i++)
    {
        sum+=arr[i];
    }
    return sum;
}
/**
*4.​ Hacer una función que reciba como parámetro un arreglo, la cantidad de elementos (válidos)
*cargados en él y una Pila. La función debe copiar los elementos del arreglo en la pila.
*/

void arrayToPila(int arr[],int validos,Pila* pila)
{
    for(int i=0; i<validos; i++)
    {
        apilar(pila,arr[i]);
    }
}
/**
*5.​ Realizar una función que sume los elementos de un arreglo de números reales (float) de
*dimensión 100. (se recomienda hacer una función para cargar y otra para mostrar para este
*tipo de dato asociado al arreglo)
*/
void menuFloat(float arreglo[],int* validos)
{
    int option,status=IN;
    while(status)
    {
        printf("0\tSalir\n1\tCargar Arreglo Float\n2\tMostrar arreglo Float\n");
        scanf("%i",&option);
        switch(option)
        {
        case 0:
            status=OUT;
            break;
        case 1:
            cargarArrayFloat(arreglo,validos);
            break;
        case 2:
            showArrayFloat(arreglo,*validos);
            break;
        }

    }
}
void cargarArrayFloat(float arreglo[],int* validos)
{
    int option,cantidad,status=IN;
    while(status)
    {
        printf("1\tCargar numero\n0\tSalir\n");
        scanf("%i",&option);
        switch(option)
        {
        case 0:
            status=OUT;
            break;

        case 1:
            printf("Cuantos numeros desea agregar?\n");
            scanf("%i",&cantidad);
            if((cantidad+*validos)<=DIMENSION)
            {
                addNumFloat(cantidad,arreglo, validos);
            }
            else
            {
                printf("La cantidad de lugares disponibles en el arreglo es de: %i\n", DIMENSION-*validos);
            }

            break;

        }
    }
}
void addNumFloat(int cantidad,float arreglo[],int* validos)
{
    float num;

    for(int i=0; i<cantidad; i++)
    {
        printf("Ingrese el numero a agregar en el lugar %i:\n",*validos+i);
        scanf("%f",&num);
        arreglo[*validos+i]=num;
    }
    *validos+=cantidad;
}
void inicArrayFloat(float arreglo[])
{

    int i;
    for( i=0; i<DIMENSION; i++)
    {
        arreglo[i]=(float) 0;
    }
}
void showArrayFloat(float arreglo[],int validos)
{
    printf("Array:\n");
    for(int i =0; i<validos; i++)
    {
        if(i==0)
        {
            printf("{%.2f,",arreglo[i]);
        }
        else if(i==validos-1)
        {
            printf(" %.2f}\n", arreglo[i]);
        }
        else
        {
            printf(" %.2f,", arreglo[i]);
        }
    }
}
/**
*6.​ Realizar una función que indique si un elemento dado se encuentra en un arreglo de
*caracteres.
*/
void menuChar(char arreglo[],int* validos){
    int option, status=IN;
    while(status)
    {
        printf("0\tSalir\n1\tCargar String\n2\tMostrar string\n");
        scanf("%i",&option);
        switch(option)
        {
        case 0:
            printf("Saliendoo!");
            status=OUT;
            break;
        case 1:
            menuInt(arreglo, validos,pila);
            break;

        case 2:
            menuFloat(arregloFloat,validosFloat);
            break;
        }
    }
}
