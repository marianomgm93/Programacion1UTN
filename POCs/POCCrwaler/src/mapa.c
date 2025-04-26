#include <stdio.h>
#include "mapa.h"

void inicializarMapa(struct Mapa *mapa,int alto,int ancho,char simbolo)
{
    mapa->alto=alto;
    mapa->ancho=ancho;
    for(int y=0; y<alto; y++)
    {
        for(int x=0; x<ancho; x++)
        {
            mapa->celdas[y][x]=simbolo;
        }
    }
}

void dibujarMapa(struct Jugador *jugador, struct Mapa *mapa)
{
    float rVisionBase = (mapa->alto * mapa->ancho) * 0.02;
    int rVisionJugador = (int)(rVisionBase + 0.005 * jugador->stats.inteligencia);
    //delimitado
    int minY = jugador->posicion.y - rVisionJugador;
    if (minY < 0) minY = 0;

    int maxY = jugador->posicion.y + rVisionJugador;
    if (maxY >= mapa.alto) maxY = mapa.alto - 1;

    int minX = jugador->posicion.x - rVisionJugador;
    if (minX < 0) minX = 0;

    int maxX = jugador->posicion.x + rVisionJugador;
    if (maxX >= mapa.ancho) maxX = mapa.ancho - 1;
}
