#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char **argv)
{
    char *file = argv[1];
    char *pwd = getcwd(NULL,0);
    char path[strlen(file) + strlen(pwd) + 2];
    sprintf(path, "%s/%s",pwd,file);
    printf("pwd %s\n", path);
    
    printf("%d",unlink(path));
} 