#include<stdio.h>

void split(unsigned short a, unsigned short *pOdd, unsigned short *pEven){
  if(a==0){
    *pOdd = 0;
    *pEven = 0;
    return;
  }
  char s[20];
  int len = 0;
  while(a>0){
    s[len++] = a%10;
    a /= 10;
  }
  *pOdd=0;
  *pEven=0;
  for(int i=1; i<=len; i++){
    if(i%2==1) //奇数位
      *pOdd = *pOdd*10 + s[len-i];
    else //偶数位
      *pEven = *pEven*10 + s[len-i];
  }
  return;
}

int main(){
  unsigned short n;
  unsigned short odd, even;
  while(scanf("%d",&n)==1){
    split(n,&odd, &even);
    printf("%d\t%d\n",odd,even);
  }
  return 0;
}
