#ifndef HABITACION_H_INCLUDED
#define HABITACION_H_INCLUDED
#define MAX_EVENTOS 4
#include "evento.h"
typedef struct{
    Evento eventos[MAX_EVENTOS];
    int numeroHabitacion;
}Habitacion;
void inicializarHabitacion(Habitacion *habitacion,int posicion);

#endif // HABITACION_H_INCLUDED
