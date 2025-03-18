#include <stdio.h>
#include <stdlib.h>
#include <math.h>
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
        printf("0\tSalir\n1\tIngresar elementos\n2\tPasar elementos\n3\tPasar elementos Ordenado\n4\t"
               "Sacar menor\n5\tOrdenar pila\n6\tInsertar ordenado\n7\tPasar pila ordenada\n8\tSumar primeros\n"
               "10\tCalcular promedio\n11\tConversion Lineal"
               "\n9\tMostrar pilas\n");
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
        case 6:
            printf("1\tInsertar en pila 1\n2\tInsertar en pila 2\n");
            scanf("%i",&option);
            switch(option)
            {
            case 1:
                insertarOrdenado(pila1);
                break;
            case 2:
                insertarOrdenado(pila2);
                break;
            default:
                printf("La opcion ingresada no es valida\n");
                break;
            }
            break;
        case 7:
            printf("1\tDestino pila 2\n2\tDestino pila 1\n");
            scanf("%i",&option);
            switch(option)
            {
            case 1:
                generarPilaOrdenada(pila1,pila2);
                break;
            case 2:
                generarPilaOrdenada(pila2,pila1);
                break;
            default:
                printf("La opcion ingresada no es valida\n");
                break;
            }
            break;
        case 8:
            printf("1\tsumar de pila 1\n2\tSumar de pila 2\n");
            scanf("%i",&option);
            switch(option)
            {
            case 1:
                printf("%i\n",sumarPrimeros(pila1));

                break;
            case 2:
                printf("%i\n",sumarPrimeros(pila2));
                break;
            default:
                printf("La opcion ingresada no es valida\n");
                break;
            }
            break;
        case 10:
            printf("1\tPromediar pila 1\n2\tPromediar pila 2\n");
            scanf("%i",&option);
            switch(option)
            {
            case 1:
                calcularPromedio(pila1);

                break;
            case 2:
                calcularPromedio(pila2);
                break;
            default:
                printf("La opcion ingresada no es valida\n");
                break;
            }
            break;
        case 11:
            printf("1\tConversion lineal pila 1\n2\tConversion lineal pila 2\n");
            scanf("%i",&option);
            switch(option)
            {
            case 1:
                convertirLineal(pila1);

                break;
            case 2:
                convertirLineal(pila2);
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
/**
6. Hacer una función que inserta en una pila ordenada un nuevo elemento, conservando el orden de ésta.
*/
void insertarOrdenado(Pila* pila)
{
    int num,status=IN;
    Pila pilaAux;
    inicpila(&pilaAux);
    printf("Ingrese el numero a insertar en la pila");
    scanf("%i",&num);
    while(!pilavacia(pila) && status)
    {
        if(tope(pila)<num)
        {
            apilar(pila,num);
            status=OUT;
        }
        else
        {
            apilar(&pilaAux, desapilar(pila));
        }
    }
    if(status)
    {
        apilar(pila,num);
    }
    while(!pilavacia(&pilaAux))
    {
        apilar(pila,desapilar(&pilaAux));
    }
    printf("El numero ha sido insertado exitosamente\n");
}
void insertarOrdenadoSinMenu(Pila* pila,int num)
{
    int status=IN;
    Pila pilaAux;
    inicpila(&pilaAux);
    while(!pilavacia(pila) && status)
    {
        if(tope(pila)<num)
        {
            apilar(pila,num);
            status=OUT;
        }
        else
        {
            apilar(&pilaAux, desapilar(pila));
        }
    }
    if(status)
    {
        apilar(pila,num);
    }
    while(!pilavacia(&pilaAux))
    {
        apilar(pila,desapilar(&pilaAux));
    }
}
/**
7. Hacer una función que pase los elementos de una pila a otra,
de manera que se genere una nueva pila ordenada. Usar la función del ejercicio 6.  (Ordenamiento por inserción)
*/
void generarPilaOrdenada(Pila* pilaOrigen, Pila* pilaDestino)
{
    while(!pilavacia(pilaOrigen))
    {
        insertarOrdenadoSinMenu(pilaDestino,desapilar(pilaOrigen));
    }
    printf("Proceso finalizado\n");
}
/**
*8. Hacer una función que sume los dos primeros elementos de una pila (tope y anterior), y retorne la suma,
*   sin alterar el contenido de la pila.
*/
int sumarPrimeros(Pila* pila)
{
    int suma,num;
    num=desapilar(pila);
    suma=tope(pila)+num;
    apilar(pila,num);
    return suma;
}

/**
*9. Hacer una función que calcule el promedio de los elementos de una pila,
*para ello hacer también una función que calcule la suma, otra para la cuenta y otra que divida.
*En total son cuatro funciones, y la función que calcula el promedio invoca a las otras 3.
*/

int sumarTodos(Pila* pila)
{
    int suma=0;
    Pila pilaAux;
    inicpila(&pilaAux);
    while(!pilavacia(pila))
    {
        suma+=tope(pila);
        apilar(&pilaAux,desapilar(pila));
    }
    while(!pilavacia(&pilaAux))
    {
        apilar(pila,desapilar(&pilaAux));
    }
    printf("Suma finalizada");
    return suma;
}
int contarTodos(Pila* pila)
{
    int contador=0;
    Pila pilaAux;
    inicpila(&pilaAux);
    while(!pilavacia(pila))
    {
        contador++;
        apilar(&pilaAux,desapilar(pila));
    }
    pasarElementos(&pilaAux,pila);
    return contador;
}
float division(int dividendo,int divisor)
{
    float razon=(float) dividendo/divisor;
    return razon;
}
void calcularPromedio(Pila* pila)
{
    printf("El promedio de la pila es de : %.2f\n",division(sumarTodos(pila),contarTodos(pila)));
}
/**
*10. Hacer una función que reciba una pila con números de un solo dígito
(es responsabilidad de quien usa el programa) y que transforme esos dígitos en un número decimal.
*/

void convertirLineal(Pila* pila)
{
    int num=0,cantidad=contarTodos(pila);
    Pila pilaAux;
    inicpila(&pilaAux);
    for (int i=cantidad-1;i>=0;i--)
    {
        num+=tope(pila)* potencia(10,i);
        apilar(&pilaAux,desapilar(pila));
    }
    pasarElementos(&pilaAux,pila);
    printf("El numero resultante es: %i\n",num);
}
int potencia(int base,int exponente){
    int resultado=1;
    for(int i=1;i<=exponente;i++){
        resultado*=base;
    }
    return resultado;
}
