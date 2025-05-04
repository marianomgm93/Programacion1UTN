#include <stdio.h>
#include "habitacion.h"
void inicializarHabitacion(Habitacion *habitacion,int posicion)
{
    habitacion->numeroHabitacion=posicion;
    for(int i=0; i<MAX_EVENTOS; i++)
    {
        inicializarEvento(&(habitacion->eventos[i]), posicion);
    }

}
