#include<stdio.h>
#include<malloc.h>
int main(){
  freopen("stat.in", "r", stdin);
  freopen("stat.out", "w" ,stdout);
  int n, m;
  scanf("%d",&n);
  int *L = (int*)malloc(sizeof(int)*n);
  for(int i=0; i<n; i++)
    scanf("%d", (L+i));
  scanf("%d", &m);
  int count=0;
  for(int i=0; i<n; i++)
    if(L[i]<m)
      count++;
  printf("%d\n", count);
  return 0;
}
