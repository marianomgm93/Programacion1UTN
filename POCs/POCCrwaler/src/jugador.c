#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "jugador.h"
#include <conio.h>
#define IN 1
#define OUT 0

void inicializarJugador( Jugador* jugador, char nombre[])//no mas mapa
{
    strcpy(jugador->nombre,nombre);
    jugador->experiencia=0;
    memset(jugador->items,0,sizeof(jugador->items));
    jugador->stats=inicializarEstadisticas();

}

void mostrarJugador( Jugador *jugador)
{
    printf("Nombre: %s\nHP: %i\nExp: %i\nItems:\n", jugador->nombre, jugador->stats.vida, jugador->experiencia);

    mostrarInventario(*jugador);
    printf("Estadisticas:\n");
    printf("Ataque: %i\n", jugador->stats.ataque);
    printf("Defensa: %i\n", jugador->stats.defensa);
    printf("Velocidad: %i\n", jugador->stats.velocidad);
    printf("Suerte: %i\n", jugador->stats.suerte);
    printf("Inteligencia: %i\n", jugador->stats.inteligencia);
    printf("Puntos: %i\n",jugador->stats.puntosLibres);
    if (jugador->tieneItemEquipado)
    {
        printf("Item equipado: %s\n", jugador->itemEquipado.nombre);
    }
    else
    {
        printf("No tiene ningun item equipado.\n");
    }
}

void equiparItem( Jugador *jugador, char nombreItem[])
{
    int itemSocket = buscarItem(jugador, nombreItem);

    if (itemSocket != -1)
    {
        jugador->itemEquipado = jugador->items[itemSocket];
        jugador->tieneItemEquipado = 1;
        printf("Has equipado el ítem '%s'.\n", jugador->itemEquipado.nombre);
    }
    else
    {
        printf("El ítem '%s' no está en el inventario.\n", nombreItem);
    }
}

void desequiparItem( Jugador *jugador)
{
    if (jugador->tieneItemEquipado)
    {
        jugador->itemEquipado.nombre[0]='\0';
        jugador->itemEquipado.cantidad=0;
        jugador->tieneItemEquipado=0;
        printf("Has desequipado el ítem.\n");
    }
}
void mostrarInventario( Jugador jugador)
{

    for (int i = 0; i < DIM; i++)
    {
        if (jugador.items[i].cantidad > 0)
        {
            printf("%s.......x%i\n", jugador.items[i].nombre, jugador.items[i].cantidad);
        }
    }

}
void lvlUp(Jugador* jugador)
{
    int status=IN;
    int at=0,def=0,vel=0,sue=0,in=0,vit=0,usados=0,puntosRes;
    char option;
    while(status)
    {
        system("cls");
        usados=at+def+vel+sue+in+vit;
        puntosRes=jugador->stats.puntosLibres-usados;
        printf("Puntos restantes: %i\n",puntosRes);
        printf("1\tAtaque: %i + %i\n", jugador->stats.ataque, at);
        printf("2\tDefensa: %i + %i\n", jugador->stats.defensa, def);
        printf("3\tVelocidad: %i + %i\n", jugador->stats.velocidad, vel);
        printf("4\tSuerte: %i + %i\n", jugador->stats.suerte,sue);
        printf("5\tInteligencia: %i + %i\n", jugador->stats.inteligencia, in);
        printf("6\tVitalidad: %i + %i\n", jugador->stats.vida, vit);
        printf("R\tReset points\n");
        printf("0\tTerminar\n");

        option=getch();
        switch(option)
        {
        case '0':
            status=OUT;
            break;
        case '1':
            at+=(puntosRes>0)? 1 : 0;
            break;
        case '2':
            def+=(puntosRes>0)? 1 : 0;
            break;
        case '3':
            vel+=(puntosRes>0)? 1 : 0;
            break;
        case '4':
            sue+=(puntosRes>0)? 1 : 0;
            break;
        case '5':
            in+=(puntosRes>0)? 1 : 0;
            break;
        case '6':
            vit+=(puntosRes>0)? 1 : 0;
            break;
        case 'r':
            in=sue=vel=def=at=vit=usados=0;
            break;
        case 'R':
            in=sue=vel=def=at=vit=usados=0;
            break;
        default:
            break;
        }

    }
    aumentarStats(&(jugador->stats),at,def,vel,sue,in,vit);

}
