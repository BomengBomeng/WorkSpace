#include<stdio.h>

int main(){
  freopen("digit.in", "r", stdin);
  freopen("digit.out", "w", stdout);
  int n, count=0;
  scanf("%d",&n);
  while(n!=0){
    count++;
    n = n / 10;
  }
  printf("这是一个 %d 位数\n", count);
  return 0;
}
