#ifndef MAPA_H_INCLUDED
#define MAPA_H_INCLUDED

#include "jugador.h"
#define LARGO_PARTIDA 100
#include "habitacion.h"

typedef struct {
    int diasTotales;
    int diaActual;
    Habitacion habitaciones[LARGO_PARTIDA];
} Mapa;

void inicializarMapa(Mapa *mapa,int diasTotales);
void dibujarMapa( Jugador *jugador,Mapa mapa);


#endif // MAPA_H_INCLUDED
