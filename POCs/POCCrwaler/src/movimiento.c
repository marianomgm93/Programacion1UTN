#include <stdio.h>
#include "movimiento.h"


enum Direccion capturarDireccion() {
    char tecla = getch();
    switch (tecla) {
        case 'w': return ARRIBA;
        case 's': return ABAJO;
        case 'a': return IZQUIERDA;
        case 'd': return DERECHA;
        default: return NINGUNA;
    }
}

void moverJugador(struct Jugador *jugador, enum Direccion direccion){
    switch(direccion){
        case ARRIBA:
            if (jugador->posicion.y > 0)
                jugador->posicion.y -= 1;
            else
                printf("No puedo moverme más hacia arriba.\n");
            break;
        case ABAJO:
            if (jugador->posicion.y < MAPDIM - 1)
                jugador->posicion.y += 1;
            else
                printf("No puedo moverme más hacia abajo.\n");
            break;
        case IZQUIERDA:
            if (jugador->posicion.x > 0)
                jugador->posicion.x -= 1;
            else
                printf("No puedo moverme más hacia la izquierda.\n");
            break;
        case DERECHA:
            if (jugador->posicion.x < MAPDIM - 1)
                jugador->posicion.x += 1;
            else
                printf("No puedo moverme más hacia la derecha.\n");
            break;
        default:
            // No hacer nada
            break;
    }
}
