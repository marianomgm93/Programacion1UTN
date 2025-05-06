#include <stdio.h>
#include <stdlib.h>
#include "movimiento.h"

enum Direccion capturarDireccion()
{
    char tecla = getch();
    int aux;
    switch (tecla)
    {
    case '1':
        aux=1;
        break;
    case '2':
        aux=2;
        break;
    case '3':
        aux=3;
        break;
    case '4':
        aux=4;
        break;
    default:
        break;

    }
}

void moverJugador(Mapa mapa,enum Direccion direccion, Jugador* jugador)
{
    seleccionarEvento(mapa.habitaciones[mapa.diaActual].eventos[direccion-1],jugador);

}


