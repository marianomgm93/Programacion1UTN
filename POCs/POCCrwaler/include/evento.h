#ifndef EVENTO_H_INCLUDED
#define EVENTO_H_INCLUDED
#include "item.h"
#include "enemigo.h"
#include "mapa.h"
#include "jugador.h"
typedef enum{
    TESORO,
    COMBATE,
    MISION,
    TIENDA
}TipoEvento;
struct TesoroData{
    int cantidadOro;
    int rarezaObjeto;
};
struct CombateData{
    Enemigo enemigo;
};
struct MisionData{
    char idObjeto[DIM];

};
struct TiendaData{
    struct Item itemsEnVenta[5];
    int puedeDescansar;

};
union DatosEvento{
    struct TesoroData tesoro;
    struct CombateData combate;
    struct MisionData mision;
    struct TiendaData tienda;
};

typedef struct{
    TipoEvento tipo;
    int nivelEspecial;//booleano si, no;
    union DatosEvento datos;
}Evento;

void inicializarEvento(Evento* evento,int nivel);
void seleccionarEvento(Evento evento, struct Jugador* jugador);
#endif // EVENTO_H_INCLUDED
