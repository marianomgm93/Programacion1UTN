#ifndef JUGADOR_H_INCLUDED
#define JUGADOR_H_INCLUDED
#include "habitacion.h"
#include "item.h"
#include "estadisticas.h"
#include "mapa.h"

struct Jugador {
    char nombre[30];
    int vida;
    Habitacion habitacionActual;
    struct Item items[DIM];
    struct Estadisticas stats;
    struct Item itemEquipado;
    int tieneItemEquipado;

};
void inicializarJugador(struct Jugador *jugador, char nombre[],struct Mapa* mapa);
void mostrarJugador(struct Jugador *jugador);
void desequiparItem(struct Jugador *jugador);
void equiparItem(struct Jugador *jugador, char nombreItem[]);
void mostrarInventario(struct Jugador jugador);

#endif // JUGADOR_H_INCLUDED

