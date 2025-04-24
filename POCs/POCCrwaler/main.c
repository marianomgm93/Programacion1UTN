#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define DIM 30
struct Posicion{
    int x;
    int y;
};
struct Item{
    char nombre[DIM];
    int cantidad;
};
struct Jugador
{
    char nombre[DIM];
    int vida;
    struct Posicion posicion;
    struct Item items[DIM];

};
int main()
{
    srand(time(NULL));
    struct Jugador j1;
    strcpy(j1.nombre,"Mariano");
    j1.vida=rand()%10+15;
    j1.posX = rand() % 10;
    j1.posY = rand() % 10;

    printf("Jugador: %s\n", j1.nombre);
    printf("Vida: %d\n", j1.vida);
    printf("Posición: (%d, %d)\n", j1.posX, j1.posY);
    return 0;
}
