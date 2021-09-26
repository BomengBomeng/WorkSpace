#include<stdio.h>
int main(){
  freopen("hanxin.in", "r", stdin);
  freopen("hanxin.out", "w" ,stdout);
  int a, b, c;
  scanf("%d %d %d", &a, &b, &c);
  for(int i=10; i<=100; i++){
    if(i%3==a && i%5==b && i%7==c){
      printf("队伍认数的最小值位： %d\n",i);
      return 0;
    }
  }
  printf("No answer!\n");
  return 0;
}
