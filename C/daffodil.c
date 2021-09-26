#include<stdio.h>

int main(){
  freopen("daffodil.in", "r", stdin);
  freopen("daffodil.out", "w", stdout);
  printf("100~999的水仙花数有：\n");
  int hi, mid, lo;
  for(int i=100; i<=999; i++){
    hi = i/100;
    lo = i%10;
    mid = (i%100)/10;
    //printf("-----%d %d %d\n",hi,mid,lo);
    if( (hi*hi*hi + mid*mid*mid + lo*lo*lo) == i){
      printf("%d\n", i);

    }
  }
  printf("\n");
  return 0;
}
