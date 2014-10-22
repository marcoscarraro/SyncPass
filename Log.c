/*

Este arquivo contem somente as funções de log

*/

#include "SyncPass.h"

int GravaLogBkp(char value[]) {
  FILE * pFile;
  pFile = fopen ("C:\\tmp\\debug.log", "wb");
  fwrite (value , sizeof(char), sizeof(value), pFile);
  fclose (pFile);
  return 0;
}


int GravaLog(char *usuario,char *senha) {
  FILE *fp;

  //printf("Iniciou.\n\r");

  fp=freopen("C:\\tmp\\debug.log", "a" ,stdout);

  printf("String %s %s.\n\r",usuario,senha);

 // printf("Terminou.\n\r");

  fclose(fp);

  return 0;
}


