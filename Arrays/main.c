#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
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
void menu(int arreglo[],int* validos,Pila* pila,float arregloFloat[], int* validosFloat,char arregloChar[],int* validosChar);
void menuFloat(float arreglo[],int* validos);
void menuChar(char arreglo[],int* validos);
void arrayToPila(int arr[],int validos,Pila* pila);
int buscarElemento(char arreglo[],char letra,int validos);
void buscarElementoMenu(char arreglo[],int validos);
void cargarArrayChar(char arreglo[],int* validos);
void insertarCaracterOrdenado(char arreglo[], char letra,int* validos);
void insertarCaracterOrdenadoMenu(char arreglo[],int* validos);
char maximoCaracter(char arreglo[],int validos);
int esCapicua(int arreglo[],int validos);
void invertirArreglo(int arreglo[],int validos);
void ordenamientoPorSeleccion(int arreglo[],int validos);
int posicionMenor(int posicionInicial,int arreglo[],int validos);
void ordenamientoPorInsercion(int arreglo[],int validos);
void insertarNum(int arreglo[],int posicionMenor);
int comparar(int num1,int num2);
int main()
{
    int arregloInt[DIMENSION];
    float arregloFloat[DIMENSION];
    char arregloChar[DIMENSION];
    Pila pila;
    inicpila(&pila);
    int validos=0;
    int validosFloat=0;
    int validosChar=0;
    menu(arregloInt, &validos,&pila,arregloFloat,&validosFloat,arregloChar,&validosChar);
    return 0;
}
void menu(int arreglo[],int* validos,Pila* pila,float arregloFloat[], int* validosFloat,char arregloChar[],int* validosChar)
{
    int option, status=IN;
    while(status)
    {
        system("cls");
        printf("0\tSalir\n1\tMenu Enteros\n2\tMenu Float\n3\tMenu char\n");
        scanf("%i",&option);
        switch(option)
        {
        case 0:
            system("cls");
            printf("Saliendoo!");
            status=OUT;
            break;
        case 1:
            menuInt(arreglo, validos,pila);
            break;

        case 2:
            menuFloat(arregloFloat,validosFloat);
            break;
        case 3:
            menuChar(arregloChar,validosChar);
            break;
        }

    }

}
void menuInt(int arreglo[],int* validos,Pila* pila)
{
    int option,status=IN;
    while(status)
    {
        printf("0\tAtras\n1\tCargar Arreglo\n2\tSumar arreglo\n3\tArreglo a pila\n4\tMostrar arreglo\n5\tEs capicua?\n"
               "6\tInvertir arreglo\n7\tOrdenamiento por seleccion\n");
        scanf("%i",&option);
        switch(option)
        {
        case 0:
            system("cls");
            printf("Saliendoo!\n");
            status=OUT;
            break;
        case 1:
            system("cls");
            cargarArray(arreglo,validos);
            showArray(arreglo,*validos);
            break;
        case 2:
            system("cls");
            printf("La suma del arreglo es: %i\n",sumarArray(arreglo,*validos));
            break;
        case 3:
            system("cls");
            arrayToPila(arreglo,*validos,pila);
            mostrar(pila);
            break;
        case 4:
            showArray(arreglo,*validos);
            break;
        case 5:
            system("cls");
            esCapicua(arreglo,*validos);
            break;
        case 6:
            system("cls");
            invertirArreglo(arreglo,*validos);
            break;
        case 7:
            system("cls");
            ordenamientoPorSeleccion(arreglo,*validos);
            showArray(arreglo,*validos);
            break;
        case 8:
            system("cls");
            ordenamientoPorInsercion(arreglo,*validos);
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
            system("cls");
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
        system("cls");
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
    system("cls");
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
        system("cls");
        printf("0\tAtras\n1\tCargar Arreglo Float\n2\tMostrar arreglo Float\n");
        scanf("%i",&option);
        switch(option)
        {
        case 0:
            status=OUT;
            break;
        case 1:
            system("cls");
            cargarArrayFloat(arreglo,validos);
            break;
        case 2:
            system("cls");
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

void menuChar(char arreglo[],int* validos)
{
    int option, status=IN;
    while(status)
    {
        system("cls");
        printf("0\tAtras\n1\tCargar String\n2\tMostrar string\n3\tBuscar elemento\n4\t"
               "Insertar caracter ordenado\n5\tObtener maximo\n");
        scanf("%i",&option);
        switch(option)
        {
        case 0:
            printf("Saliendoo!\n");
            status=OUT;
            break;
        case 1:
            cargarArrayChar(arreglo,validos);
            break;
        case 2:
            printf("String:\n%s\n",arreglo);
            break;
        case 3:
            buscarElementoMenu(arreglo,*validos);
            break;
        case 4:
            insertarCaracterOrdenadoMenu(arreglo,validos);
            break;
        case 5:
            printf("El caracter mas grande del arreglo es: %c\n", maximoCaracter(arreglo,*validos));
            break;
        }


    }
}
void cargarArrayChar(char arreglo[],int* validos)
{
    int option,cantidad,status=IN;
    while(status)
    {
        system("cls");
        printf("1\tCargar cadena(max 100c)\n0\tAtras\n");
        scanf("%i",&option);
        switch(option)
        {
        case 0:
            status=OUT;
            break;

        case 1:
            printf("Cuantos caracteres desea ingresar?\n");
            scanf("%i",&cantidad);
            addChar(cantidad,arreglo,validos);
            break;
        }
    }
}
void addChar(int cantidad,char arreglo[],int* validos)
{
    char letra;

    for(int i=0; i<cantidad; i++)
    {
        printf("Ingrese el caracter a agregar en el lugar %i:\n",*validos+i);
        scanf(" %c",&letra);
        fflush(stdin);
        arreglo[*validos+i]=letra;
    }
    *validos+=cantidad;
}
/**
*6.​ Realizar una función que indique si un elemento dado se encuentra en un arreglo de
*caracteres.
*/
void buscarElementoMenu(char arreglo[],int validos)
{
    int option,status=IN;
    char letra;
    while(status)
    {
        system("cls");
        printf("1\tBuscar un caracter\n0\tAtras\n");
        scanf("%i",&option);
        switch(option)
        {
        case 0:
            printf("Volviendo al menu anterior\n");
            status=OUT;
            break;
        case 1:
            printf("Ingrese el caracter a buscar en el arreglo:\n");
            scanf(" %c",&letra);
            switch(buscarElemento(arreglo,letra,validos))
            {
            case 0:
                printf("No existe ese elemento en el arreglo\n");
                break;
            case 1:
                printf("El elemento se encuentra en el arreglo\n");
                break;
            }

            break;
        }
    }
}
/**
*@Param Retorna 1(TRUE) y 0(FALSE) segun el caracter se encuentre en el arreglo.
*/
int buscarElemento(char arreglo[],char letra,int validos)
{
    int condition=0;
    for(int i=0; i<validos; i++)
    {
        if(arreglo[i]==letra)
        {
            condition=1;
        }
    }
    return condition;
}
/**
*7. Realizar una función que inserte un carácter en un arreglo ordenado alfabéticamente,
*conservando el orden.
*/
void insertarCaracterOrdenadoMenu(char arreglo[],int* validos)
{
    system("cls");
    char letra;
    printf("ingrese el caracter que desea insertar\n");
    fflush(stdin);
    scanf(" %c",&letra);
    insertarCaracterOrdenado(arreglo,letra,validos);
}
void insertarCaracterOrdenado(char arreglo[], char letra,int* validos)
{
    for(int i=(*validos)-1; i>=0; i--)
    {
        if(letra<arreglo[i])
        {
            arreglo[i+1]=arreglo[i];
        }
        else if(letra>arreglo[i]&&letra<arreglo[i+1])
        {
            arreglo[i+1]=letra;
            printf("Caracter insertado!\n");
        }

    }
    (*validos)++;
}
/**
*8. Realizar una función que obtenga el máximo carácter de un arreglo dado.
*/
char maximoCaracter(char arreglo[],int validos)
{
    char maximo=arreglo[0];
    for(int i=1; i<validos; i++)
    {
        if(arreglo[i]>maximo)
        {
            maximo=arreglo[i];
        }
    }

    return maximo;
}
/**
*9. Realizar una función que determine si un arreglo es capicúa
*Devuelve 1 y 0 segun sea o no capicua.
*/
int esCapicua(int arreglo[],int validos)
{
    int capicua=1;
    for(int i=0; i<validos/2; i++)
    {
        if(arreglo[i]!=arreglo[validos-1-i])
        {
            capicua=0;
        }
    }
    if(capicua)
    {
        printf("Es capicua!\n");
    }
    else
    {
        printf("No es capicua =(\n");
    }
    return capicua;
}
/**
*10. Realizar una función que invierta los elementos de un arreglo. (sin utilizar un arreglo auxiliar)
*/
void invertirArreglo(int arreglo[],int validos)
{
    int num;
    for(int i=0; i<validos/2; i++)
    {
        num=arreglo[validos-1-i];
        arreglo[validos-1-i]=arreglo[i];
        arreglo[i]=num;
    }
}
/**
*11. Ordenar un arreglo según los siguientes métodos:
*a. Selección
*b. Inserción
*/
void ordenamientoPorSeleccion(int arreglo[],int validos)
{
    int aux,posicionAux;

    for(int i=0; i<validos-1; i++)
    {
        posicionAux=posicionMenor(i,arreglo,validos);
        aux=arreglo[i];
        arreglo[i]=arreglo[posicionAux];
        arreglo[posicionAux]=aux;
    }

}
int posicionMenor(int posicionInicial,int arreglo[],int validos)
{
    int posicionDelMenor=posicionInicial,menor=arreglo[posicionInicial];
    for(int i=posicionInicial+1; i<validos; i++)
    {
        if(arreglo[i]<menor)
        {
            posicionDelMenor=i;
            menor=arreglo[i];
        }
    }
    return posicionDelMenor;
}
void ordenamientoPorInsercion(int arreglo[],int validos)
{
    int aux,posicionAux,i;

    for(i=1; i<validos; i++)
    {
        insertarNum(arreglo,i);
    }

}
void insertarNum(int arreglo[],int posicion)
{
    int aux=arreglo[posicion],j=posicion-1;
    while(j>=0){
        if(comparar(aux,arreglo[j])){
            arreglo[j+1]=aux;
        }else{
            arreglo[j+1]=arreglo[j];
        }
        arreglo[j+1]=aux;
        j--;

    }


}
/**
*Devuelve 1 y 0 segun sea mas grande el primer o segundo numero

*/
int comparar(int num1,int num2){
    if (num2<num1){
        return 1;
    }else{
        return 0;
    }
}
