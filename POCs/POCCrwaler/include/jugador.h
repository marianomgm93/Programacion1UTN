#ifndef JUGADOR_H_INCLUDED
#define JUGADOR_H_INCLUDED

#include "item.h"
#include "estadisticas.h"

struct Coordenada {
    int x;
    int y;
};

struct Jugador {
    char nombre[30];
    int vida;
    struct Coordenada posicion;
    struct Item items[DIM];
    struct Estadisticas stats;
    struct Item itemEquipado;
    int tieneItemEquipado;
};

void mostrarJugador(struct Jugador jugador);
void desequiparItem(struct Jugador *jugador);
#endif // JUGADOR_H_INCLUDED

