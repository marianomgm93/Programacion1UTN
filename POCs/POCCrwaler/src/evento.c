#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "evento.h"
#include "jugador.h"
void inicializarEvento(Evento* evento)
{
    evento->tipo=rand()%4;
    evento->nivelEspecial=rand()%2;

    switch(evento->tipo)
    {
    case TESORO:
        evento->datos.tesoro.cantidadOro=500;
        evento->datos.tesoro.rarezaObjeto=rand()%4;
        break;
    case COMBATE:
        evento->datos.combate.enemigos=rand()%3;
        evento->datos.combate.nivelEnemigos=rand()%10+1;
        break;
    case MISION:
        //evento->datos.mision.idObjeto="";
        break;
    case TIENDA:
        //evento->datos.tienda.itemsEnVenta
        evento->datos.tienda.puedeDescansar=1;
        break;
    }
}
void seleccionarEvento(Evento evento, struct Jugador* jugador){
        switch(evento.tipo)
    {
    case TESORO:
        jugador->items[0].cantidad+=evento.datos.tesoro.cantidadOro;
        break;
    case COMBATE:
        jugador->vida--;
        break;
    case MISION:
        //evento->datos.mision.idObjeto="";
        break;
    case TIENDA:
        //evento->datos.tienda.itemsEnVenta
        jugador->items[0].cantidad-=100;
        break;
    }



}

