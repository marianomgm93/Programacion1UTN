#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mapa.h"
#include <time.h>
#include "jugador.h"
#include "movimiento.h"
/*
LO ULTIMO QUE HICE FUE CREAR LA CLASE ENEMIGO, SE DEBE PROSEGUIR CON EL SISTEMA DE COMBATE.

*/
int main() {
    srand(time(NULL));
    Jugador jugador;
    Mapa mapa;

    // Inicialización
    inicializarMapa(&mapa, 100);
    inicializarJugador(&jugador, "Jugador 1",&mapa);
     Item oro;
    oro.cantidad=500;
    strcpy(oro.nombre,"Oro");
    jugador.items[0]=oro;

    // Mostrar mapa con el jugador
    //dibujarMapa(&jugador, &mapa);



    while (1) {
        system("cls");
        dibujarMapa(&jugador, mapa);

        mostrarJugador(&jugador); // Mostrar información del jugador

        printf("Dia Actual: %i\n",mapa.diaActual);
        // Capturar dirección del jugador
        enum Direccion direccion = capturarDireccion();
        moverJugador(&jugador, direccion); // Mover al jugador
        mapa.diaActual++;

        jugador.habitacionActual=mapa.habitaciones[mapa.diaActual];
}
}
