#include <stdio.h>
#include <string.h>
#include "jugador.h"
#include "estadisticas.h"
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
}

void agregarItem(struct Jugador *jugador, char nombreItem[], int cantidad)
{
    int i = 0;
    while (i < DIM && strcmp(jugador->items[i].nombre, nombreItem) != 0)
    {
        i++;
    }
    if (i < DIM && strcmp(jugador->items[i].nombre, nombreItem) == 0)
    {
        jugador->items[i].cantidad += cantidad;
    }
    else
    {
        i = 0;
        while (i < DIM && jugador->items[i].cantidad != 0)
        {
            i++;
        }
        if (i < DIM)
        {
            strcpy(jugador->items[i].nombre, nombreItem);
            jugador->items[i].cantidad = cantidad;
        }
        else
        {
            printf("Inventario lleno. No se pudo agregar el item %s\n", nombreItem);
        }
    }
}


int buscarItem(struct Jugador *jugador, char nombreItem[])
{
    for (int i = 0; i < DIM; i++)
    {
        if (stricmp(jugador->items[i].nombre, nombreItem) == 0)
        {
            return i;
        }
    }
    return -1;
}
/**
*@Param Si el item existe, lo elimina, retorna 1 si se realizó correctamente, 0 si el item no existia en el inventario;
*/
int eliminarItem(struct Jugador *jugador, char nombreItem[])
{
    int itemSocket=buscarItem(jugador,nombreItem);
    if(itemSocket!=-1)
    {
        jugador->items[itemSocket].cantidad = 0;
        jugador->items[itemSocket].nombre[0] = '\0';
        return 1;
    }
    return 0;
}
/**
*@Param Se utiliza el item, si no quedan mas, se eliminan del inventario;
*/
void usarItem(struct Jugador *jugador, char nombreItem[])
{
    int itemSocket = buscarItem(jugador, nombreItem);
    if (itemSocket != -1)
    {
        jugador->items[itemSocket].cantidad--;
        if (jugador->items[itemSocket].cantidad == 0)
        {
            if (eliminarItem(jugador, nombreItem))
            {
                printf("Item '%s' fue eliminado del inventario.\n", nombreItem);
            }
            else
            {
                printf("Hubo un error al intentar eliminar el item '%s'.\n", nombreItem);
            }
        }
    }
    else
    {
        printf("No tengo más %s\n", nombreItem);
    }
}
