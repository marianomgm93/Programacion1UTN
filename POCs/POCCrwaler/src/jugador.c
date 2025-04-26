#include <stdio.h>
#include "jugador.h"
#include <string.h>
#include "estadisticas.h"
#include "item.h"

void inicializarJugador(struct Jugador jugador, char nombre[]){
    strcpy(jugador->nombre,nombre);
    jugador->vida=rand()%11+10;
    jugador->posicion.x=rand()10%;
    jugador->posicion.y=rand()10%;
    memset(jugador->items,0,sizeof(jugador->items));
    jugador->estadisticas=inicializarEstadisticas();

}
void mostrarJugador(struct Jugador jugador)
{
    printf("Nombre: %s\nHP: %i\nPosicion: %i,%i\nItems:\n", jugador.nombre, jugador.vida, jugador.posicion.x, jugador.posicion.y);
    for (int i = 0; i < DIM; i++)
    {
        if (jugador.items[i].cantidad != 0)
        {
            printf("%s.......x%i\n", jugador.items[i].nombre, jugador.items[i].cantidad);
        }
    }

    printf("Estad�sticas:\n");
    printf("Ataque: %i\n", jugador.estadisticas.ataque);
    printf("Defensa: %i\n", jugador.estadisticas.defensa);
    printf("Velocidad: %i\n", jugador.estadisticas.velocidad);
    printf("Suerte: %i\n", jugador.estadisticas.suerte);
    printf("Inteligencia: %i\n", jugador.estadisticas.inteligencia);
    if (jugador.tieneItemEquipado)
    {
        printf("�tem equipado: %s\n", jugador.itemEquipado.nombre);
    }
    else
    {
        printf("No tiene ning�n �tem equipado.\n");
    }
}

void equiparItem(struct Jugador *jugador, char nombreItem[]) {
    int itemSocket = buscarItem(jugador, nombreItem);

    if (itemSocket != -1) {
        jugador->itemEquipado = jugador->items[itemSocket];
        jugador->tieneItemEquipado = 1;
        printf("Has equipado el �tem '%s'.\n", jugador->itemEquipado.nombre);
    } else {
        printf("El �tem '%s' no est� en el inventario.\n", nombreItem);
    }
}
void desequiparItem(struct Jugador *jugador){
    if (jugador->tieneItemEquipado){
        jugador->itemEquipado.nombre[0]='\0';
        jugador->itemEquipado.cantidad=0;
        jugador->tieneItemEquipado=0;
        printf("Has desequipado el �tem.\n");
    }

}
