#include <stdlib.h>
#include <stdio.h>
#include "enemigo.h"

#define VIDA_BASE 10

Enemigo constructorEnemigo(int nivel, TipoEnemigo tipo)
{
    Enemigo enemigo;
    enemigo.nivel=nivel;
    enemigo.stats=inicializarEstadisticas();
    switch(tipo)
    {
    case FACIL:
        enemigo.stats.vida=rand()%3*nivel+VIDA_BASE;
        break;
    case NORMAL:
        enemigo.stats.vida=rand()%6*nivel+VIDA_BASE;
        break;
    case DIFICIL:
        enemigo.stats.vida=rand()%8*nivel+VIDA_BASE;
        break;
    case IMPOSIBLE:
        enemigo.stats.vida=rand()%11*nivel+VIDA_BASE;
        break;
    }
    return enemigo;
}
