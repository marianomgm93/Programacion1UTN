#ifndef ENEMIGO_H_INCLUDED
#define ENEMIGO_H_INCLUDED
#include <string.h>
#include "estadisticas.h"
typedef enum{
    FACIL,
    NORMAL,
    DIFICIL,
    IMPOSIBLE
}TipoEnemigo;

typedef struct{
    int nivel;
    TipoEnemigo tipo;
    Estadisticas stats;
}Enemigo;
Enemigo constructorEnemigo(int nivel, TipoEnemigo tipo);


#endif // ENEMIGO_H_INCLUDED
