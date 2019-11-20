#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char **argv)
{
    char *file1 = argv[1];
    char *file2 = argv[2];
    char *pwd = getcwd(NULL,0);
    char path1[strlen(file1) + strlen(pwd) + 2];
    char path2[strlen(file2) + strlen(pwd) + 2];
    sprintf(path1, "%s/%s",pwd,file1);
    sprintf(path2, "%s/%s",pwd,file2);

    printf("pwd %s\n", path1);
    printf("pwd %s\n", path2);

    printf("%d",link(file1, file2));
    unlink(file1);
} 