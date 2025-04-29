#include <stdio.h>
#include "stAlumno.h"
/**
*@Argument constructor Alumno
*
*/
stAlumno crearAlumno(int matricula,char nombre[],char genero){
    stAlumno alumno;
    strcpy(alumno.nombre,nombre);
    alumno.genero=genero;
    alumno.matricula=matricula;
    return alumno;
}
void alumnoToString(stAlumno alumno){
    printf("<------Alumno------->\nNombre: %s\nMatricula: %i\nGenero: %c\n<------FIN------->\n",alumno.nombre,alumno.matricula,toupper(alumno.genero));
}
