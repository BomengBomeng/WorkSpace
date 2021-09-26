#include<stdio.h>

int static count=0;
void move(char x, char y, char z, int n){
  count++;
  if(n==1){
    printf("%d\t%c --> %c\n",n,x,z);
    return;
  }
  else{
    move(x,z,y,n-1);
    printf("%d\t%c --> %c\n",n,x,z);
    move(y,x,z,n-1);
  }
}

int main(){
  move('a','b','c',13);
  printf("the of using move() function: %d",count);
  return 0;
}
