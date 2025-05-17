#include <stdio.h>
#include <stdlib.h>
#include "pila.h"
#define IN 1
#define OUT 0
/**1. Hacer una función que agregue un elemento al final de un archivo.*/
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
/**2. Hacer una función que muestre por pantalla el contenido de un archivo. */
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
/**3. Hacer una función que retorne la cantidad de registros que contiene un archivo.*/
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

    }else{
        printf("El archivo ya se encuentra creado!\n");
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
void apilarMayores(Pila* p,char nombreArchivo[])
{
    FILE* buffer=fopen(nombreArchivo,"rb");
    stAlumno alumno;
    if(buffer)
    {
        while(!feof(buffer))
        {
            fread(&alumno,sizeof(alumno),1,buffer);
            if(!feof(buffer)&&alumno.edad>18)
            {
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
int contarMayores(char nombreArchivo[],int edadEspecifica)
{
    FILE* buffer=fopen(nombreArchivo,"rb");
    stAlumno alumno;
    int contador=0;
    if(buffer)
    {
        while(!feof(buffer))
        {
            fread(&alumno,sizeof(alumno),1,buffer);
            if(!feof(buffer)&&alumno.edad>edadEspecifica)
            {
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
void mostarRango(char nombreArchivo[],int menor,int mayor)
{
    FILE* buffer=fopen(nombreArchivo,"rb");
    stAlumno alumno;
    if(buffer)
    {
        printf("Alumnos entre %i y %i anios:\n",menor,mayor);
        while(!feof(buffer))
        {
            fread(&alumno,sizeof(alumno),1,buffer);
            if(!feof(buffer) && (alumno.edad>menor && alumno.edad<mayor))
            {
                printf("%s\n",alumno.nombreYapellido);
            }
        }
        fclose(buffer);
    }
}
/**
*10_Dado un archivo de alumnos, mostrar los datos del alumno de mayor edad. Modularizar.
*/
void mostrarMayor(char nombreArchivo[])
{
    FILE* buffer=fopen(nombreArchivo,"rb");
    stAlumno alumno;
    stAlumno alumnoMayor;
    if(buffer)
    {
        fread(&alumnoMayor,sizeof(alumno),1,buffer);
        while(!feof(buffer))
        {
            fread(&alumno,sizeof(alumno),1,buffer);
            if(!feof(buffer) && (alumnoMayor.edad<alumno.edad) )
            {
                alumnoMayor=alumno;
            }
        }
        fclose(buffer);
    }
    alumnoToString(alumnoMayor);
}
/**
*11. Crear una función que retorne la cantidad de alumnos que cursan un determinado año. El
*año buscado se pasa por parámetro.
*/
int alumnosEnAnio(char nombreArchivo[],int anioCurso)
{
    FILE* buffer=fopen(nombreArchivo,"rb");
    stAlumno alumno;
    int contador=0;
    if(buffer)
    {
        while(!feof(buffer))
        {
            fread(&alumno, sizeof(alumno), 1,buffer);
            if(!feof(buffer) && alumno.anio==anioCurso)
            {
                contador++;
            }
        }
    }
    return contador;
}
/**
*12_Crear una función que reciba como parámetro un arreglo de tipo alumno y lo copie en el
*archivo. Asimismo, realice otra función que pase los elementos del archivo a un arreglo de
*alumnos, filtrando los estudiantes de un año en particular.
*/

void archivarArreglo(char nombreArchivo[], stAlumno arr[],int validos)
{
    FILE* buffer=fopen(nombreArchivo,"wb");
    if(buffer)
    {
        fwrite(arr,sizeof(stAlumno),validos,buffer);
        fclose(buffer);
    }
}

void filtrarPorAnio(char nombreArchivo[], int anioFiltro, stAlumno arr[], int* validos)
{
    FILE* buffer=fopen(nombreArchivo,"rb");
    stAlumno alumno;
    if(buffer)
    {
        while(!feof(buffer))
        {
            fread(&alumno,sizeof(stAlumno),1,buffer);
            if(!feof(buffer) && anioFiltro==alumno.anio)
            {
                arr[*validos]=alumno;
                (*validos)++;
            }
        }
        fclose(buffer);
    }
}
/**
*13. Crear una función que retorne la cantidad de registros que tiene el archivo. Usar fseek y
*ftell. Puede pensar la función para uso genérico, que sirva para averiguar la cantidad de
*registros de cualquier archivo.
*/
int cantidadAlumnos(char nombreArchivo[])
{
    FILE* buffer=fopen(nombreArchivo,"rb");
    int total=-1;
    if(buffer)
    {
        total=0;
        fseek(buffer,0,SEEK_END);
        total=ftell(buffer)/sizeof(stAlumno);
        fclose(buffer);
    }
    return total;
}
/**
*14. Dado un archivo de alumnos, que tenga al menos 10 registros, hacer una función que
*muestre el contenido de un registro, cuyo número (entre 0 y 9) se pase por parámetro.
*Controlar no sobrepasar los límites del archivo.
*/

void mostrarRegistro(char nombreArchivo[],int numeroRegistro)
{
    FILE* buffer=fopen(nombreArchivo,"rb");
    int totalRegistros;
    stAlumno alumno;
    if(numeroRegistro<10 && numeroRegistro>=0)
    {

        if(buffer)
        {
            fseek(buffer,0,SEEK_END);
            totalRegistros=ftell(buffer)/sizeof(stAlumno);
            if(numeroRegistro<=totalRegistros)
            {
                fseek(buffer,numeroRegistro*sizeof(stAlumno),SEEK_SET);
                fread(&alumno,sizeof(stAlumno),1,buffer);
                alumnoToString(alumno);
            }
            else
            {
                printf("El numero de registro no existe en el archivo\n");
            }

            fclose(buffer);
        }
    }
    else
    {
        printf("El numero ingresado debe estar entre 0 y 9\n");
    }
}

/**
*15_Realice una (o varias) funciones que permitan modificar un registro existente en el archivo
*de alumnos. La misma debe permitir modificar uno o todos los campos de la estructura y
*sobreescribir el registro existente en el archivo.
*/

int obtenerRegistro(char nombreArchivo[],int numeroRegistro,stAlumno* alumno)
{
    FILE* buffer=fopen(nombreArchivo,"rb");
    int totalRegistros,resultado;

    if(buffer)
    {
        fseek(buffer,0,SEEK_END);
        totalRegistros=ftell(buffer)/sizeof(stAlumno);
        if(numeroRegistro<totalRegistros)
        {
            fseek(buffer,numeroRegistro*sizeof(stAlumno),SEEK_SET);
            fread(alumno,sizeof(stAlumno),1,buffer);
            resultado=1;//devuelve 1 si se encuentra el registro;
        }
        else
        {
            printf("El numero de registro no existe en el archivo\n");
            resultado=0;//devuelve 0 si no se encuentra el registro
        }

        fclose(buffer);
    }
    return resultado;
}
void menuModificarAlumno (stAlumno* alumno)
{
    int option;
    int status=IN;
    while(status)
    {
        alumnoToString(*alumno);
        printf("0\tAtras\n1\tModificar legajo\n2\tModificar nombre\n3\tModificar anio\n4\tModificar edad\n");
        scanf("%i",&option);

        switch(option)
        {
        case 0:
            status=OUT;
            break;
        case 1:
            printf("Ingrese nuevo legajo:\n");
            scanf("%i",&(alumno->legajo));
            break;
        case 2:
            printf("Ingrese nuevo nombre:\n");
            fflush(stdin);
            gets(&(alumno->nombreYapellido));
            break;
        case 3:
            printf("Ingrese nuevo anio:\n");
            scanf("%i",&(alumno->anio));
            break;
        case 4:
            printf("Ingrese nueva edad:\n");
            scanf("%i",&(alumno->edad));
            break;
        default:
            printf("La opcion ingresada no es valida\n");
            break;
        }
    }
}
void guardarEn(char nombreArchivo[],int posicion,stAlumno alumno)
{
    FILE* buffer=fopen(nombreArchivo,"r+b");
    if(buffer)
    {
        fseek(buffer,posicion*sizeof(stAlumno),SEEK_SET);
        fwrite(&alumno,sizeof(stAlumno),1,buffer);
        fclose(buffer);
    }

}
void modificarRegistro(char nombreArchivo[])
{
    int status=IN,option;
    stAlumno alumno;
    int numeroRegistro;

    while(status)
    {
        printf("1\tBuscar registro\n0\tSalir\n");
        scanf("%i",&option);
        switch(option)
        {
        case 0:
            status=OUT;
            break;
        case 1:
            printf("Ingrese el registro que desee buscar\n");
            scanf("%i",&numeroRegistro);
            if(obtenerRegistro(nombreArchivo,numeroRegistro,&alumno))//comprobacion y consumo alumno
            {
                menuModificarAlumno(&alumno);//modificacion del alumno
                guardarEn(nombreArchivo,numeroRegistro,alumno);//update
            }
            break;
        default:
            printf("Opcion incorrecta\n");
            break;
        }
    }
}
/**
*16_Dado un archivo de alumnos, hacer una función que invierta los elementos del mismo. No
se puede usar otro archivo auxiliar ni un arreglo auxiliar. Debe trabajar sobre el archivo.
Puede utilizar variables de tipo alumno auxiliares.
*/

void invertirArchivo(char nombreArchivo[])
{
    int total=cantidadAlumnos(nombreArchivo);
    stAlumno alumno1,alumno2;
    if(total>=0)//Arroja -1 si no existe el archivo
    {
        for(int i=0; i<total/2; i++)
        {
            obtenerRegistro(nombreArchivo,i,&alumno1);
            obtenerRegistro(nombreArchivo,total-1-i,&alumno2);
            guardarEn(nombreArchivo,i,alumno2);
            guardarEn(nombreArchivo,total-1-i,alumno1);
        }
    }
}
/**
*17_Hacer una función principal que pruebe el funcionamiento de todos los incisos anteriores, con
*un menú de opciones para poder ejecutar todas las funciones requeridas. Tengan presente la
*correcta declaración y el ámbito de variables
*/
void menu()
{
    char archivo[]="documento";
    char alumnosAnioUno[]="alumnosPrimerAnio";
    char alumnos[]="alumnos";
    stAlumno arregloAlumnos[30];
    int validosAlumnos=0;
    Pila alumnosMayores;
    inicpila(&alumnosMayores);
    int status=IN;
    int option;
    while(status)
    {
        printf("Ingrese el ejercicio que desea ejecutar:\n0\tSalir\n1,2,3\t archivos int"
               "\n4-16\tArchivos alumnos\n");
        scanf("%i",&option);
        switch(option)
        {
        case 0:
            status=OUT;
            break;
        case 1:
        case 2:
        case 3:
            menuArchivos(archivo);
            break;
        case 4:
            printf("Entre al 4\n");
            cargarAlumnos(alumnos);
            break;
        case 5:
            mostrarAlumnos(alumnos);
            break;
        case 6:
            nuevoAlumno(alumnos);
            break;
        case 7:
            apilarMayores(&alumnosMayores,alumnos);
            mostrar(&alumnosMayores);
            break;
        case 8:
            printf("Alumnos mayores de edad: %i\n",contarMayores(alumnos,18));
            break;
        case 9:
            mostarRango(alumnos,18,30);
            break;
        case 10:
            mostrarMayor(alumnos);
            break;
        case 11:
            printf("Hay %i alumnos cursando el anio 1\n", alumnosEnAnio(alumnos,1));
            break;
        case 12:
            filtrarPorAnio(alumnos,1,arregloAlumnos,&validosAlumnos);
            archivarArreglo(alumnosAnioUno,arregloAlumnos,validosAlumnos);
            mostrarAlumnos(alumnosAnioUno);
            break;
        case 13:
            printf("Hay %i alumnos en total",cantidadAlumnos(alumnos));
            break;
        case 14:
            mostrarRegistro(alumnos,3);
            break;
        case 15:
            modificarRegistro(alumnos);
            break;
        case 16:
            mostrarAlumnos(alumnos);
            invertirArchivo(alumnos);
            printf("Alumnos invertidos\n");
            mostrarAlumnos(alumnos);
            break;
        default:
            printf("La opcion solicitada no existe\n");
            break;


        }
    }

}
int main()
{
    menu();
    return 0;
}
