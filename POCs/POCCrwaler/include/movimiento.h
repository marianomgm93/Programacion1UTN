#ifndef MOVIMIENTO_H_INCLUDED
#define MOVIMIENTO_H_INCLUDED
#include "mapa.h"
#include "conio.h"
enum Direccion {
    ARRIBA,
    ABAJO,
    IZQUIERDA,
    DERECHA,
    NINGUNA
};
enum Direccion capturarDireccion();
void moverJugador( Mapa mapa, enum Direccion direccion, Jugador *jugador);

#endif // MOVIMIENTO_H_INCLUDED
