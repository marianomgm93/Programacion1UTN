#include <stdio.h>
#include <stdlib.h>
#include <string.h>
const int FILAS=15;
const int DIMPALABRA=30;
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
        scanf("%c",&option);
        switch(option)
        {
        case '0':
            status=OUT;
            break;
        case '1':
            printf("Ingrese la palabra a cargar:\n");
            fflush(stdin);
            gets(palabra);
            //scanf("%s",palabra);
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
*7_Hacer una función que cargue un arreglo de palabras (strings). La función debe retornar cuantas palabras se cargaron.  (puede ser a través del parámetro como puntero).

*/
void cargarString(char matriz[][DIMPALABRA],int* validos,char palabra[DIMPALABRA])
{
    strcpy(matriz[*validos],palabra);
    (*validos)++;
}
/**
*8_Hacer una función que muestre un arreglo de palabras.
*/
void mostrarStrings(char matriz[][DIMPALABRA],int validos)
{
    for(int i=0; i<validos; i++)
    {
        ;
        printf("\t%i\t%s\n",i,matriz[i]);
    }

}
/**
*9_Hacer una función que determine si un string se encuentra dentro
*de un arreglo de strings. La función recibe el arreglo, la cantidad de
*palabras que contiene y la palabra a buscar.
///devuelve el índice de la fila en que se encuentra, de lo contrario retorna -1.
*/

void menuBuscarPalabra(char matriz[][DIMPALABRA],int validos)
{
    int status=IN,presente;
    char palabra[DIMPALABRA];
    char option;
    while(status)
    {
        printf("0\tAtras\n1\tBuscar en matriz completa\n2\tBuscar en matriz ordenada\n");
        fflush(stdin);
        scanf("%c",&option);
        switch(option)
        {
        case '0':
            status=OUT;
            break;
        case '1':
            printf("Ingrese la palabra a buscar:\n");
            fflush(stdin);
            gets(palabra);
            presente=buscarPalabra(matriz,validos,palabra);
            if(presente!=-1)
            {
                printf("La palabra ya se encuentra en el arreglo\n");
            }
            else
            {
                printf("La palabra NO se encuentra en el arreglo...Todavia...\n");
            }
            break;
        case '2':
            printf("Ingrese la palabra a buscar:\n");
            fflush(stdin);
            gets(palabra);
            presente=buscarPalabraOrdenado(matriz,validos,palabra);
            if(presente!=-1)
            {
                printf("La palabra ya se encuentra en el arreglo\n");
            }
            else
            {
                printf("La palabra NO se encuentra en el arreglo...Todavia...\n");
            }
            break;
        default:
            printf("La opcion ingresada no es valida\n");
            break;
        }
    }
}
int buscarPalabra(char matriz[][DIMPALABRA],int validos,char palabra[DIMPALABRA])
{
    int flag=-1;
    for(int i=0; i<validos; i++)
    {
        if(strcmp(matriz[i],palabra)==0)
        {
            flag=i;
            return flag;
        }
    }
    return flag;
}
/**
*10. Hacer una función que determine si un string se encuentra dentro de un
*arreglo de strings ordenado alfabéticamente. La función recibe el arreglo, la
*cantidad de palabras que contiene y el string a buscar. ///devuelve el índice
*de la fila en que se encuentra, de lo contrario retorna -1
*/
int buscarPalabraOrdenado(char matriz[][DIMPALABRA],int validos,char palabra[DIMPALABRA])
{
    int flag=-1;
    int i=0;

    while(i<validos && flag!=0)
    {
        if(strcmp(matriz[i],palabra)==0)
        {
            flag=i;
        }
    }
    return flag;
}
/**
*11.Hacer una función (o varias) que ordene un arreglo de palabras por orden
*alfabético. (Por selección o inserción, el que más te guste)
*/
void ordenamientoPorInsercion(char matriz[][DIMPALABRA],int validos)
{
    int flag=0;
    char aux[DIMPALABRA];
    for(int i=0; i<validos-1; i++)
    {
        strcpy(aux,matriz[i+1]);
        insertarElemento(matriz,i,aux);
    }
}
void insertarElemento(char matriz[][DIMPALABRA],int ultimaPosicion,char palabra[DIMPALABRA]){
        int j=ultimaPosicion;
        while(j>=0 && strcmp(matriz[j],palabra)>0)//hasta que palabra sea <= que matriz[j]
        {
            strcpy(matriz[j+1],matriz[j]);
            j--;
        }
        strcpy(matriz[j+1],palabra);
}
    void menu(char matriz[][DIMPALABRA],int* validos)
    {

        char option;
        int status=IN;
        while(status==IN)
        {
            printf("0\tSalir\n1\tMostrar strings\n2\tCargar strings\n3\tBuscar palabra\n"
                   "4\tOrdenar (Por Insercion)\n");
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
            case '3':
                menuBuscarPalabra(matriz,*validos);
                break;
            case '4':
                ordenamientoPorInsercion(matriz,*validos);
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
