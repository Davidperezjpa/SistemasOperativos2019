#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#define NUM_FILOS 5

pthread_mutex_t forks[5];


void actions(){
    sleep(1 + rand()%5);
}

void * life(void *ptId){
    long tid;
    tid = (long)ptId;
    srand(time(NULL) + tid);
    while (1){
        printf("Voy a pensar un rato %ld\n",tid);
        actions();
        printf("Tengo Hambre %ld\n",tid);
        //pensar
        if (tid % 2 ==0){   // pares
            pthread_mutex_lock(&forks[tid]);    //el &hace referencia al objeto literalmente (no hace una copia)
            printf("Ya tengo el tenedor derecho %ld\n",tid);
            pthread_mutex_lock(&forks[(tid+1)%NUM_FILOS]);
            printf("Ya tengo el tenedor Izquierdo %ld\n",tid);
            printf("a comer %ld\n",tid);
            actions();  //come del espaguetti
            printf("Regresando tenedores %ld\n",tid);
            pthread_mutex_unlock(&forks[tid]);
            pthread_mutex_unlock(&forks[(tid+1)%NUM_FILOS]);
        }
        else{   // impares
            pthread_mutex_lock(&forks[(tid+1)%NUM_FILOS]);
            printf("Ya tengo el tenedor Izquierdo %ld\n",tid);
            pthread_mutex_lock(&forks[tid]);
            printf("Ya tengo el tenedor derecho %ld\n",tid);
            actions();  //Come del espaguetti
            printf("Regresando tenedores %ld\n",tid);
            pthread_mutex_unlock(&forks[tid]);
            pthread_mutex_unlock(&forks[(tid+1)%NUM_FILOS]);
        }
    }
}

int main(int argc, char *argv[])
{
   pthread_t threads[NUM_FILOS];
   int rc;
   long t;
   for(t=0;t<NUM_FILOS;t++){
     printf("In main: creating thread %ld\n", t);
     rc = pthread_create(&threads[t], NULL, life, (void *)t);
     if (rc){
       printf("ERROR; return code from pthread_create() is %d\n", rc);
       exit(-1);
       }
    }
    pthread_exit(NULL);
}