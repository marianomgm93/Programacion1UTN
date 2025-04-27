#ifndef MOVIMIENTO_H_INCLUDED
#define MOVIMIENTO_H_INCLUDED
#include "mapa.h"
#include "jugador.h"
#include "conio.h"
enum Direccion {
    ARRIBA,
    ABAJO,
    IZQUIERDA,
    DERECHA,
    NINGUNA
};
enum Direccion capturarDireccion();
void moverJugador(struct Jugador *jugador, enum Direccion direccion);

#endif // MOVIMIENTO_H_INCLUDED
