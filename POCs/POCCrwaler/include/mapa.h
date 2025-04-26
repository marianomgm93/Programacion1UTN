#ifndef MAPA_H_INCLUDED
#define MAPA_H_INCLUDED
#deifne MAX_ALTO 100
#define MAX_ANCHO 100

struct Mapa {
    int ancho;
    int alto;
    char celdas[MAX_ALTO][MAX_ANCHO];
};
void inicializarMapa(struct Mapa *mapa,int alto, int ancho,char simbolo);
void dibujarMapa(struct Jugador *jugador,struct Mapa *mapa);


#endif // MAPA_H_INCLUDED
