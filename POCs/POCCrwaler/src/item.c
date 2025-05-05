#include <stdio.h>
#include <string.h>
#include "item.h"

int buscarItem( Item items[], char nombreItem[]) {
    for (int i = 0; i < DIM; i++) {
        if (stricmp(items[i].nombre, nombreItem) == 0) {
            return i;
        }
    }
    return -1;
}

int eliminarItem( Item items[], char nombreItem[]) {
    int i = buscarItem(items, nombreItem);
    if (i != -1) {
        items[i].cantidad = 0;
        items[i].nombre[0] = '\0';
        return 1;
    }
    return 0;
}

void usarItem( Item items[], char nombreItem[]) {
    int i = buscarItem(items, nombreItem);
    if (i != -1) {
        items[i].cantidad--;
        if (items[i].cantidad == 0) {
            eliminarItem(items, nombreItem);
            printf("Item '%s' fue eliminado del inventario.\n", nombreItem);
        }
    } else {
        printf("No tengo más %s\n", nombreItem);
    }
}

void agregarItem( Item items[], char nombreItem[], int cantidad) {
    int i = buscarItem(items, nombreItem);
    if (i != -1) {
        items[i].cantidad += cantidad;
    } else {
        for (i = 0; i < DIM; i++) {
            if (items[i].cantidad == 0) {
                strcpy(items[i].nombre, nombreItem);
                items[i].cantidad = cantidad;
                return;
            }
        }
        printf("Inventario lleno. No se pudo agregar el item %s\n", nombreItem);
    }
}
