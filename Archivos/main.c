#include <stdio.h>
#include <stdlib.h>
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
    printf("Ingrese nombre");
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
    if(buffer==NULL)
    {
        fclose(buffer);
        buffer=fopen(nombreArchivo,"ab");
        for(int i=0; i<5; i++)
        {
            alumno=constructorAlumno();
            fwrite(&alumno,sizeof(alumno),1,buffer);
        }
        fclose(buffer);
    }
}

int main()
{
    char archivo[]="documento";
    //menuArchivos(archivo);
    char alumnos[]="alumnos";
    cargarAlumnos(alumnos);
    return 0;
}
