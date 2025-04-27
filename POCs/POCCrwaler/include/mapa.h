#ifndef MAPA_H_INCLUDED
#define MAPA_H_INCLUDED
#define MAX_ALTO 100
#define MAX_ANCHO 100
#define MAPDIM 20
#include "jugador.h"
#define PARED '#'
#define VACIO '.'

struct Mapa {
    int ancho;
    int alto;
    char celdas[MAX_ALTO][MAX_ANCHO];
};
void inicializarMapa(struct Mapa *mapa,int alto, int ancho);
void dibujarMapa(struct Jugador *jugador,struct Mapa *mapa);


#endif // MAPA_H_INCLUDED
