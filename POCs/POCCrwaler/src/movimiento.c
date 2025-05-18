#include <stdio.h>
#include <stdlib.h>
#include "movimiento.h"

Direccion capturarDireccion()
{
    int status=1;

    int aux;
    while(status)
    {
        char tecla = getch();
        switch (tecla)
        {
        case '1':
            aux=0;
            status=0;
            break;
        case '2':
            aux=1;
            status=0;
            break;
        case '3':
            aux=2;
            status=0;
            break;
        case '4':
            aux=3;
            status=0;
            break;
        case 'n':
            aux=4;
            status=0;
            break;
        default:
            break;

        }
    }
    return aux;
}

void moverJugador(Mapa *mapa,Direccion direccion, Jugador* jugador)
{
    seleccionarEvento(mapa->habitaciones[mapa->diaActual].eventos[direccion],jugador);
    mapa->diaActual++;

}


