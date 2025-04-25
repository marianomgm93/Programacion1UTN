#ifndef JUGADOR_H_INCLUDED
#define JUGADOR_H_INCLUDED

#define DIM 30

struct Posicion {
    int x;
    int y;
};

struct Item {
    char nombre[DIM];
    int cantidad;
};

struct Jugador {
    char nombre[DIM];
    int vida;
    struct Posicion posicion;
    struct Item items[DIM];
    struct Estadisticas stats;
};

void mostrarJugador(struct Jugador jugador);
void agregarItem(struct Jugador *jugador, char nombreItem[], int cantidad);
void eliminarItem(struct Jugador *jugador, char nombreItem[]);
int buscarItem(struct Jugador *jugador, char nombreItem[]);
void usarItem(struct Jugador *jugador, char nombreItem[]);

#endif // JUGADOR_H_INCLUDED
