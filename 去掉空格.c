/*去掉空格*/
#include<stdio.h>

void func(char *str){
  char *p = str;
  while(*p!='\0')
    if(*p!=' ')
      *str++ = *p++;
    else
      *p++;
  *str = '\0';
}

int main(){
  char s[100];
  gets(s);
  func(s);
  puts(s);
  return 0;
}
