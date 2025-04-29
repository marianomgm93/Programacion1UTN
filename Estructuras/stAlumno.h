#ifndef STALUMNO_H_INCLUDED
#define STALUMNO_H_INCLUDED
#include <string.h>
typedef struct {
    int matricula;
    char nombre[30];
    char genero; //m, f, o
} stAlumno;
stAlumno crearAlumno(int matricula,char nombre[],char genero);
void alumnoToString(stAlumno alumno);
#endif // STALUMNO_H_INCLUDED
