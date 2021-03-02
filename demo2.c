       #include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define datafile "checi.txt"

typedef struct {
  char num[9];
  char from[9];
  char to[9];
  char time[6];
}Checi;

void OpenFile(FILE **fp){
  if((*fp=fopen(datafile,"r"))==NULL){
    printf("ERROR can not find data!\n");
    exit(1);
  }
}

int main(int argc, char *argv[]){
  if(argc<2){
    printf("Parameters Missing!\n");
    exit(1);
  }
  Checi Search;
  FILE *fp;
  OpenFile(&fp);
  while(!feof(fp)){
    fscanf(fp, "%s", Search.num);
    fscanf(fp, "%s", Search.from);
    fscanf(fp, "%s", Search.to);
    fscanf(fp, "%s", Search.time);
    if(!strcmp(Search.num,argv[1])){
      printf("Get it!\n");
      printf("%s from %s to %s at %s\n",Search.num, Search.from, Search.to, Search.time);
      exit(0);
    }
  }
  printf("Can not find  %s\n",argv[1]);
  return 0;
}
