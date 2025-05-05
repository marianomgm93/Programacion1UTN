#ifndef JUGADOR_H_INCLUDED
#define JUGADOR_H_INCLUDED
#include "mapa.h"
#include "estadisticas.h"
#define INVENTARIO 30
typedef struct
{
    char nombre[30];
    int vida;
    Habitacion habitacionActual;
    Item items[INVENTARIO];
    Estadisticas stats;
    Item itemEquipado;
    int tieneItemEquipado;

} Jugador;
void inicializarJugador( Jugador *jugador, char nombre[],Mapa *mapa);
void mostrarJugador( Jugador *jugador);
void desequiparItem( Jugador *jugador);
void equiparItem( Jugador *jugador, char nombreItem[]);
void mostrarInventario( Jugador jugador);

#endif // JUGADOR_H_INCLUDED

