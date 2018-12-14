#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#include "commands.h"

char *getcwd(char *buf, size_t size);
int chdir(const char *path);

int do_cd(int argc, char** argv) {
  if (!validate_cd_argv(argc, argv))
   return -1;     

  int result;
  result = chdir(argv[1]);
  return result;
}

int do_pwd(int argc, char** argv) {                 
  if (!validate_pwd_argv(argc, argv))
   return -1;

  char buf[8096];
  getcwd(buf, 8096);
  printf("%s\n", buf);

  return 0;
}

int validate_cd_argv(int argc, char** argv) {
  if(argc!=2) return 0;
  else return 1;
}

int validate_pwd_argv(int argc, char** argv) {
  if(argc==1) return 1;
  
  else return 0;
}