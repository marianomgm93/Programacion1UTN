#ifndef ESTADISTICAS_H_INCLUDED
#define ESTADISTICAS_H_INCLUDED
typedef struct {
    int vida;
    int ataque;
    int defensa;
    int velocidad;
    int suerte;
    int inteligencia;
    int puntosLibres;
}Estadisticas;

Estadisticas inicializarEstadisticas();
void aumentarStats(Estadisticas* stats,int at,int def,int vel,int sue,int i,int vit);


#endif // ESTADISTICAS_H_INCLUDED
