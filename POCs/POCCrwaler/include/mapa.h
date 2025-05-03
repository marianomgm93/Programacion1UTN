#ifndef MAPA_H_INCLUDED
#define MAPA_H_INCLUDED
#define MAX_ALTO 100
#define MAX_ANCHO 100
#define MAPDIM 20
#include "jugador.h"
#define PARED '#'
#define VACIO '.'
#define LARGO_PARTIDA 100
#include "habitacion.h"
#include "evento.h"
struct Mapa {
    int diasTotales;
    int diaActual;
    Habitacion habitaciones[LARGO_PARTIDA];
};
void inicializarMapa(struct Mapa *mapa,int diasTotales);
void dibujarMapa(struct Jugador *jugador,struct Mapa mapa);


#endif // MAPA_H_INCLUDED
