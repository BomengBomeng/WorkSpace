#include<stdio.h>
#include<ctype.h>
#include<string.h>

int A_to_I(char *strnum){
  int sum=0;
  for(int i=0; i<strlen(strnum); i++)
    if(isdigit(strnum[i])==1){
      printf("%c  %d\n",strnum[i],strnum[i]-'0');
      sum = sum*10 + strnum[i]-'0';
    }
    else
      break;
  return sum;
}
int main(){
  char ssr[30];
  gets(ssr);
  printf("%d",A_to_I(ssr));
  return 0;
}
