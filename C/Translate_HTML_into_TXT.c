#include<string.h>
#include<stdlib.h>
#include<stdio.h>
int main(int argc, char *argv[]){
  FILE *fin, *fout;
  char ch, tag[8];
  int status, len;
  if(argc!=3){
    printf("Parameters missing!\n");
    exit(1);
  }
  if((fin=fopen(argv[1],"r"))==NULL){
    printf("Can not open the read file\n");
    exit(1);
  }
  if((fout=fopen(argv[2],"w"))==NULL){
    printf("Can not Create the write file\n");
    fclose(fin);
    exit(1);
  }
  status=0;
  while((ch=fgetc(fin))!=EOF)
    switch(ch){
      case '<':
                status=1; len=0;
                break;
      case '>':
                status=0;
                if(len<=6)
                  tag[len] = '\0';
                puts(tag);
                if(!strcmp(tag,"/TITLE") || !strcmp(tag, "/A"))
                  fputc('\n',fout);
                break;
      case '\n':
                break;
      default:
                if(!status)
                  fputc(ch,fout);
                else{
                  len++;
                  if(len<=6)
                    tag[len-1]=ch;
                }
    }//switch
    fclose(fin);
    fclose(fout);
  return 0;
}
