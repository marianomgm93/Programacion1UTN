#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "pila.h"
#include <string.h>
#define FILAS 15
#define COLUMNAS 15
const int IN=1;
const int OUT=0;
//const int FILAS=15;
//const int COLUMNAS=15;
/**
Vamos a organizar las ventas de una fábrica, realizadas durante un día, serán agregadas a
una pila, de forma individual, y al finalizar el día, en un arreglo se contarán los valores de las
compras de acuerdo a la cantidad de dígitos.
*/
/**
1- Se desea crear una función para la carga de los elementos en la pila, al finalizar la carga,
tenemos que tener guardada la información de cuánto fue el monto total de las compras y
cuántas compras hubo. (pensar cómo conservar esa información, no tiene que mostrarse)
*/
void cargarPila(Pila *pila, int *cantidadCompras,float *totalCompras)
{
    int status=IN;
    char option;
    printf("Cargando pila de compras...\n");
    while(status)
    {
        printf("Desea Cargar un nuevo elemento?\n0\tAtras\n1\tCargar nuevo\n");
        fflush(stdin);
        scanf("%c",&option);
        switch(option)
        {
        case '0':
            status=OUT;
            break;
        case '1':
            leer(pila);
            (*cantidadCompras)++;
            (*totalCompras)+=tope(pila);
            break;
        default:
            printf("La opcion ingresada no existe, vuelva a intentarlo.");
            break;
        }
    }

}
/**
2- Ordenar los elementos de la pila de menor a mayor, por método de inserción.
*/
void insertarNumero(Pila* pila,int num)
{
    Pila pilaAux;
    inicpila(&pilaAux);
    while(!pilavacia(pila)&&tope(pila)>num)
        apilar(&pilaAux,desapilar(pila));
    apilar(pila,num);
    while(!pilavacia(&pilaAux))
        apilar(pila,desapilar(&pilaAux));
}
void ordenamientoPorInsercion(Pila *pila)
{
    Pila pilaAux;
    inicpila(&pilaAux);
    while(!pilavacia(pila))
    {
        apilar(&pilaAux,desapilar(pila));
    }
    while(!pilavacia(&pilaAux))
    {
        insertarNumero(pila,desapilar(&pilaAux));
    }
}

/**
3- Ahora que están ordenados, tenemos que guardar en un arreglo la cantidad de compras
según la cantidad de dígitos. Es decir, en la primera posición, todas las compras de un
dígito, en la segunda, de dos dígitos, etc. Recuerden que están ordenados, así que una vez
que cambian la cantidad de dígitos, pueden moverse de posición en el arreglo. (Viene con
ayuda en el pizarrón)
*/
int cantidadDigitos(int num){
    int i=1;
    while(num>9){
        num=num/10;
        i++;
    }
    return i;
}
void inicArray(int arr[],int validos){
    for (int i=0;i<validos;i++){
        arr[i]=0;
    }
}
void sumatoriasEnArreglo(Pila *pila,int arr[],int* validos){
    int posicion;
    while(!pilavacia(pila)){
        posicion=cantidadDigitos(tope(pila))-1;
        arr[posicion]+=desapilar(pila);
    }
}
void mostrarArreglo(int arr[],int validos){
    printf("arreglo={ ");
    for(int i=0; i<validos;i++){
        printf("%i ",arr[i]);
    }
    printf(" }\n");
}
/**
4- Calcular cuál fue el rango de compras que mayor monto acumulado tuvo, y devolver esa
información.
*/
int mayorMontoPos(int arr[],int validos){
    int mayorPosicion=0;
    int mayor=arr[0];
    for(int i=0;i<validos;i++){
        if (mayor<arr[i]){
            mayor=arr[i];
            mayorPosicion=i;
        }
    }
    return mayorPosicion;
}
void cargarPorcentajes(int arrCompras[],float arrPorcentajes[],int validos,float totalCompras){
    for(int i=0;i<validos;i++){
        arrPorcentajes[i]=(float)(arrCompras[i]*100)/totalCompras;
    }
}
void mostrarArregloFloat(float arr[],int validos){
    system("cls");
    printf("Arreglo:\n");
    for(int i=0; i<validos;i++){
        printf("%i digitos: %%%.2f\n",i+1,arr[i]);
    }
}
/**
6- Hacer una función que verifique si un nombre existe en una arreglo de strings. Luego
hacer una función que cargue un arreglo de strings, pero cada vez que cargamos una
palabra, verifique que la palabra no exista, y si existe no la cargue y le avise al usuario que
está repetida. También hay que hacer una función para mostrar dicho arreglo de strings.
*/

