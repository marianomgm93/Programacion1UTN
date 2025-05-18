#ifndef MOVIMIENTO_H_INCLUDED
#define MOVIMIENTO_H_INCLUDED
#include "mapa.h"
#include "conio.h"
typedef enum{
    ARRIBA,
    ABAJO,
    IZQUIERDA,
    DERECHA,
    LEVELUP,
    NINGUNA
}Direccion;
Direccion capturarDireccion();
void moverJugador( Mapa* mapa, Direccion direccion, Jugador *jugador);

#endif // MOVIMIENTO_H_INCLUDED
