#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "movimiento.h"
/*
*Ultimo cambio:
*Funcionalidad agregada lvlUp en jugador.
*/
int main()
{
    srand(time(NULL));
    Jugador jugador;
    Mapa mapa;

    // Inicialización
    inicializarMapa(&mapa, 100);
    inicializarJugador(&jugador, "Jugador 1");
    Item oro;
    oro.cantidad=500;
    strcpy(oro.nombre,"Oro");
    jugador.items[0]=oro;

    // Mostrar mapa con el jugador
    //dibujarMapa(&jugador, &mapa);



    while (1)
    {
        system("cls");
        dibujarMapa(mapa);

        mostrarJugador(&jugador); // Mostrar información del jugador

        printf("Dia Actual: %i\n",mapa.diaActual);
        // Capturar dirección del jugador
        Direccion direccion = capturarDireccion();
        if(direccion<4){
        moverJugador(&mapa, direccion,&jugador); // Mover al jugador
        }else if(direccion=4){
            lvlUp(&jugador);
        }
        // mapa.diaActual++; ahora en movimiento.c


    }
}
