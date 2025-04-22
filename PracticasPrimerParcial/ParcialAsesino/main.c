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

void cargarNombres(char arr[][DIM],int* validos,int* contador)
{
    char nombre[DIM];
    char option;
    int status=IN;


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
            if((*contador)==3)
            {
                strcpy(arr[*validos],"---");
                (*validos)++;
                *contador=0;
            }


            printf("Ingrese un nuevo nombre\n");
            fflush(stdin);
            gets(nombre);
            strcpy(arr[*validos],nombre);

            (*validos)++;
            (*contador)++;
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

/**
*2_Ordenarlos al revés ignorando los guiones.
*/
void insertar(char arr[][DIM],int posicion,char palabra[])
{
    int u=posicion;
    char aux[DIM];
    strcpy(aux,palabra);
    printf("pal: %s pos=%i\n",palabra,u);
    while(strcmpi(arr[u],aux)<=0 && u>=0)
    {
        if(strcmpi(arr[u],"---")!=0)
        {
            if(strcmpi(arr[u+1],"---")!=0)
            {
                strcpy(arr[u+1],arr[u]);
            }
            else
            {
                strcpy(arr[u+2],arr[u]);
            }
        }

        u--;
    }
    printf("pegando en pal: %s pos=%i\n",aux,u+1);
    if(strcmpi(arr[u+1],"---")!=0)
    {
        strcpy(arr[u+1],aux);
    }
    else
    {
        strcpy(arr[u+2],aux);
    }

}
void ordenarPorInsercion(char arr[][DIM],int validos)
{
    for(int i=1; i<validos; i++)
    {
        if (strcmpi(arr[i],"---")!=0)
        {
            insertar(arr,i-1,arr[i]);
            showArr(arr,validos);
        }
    }
}
int main()
{
    char desaprobados[6][52];
    int validos=0;
    int contador=0;
    char tonotos[150][68];
    printf("Cargando arreglo\n");
    cargarNombres(tonotos,&validos,&contador);
    showArr(tonotos,validos);
    printf("Ordenando arreglo\n");
    ordenarPorInsercion(tonotos,validos);
    showArr(tonotos,validos);
    return 0;
}
