#include <stdio.h>
#include <stdlib.h>
#include "pila.h"
#define IN 1
#define OUT 0
int main()
{
    Pila pila1;
    inicpila(&pila1);
    Pila pila2;
    inicpila(&pila2);
    menu(&pila1,&pila2);
}
void menu(Pila* pila1, Pila* pila2)
{
    int status=IN;
    int option;
    while(status)
    {
        printf("0\tSalir\n1\tIngresar elementos\n2\tPasar elementos\n3\tPasar elementos Ordenado\n4\tSacar menor\n5\tOrdenar pila\n9\tMostrar pilas\n");
        scanf("%i",&option);
        switch(option)
        {
        case 0:
            status=OUT;
            break;
        case 1:
            ingresarElemento(pila1);
            break;

        case 2:
            printf("1\tpila 1 ---> pila 2\n2\tpila 2 ---> pila 1\n");
            scanf("%i",&option);
            switch(option)
            {
            case 1:
                pasarElementos(pila1,pila2);
                break;
            case 2:
                pasarElementos(pila2,pila1);
                break;
            default:
                printf("La opcion ingresada no es valida\n");
                break;
            }
            break;
        case 3:
            printf("1\tpila 1 ---> pila 2\n2\tpila 2 ---> pila 1\n");
            scanf("%i",&option);
            switch(option)
            {
            case 1:
                pasarElementosOrdenado(pila1,pila2);
                break;
            case 2:
                pasarElementosOrdenado(pila2,pila1);
                break;
            default:
                printf("La opcion ingresada no es valida\n");
                break;
            }
            break;
        case 4:
            printf("1\tSacar menor pila 1\n2\tSacar menor pila 2\n");
            scanf("%i",&option);
            switch(option)
            {
            case 1:
                sacarMenor(pila1);
                break;
            case 2:
                sacarMenor(pila2);
                break;
            default:
                printf("La opcion ingresada no es valida\n");
                break;
            }
            break;
        case 5:
            printf("1\tDestino pila 2\n2\tDestino pila 1\n");
            scanf("%i",&option);
            switch(option)
            {
            case 1:
                ordenarPila(pila1,pila2);
                break;
            case 2:
                ordenarPila(pila2,pila1);
                break;
            default:
                printf("La opcion ingresada no es valida\n");
                break;
            }
            break;
        case 9:
            printf("1\tMostrar pila 1\n2\tMostrar pila 2\n");
            scanf("%i",&option);
            switch(option)
            {
            case 1:
                mostrar(pila1);
                break;
            case 2:
                mostrar(pila2);
                break;
            default:
                printf("La opcion ingresada no es valida\n");
                break;
            }
        }
    }

}
/**
*1. Hacer una función que permita ingresar varios elementos a una pila, tanto como quiera el
usuario.
*/
void ingresarElemento(Pila* pila)
{
    int status=IN;
    int option,num;
    while(status)
    {
        printf("Ingresar nuevo elemento en la pila?\n1\tSI\n0\tNO\n");
        scanf("%i",&option);
        switch(option)
        {
        case 0:
            status=OUT;
            break;
        case 1:
            printf("Ingrese el numero a agregar\n");
            scanf("%i",&num);
            apilar(pila,num);
            mostrar(pila);
            break;
        }
    }
}
/**
*2. Hacer una función que pase todos los elementos de una pila a otra.
*/
void pasarElementos(Pila* pilaOrigen, Pila* pilaDestino)
{
    while(!pilavacia(pilaOrigen))
    {
        apilar(pilaDestino,desapilar(pilaOrigen));
    }
}
/**
*3. Hacer una función que pase todos los elementos de una pila a otra, pero conservando el orden.
*/
void pasarElementosOrdenado(Pila* pilaOrigen, Pila* pilaDestino)
{
    Pila pilaAux;
    inicpila(&pilaAux);
    pasarElementos(pilaOrigen,&pilaAux);
    pasarElementos(&pilaAux,pilaDestino);
}
/**
*4. Hacer una función que encuentre el menor elemento de una pila y lo retorna. La
misma debe eliminar ese dato de la pila.
*/
int sacarMenor(Pila* pila)
{
    int menor=desapilar(pila);
    Pila pilaAux;
    inicpila(&pilaAux);
    while(!pilavacia(pila))
    {
        if (menor > tope(pila))
        {
            apilar(&pilaAux,menor);
            menor=(desapilar(pila));
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
/**
*5. Hacer una función que pase los elementos de una pila a otra, de manera que se genere una
*nueva pila ordenada. Usar la función del ejercicio 4. (Ordenamiento por selección)
*/
void ordenarPila(Pila* pilaOrigen, Pila* pilaDestino)
{
    int menor;
    while (!pilavacia(pilaOrigen))
    {
        menor=sacarMenor(pilaOrigen);
        apilar(pilaDestino,menor);
    }
}
