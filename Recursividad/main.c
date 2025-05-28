#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//1
/**
1. Calcular el factorial de un número en forma recursiva.
*/
int factorial(int num)
{
    int resultado;
    if(num==0)
        resultado=1;
    else
    {
        resultado=(num*factorial(num-1));
    }
    return resultado;
}
/**
2. Calcular la potencia de un número en forma recursiva
*/
int pot(int num,int potencia)
{
    int resultado;
    if(potencia==0)
        resultado=1;
    else
    {
        resultado=num*pot(num,potencia-1);
    }
    return resultado;
}
/**
3. Recorrer un arreglo y mostrar sus elementos en forma recursiva.
*/
void recorrerArregloRecursivo(int arr[],int validos, int i)
{
    if (validos>i)
    {
        printf(" |%d| ", arr[i]);
        recorrerArregloRecursivo(arr,validos,i+1);
    }
}
/**
4. Recorrer un arreglo comenzando desde la posición 0 y mostrar sus elementos en
forma invertida (recursivo).
*/

void recorrerArregloRecursivoInverso(int arr[],int validos, int i)
{
    if (validos>i)
    {
        recorrerArregloRecursivoInverso(arr,validos,i+1);
        printf(" |%d| ", arr[i]);
    }
}
/**
5. Determinar en forma recursiva si un arreglo es capicúa.
*/
int esCapicua(int arr[],int validos,int i)
{
    int resultado;
    if(validos/2-i==0)
        resultado=1;
    else
    {
        resultado=(arr[i]==arr[validos-1-i])? 1:0;
        if(resultado)
            resultado=esCapicua(arr,validos,i+1);
    }
    return resultado;
}
/**
6. Sumar en forma recursiva los elementos de un arreglo de enteros y retornar el total de
la suma.
*/
int sumarArrRecursiva(int arr[], int validos, int posicion)
{

    return (posicion<validos) ? arr[posicion]+sumarArrRecursiva(arr,validos,posicion+1) : 0;
}
/**
7. Buscar el menor elemento de un arreglo en forma recursiva.
*/
int buscaMenorRecursiva(int arr[],int validos, int posicion, int posicionMenor)
{

    return ((posicion<validos-1) ? ((arr[posicion]<arr[posicionMenor]) ? buscaMenorRecursiva(arr,validos,posicion+1,posicion):buscaMenorRecursiva(arr,validos,posicion+1,posicionMenor)): (arr[posicion]<arr[posicionMenor])? arr[posicion]:arr[posicionMenor]);

}
/**
8. Buscar el menor elemento de un archivo de números enteros de forma recursiva.
(desde el mismo archivo)
*/
void mostrarArchivo(char nombreArchivo[])
{
    FILE* buffer=fopen(nombreArchivo,"rb");
    int num;
    if(buffer)
    {
        printf("Numeros en archivo:\n");
        while(fread(&num,sizeof(int),1,buffer))
        {
            printf("%i\n",num);
        }
        printf("FIN\n");
        fclose(buffer);
    }
}
int leerArchivo(FILE* buffer,int posicion)
{
    int num;
    fseek(buffer,posicion*sizeof(int),SEEK_SET);
    fread(&num,sizeof(int),1,buffer);
    fseek(buffer,0,SEEK_SET);
    return num;
}


int menorArchivo(FILE *buffer)
{
    int num;
    int menor;
    if(fread(&num,sizeof(int),1,buffer)>0)
    {
        menor=menorArchivo(buffer);
        menor = num<menor?num:menor;
    }
    else
    {
        rewind(buffer);
        fread(&menor,sizeof(int),1,buffer);
    }

    return menor;
}
/**
9. Invertir los elementos de un archivo de números enteros de
forma recursiva. (si no te sale, primero proba con invertir
los elementos de un arreglo de int)
*/
int invertirArchivo(FILE * buffer){
    int num1,num2;
    if()

}
int main()
{
    srand(time(NULL));
    ///1
    printf("5! = %d\n",factorial(5));
    ///2
    printf("5^5 = %d\n",pot(5,5));
    ///3
    int arr1[]= {1,2,3,4,5};
    int validos=5;
    int i=0;
    recorrerArregloRecursivo(arr1,validos,i);
    printf("\n");
    ///4
    recorrerArregloRecursivoInverso(arr1,validos,i);
    printf("\n");
    ///5
    int arrCapicua[]= {1,2,3,2,1};
    (esCapicua(arrCapicua,5,0)) ? printf("Es Capicua :)\n") : printf("No es capicua :(\n");
    ///6
    printf("La suma total del arreglo es: %i\n",sumarArrRecursiva(arr1,validos,0));
    ///7
    printf("El menor del arreglo es : %i\n",buscaMenorRecursiva(arr1,validos,0,0));
    ///8
    int random;
    FILE * buffer=fopen("numeros","wb");
    for(int i=0; i<validos; i++)
    {
        random=rand()%10+1;
        fwrite(&random,sizeof(int),1,buffer);
    }
    fclose(buffer);

    mostrarArchivo("numeros");
    buffer=fopen("numeros","rb");
    printf("El menor del arreglo es : %i\n",menorArchivo(buffer));
    fclose(buffer);
    ///9


    return 0;
}
