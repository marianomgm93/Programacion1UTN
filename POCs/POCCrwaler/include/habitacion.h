#ifndef HABITACION_H_INCLUDED
#define HABITACION_H_INCLUDED
#define MAX_EVENTOS 4
#include "evento.h"
struct Habitacion{
    struct Evento eventos[MAX_EVENTOS];
    int numeroHabitacion;
};


#endif // HABITACION_H_INCLUDED
