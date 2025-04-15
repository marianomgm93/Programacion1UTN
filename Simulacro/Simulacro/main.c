#include <stdio.h>
#include <stdlib.h>
#include "pila.h"
#include <string.h>
const int IN=1;
const int OUT=0;
const int FILAS=3;
const int COLUMNAS=3;
const int CHARFILAS=5;
const int CHARCOLUMNAS=10;
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
void mostrarPosicion(int arr[],int validos)
{
    int posAMostrar=pedirPosicion(arr,validos);
    printf("El numero que se encuentra en la posicion %i, es: %i\n",posAMostrar,arr[posAMostrar]);
}
void ordenarPilaPorSeleccion(Pila *pila)
{
    Pila pilaAux;
    inicpila(&pilaAux);
    while(!pilavacia(pila))
    {
        apilar(&pilaAux,desapilar(pila));
    }
    while(!pilavacia(&pilaAux))
    {
        apilar(pila,sacarMenor(&pilaAux));
    }

}
int sacarMenor(Pila *pila)
{
    Pila pilaAux;
    inicpila(&pilaAux);
    int menor;
    menor=desapilar(pila);
    while(!pilavacia(pila))
    {
        if(menor>tope(pila))
        {
            apilar(&pilaAux,menor);
            menor=desapilar(pila);
        }
        else
        {
            apilar(&pilaAux,desapilar(pila));
        }
    }
    while(!pilavacia(&pilaAux))
    {
        apilar(pila,desapilar(&pilaAux));
    }
    return menor;
}
int sumarMatriz(int matriz[][COLUMNAS],int filas, int columnas)
{
    int suma=0;
    for(int i=0; i<filas; i++)
    {
        for (int j=0; j<columnas; j++)
        {
            suma+=matriz[i][j];
        }
    }
    return suma;
}
float promediarMatriz(int matriz[][COLUMNAS],int filas,int columnas)
{
    int suma=sumarMatriz(matriz,filas,columnas);
    return (float)suma/(filas*columnas);
}
char randChar()
{

    return ('A'+rand()%26);
}
void cargarMatrizChar(char matriz[][CHARCOLUMNAS],int filas,int columnas)
{
    for(int i=0; i<filas; i++)
    {
        for (int j=0; j<columnas; j++)
        {
            matriz[i][j]=randChar();
        }
    }
}

void mostrarMatrizChar(char matriz[][COLUMNAS],int filas, int columnas)
{
    for(int i=0; i<filas; i++)
    {
        printf("|");
        for (int j=0; j<columnas; j++)
        {
            printf(" %c",matriz[i][j]);
        }
        printf(" |\n");
    }
}
int compararStrings(char arr1[][CHARCOLUMNAS],int validos1,char arr2[][CHARCOLUMNAS],int validos2)
{
    int contador=0;
    for(int i=0; i<validos1; i++)
    {
        for(int j=0; j<validos2; j++)
        {
            if(strcmp(arr1[i],arr2[j])==0)
            {
                contador++;
            }
        }
    }
    return contador;
}

int main()
{
    char *arregloChar1[]= {"perro","gato","conejo"};
    char *arregloChar2[]= {"gato","loro","perro","gato"};
    int validosChar1=3,validosChar2=4;
    char matrizChar[CHARFILAS][CHARCOLUMNAS];
    int arreglo[20];
    int validos=0;
    int menor;
    int posMenor;
    int matriz[FILAS][COLUMNAS];
    Pila pila;
    inicpila(&pila);

    //10
    int status=IN,option;

    while(status)
    {
        printf("Indique el ejercicio que desee hacer funcionar (1-9,0 para salir):\n");
        fflush(stdin);
        scanf(" %c",&option);
        switch(option)
        {
        case '0':
            status=OUT;
            break;
        case '1':
            //1
            menuCargarPila(&pila);
            break;
        case '2':
            //2
            copiarMultiplosDe5(&pila,arreglo,&validos);
            mostrarArreglo(arreglo,validos);
            break;
        case '3':
            //3
            posMenor=encontrarMenor(arreglo,validos);
            menor=arreglo[posMenor];
            printf("El menor numero encontrado es %i, se encuentra en la posicion %i del arreglo\n",menor,posMenor);
            break;
        case '4':
            //4
            cargarMatriz(matriz);
            mostrarMatriz(matriz,FILAS,COLUMNAS);
            break;
        case '5':
            //5
            mostrarPosicion(arreglo,validos);
            break;
        case '6':
            //6
            menuCargarPila(&pila);
            ordenarPilaPorSeleccion(&pila);
            mostrar(&pila);
            break;
        case '7':
            //7
            cargarMatriz(matriz);
            mostrarMatriz(matriz,FILAS,COLUMNAS);
            printf("El promedio de la matriz es de: %.2f\n",promediarMatriz(matriz,FILAS,COLUMNAS));
            break;
        case '8':
            //8
            cargarMatrizChar(matrizChar,CHARFILAS,CHARCOLUMNAS);
            mostrarMatrizChar(matrizChar,CHARFILAS,CHARCOLUMNAS);
            break;
        case '9':
            //9
            printf("Hay %i coincidencias entre ambos arreglos\n",compararStrings(arregloChar1,validosChar1,arregloChar2,validosChar2));
            break;
        default:
            printf("El caracter ingresado no pertenece a ninguna opcion,intentelo nuevamente\n");

        }

    }

    return 0;
}
