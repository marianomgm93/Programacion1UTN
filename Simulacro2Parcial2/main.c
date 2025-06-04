#include <stdio.h>
#include <stdlib.h>
#include <string.h>
///Structs
int idJugador=0;
typedef struct
{
    int id;
    char nombre [20];
    char posicion [20];
     int curso;
    int puntosGanados;
} stJugador;

typedef struct
{
    char nombreEquipo[20];
    int puntosGanados;
    stJugador dato[25];
    int valEquipo;


} stEquipo;
///FIN STRUCTS
///Ejercicio 1
/**
Cargar un arreglo de equipos. Debe estar correctamente modularizado, separando la parte de jugador de la de equipo
en distintas funciones. Los puntos del jugador se cargan, pero en el equipo no se carga por teclado, sino que tiene
un valor inicial de -1. Modularizar.  20
*/
stJugador constructorJug(char nombre [20],char posicion [20], int curso, int puntosGanados){

    stJugador jugador;
    jugador.id=idJugador;
    idJugador++;
    strcpy(jugador.nombre,nombre);
    strcpy(jugador.posicion,posicion);
    jugador.curso=curso;
    jugador.puntosGanados=puntosGanados;

    return jugador;

}
stJugador serviceCrearJug(){
    char nombre[20];
    char posicion[20];
    int curso, puntosGanados;

    printf("Ingrese nombre del jugador\n");
    fflush(stdin);
    scanf("%s",nombre);
    printf("Ingrese posicion del jugador\n");
    fflush(stdin);
    scanf("%s",posicion);

    printf("Ingrese curso del jugador\n");
    scanf("%d", &curso);
    printf("Ingrese puntos ganados del jugador\n");
    scanf("%d", &puntosGanados);

    return constructorJug(nombre,posicion, curso, puntosGanados);
}
stEquipo constructorEquipo(char nombreEquipo[20],stJugador dato[25],int valEquipo){
    stEquipo equipo;

    strcpy(equipo.nombreEquipo,nombreEquipo);
    equipo.puntosGanados=-1;
    for(int i=0;i<valEquipo;i++){
        equipo.dato[i]=dato[i];
    }
    equipo.valEquipo=valEquipo;
    return equipo;
}
stEquipo serviceCrearEquipo(){
    char nombreEquipo[20];
    stJugador dato[25];
    int valEquipo=0,option;
    printf("Ingrese nombre del equipo\n");
    fflush(stdin);
    gets(nombreEquipo);
    do{
        dato[valEquipo]=serviceCrearJug();
        valEquipo++;
        printf("0\tSalir\n1\tNuevo Jugador\n");
        scanf("%d",&option);
    }while(option);

    return constructorEquipo(nombreEquipo,dato,valEquipo);
}
///mostrar
void mostrarJugador(stJugador ju){
    printf("Nombre Jugador: %s\n",ju.nombre);
    printf("id jugador: %d\n",ju.id);
}
void mostrarEquipo(stEquipo eq){
    printf("Nombre Equipo: %s\n",eq.nombreEquipo);
    printf("Puntos Equipo: %d\n",eq.puntosGanados);
    for(int i=0;i<eq.valEquipo;i++){
        mostrarJugador(eq.dato[i]);

    }
}
///2
/**
2.Realizar una función que ordena un arreglo de jugadores  de acuerdo a la cantidad de puntos que tiene.  15
*/
int posMenor(stJugador arr[],int validos, int inicio){
    int posicion=inicio;
    for(int i=inicio;i<validos;i++){
        if(arr[posicion].puntosGanados<arr[i].puntosGanados){
            posicion=i;
        }
    }
    return posicion;
}
void ordenarArrJug(stJugador arr[],int validos){
    stJugador aux;
    int menor;
    for(int i=0;i<validos;i++){
        aux=arr[i];
        menor=posMenor(arr,validos,i);
        arr[i]=arr[menor];
        arr[menor]=aux;
    }
}
///3
int contarPuntos(stJugador arr[],int validos){
    validos--;
    return (validos>=0) ? arr[validos].puntosGanados+contarPuntos(arr,validos) : 0;
}
///4
void cargarPuntos(stEquipo arr[], int validos){
    for(int i=0;i<validos;i++){
        arr[i].puntosGanados=contarPuntos(arr[i].dato,arr[i].valEquipo);
    }

}
///5
/**
5.Realice una función que, recibiendo un equipo y un nombre, encuentre el id, de forma recursiva. 15
*/
//retorna -1 si no se encuentra el nombre.
int buscarPorNombre(stEquipo eq,char nombre[],int i){

    return (i==eq.valEquipo) ? -1 : (strcmpi(eq.dato[i].nombre,nombre)==0) ? eq.dato[i].id : buscarPorNombre(eq,nombre,i+1);
}
///6
/**
a- Guardar en un archivo, los jugadores de un equipo que se solicite por parámetro.10
b- Traerlos del archivo a un arreglo del tamaño justo.  10
*/

void persistirEquipo(stEquipo eq,char archivo[]){
    FILE* buffer=fopen(archivo,"wb");
    int i=0;
    stJugador jug;
    if(buffer){
        while(i<eq.valEquipo){
            jug=eq.dato[i];
            fwrite(&jug,sizeof(stJugador),1,buffer);
            i++;
        }
        fclose(buffer);
    }

}
void levantarJugadores(stJugador** arr, int* validos,char archivo[]){
    FILE* buffer=fopen(archivo,"rb");
    stJugador jug;
    int i=0;
    if(buffer){
        fseek(buffer,0,SEEK_END);
        (*validos)=ftell(buffer)/sizeof(stJugador);
        rewind(buffer);
        (*arr)=malloc(sizeof(stJugador)*(*validos));
        while(fread(&jug,sizeof(stJugador),1,buffer)>0 && i<(*validos)){
            (*arr)[i]=jug;
            i++;
        }
        fclose(buffer);
    }


}

int main()
{
    char archivo[]="jugadores";
    stEquipo arrEq[20];
    stJugador arrJug[20];
    arrJug[0]=constructorJug("j1","def",90,20);
    arrJug[1]=constructorJug("j2","def",90,5);
    arrJug[2]=constructorJug("j3","def",90,10);
    int validosJug=3;
    arrEq[0]=constructorEquipo("Eq1",arrJug,validosJug);

    mostrarEquipo(arrEq[0]);

    ordenarArrJug(arrEq[0].dato,arrEq[0].valEquipo);
    mostrarEquipo(arrEq[0]);

    cargarPuntos(arrEq,1);
    printf("Puntos totales: %d\n",arrEq[0].puntosGanados);
    mostrarEquipo(arrEq[0]);
    printf("ID del jugador j2: %d\n", buscarPorNombre(arrEq[0],"j2",0));

    stJugador * jugadoresPersistidos;
    int validosJugPer=0;
    persistirEquipo(arrEq[0],archivo);
    levantarJugadores(&jugadoresPersistidos,&validosJugPer,archivo);
    puts("/////PERSISTIDOS/////");
    for(int i=0;i<validosJugPer;i++){
        mostrarJugador(jugadoresPersistidos[i]);
    }
    return 0;
}
