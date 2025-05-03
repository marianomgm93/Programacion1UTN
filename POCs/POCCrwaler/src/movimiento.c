#include <stdio.h>
#include "movimiento.h"
#include "evento.h"

enum Direccion capturarDireccion() {
    char tecla = getch();
    switch (tecla) {
        case '1': return 1;
        case '2': return 2;
        case '3': return 3;
        case '4': return 4;
        default: return NINGUNA;
    }
}

void moverJugador(struct Jugador* jugador, enum Direccion direccion){
    seleccionarEvento(jugador->habitacionActual.eventos[direccion-1],jugador);

}


