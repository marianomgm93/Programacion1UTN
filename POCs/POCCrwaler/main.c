#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "jugador.h"

int main() {
    srand(time(NULL));
    struct Jugador j1;
    memset(j1.items, 0, sizeof(j1.items));
    strcpy(j1.nombre, "Mariano");
    j1.vida = rand() % 20 + 21;
    j1.posicion.x = rand() % 10;
    j1.posicion.y = rand() % 10;

    agregarItem(&j1, "Espada", 1);
    agregarItem(&j1, "Pocion", 3);
    agregarItem(&j1, "ManaPotion", 1);

    mostrarJugador(j1);

    usarItem(&j1, "ManaPotion");
    usarItem(&j1, "Pocion");

    mostrarJugador(j1);
while (1) {
    char tecla = getch();

    switch (tecla) {
        case 'w': moverArriba(); break;
        case 's': moverAbajo(); break;
        case 'a': moverIzquierda(); break;
        case 'd': moverDerecha(); break;
        case 'q': return; // salir del juego
    }
}
    return 0;
}
