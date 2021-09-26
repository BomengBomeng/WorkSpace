/*大数取余*/
#include<stdio.h>
#include<string.h>
char str[1000001];

int func(char *str, int len){
  int ans=0;
  for(int i=0; i<len; i++)
    ans = (ans*10 + str[i]-'0') % 9;
  return ans;
}

int main(){
  int len, ans;
  gets(str);
  len = strlen(str);
  if(str[0]!='-') //正数
    printf("%d",func(str,len));
  else  //负数
    printf("%d",-func(str+1,len-1));
  return 0;
}
