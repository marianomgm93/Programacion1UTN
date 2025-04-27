#include <stdio.h>
#include "mapa.h"
#define VENTANA_ANCHO 20
#define VENTANA_ALTO 10
void inicializarMapa(struct Mapa *mapa, int alto, int ancho) {
    mapa->alto = alto;
    mapa->ancho = ancho;

    // Crear el mapa con paredes
    for (int y = 0; y < alto; y++) {
        for (int x = 0; x < ancho; x++) {
            // Paredes en los bordes: primer fila, última fila, primera columna, última columna
            if (x == 0 || x == ancho - 1 || y == 0 || y == alto - 1) {
                mapa->celdas[y][x] = PARED;  // Pared en los bordes
            } else {
                mapa->celdas[y][x] = VACIO;  // Espacio vacío en el interior
            }
        }
    }
}
