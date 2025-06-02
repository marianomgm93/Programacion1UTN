#include <stdio.h>
#include <stdlib.h>
#include <string.h>
///CLASES//////////////////////////////////////
typedef struct
{
    char nombrePlaneta [20];
    char estrella [20];
    int cantidadSatelites;
    float masa; ///(se mide en relación a la Tierra, por ejemplo Neptuno es 17,14 Tierras)
    int tempMax;
    int tempMin;
} Planeta;

typedef struct
{
    char nombreGalaxia [20];
    char tipoGalaxia [20]; ///elíptica, lenticular, espiral, irregular, etc
    char descubiertoPor [20];
    Planeta listaPlanetas[20];
    int valPlanetas;
} Galaxia;

///FUNCIONES///////////////////////

Planeta constructorPlaneta(char nombre[],char estrella[], int cantSat, float masa, int tMax, int tMin)
{
    Planeta planetin;
    strcpy(planetin.nombrePlaneta,nombre);
    strcpy(planetin.estrella,estrella);
    planetin.cantidadSatelites=cantSat;
    planetin.masa=masa;
    planetin.tempMax=tMax;
    planetin.tempMin=tMin;
    return planetin;
}
Galaxia constructorGalaxia(char nombre[], char tipo[],char descubridor[],Planeta lista[],int validos)
{
    Galaxia gal;
    strcpy(gal.nombreGalaxia,nombre);
    strcpy(gal.tipoGalaxia,tipo);
    strcpy(gal.descubiertoPor, descubridor);
    for(int i=0; i<validos; i++)
    {
        gal.listaPlanetas[i]=lista[i];
    }
    gal.valPlanetas=validos;
    return gal;
}
Planeta crearPlaneta()
{
    char nombre[20];
    char estrella[20];
    int cantSat;
    float masa;
    int tMax;
    int tMin;

    printf("Ingrese el nombre del planeta\n");
    fflush(stdin);
    gets(nombre);
    printf("Ingrese estrella\n");
    gets(estrella);
    printf("Ingrese cantidad de satelites\n");
    scanf("%d",&cantSat);
    printf("Ingrese la Masa\n");
    scanf("%f",&masa);
    printf("Ingrese la temperatura maxima\n");
    scanf("%d", &tMax);
    printf("Ingrese la  temperatura minima\n");
    scanf("%d", &tMin);
    return constructorPlaneta(nombre,estrella,cantSat,masa,tMax,tMin);
}
void cargarArregloPlanetas(Planeta arr[], int* validos)
{
    int option;
    do
    {
        arr[*validos]=crearPlaneta();
        (*validos)++;
        printf("Desea cargar un nuevo planeta?\n1\tCargar Nuevo Planeta\n0\tSalir\n");
        scanf("%d",&option);

    }while(option);

}
Galaxia crearGalaxia()
{
    char nombreGalaxia [20];
    char tipoGalaxia [20]; ///elíptica, lenticular, espiral, irregular, etc
    char descubiertoPor [20];
    Planeta listaPlanetas[20];
    int valPlanetas;
    printf("Ingrese nombre de la galaxia\n");
    fflush(stdin);
    gets(nombreGalaxia);
    printf("Ingrese tipo de galaxia\n");
    fflush(stdin);
    gets(tipoGalaxia);
    printf("Ingrese nombre del descubridor\n");
    fflush(stdin);
    gets(descubiertoPor);
    cargarArregloPlanetas(listaPlanetas,&valPlanetas);
    return constructorGalaxia(nombreGalaxia,tipoGalaxia,descubiertoPor,listaPlanetas,valPlanetas);
}
///2_Mostrar//////////////////////
void planetaToString(Planeta pla){
    puts("///////////////PLANETA//////////////////");
    printf("%s\n",pla.nombrePlaneta);
    printf("Estrella: %s\n",pla.estrella);
    printf("Cantidad de satelites: %d\n",pla.cantidadSatelites);
    printf("%.2f\n",pla.masa);
    printf("Temperatura Maxima: %d\n",pla.tempMax);
    printf("Temperatura Minima: %d\n",pla.tempMin);
    puts("///////////////////////////////////////");

}
void toString(Galaxia gal){
    puts("///////////////GALAXIA//////////////////");
    printf("Galaxia: %s\n",gal.nombreGalaxia);
    printf("Tipo: %s\n",gal.tipoGalaxia);
    printf("Descubierto por: %s\n",gal.descubiertoPor);
    printf("Planetas:\n");
    for(int i=0;i<gal.valPlanetas;i++){
        planetaToString(gal.listaPlanetas[i]);
    }
    puts("///////////////////////////////////////");



}
int main()
{
    Galaxia gal;
    printf("1\tNueva Galaxia\n");
    gal=crearGalaxia();
    toString(gal);
    return 0;
}
