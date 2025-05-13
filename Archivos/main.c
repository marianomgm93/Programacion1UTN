#include <stdio.h>
#include <stdlib.h>
#include "pila.h"
#define IN 1
#define OUT 0
void agregarEntero(char nombre[],int a)
{
    FILE *buffer=fopen(nombre,"ab");
    if(buffer !=NULL)
    {
        fwrite(&a,sizeof(a),1,buffer);
        fclose(buffer);
    }
    else
    {
        printf("El archivo no se abrio correctamente\n");
    }
}

void mostrarArchivo(char nombre[])
{
    FILE* buffer=fopen(nombre,"rb");
    int a;
    if(buffer!=NULL)
    {
        while(!feof(buffer))
        {
            fread(&a,sizeof(a),1,buffer);
            if(!feof(buffer))
            {
                printf("%i\n",a);
            }
        }
        fclose(buffer);
    }
}
int contarRegistros(char archivo[])
{
    FILE* buffer=fopen(archivo,"rb");
    int a,contador=0;
    if(buffer!=NULL)
    {
        while(!feof(buffer))
        {
            fread(&a,sizeof(a),1,buffer);
            if(!feof(buffer))
            {
                contador++;
            }
        }

        fclose(buffer);
    }
    return contador;
}
void menuArchivos(char nombre[])
{
    int status=IN,numero;
    char option;
    while(status)
    {
        printf("0\tSalir\n1\t%s\n2\t%s\n3\t%s\n",
               "Agregar entero","Mostrar archivo","Contar registros");
        fflush(stdin);
        scanf("%c",&option);
        switch(option)
        {
        case '0':
            status=OUT;
            break;
        case '1':
            printf("Ingrese el numero que desea agregar:\n");
            scanf("%i",&numero);
            agregarEntero(nombre,numero);
            break;
        case '2':
            mostrarArchivo(nombre);
            break;
        case '3':
            printf("Registros en el archivo------>%i\n", contarRegistros(nombre));
            break;
        }

    }

}
typedef struct
{
    int legajo;
    char nombreYapellido [30];
    int edad;
    int anio;
//año que cursa, recordar que no podemos utilizar la ñ para definir variables
} stAlumno;
/**
*4_Crear una función que cargue un archivo de alumnos.
*Abrirlo de manera tal de verificar si el archivo ya está creado previamente.
*Cargar el archivo con 5 datos. Cerrarlo dentro de la función
*/
stAlumno constructorAlumno()
{

    stAlumno alumno;
    printf("Cargando nuevo alumno\n");
    printf("Ingrese legajo\n");
    scanf("%i",&(alumno.legajo));
    printf("Ingrese nombre\n");
    fflush(stdin);
    gets(&(alumno.nombreYapellido));
    printf("Ingrese edad\n");
    scanf("%i",&(alumno.edad));
    printf("Ingrese anio\n");
    scanf("%i",&(alumno.anio));

    return alumno;
}
void cargarAlumnos(char nombreArchivo[])
{
    FILE* buffer=fopen(nombreArchivo,"rb");
    stAlumno alumno;
    if(!buffer)
    {
        buffer=fopen(nombreArchivo,"wb");
        for(int i=0; i<5; i++)
        {
            alumno=constructorAlumno();
            fwrite(&alumno,sizeof(alumno),1,buffer);
        }

    }
    fclose(buffer);
}
void alumnoToString(stAlumno alumno)
{
    printf("_________Alumno_________\n"
           "Nombre: %s\nLegajo: %i\nEdad: %i\nAnio: %i\n"
           "_______Fin Alumno_______\n",alumno.nombreYapellido,alumno.legajo,alumno.edad,alumno.anio);
}
void mostrarAlumnos(char nombreArchivo[])
{
    FILE* buffer=fopen(nombreArchivo,"rb");
    stAlumno alumno;
    if(buffer)
    {
        while(!feof(buffer))
        {
            fread(&alumno,sizeof(alumno),1,buffer);
            if(!feof(buffer))
            {
                alumnoToString(alumno);
            }
        }
        fclose(buffer);
    }


}
/**
6_Crear una función que permita agregar de a un elemento al final del archivo.
*O sea, se debe abrir el archivo, se piden los datos
*(se llena una variable de tipo struct alumno), se escribe en el archivo y se cierra.
*/
void nuevoAlumno(char nombreArchivo[])
{
    FILE* buffer=fopen(nombreArchivo,"ab");
    if(buffer)
    {
        stAlumno alumno=constructorAlumno();
        fwrite(&alumno,sizeof(alumno),1,buffer);
        fclose(buffer);
    }
}
/**
*7_Crear una función que pase a una pila los números de legajo de los alumnos mayores de edad.
*/
void apilarMayores(Pila* p,char nombreArchivo[]){
    FILE* buffer=fopen(nombreArchivo,"rb");
    stAlumno alumno;
    if(buffer){
        while(!feof(buffer)){
            fread(&alumno,sizeof(alumno),1,buffer);
            if(!feof(buffer)&&alumno.edad>18){
                apilar(p,alumno.legajo);
            }
        }
        fclose(buffer);
    }
}
/**
*8_Dado un archivo de alumnos, hacer una función
*que cuente la cantidad de alumnos mayores a edad específica que se envía por parámetro.
*/
int contarMayores(char nombreArchivo[],int edadEspecifica){
    FILE* buffer=fopen(nombreArchivo,"rb");
    stAlumno alumno;
    int contador=0;
    if(buffer){
        while(!feof(buffer)){
            fread(&alumno,sizeof(alumno),1,buffer);
            if(!feof(buffer)&&alumno.edad>edadEspecifica){
                contador++;
            }
        }
    fclose(buffer);
    }
    return contador;
}
/**
*9_Dado un archivo de alumnos, mostrar por pantalla el nombre de todos los alumnos entre un
*rango de edades
*específico (por ejemplo, entre 17 y 25 años). Dicho rango debe recibirse por parámetro. Modularizar
*/
void mostarRango(char nombreArchivo[],int menor,int mayor){
    FILE* buffer=fopen(nombreArchivo,"rb");
    stAlumno alumno;
    if(buffer){
        printf("Alumnos entre %i y %i anios:\n",menor,mayor);
        while(!feof(buffer)){
            fread(&alumno,sizeof(alumno),1,buffer);
            if(!feof(buffer) && (alumno.edad>menor && alumno.edad<mayor)){
                printf("%s\n",alumno.nombreYapellido);
            }
        }
        fclose(buffer);
    }
}
/**
*10_Dado un archivo de alumnos, mostrar los datos del alumno de mayor edad. Modularizar.
*/
void mostrarMayor(char nombreArchivo[]){
    FILE* buffer=fopen(nombreArchivo,"rb");
    stAlumno alumno;
    stAlumno alumnoMayor;
    if(buffer){
        fread(&alumnoMayor,sizeof(alumno),1,buffer);
        while(!feof(buffer)){
            fread(&alumno,sizeof(alumno),1,buffer);
            if(!feof(buffer) && (alumnoMayor.edad<alumno.edad) ){
                alumnoMayor=alumno;
            }
        }
        fclose(buffer);
    }
    alumnoToString(alumnoMayor);
}
int main()
{
    char archivo[]="documento";
    //menuArchivos(archivo);
    char alumnos[]="alumnos";
    Pila alumnosMayores;
    inicpila(&alumnosMayores);
    /*cargarAlumnos(alumnos);
    mostrarAlumnos(alumnos);
    nuevoAlumno(alumnos);
    mostrarAlumnos(alumnos);
    apilarMayores(&alumnosMayores,alumnos);
    mostrar(&alumnosMayores);

    printf("Alumnos mayores de edad: %i\n",contarMayores(alumnos,18));
    mostarRango(alumnos,18,30);
    */
    mostrarMayor(alumnos);
    return 0;
}
