#include <stdio.h>
#include <stdlib.h>
void agregarEntero(char nombre[],int a){
    FILE *buffer=fopen(nombre,"ab");
    if(buffer !=NULL){
        fwrite(&a,sizeof(a),1,buffer);
        fclose(buffer);
    }else{
        printf("El archivo no se abrio correctamente\n");
    }

}
void mostrarArchivo(char nombre[]){
    FILE* buffer=fopen(nombre,"rb");
    int a;
    if(buffer!=NULL){
        while(!feof(buffer)){
            fread(&a,sizeof(a),1,buffer);
            if(!feof(buffer)){
            printf("%i\n",a);
            }
        }
        fclose(buffer);
    }

}

int main()
{
    int a=910;
    char archivo[]="documento";
    agregarEntero(archivo,a);
    a=31;
    agregarEntero(archivo,a);
    a=10;
    agregarEntero(archivo,a);
    a=15;
    agregarEntero(archivo,a);
    mostrarArchivo(archivo);
    printf("Hello world!\n");
    return 0;
}
