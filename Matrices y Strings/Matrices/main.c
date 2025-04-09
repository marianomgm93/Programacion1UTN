#include <stdio.h>
#include <stdlib.h>
const int FILAS=3;
const int COLUMNAS=3;
const int IN=1;
const int OUT=0;
/**1. Hacer una función que reciba como parámetro una matriz de números enteros
y permita que el usuario ingrese valores al mismo por teclado. La función
debe cargar la matriz por completo.
*/
void cargarMatriz(int matriz[FILAS][COLUMNAS])
{
    for (int i=0; i<FILAS; i++)
    {
        for(int j=0; j<COLUMNAS; j++)
        {
            matriz[i][j]=rand()%9;
        }
    }
}
/**
2. Hacer una función que reciba como parámetro una matriz de números enteros
y la muestre por pantalla (en formato matricial).
*/
void mostrarMatriz(int matriz[FILAS][COLUMNAS])
{
    for (int i=0; i<FILAS; i++)
    {
        for(int j=0; j<COLUMNAS; j++)
        {
            printf(" |%i|",matriz[i][j]);
            if(j==COLUMNAS-1)
            {
                printf("\n");
            }
        }
    }

}
/**4. Hacer una función tipo int que sume el contenido total de una matriz de
números enteros
*/
int sumarElementos(int matriz[FILAS][COLUMNAS])
{
    int suma=0;
    for (int i=0; i<FILAS; i++)
    {
        for(int j=0; j<COLUMNAS; j++)
        {
            suma+=matriz[i][j];
        }
    }
    return suma;
}
/**
5. Hacer una función tipo float que calcule el promedio de una matriz de
números enteros.
*/
float promediarMatriz(int matriz[FILAS][COLUMNAS])
{
    int suma=sumarElementos(matriz);
    float promedio=suma/(FILAS*COLUMNAS);
    return promedio;
}

/**
6. Hacer una función que determine si un elemento se encuentra dentro de una
matriz de números enteros. La función recibe la matriz y el dato a buscar.
*/
int buscarElemento(int matriz[FILAS][COLUMNAS],int elemento)
{
    int flag=0;
    for (int i=0; i<FILAS; i++)
    {
        for(int j=0; j<COLUMNAS; j++)
        {
            if (elemento==matriz[i][j])
            {
                flag=1;
            }
        }
    }
    return flag;
}
void menu(int matriz[FILAS][COLUMNAS])
{

    char option;
    int status=IN;
    while(status==IN)
    {
        printf("0\tSalir\n1\tMostrar matriz\n2\tCargar Matriz\n3\tSumar elementos\n"
               "4\tPromediar matriz\n5\tBuscar elemento 1=presente\n");
        scanf(" %c",&option);

        switch(option)
        {
        case '0':
            printf("Saliendo!\n");
            status=OUT;
            break;
        case '1':
            mostrarMatriz(matriz);
            break;
        case '2':
            cargarMatriz(matriz);
            break;
        case '3':
            printf("Suma de elementos= %i\n",sumarElementos(matriz));
            break;
        case '4':
            printf("Promedio de matriz= %.2f\n",promediarMatriz(matriz));
            break;
        case '5':
            int elemento;
            printf("Ingrese el elemento a buscar en la matriz:\n");
            scanf("%i",&elemento);
            printf("Resultado de la %i\n",buscarElemento(matriz,elemento));
            break;
        default:
            system("clear");
            printf("La opcion ingresada no existe\n\n");
            break;
        }
    }
}
int main()
{
    int matriz[FILAS][COLUMNAS];
    menu(matriz);
    return 0;
}

