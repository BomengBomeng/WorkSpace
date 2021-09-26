/*约瑟夫环*/
#include<stdio.h>

int jump(int n, int m){
  if(n==1)
    return 0;
  else
    return (jump(n-1,m)+m)%n;
}

int main(){
  printf("%d",jump(100000,100));
  return 0;
}
