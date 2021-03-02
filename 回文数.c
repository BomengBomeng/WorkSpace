#include<stdio.h>

/*倒置数*/
int reverse(int t){
  char list[30];
  int i=0;
  while(t>0){
    list[i++] = t % 10;
    t = t/10;
  }
  int sum=0;
  for(int j=0; j<i; j++)
    sum = sum*10 + list[j];
  return sum;
}
/*判断回文数*/
int judge(int t){
  char list[30];
  int i=0;
  while(t>0){
    list[i++] = t % 10;
    t = t/10;
  }
  for(int j=0; j<i/2; j++){
    if(list[j]!=list[i-1-j])
      return 0;
  }
  return 1;
}
/*寻找回文数*/
int func(int t){
  if(judge(t)==1){//是回文数
    return t;
  }
  printf("%d + %d = %d\n",t,reverse(t), t+reverse(t) );
  return func(t + reverse(t) );
}


int main(){
  func(87);
  return 0;
}
