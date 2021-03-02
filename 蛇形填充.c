/*蛇形填充*/
#include<stdio.h>
int a[750][750];
int main(){
  int n;
  printf("Please input the size of matrix:\n");
  scanf("%d",&n);
  int num=1;
  for(int k=0; k<n/2; k++){
    for(int i=k; i<n-k; i++) a[k][i]=num++;
    for(int i=k+1; i<n-k; i++) a[i][n-k-1] = num++;
    for(int i=n-k-2; i>=k; i--) a[n-k-1][i] = num++;
    for(int i=n-k-2; i>k; i--)  a[i][k] = num++;
  }
  if(n%2==1)
    a[n/2][n/2]=num;
  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++)
      printf("%5d ",a[i][j]);
    printf("\n");
  }
  return 0;
}
