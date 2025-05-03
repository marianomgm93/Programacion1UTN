#ifndef EVENTO_H_INCLUDED
#define EVENTO_H_INCLUDED
#include "item.h"

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
    int enemigos;
    int nivelEnemigos;

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

typedef struct Evento{
    TipoEvento tipo;
    int nivelEspecial;//booleano si, no;
    union DatosEvento datos;
}Evento;

void inicializarEvento(Evento* evento);

#endif // EVENTO_H_INCLUDED
