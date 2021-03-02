#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char  font[10][7][5];
int  digit[4];
int  length=0;

/* 装载字体文件 p*/
void loadfonts(){
  FILE  *file;
  file = fopen("font.txt","rb");
  if  (file==NULL){
    printf("Can not open the file front.txt  ERROR\n");
    exit(1);
  }
  for(int i=0; i<10; i++){
    for(int j=0; j<7; j++){
      fscanf(file,"%s",font[i][j]);
      font[i][j][4] = '\0';
    }
  }
  fclose(file);
}

/* 打印某个字符数组 */
void printstr(char *str){
  while(*str!='\0'){
    if(*str!='-')
      putchar('*');
    else
      putchar(' ');
    str++;
  }
}

/* 将输入的整数解码为单个的数字 */
void decode(int x){
  int i;
  for(i=0; i<4; i++){
    digit[3-i]=x %  10;
    x /= 10;
    if (x==0)
      break;
  }

  length = i + 1;
  if(length >=4)
    length=4;
}

/* 显示LED */
void disnlav(){
  for(int i=0; i<7; i++){
    for(int j=4-length; j<4; j++){
      printstr(font[digit[j]][i]);
      printf("  ");
    }
    printf("\n");
  }
}

/*main*/
int main(){
  loadfonts();

  //输入目标数
  printf("Plese input a number:\n");
  int c;
  scanf("%4d",&c);
  printf("the result:\n");

  decode(c);
  disnlav();
  return 0;
}
