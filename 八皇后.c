/*八皇后*/
#include<stdio.h>
const int N = 8;
int arr[10]; total_cnt=0;

int para[9][9]; //用于存放每个位置的权值
int sum, max;

//检查该位置是否可以放置皇后
int isPlaceOk(int arr[], int n, int j){
  //j是要放置的位置
  for(int i=1; i<=n-1; i++)
    if(arr[i]==j || arr[i]-i==j-n || arr[i]+i==j+n)
      return 0;
    //a[i]==j           位置j已经在第[i]行放置过了
    //a[i]-i==j-n       斜线上出现了两个皇后
    //a[i]+i==j+n       斜线上出现了两个皇后
  return 1;
}

//打印图表
void print(int *arr){
  //打印当前排列 并 计算当前sum
  sum=0;
  for(int i=1; i<=N; i++){
    for(int j=1; j<=N; j++)
      if(arr[i]==j){
        printf("X ");
        sum += para[i][j];  //计算此种排列的sum
      }
      else
        printf("- ");
    printf("\n");
  }
  printf("sum: %d\n\n",sum);
  if(sum>max) //用max记录sum的最大值
    max = sum;
}

//添加皇后
void addQuee(int *a, int n){
  if(n>N){//上一组已经放满了八个皇后
    print(a);
    total_cnt++;  //计数器增加
    return;
  }
  for(int i=1; i<=N; i++)
    if(isPlaceOk(a,n,i)){
      a[n]=i; //可以放置则放置
      addQuee(a,n+1);
    }
}

int main(){
  //初始化
  int cv=1;
  for(int i=1; i<=N; i++)
    for(int j=1; j<=N; j++)
      para[i][j]=cv++;
  for(int i=1; i<=N; i++){
    for(int j=1; j<=N; j++)
      printf("%2d ",para[i][j]);
    printf("\n");
  }
  printf("\n");
  sum=0;
  max=0;

  addQuee(arr,1);
  printf("Total %d solutions\n",total_cnt);
  printf("max: %d",max);
  return 0;
}
