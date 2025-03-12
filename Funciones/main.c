#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define OUT 0
#define IN 1
/*
1_Desarrollar una función que devuelva un valor RANDOM en el rango de 0 a 100.

int main()
{
    int num=0;
    num=aleatorio();
    printf("%i",num);

    return 0;
}
int aleatorio(){
    srand(time(NULL));
    return (rand() % 101);
}
2_Diseñe una función que reciba 3 números enteros y muestre el mayor y el menor.

*/
/*
int main(){
    mayorYMenor(2,5,3);
}
int mayorYMenor(int num1,int num2,int num3){
    int mayor=num1;
    int menor=num1;
    if(mayor<num2){
        mayor=num2;
    }else if(mayor<num3){
        mayor=num3;
    }
    if(menor>num2){
        menor=num2;
    }else if(menor>num3){
        menor=num3;
    }
    printf("El mayor es: %i , y el menor es: %i",mayor,menor);
}
3_Diseñe una función que reciba un número entero N y realice la suma de los números enteros
positivos menores que N y lo retorne. N es un  dato ingresado por el usuario en el main.
*/
/*
int main(){
    int n,suma;
    printf("Ingrese un numero:\n");
    fflush(stdin);
    scanf("%i", &n);
    suma=sumatoria(n);
    printf("El resultado de la sumatoria es: %i",suma);
    return 0;
}
int sumatoria(int num){
    int resultado=0;
    for(int i=num;i>0;i--){
        printf("i actual: %i\n",i);
        resultado+=i;
    }
    return resultado;
}
4_Desarrollar una función que muestre la tabla de multiplicar de un número entero recibido por
parámetro.
*/
/*
int main(){
    tabla(2);
}
void tabla(int num){
    printf("La tabla del numero %i es:\n",num);
    for(int i=0;i<=10;i++){
        printf("%i x %i = %i\n",num,i,i*num);
    }
}
5_Realice una pequeña calculadora, utilizando funciones (una función de suma, una de
multiplicación, una de resta, una de división…)
*/
/*
int main()
{
    calculadora();
}

void calculadora()
{
    int status=IN;
    int num;
    while(status)
    {
        printf("1\tSumar\n2\tRestar\n3\tMultiplicar\n4\tDividir\n0\tSalir\n");
        scanf("%i",&num);
        switch(num)
        {
        case 0:
            status=OUT;
            break;
        case 1:
            sumar();
            break;
        case 2:
            restar();
            break;
        case 3:
            multiplicar();
            break;
        case 4:
            dividir();
            break;
        default:
            printf("El numero indicado no corresponde a las opciones, vuelve a intenarlo");
        }
    }
}
void sumar()
{
    int num1,num2;
    printf("Ingrese el primer numero\n");
    scanf(" %i",&num1);
    printf("\nIngrese el segundo numero\n");
    scanf(" %i",&num2);
    printf("El resultado de la suma es: %i\n",num1+num2);
}
void restar(){
    int num1,num2;
    printf("Ingrese el primer numero\n");
    scanf(" %i",&num1);
    printf("\nIngrese el segundo numero\n");
    scanf(" %i",&num2);
    printf("El resultado de la resta es: %i\n",num1-num2);
}
void multiplicar(){
    int num1,num2;
    printf("Ingrese el primer numero\n");
    scanf(" %i",&num1);
    printf("\nIngrese el segundo numero\n");
    scanf(" %i",&num2);
    printf("El resultado de la multiplicacion es: %i\n",num1*num2);
}
void dividir(){
    int num1,num2;
    printf("Ingrese el primer numero\n");
    scanf(" %i",&num1);
    printf("\nIngrese el segundo numero\n");
    scanf(" %i",&num2);
    printf("El resultado de la division es: %.2f\n",(float)num1/num2);
}
6. Realizar una función que reciba un número positivo entero por parámetro por referencia, y
cambie su signo a negativo.


int main()
{
    int num=-2;
    printf("negado: %i",negar(&num));
}
int negar(int *num)
{
    if (*num>0)
    {
        return -(*num);
    }
    else
    {
        return *num;
    }
}
*/

/*7.Realizar una función que reciba dos números enteros por parámetro por referencia y cargue
sus valores el usuario dentro de la función.
*/

int main(){
    int num1,num2;
    num1=3;
    num2=2;
    printf("La variable num1 es %i, mientras que num2 es %i\n",num1,num2);
    cargarValores(&num1,&num2);
    printf("La variable num1 es %i, mientras que num2 es %i\n",num1,num2);
}
int cargarValores(int* a,int* b){
    printf("Ingrese el nuevo valor para num1\n");
    scanf("%i",a);
    printf("Ingrese el nuevo valor para num2\n");
    scanf("%i",b);

}