int validarNombre(char arr[][COLUMNAS],int validos,char palabra[]){
    int flag=1;

    for(int i=0;i<validos;i++){
        if(strcmpi(arr[i],palabra)==0){
            flag=0;
        }
    }
    return flag;
}
void cargarString(char arr[][COLUMNAS],int *validos){
    int status=IN;
    char option;
    char nombre[COLUMNAS];
    while(status){
        printf("Cargando Strings\n0\tAtras\n1\tCargar nuevo\n");
        fflush(stdin);
        scanf("%c",&option);
        switch(option){
        case '0':
            status=OUT;
            break;
        case '1':
            printf("Ingrese el nombre que desea agregar al arreglo\n");
            fflush(stdin);
            gets(nombre);
            if(validarNombre(arr,*validos,nombre)){
                strcpy(arr[*validos],nombre);
                (*validos)++;
                printf("El nombre se cargo correctamente.\n");
            }else{
                printf("El nombre ya se encuentra cargado en el arreglo\n");
            }
            break;
        default:
            printf("La opcion ingresada no existe, intentelo nuevamente\n");
        }
    }
}

void mostrarStrings(char arr[][COLUMNAS],int validos){
    for(int i=0;i<validos;i++){
        printf("%s\n",arr[i]);
    }
}
int main()
{
    char arrStrings[FILAS][COLUMNAS]={{"leo"},{"manu"},{"sofi"}};
    int validosStrings=3;
    int mayorPos;
    float arrPorcentajes[FILAS];
    int arrComprasPorDigitos[FILAS];
    int validosComprasPorDigitos=8;
    float totalCompras=0;
    int cantidadCompras=0;
    Pila pila1;
    inicpila(&pila1);
    int status=IN;
    char option;
    while(status)
    {
        printf("elegir opcion\n0\tSalir\n1-6\n");
        fflush(stdin);
        scanf("%c",&option);
        switch(option)
        {
        case '0':
            status=OUT;
            break;
        case '1':
            cargarPila(&pila1,&cantidadCompras,&totalCompras);
            printf("Comprados: %i\nInversion: \%.2f\n",cantidadCompras,totalCompras);
            break;
        case '2':
            system("cls");
            printf("Pila inicial:\n");
            mostrar(&pila1);
            ordenamientoPorInsercion(&pila1);
            printf("Pila ordenada:\n");
            mostrar(&pila1);
            break;
        case '3':
            inicArray(arrComprasPorDigitos,validosComprasPorDigitos);
            sumatoriasEnArreglo(&pila1,arrComprasPorDigitos,&validosComprasPorDigitos);
            mostrarArreglo(arrComprasPorDigitos,validosComprasPorDigitos);
            break;
        case '4':
            mayorPos=mayorMontoPos(arrComprasPorDigitos,validosComprasPorDigitos);
            printf("El mayor monto comprado es de %i, se realizo en compras de %i digitos\n", arrComprasPorDigitos[mayorPos],mayorPos+1);
            break;
        case '5':
            cargarPorcentajes(arrComprasPorDigitos,arrPorcentajes,validosComprasPorDigitos,totalCompras);
            mostrarArregloFloat(arrPorcentajes,validosComprasPorDigitos);
            break;
        case '6':
            cargarString(arrStrings,&validosStrings);
            mostrarStrings(arrStrings,validosStrings);
            break;
        default:
            printf("Opcion incorrecta, intentelo nuevamente\n");
            break;
        }
    }
    return 0;
}
