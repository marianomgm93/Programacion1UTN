#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define DIM 5
#define DIMCHAR 30

/**
14. Los resultados de las últimas elecciones a Intendente en el pueblo “La
Matrix” han sido los siguientes:...
Escribir un programa que haga las siguientes tareas:
a. Imprimir la tabla anterior con cabeceras incluidas.
b. Calcular e imprimir el número total de votos recibidos por cada candidato y
el porcentaje total de votos emitidos. Así mismo, visualizar el candidato más
votado.
c. Si algún candidato recibe más del 50% de los votos, el programa imprimirá
un mensaje declarándolo ganador.
d. Si algún candidato recibe menos del 50% de los votos, el programa debe
imprimir el nombre de los dos candidatos más votados que serán los que
pasen a la segunda ronda de las elecciones.
*/
void elecciones()
{
    int TABLERO[][DIM]= {{1,194,48,206,45},{2,180,20,320,16},{3,221,90,140,20},{4,432,51,821,14},{5,820,61,946,18}};
    char fila0[][DIMCHAR]= {"Distrito","Candidato A","Candidato B","Candidato C","Candidato D"};
    int totales[DIM];
    float porcentajes[DIM];

    imprimirEncabezado(fila0,DIM);
    imprimirMatriz(TABLERO,DIM,DIM);
    cargarTotales(totales,TABLERO);
    imprimirFilaExtra(totales,"Totales:",4);
    imprimirPorcentajes(totales,"Porcentajes:",4);
}
void imprimirMatriz(int matriz[][DIM],int filas,int columnas)
{
    for (int i=0; i<filas; i++)
    {
        for (int j=0; j<columnas; j++)
        {
            printf("|\t%i\t",matriz[i][j]);
        }
        printf("|\n");
    }
}
void imprimirFilaExtra(int arr[DIM],char palabra[DIMCHAR],int columnas){
            printf("| %s\t",palabra);
            for (int j=0; j<columnas; j++)
        {
            printf("|\t%i\t",arr[j]);
        }
        printf("|\n");
}
void imprimirPorcentajes(int totales[DIM],char palabra[DIMCHAR],int columnas){
        int total=sumarFila(totales,columnas);
            printf("| %s\t",palabra);
            for (int j=0; j<columnas; j++)
        {
            printf("|\t%.2f\t",(float)(totales[j]*100)/total);
        }
        printf("|\n");
}
int sumarFila(int arr[DIM],int columnas){
    int sumaTotal=0;
    for(int i=0;i<columnas;i++){
        sumaTotal+=arr[i];
    }
    return sumaTotal;
}
void imprimirEncabezado(char fila[][DIMCHAR],int validos)
{
    for(int i=0; i<validos; i++)
    {
        printf("| %s\t",fila[i]);
    }
    printf("|\n");
}
void cargarTotales(int totales[DIM],int matriz[][DIM]){

        for (int j=1;j<DIM;j++){
                totales[j-1]=sumarColumna(matriz,DIM,j);
        }

}
int sumarColumna(int matriz[][DIM],int filas,int columna)
{
    int suma=0;
    for(int i=0; i<filas; i++)
    {
        suma+=matriz[i][columna];
    }
    return suma;
}
int main()
{
    elecciones();
    return 0;
}
