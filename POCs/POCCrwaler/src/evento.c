#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "evento.h"
#include <conio.h>
void inicializarEvento(Evento* evento,int nivel)
{
    evento->tipo=rand()%4;
    evento->nivelEspecial=rand()%2;
    TipoEnemigo tipo=rand()%4;
    Enemigo ene=constructorEnemigo(nivel,tipo);
    switch(evento->tipo)
    {
    case TESORO:
        evento->datos.tesoro.cantidadOro=500*nivel;
        evento->datos.tesoro.rarezaObjeto=rand()%4;
        break;
    case COMBATE:
        evento->datos.combate.enemigo=ene;
        break;
    case MISION:
        strcpy(evento->datos.mision.idObjeto,"");
        break;
    case TIENDA:
        //evento->datos.tienda.itemsEnVenta;
        evento->datos.tienda.puedeDescansar=1;
        break;
    }
}
void seleccionarEvento(Evento evento,  Jugador* jugador)
{
    int dmg;
    switch(evento.tipo)
    {
    case TESORO:
        jugador->items[0].cantidad+=evento.datos.tesoro.cantidadOro;
        break;
    case COMBATE:
        /* dmg = (jugador->stats.defensa) - (evento.datos.combate.enemigo.stats.ataque);
         if (dmg < 0)
             jugador->vida += dmg;
         else
             printf("MISS\n");*/
        break;
    case MISION:
        break;
    case TIENDA:
        //evento->datos.tienda.itemsEnVenta
        jugador->items[0].cantidad-=100;
        break;
    }



}

///el pelotude este hizo esto:

int combate(Jugador *jugador, Enemigo* enemigo)
{
    int resultado=0;

    printf("Te encuentras con un enemigo: %s\n");
    int inicia=calcular_iniciativa_combate(jugador->stats,enemigo->stats);
    int status=1;
    char option;
    while(status)
    {
        printf("1\tAtacar\n2\tItem\n0\tHuir\n");
        option=getch();
        switch(option)
        {
        case '1':
            break;
        case '2':
            break;
        case '0':
            break;

        default:
            printf("Dale bobo, ingresa una accion valida\n");
            break;

        }
    }





    return resultado;
}

int calcular_iniciativa_combate(Estadisticas jugador, Estadisticas monstruo)
{
    int iniciativa_j,iniciativa_m;

    iniciativa_j=jugador.velocidad/10+rand()%11;
    iniciativa_m=monstruo.velocidad/10+rand()%11;

    return (iniciativa_j>iniciativa_m) ? 1 : 0;
}

