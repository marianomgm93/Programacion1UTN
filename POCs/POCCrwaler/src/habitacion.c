#include <stdio.h>
#include "habitacion.h"

void inicializarHabitacion(struct Habitacion *habitacion){
        for(int i=0;i<MAX_EVENTOS;i++){
            habitacion->eventos[i]=inicializarEvento;
        }

}
