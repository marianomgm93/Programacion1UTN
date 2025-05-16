#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

sem_t sem1,sem2,sem3;
int x;
void hola1(){
    sem_wait(&sem1);
    printf("Hola soy! el hilo 1\n");
    sem_post(&sem2);
}
void hola2(){
    sem_wait(&sem2);
    printf("Hola soy! el hilo 2\n");
    sem_post(&sem3);
}
void hola3(){
    sem_wait(&sem3);
    printf("Hola soy! el hilo 3\n");
    sem_post(&sem1);
}
void procA(){
    sem_wait(&sem1);
    x=199;
    x=x+1;
    printf("X=%i\n",x);
    sem_post(&sem2);
}
void procB(){
    sem_wait(&sem2);
    x=500;
    x=x/10;
    printf("X=%i\n",x);
    sem_post(&sem1);
}
int main()
{
    pthread_t hilo1,hilo2,hilo3;
    //7
/*
    sem_init(&sem1,0,0);
    sem_init(&sem2,0,1);
    sem_init(&sem3,0,0);
    pthread_create(&hilo2,NULL,hola2,NULL);
    pthread_create(&hilo1,NULL,hola1,NULL);
    pthread_create(&hilo3,NULL,hola3,NULL);
*/


    sem_init(&sem1,0,0);
    sem_init(&sem2,0,1);
    pthread_create(&hilo1,NULL,procA,NULL);
    pthread_create(&hilo2,NULL,procB,NULL);

    //pthread_join(hilo1,NULL);
   // pthread_join(hilo2,NULL);

    sem_destroy(sem1);
    sem_destroy(sem2);
    sem_destroy(sem3);
    return 0;
}
