#include<stdio.h>

int main(){
  freopen("approximation.in", "r", stdin);
  freopen("approximation.out", "w" ,stdout);
  double PI_4=1.0, item=1.0;  //已经确定第一项
  int i=0;
  while(item>0.000001){
    i++;
    item = -1.0/(2*i+1);   //偶数项
    PI_4 += item;
    i++;
    item = 1.0/(2*i+1);    //奇数项
    PI_4 += item;
  }
  printf("%.5lf",PI_4);
  return 0;
}
