/*只有4和7两个数组成的序列，从小到大排列，给你n代表第n个数要你输出这个数。*/
#include<stdio.h>
int func(int n, char st[100]){
  //将数据解释成二进制数组
  int num = n+1;
  int i=0;
  while(num){
    st[i++] = num % 2;
    num /= 2;
  }
  //翻转数组
  char temp;
  for(int k=0; k<i/2; k++){
    temp = st[k];
    st[k] = st[i-1-k];
    st[i-1-k] = temp;
  }
  return i;   //返回数组中的元素个数
}
int main(){
  char st[100]; //生成的数以字符形式存在数组中
  int n;
  printf("Please input the n-th:\n");
  scanf("%d",&n);
  int rs = func(n, st);
  for(int i=1; i<rs; i++)
    if(st[i]==1)
      printf("7");
    else
      printf("4");
  return 0;
}
