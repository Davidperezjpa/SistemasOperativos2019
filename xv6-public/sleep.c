#include "types.h"
#include "stat.h"
#include "user.h"

int main(int argc, char **argv)
{
  int sec;

  if(argc < 2){
    printf(2, "usage: sleep seconds\n");
    exit();
  }
  sec = atoi(argv[1]);
  if(sec>0){
      sleep(sec*100);
  }
  else{
      printf(2, "Wrong input %s\n", argv[1]);
  }
  exit();
}