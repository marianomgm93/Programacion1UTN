#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define DIM 68
#define IN 1
#define OUT 0
/**
1_Tenes que guardar en un arreglo los nombres de los chicos que
desaprobaron y, cada 3 alumnos poner un guion (el guion debe ser una
posición en el arreglo, es decir, arreglo[0]=juan, arreglo[1]=perez,
arreglo[2]=carlos, arreglo[3]= ----, arreglo[4]=alejandro). La función debe ser
útil para un arreglo de cualquier dimensión. es decir, tiene que ser útil
para “char desaprobados[6][52]” y también para ”char tonotos[150][68]”
*/

void cargarNombres(char arr[][DIM],int* validos)
{
    char nombre[DIM];
    char option;
    int contador=0,status=IN;


    while(status)
    {
        printf("Desea cargar un nuevo nombre?\n");
        fflush(stdin);
        scanf("%c",&option);
        switch(option)
        {
        case '0':
            status=OUT;
            break;
        case '1':
            if((*validos)%3==0 && validos!=0)
            {
                strcpy(arr[*validos],"-");
                (*validos)++;
            }


            printf("Ingrese un nuevo nombre\n");
            fflush(stdin);
            gets(nombre);
            strcpy(arr[*validos],nombre);

            (*validos)++;
            break;
        }
    }
}
void showArr(char arr[][DIM],int validos)
{
    printf("mostrando arreglo:\n{\n");
    for(int i=0; i<validos; i++)
    {
        printf("%s\n",arr[i]);
    }
    printf("}\n");


}
int main()
{
    char desaprobados[6][52];
    int validos=0;
    char tonotos[150][68];
    cargarNombres(desaprobados,&validos);
    showArr(desaprobados,validos);
    return 0;
}
