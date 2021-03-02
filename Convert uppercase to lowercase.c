/*大写转换为小写*/
#include<stdio.h>
int main(){
  char ch;
  while((ch=getchar())!='\n'){
    if(ch>'A' && ch<'Z')
      ch += 'a' - 'A';
    putchar(ch);
  }
  return 0;
}
