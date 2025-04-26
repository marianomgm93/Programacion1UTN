#include <stdio.h>
#include "estadisticas.h"

struct Estadisticas inicializarEstadisticas(){
    struct Estadisticas stats;

    stats.ataque=rand()%20+21;
    stats.defensa=rand()%20+21;
    stats.velocidad=rand()%20+21;
    stats.suerte=rand()%20+21;
    stats.inteligencia=rand()%20+21;
    return stats;
}
