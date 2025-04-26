#ifndef MOVIMIENTO_H_INCLUDED
#define MOVIMIENTO_H_INCLUDED
enum Direccion {
    ARRIBA,
    ABAJO,
    IZQUIERDA,
    DERECHA,
    NINGUNA
};
enum Direccion capturarDireccion();
void moverJugador(struct Jugador *jugador, char direccion);

#endif // MOVIMIENTO_H_INCLUDED
