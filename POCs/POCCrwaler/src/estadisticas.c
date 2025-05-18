#include <stdio.h>
#include "estadisticas.h"

Estadisticas inicializarEstadisticas()
{
    Estadisticas stats;
    stats.vida=rand()%11+10;
    stats.ataque=rand()%20+21;
    stats.defensa=rand()%20+21;
    stats.velocidad=rand()%20+21;
    stats.suerte=rand()%20+21;
    stats.inteligencia=rand()%20+21;
    stats.puntosLibres=10;
    return stats;
}

void aumentarStats(Estadisticas* stats,int at,int def,int vel,int sue,int i,int vit){
    int total=vit+at+def+vel+sue+i;
    stats->ataque+=at;
    stats->defensa+=def;
    stats->inteligencia+=i;
    stats->suerte+=sue;
    stats->velocidad+=vel;
    stats->vida+=vit;
    stats->puntosLibres-=total;
}
