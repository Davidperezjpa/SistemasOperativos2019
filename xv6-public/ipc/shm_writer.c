#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include <unistd.h>

int main(){
    int key = 27; // numero usado para generar el id del bloque de memoria
    int shmid = shmget(key,  100, IPC_CREAT);
    char* word;

    word = (char*)shmat(shmid, NULL, 0);
    //word = "hello world"; // reemplaza el aputador
    sprintf(word,"Hello world\n");

    while(word[0] == 'H'){
        sleep(1);
    }
    printf("Sali del ciclo: %s",word);
    return 0;
}