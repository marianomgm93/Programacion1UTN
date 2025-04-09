#include <stdio.h>
#include <stdlib.h>
#include <string.h>
const int FILAS=3;
const int DIMPALABRA=15;
const int IN=1;
const int OUT=0;
void menuCargarString(char matriz[][DIMPALABRA],int* validos)
{
    int status=IN;
    char option;
    char palabra[DIMPALABRA];
    while(status)
    {
        printf("0\tSalir\n1\tCargar String\n");
        fflush(stdin);
        scanf('%c',&option);
        switch(option)
        {
        case '0':
            status=OUT;
            break;
        case '1':
            printf("Ingrese la palabra a cargar:\n");
            fflush(stdin);
            scanf("%s",palabra);
            cargarString(matriz,validos,palabra);
            break;
        default:
            printf("La opcion ingresada no es valida");
            break;

        }
    }
}
/**
*@Param
*/
void cargarString(char matriz[][DIMPALABRA],int* validos,char palabra[])
{
    strcpy(matriz[*validos],palabra);
    *(validos++);
}
void mostrarStrings(char matriz[][DIMPALABRA],int validos)
{
    for(int i=0; i<validos; i++)
    {
        printf("%s\n",matriz[i]);
    }

}
void menu(char matriz[][DIMPALABRA],int* validos)
{

    char option;
    int status=IN;
    while(status==IN)
    {
        printf("0\tSalir\n1\tMostrar strings\n2\tCargar strings\n");
        scanf(" %c",&option);

        switch(option)
        {
        case '0':
            printf("Saliendo!\n");
            status=OUT;
            break;
        case '1':
            mostrarStrings(matriz,*validos);
            break;
        case '2':
            menuCargarString(matriz,validos);
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
    char matriz[FILAS][DIMPALABRA];
    int validos=0;
    menu(matriz,&validos);
    return 0;
}
