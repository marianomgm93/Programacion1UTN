#include <stdio.h>
#include "evento.h"

void inicializarEvento(struct Evento evento)
{
    evento->tipo=rand()%4;
    evento->nivelEspecial=rand()%2;

    switch(evento->tipo)
    {
    case TESORO:
        evento->datos.tesoro.cantidadOro=500;
        evento->datos.tesoro.rarezaObjeto=rand()%4;
    case COMBATE:
        evento->datos.combate.enemigos=rand()%3;
        evento->datos.combate.nivelEnemigos=rand()%10+1;
    case MISION:
        evento->datos.mision.idObjeto="";
    case TIENDA:
        //evento->datos.tienda.itemsEnVenta
        evento->datos.tienda.puedeDescansar=1;
    }
}
