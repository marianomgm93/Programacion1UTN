#ifndef EVENTO_H_INCLUDED
#define EVENTO_H_INCLUDED
#include "enemigo.h"
#include "jugador.h"
typedef enum
{
    TESORO,
    COMBATE,
    MISION,
    TIENDA
} TipoEvento;
typedef struct
{
    int cantidadOro;
    int rarezaObjeto;
} TesoroData;
typedef struct
{
    Enemigo enemigo;
} CombateData;

typedef struct
{
    char idObjeto[DIM];

} MisionData;
typedef struct
{
    Item itemsEnVenta[5];
    int puedeDescansar;

} TiendaData;

typedef union
{
    TesoroData tesoro;
    CombateData combate;
    MisionData mision;
    TiendaData tienda;
}DatosEvento;

typedef struct
{
    TipoEvento tipo;
    int nivelEspecial;//booleano si, no;
    DatosEvento datos;
} Evento;

void inicializarEvento(Evento* evento,int nivel);
void seleccionarEvento(Evento evento,  Jugador *jugador);
#endif // EVENTO_H_INCLUDED
