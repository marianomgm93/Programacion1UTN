#include <stdio.h>
#include <stdlib.h>
#include "pila.h"
#include <time.h>
#include <string.h>
const int DIM=30;
const int IN=1;
const int OUT=0;
/**
Desarrollar una función (cargaArreglos) que permita cargar dos arreglos
paralelos/simultáneos (ambos con igual cantidad de elementos):
• tiposMuestras[]: almacena los tipos de muestra.
• concentracionesMuestras[]: almacena las concentraciones.
La función debe recibir por parámetro la cantidad de muestras a cargar y un modo
de carga. El modo de carga podrá ser manual donde se solicita al usuario el ingreso
de tipo y concentración para cada muestra (validar), o modo automático donde se
cargan valores aleatorios válidos tanto p/tipos como p/concentraciones. Ambos
arreglos tienen una dimensión máxima de DIM elementos (usar una cte).
*/
void cargaArreglos(char tiposMuestras[][DIM],float concentracionMuestras[DIM],int *validos,char modoCarga[30])
{
    if(strcmpi(modoCarga,"manual")==0)
    {
        cargaManual(tiposMuestras,concentracionMuestras,validos);
    }
    else if(strcmpi(modoCarga,"automatico")==0)
    {

    }
}

void cargaManual(char tiposMuestras[][DIM],float concentracionMuestras[DIM],int *validos)
{
    char tipo[DIM];
    char option;
    int status=IN;
    float concentracion;
    while(status)
    {
        printf("0\tSalir\n1\tCargar nueva muestra\n");
        fflush(stdin);
        scanf("%c",&option);
        switch(option)
        {
        case '0':
            status=OUT;
            break;
        case '1':
            printf("Ingrese el tipo de muestra\n");
            fflush(stdin);
            gets(tipo);
            do
            {
                printf("Ingrese la concentracion\n");
                fflush(stdin);
                scanf("%f",&concentracion);
                if (concentracion<=0)
                    printf("La concentracion debe ser mayor que 0\n");
            }
            while(concentracion<=0);
            cargaParalelos(tiposMuestras,concentracionMuestras,validos,tipo,concentracion);
            break;
        }

    }

}
void cargaParalelos(char arr1[][DIM],float arr2[DIM],int *validos,char dato1[],float dato2)
{
    strcpy(arr1[*validos],dato1);
    arr2[*validos]=dato2;
    (*validos)++;
}

int main()
{
    srand(time(NULL));
    char tipoMuestras[DIM][DIM];
    float concentracionesMuestras[DIM];
    int validosParalelos=0,status=IN;
    char option;
    while(status)
    {
        printf("Ingrese el numero del ejercicio que quiera hacer funcionar(0 para salir)\n");
        scanf(" %c",&option);
        switch(option)
        {
        case '0':
            status=OUT;
            break;
        case '1':
            cargaArreglos(tipoMuestras,concentracionesMuestras,&validosParalelos,"manual");
            break;
        }
    }
    return 0;
}
