#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "jugador.h"
void inicializarJugador( Jugador* jugador, char nombre[], Mapa* mapa)//no mas mapa
{
    strcpy(jugador->nombre,nombre);
    jugador->vida=rand()%11+10;
    jugador->habitacionActual=mapa->habitaciones[mapa->diaActual];///siempre 0
    memset(jugador->items,0,sizeof(jugador->items));
    jugador->stats=inicializarEstadisticas();

}

void mostrarJugador( Jugador *jugador)
{
    printf("Nombre: %s\nHP: %i\nDia actual: %i\nItems:\n", jugador->nombre, jugador->vida,jugador->habitacionActual.numeroHabitacion);

    mostrarInventario(*jugador);
    printf("Estadisticas:\n");
    printf("Ataque: %i\n", jugador->stats.ataque);
    printf("Defensa: %i\n", jugador->stats.defensa);
    printf("Velocidad: %i\n", jugador->stats.velocidad);
    printf("Suerte: %i\n", jugador->stats.suerte);
    printf("Inteligencia: %i\n", jugador->stats.inteligencia);
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
