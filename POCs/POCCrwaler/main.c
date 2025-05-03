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
    inicializarJugador(&jugador, "Jugador 1",&mapa);
    inicializarMapa(&mapa, 100);
    struct Item oro;
    oro.cantidad=500;
    strcpy(oro.nombre,"Oro");
    jugador.items[0]=oro;


    // Mostrar mapa con el jugador
    //dibujarMapa(&jugador, &mapa);



    while (1) {
        system("cls");
        dibujarMapa(&jugador, mapa);

        mostrarJugador(&jugador); // Mostrar información del jugador

        // Capturar dirección del jugador
        enum Direccion direccion = capturarDireccion();
        //moverJugador(&jugador, direccion); // Mover al jugador
        mapa.diaActual++;
        jugador.habitacionActual=mapa.habitaciones[mapa.diaActual];
}
}
