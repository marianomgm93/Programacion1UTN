#ifndef MAPA_H_INCLUDED
#define MAPA_H_INCLUDED
#include "habitacion.h"
#define LARGO_PARTIDA 100

typedef struct {
    int diasTotales;
    int diaActual;
    Habitacion habitaciones[LARGO_PARTIDA];
} Mapa;

void inicializarMapa(Mapa *mapa,int diasTotales);
void dibujarMapa( Jugador *jugador,Mapa mapa);


#endif // MAPA_H_INCLUDED
