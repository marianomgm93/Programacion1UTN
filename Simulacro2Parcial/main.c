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

    }
    while(option);

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
void cargarArregloGalaxias(Galaxia arr[], int* validos)
{
    int option;
    do
    {
        arr[*validos]=crearGalaxia();
        (*validos)++;
        printf("Desea cargar otra galaxia?\n1\tCargar otra galaxia\n0\tSalir\n");
        scanf("%i",&option);
    }
    while(option);

}
///2_Mostrar//////////////////////
void planetaToString(Planeta pla)
{
    puts("///////////////PLANETA//////////////////");
    printf("%s\n",pla.nombrePlaneta);
    printf("Estrella: %s\n",pla.estrella);
    printf("Cantidad de satelites: %d\n",pla.cantidadSatelites);
    printf("%.2f\n",pla.masa);
    printf("Temperatura Maxima: %d\n",pla.tempMax);
    printf("Temperatura Minima: %d\n",pla.tempMin);
    puts("///////////////////////////////////////");

}
void toString(Galaxia gal)
{
    puts("///////////////GALAXIA//////////////////");
    printf("Galaxia: %s\n",gal.nombreGalaxia);
    printf("Tipo: %s\n",gal.tipoGalaxia);
    printf("Descubierto por: %s\n",gal.descubiertoPor);
    printf("Planetas:\n");
    for(int i=0; i<gal.valPlanetas; i++)
    {
        planetaToString(gal.listaPlanetas[i]);
    }
    puts("///////////////////////////////////////");



}
void mostrarArrGalaxias(Galaxia arr[],int validos)
{
    for(int i=0; i<validos; i++)
    {
        toString(arr[i]);
    }

}
void mostrarArrGalaxiasConTipo(Galaxia arr[],int validos,char tipoGalaxia[])
{
    for(int i=0; i<validos; i++)
    {
        if(strcmpi(arr[i].tipoGalaxia,tipoGalaxia)==0)
        {
            toString(arr[i]);
        }
    }

}
///3. contar satelites////////////////
int contarSatelitesPlaneta(Planeta arr[],int validos)
{
    return(validos-1>=0) ? arr[validos-1].cantidadSatelites+contarSatelitesPlaneta(arr,validos-1) : 0;
}

int contarSatelitesGalaxia(Galaxia arr[],int validos)
{
    int totalSat=0;
    for (int i=0; i<validos; i++)
    {
        totalSat+=contarSatelitesPlaneta(arr[i].listaPlanetas,arr[i].valPlanetas);
    }
    return totalSat;
}
///4. Archivo///////////////////////
void persistirArr(Galaxia arr[], int validos, char nombreArchivo[])
{
    FILE* buffer= fopen(nombreArchivo,"ab");
    int i=0;
    Galaxia gal;
    if(buffer)
    {
        while(i<validos)
        {
            gal=arr[i];
            fwrite(&gal,sizeof(Galaxia),1,buffer);
            i++;
        }
        fclose(buffer);
    }
    else
        printf("no fue posible ingresar al archivo %s\n",nombreArchivo);
}
void persistirArr(Planeta arr[], int validos, char nombreArchivo[], float masa)
{
    FILE* buffer= fopen(nombreArchivo,"ab");
    int i=0;
    Planeta pla;
    if(buffer)
    {
        while(i<validos)
        {
            pla=arr[i];
            if(pla.masa>masa)
            {
                fwrite(&pla,sizeof(Planeta),1,buffer);
            }
            i++;
        }
        fclose(buffer);
    }
    else
        printf("no fue posible ingresar al archivo %s\n",nombreArchivo);
}

///5///////////////
void levantarGalaxias(char archivo[],Galaxia** arr, int* validos)
{
    FILE* buffer = fopen(archivo,"rb");
    int i=0;
    Galaxia gal;
    if(buffer)
    {
        fseek(buffer,0,SEEK_END);
        (*validos)=ftell(buffer)/sizeof(Galaxia);
        (*arr)=malloc(sizeof(Galaxia)*(*validos));
        rewind(buffer);
        while(fread(&gal,sizeof(Galaxia),1,buffer)>0 && i<(*validos))
        {
            (*arr)[i]=gal;

            i++;
        }
        fclose(buffer);
    }
}
int main()
{
    char archivo[]="galaxias";
    char planetas[]="planetas";
    Galaxia arrGalaxias[20];
    int validosGalaxias;
    ///1
    //cargarArregloGalaxias(arrGalaxias,&validosGalaxias);
    //mostrarArrGalaxias(arrGalaxias,validosGalaxias);
    ///2
    //mostrarArrGalaxiasConTipo(arrGalaxias,validosGalaxias,"espiral");
    ///3
    ///4
    //persistirArr(arrGalaxias,validosGalaxias,archivo);
    ///5
    Galaxia * arrGalaxiasPersistidas;
    int validos2;
    levantarGalaxias(archivo,&arrGalaxiasPersistidas,&validos2);
    mostrarArrGalaxias(arrGalaxiasPersistidas,validos2);
    printf("%d\n",contarSatelitesPlaneta(arrGalaxiasPersistidas[0].listaPlanetas,arrGalaxiasPersistidas[0].valPlanetas));
    printf("La Cantidad de satelites del arreglo de galaxias es: %i\n",contarSatelitesGalaxia(arrGalaxiasPersistidas,validos2));
    return 0;
}
