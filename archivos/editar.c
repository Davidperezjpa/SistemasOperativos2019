#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>

void cambiar(char* word, char* patron, int fd2, int n, char* remplazo){
    //printf("word: %s\n", word);
            if(strcmp(word, patron)){
                write(fd2, word, n);
                write(fd2, " ", 1);
            }
            else{
                write(fd2, remplazo, strlen(remplazo));
                write(fd2, " ", 1);
            }
}

int main(int argc, char** argv){
    char * archivo = argv[1];
    char* patron = argv[2];
    char* remplazo = argv[3];
    char* pwd = getcwd(NULL,0);
    char path[strlen(archivo) + strlen(pwd) + 2];

    sprintf(path, "%s/%s", pwd, archivo);
    int fd = open(path, O_RDONLY);
    int fd2 = open("tmp.txt", O_WRONLY|O_CREAT,0666);
    char word[100];
    char c;
    int n;
    while(read(fd, &c, 1)){
        if(c != ' '){
            word[n++] = c;
        }
        else{
            word[n] = '\0';
            cambiar(word, patron, fd2, n, remplazo);
            n= 0;
        }
    }
    word[n] = '\0';

    cambiar(word, patron, fd2, n, remplazo);
    close(fd);
    close(fd2);
    unlink(archivo);
    link("tmp.txt", archivo);
    unlink("tmp.txt");

    return 0;
}