#include <stdio.h>
#include <stdlib.h>
//1
/**
1. Calcular el factorial de un número en forma recursiva.
*/
int factorial(int num){
    int resultado;
    if(num==0)
        resultado=1;
    else{
        resultado=(num*factorial(num-1));
    }
    return resultado;
}
/**
2. Calcular la potencia de un número en forma recursiva
*/
int pot(int num,int potencia){
    int resultado;
    if(potencia==0)
        resultado=1;
    else{
        resultado=num*pot(num,potencia-1);
    }
    return resultado;
}
/**
3. Recorrer un arreglo y mostrar sus elementos en forma recursiva.
*/
void recorrerArregloRecursivo(int arr[],int validos, int i){
    if (validos>i){
        printf(" |%d| ", arr[i]);
        recorrerArregloRecursivo(arr,validos,i+1);
    }
}
/**
4. Recorrer un arreglo comenzando desde la posición 0 y mostrar sus elementos en
forma invertida (recursivo).
*/

void recorrerArregloRecursivoInverso(int arr[],int validos, int i){
    if (validos>i){
        recorrerArregloRecursivoInverso(arr,validos,i+1);
        printf(" |%d| ", arr[i]);
    }
}
/**
5. Determinar en forma recursiva si un arreglo es capicúa.
*/
int esCapicua(int arr[],int validos,int i){
    int resultado;
    if(validos/2-i==0)
        resultado=1;
    else{
        resultado=(arr[i]==arr[validos-1-i])? 1:0;
        if(resultado)
            resultado=esCapicua(arr,validos,i+1);
    }
    return resultado;
}
int main()
{
    //1
    printf("5! = %d\n",factorial(5));
    //2
    printf("5^5 = %d\n",pot(5,5));
    //3
    int arr1[]={1,2,3,4,5};
    int validos=5;
    int i=0;
    recorrerArregloRecursivo(arr1,validos,i);
    printf("\n");
    //4
    recorrerArregloRecursivoInverso(arr1,validos,i);
    printf("\n");
    //5
    int arrCapicua[]={1,2,3,2,1};
    (esCapicua(arrCapicua,5,0)) ? printf("Es Capicua :)\n") : printf("No es capicua :(\n");
    //6

    return 0;
}
