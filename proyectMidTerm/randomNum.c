#include <stdio.h>
#include <unistd.h>




int main(int argc, char **argv){
    int i;
    char prueba [10];
    char minusone [10];
    sprintf(minusone,"-1");
    for (i = 2; i < 101; i++){

        sprintf(prueba, "%d" ,i);
        write(1,prueba,sizeof(prueba));
    }
    write(1,minusone,sizeof(minusone));
    return 0;
}

