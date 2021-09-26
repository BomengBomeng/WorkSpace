#include<stdio.h>

int MaxSameChar(char *s){
  if(*s=='\0'){
    printf("Error!\n");
    return 0;
  }
  char maxSame = *s;
  int maxcount = 1;
  char Same = *s;
  int count = 1;
  while(*s!='\0'){
    if(*++s==Same)
      count++;
    else{
      if(count>maxcount){
        maxSame = Same;
        maxcount = count;
      }
      count=1;
      Same = *s;
    }
  }//while
  return maxcount;
}
int main(){
  char s[30];
  printf("Please Input the string!\n");
  gets(s);
  printf("%d\n",MaxSameChar(s));
}
