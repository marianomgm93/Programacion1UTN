#include <stdio.h>
#include "mapa.h"
#define VENTANA_ANCHO 20
#define VENTANA_ALTO 10
#include "habitacion.h"

void inicializarMapa(struct Mapa* mapa,int dias)
{
    mapa->diasTotales=dias;
    mapa->diaActual=0;
    for(int i=0; i<mapa->diasTotales; i++)
    {
        inicializarHabitacion(&(mapa->habitaciones[i]),i);

    }
}

void dibujarMapa(struct Jugador* jugador,struct Mapa mapa)
{
    char tipo[DIM];

    for(int i=0; i<MAX_EVENTOS; i++)
    {
        switch(mapa.habitaciones[i].eventos[i].tipo)
        {
        case TESORO:
            strcpy(tipo,"TESORO");
            break;
        case MISION:
            strcpy(tipo,"MISION");
            break;
        case COMBATE:
            strcpy(tipo,"COMBATE");
            break;
        case TIENDA:
            strcpy(tipo,"TIENDA");
            break;
        }
        printf("Camino %i: %s\n",i+1,tipo);

    }
}


