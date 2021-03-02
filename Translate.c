#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void openfile(FILE **fhtml, FILE ** ftxt, char *html, char *txt){
  if((*fhtml=fopen(html,"r"))==NULL){
     printf("Error Can not open the file: %s\n",html);
     exit(1);
  }
  if((*ftxt=fopen(txt,"w"))==NULL){
    printf("Error Can not open the file: %s\n", txt);
    fclose(*fhtml);
    *fhtml=NULL;
    exit(1);
  }
}

void closefile(FILE **fp1, FILE **fp2){
  fclose(*fp1);
  fclose(*fp2);
}

int main(int argc, char *argv[]){
  if(argc<3){
    printf("Missing Parameter!\n");
    exit(1);
  }
  FILE *fhtml, *ftxt;
  openfile(&fhtml,&ftxt,argv[1],argv[2]);
  char ch, buf[7];
  int len=0, flage;
  while((ch=getc(fhtml))!=EOF){
    switch (ch) {
      case '<':
                flage=1;
                len=0;
                break;
      case '>':
                flage=0;
                buf[len++]='\0';
                if(strcmp(buf,"/TITLE")==0)
                  fprintf(ftxt,"\n");
                if(strcmp(buf,"BR")==0)
                  fprintf(ftxt,"\n");
                break;
      default:
                if(flage==1 && len <6) //接收的是控制字符
                  buf[len++] = ch;
                else//flafe==0, 接收的是文本字符
                  if(ch!='\n')
                    fputc(ch,ftxt);
    }//switch
  }//while
  closefile(&fhtml, &ftxt);
  return 0;
}//main
