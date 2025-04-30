#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mapa.h"
#include <time.h>
#include "jugador.h"
#include "movimiento.h"
int main() {
    srand(time(NULL));
    struct Jugador jugador;
    struct Mapa mapa;

    // Inicialización
    inicializarJugador(&jugador, "Jugador 1");
    inicializarMapa(&mapa, 100, 100);

    // Colocamos algunas paredes internas (¡como diseñamos!)
    mapa.celdas[2][3] = '#';
    mapa.celdas[2][4] = '#';
    mapa.celdas[4][5] = '#';
    mapa.celdas[7][3] = '#';

    // Inicializamos al jugador    jugador.posicion.x = 1; // Empezamos en una casilla libre
    jugador.posicion.y = 1;

    // Mostrar mapa con el jugador
    //dibujarMapa(&jugador, &mapa);


    while (1) {
        system("cls");
        //dibujarMapa(&jugador, &mapa); // Mostrar el mapa
        mostrarJugador(&jugador); // Mostrar información del jugador

        // Capturar dirección del jugador
        enum Direccion direccion = capturarDireccion();
        moverJugador(&jugador, direccion); // Mover al jugador
}
}
