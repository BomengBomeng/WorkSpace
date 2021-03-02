#include<stdio.h>

int main(){
  freopen("triangle.in", "r", stdin);
  freopen("triangle.out", "w" ,stdout);
  for(int i=0; i<5; i++){
    for(int j=0; j<=i; j++)
      printf(" ");
    for(int k=1; k<=9-2*i; k++)
      printf("#");
    printf("\n");
  }
  return 0;
}
