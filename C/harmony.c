#include<stdio.h>

int main(){
  freopen("harmony.in", "r", stdin);
  freopen("harmony.out", "w" ,stdout);
  int n;
  double h=0;
  scanf("%d",&n);
  while(n>0)
    h += 1.0 / n--;
  printf("%.3lf", h);
  return 0;
}
