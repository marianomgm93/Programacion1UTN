#include <stdio.h>
#include <stdlib.h>

/**
*13. Crear una función que retorne la cantidad de registros que tiene el archivo. Usar fseek y
*ftell. Puede pensar la función para uso genérico, que sirva para averiguar la cantidad de
*registros de cualquier archivo.
*/
///////////////////////////

typedef struct
{
    int legajo;
    char nombreYapellido [30];
    int edad;
    int anio;
//año que cursa, recordar que no podemos utilizar la ñ para definir variables
} stAlumno;

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

//////////////////

void * crearArregloPares2(int arrOrigen[],int validos,int* pares, int** arrPares){
    *pares=contarPares(arrOrigen,validos);
    *arrPares=malloc((*pares)*sizeof(int));
    pasarArreglo(*arrPares, arrOrigen, pares, validos);

}
int * crearArregloPares(int arrOrigen[],int validos,int* pares){
    *pares=contarPares(arrOrigen,validos);
    int * arrPares=malloc((*pares)*sizeof(int));
    pasarArreglo(arrPares, arrOrigen, pares, validos);
    return arrPares;
}
void mostrarArreglo(int arr[],int validos){
    printf("Arreglo:{");
    for(int i=0;i<validos;i++){
        printf(" %i", arr[i]);
    }
    printf(" }\n");
}
void pasarArreglo(int arrDestino[], int arrOrigen[], int validosDestino, int validosOrigen){
    int contador=0,aux;
    for (int i=0;i<validosOrigen && contador<validosDestino;i++){
        aux=arrOrigen[i];
        if(aux%2==0){
            arrDestino[contador]=aux;
            contador++;
        }
    }
}
int contarPares(int arr[],int validos){
    int pares=0;
    for (int i=0;i<validos;i++){
        if(arr[i]%2==0){
            pares++;
        }
    }
    return pares;
}
int main()
{

    //1
    /**
    int valor=0;
    int * pint = &valor;
    int ** ppint = &pint;
    printf("Direccion 1 : %p\n", &valor);
    printf("Direccion 2 : %p\n", &pint);
    printf("Direccion 3 : %p\n", &ppint);

    printf("Valor: %i\n",valor);
    *pint=1;
    printf("Valor: %i\n",valor);
    **ppint=2;
    printf("Valor: %i\n",valor);
    */

    //2

    /**
    int arrEnteros[]={0,1,2,3,4,5,6,7,8,9};
    int validos=10;
    int pares=contarPares(arrEnteros,validos);
    int * arrPares=malloc(pares*sizeof(int));
    pasarArreglo(arrPares,arrEnteros,pares,validos);
    mostrarArreglo(arrPares,pares);
    */

    //2B

    /**
    int arrEnteros[]={0,1,2,3,4,5,6,7,8,9};
    int validos=10;
    int validosPares;
    int * arrPares=crearArregloPares(arrEnteros,validos,&validosPares);
    mostrarArreglo(arrPares,validosPares);
    */

    //2C
    /**
    int arrEnteros[]={0,1,2,3,4,5,6,7,8,9};
    int validos=10;
    int validosPares;
    int * arrPares;
    crearArregloPares2(arrEnteros,validos,&validosPares,&arrPares);
    mostrarArreglo(arrPares,validosPares);
    */


    return 0;
}
