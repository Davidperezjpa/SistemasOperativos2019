#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int prime;
char minusone [10];

void checkPrimes(int number){
    if (number % prime != 0){
        char numberc [10];
        sprintf(numberc, "%d" ,number);
        write(1,numberc,sizeof(numberc));
    }
}


int main(int argc, char **argv){
    char primec [10];
    sprintf(minusone,"-1");
    read(0,primec,sizeof(primec));
    prime = atoi(primec);
    if (prime == -1){
        write(1,minusone,sizeof(minusone));
        return 0;
    }
    fprintf(stderr, "%s \n", primec);
    while(1){

        char numberc [10];
        read(0,numberc,sizeof(numberc));

        int number = atoi(numberc);
        if (number == -1){
            write(1,minusone,sizeof(minusone));
            return 0;
        }
        else{
            checkPrimes(number);
        }


    }

    return 0;
}