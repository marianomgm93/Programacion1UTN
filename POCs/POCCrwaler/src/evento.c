#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "evento.h"
#include "jugador.h"
#include "enemigo.h"
void inicializarEvento(Evento* evento,int nivel)
{
    evento->tipo=rand()%4;
    evento->nivelEspecial=rand()%2;
    switch(evento->tipo)
    {
    case TESORO:
        evento->datos.tesoro.cantidadOro=500*nivel;
        evento->datos.tesoro.rarezaObjeto=rand()%4;
        break;
    case COMBATE:
        //evento->datos.combate.enemigo=constructorEnemigo(nivel,rand()%4);
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
void seleccionarEvento(Evento evento, struct Jugador* jugador)
{
    switch(evento.tipo)
    {
    case TESORO:
        jugador->items[0].cantidad+=evento.datos.tesoro.cantidadOro;
        break;
    case COMBATE:
        int dmg = jugador->stats.defensa - evento.datos.combate.enemigo.stats.ataque;
        if (dmg < 0)
            jugador->vida += dmg;
        else
            printf("MISS\n");
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

