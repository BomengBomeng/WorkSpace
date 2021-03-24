#include<stdio.h>

int arr[21] = {99,1,2,2,2,2,4,5,0,9,7,10,15,19,17,18,12,2,13,11,16};

void insertSort(int *R, int n){
  int i,j;
  for(i=2; i<=n; i++)
    if(R[i]<R[i-1]){
      R[0] = R[i];
      for(j=i-1; R[j]>R[0]; j--)
        R[j+1] = R[j];
      R[j+1] = R[0];
    }
}
void BinarySearchInsertSort(int *R, int n){
  int low, high, mid, i, j;
  for(i=2; i<=n; i++)
    if(R[i]<R[i-1]){
      low = 1;
      high = i-1;
      while(low<=high){
        mid = (low+high)/2;
        if(R[mid]>R[i])
          high = mid-1;
        else  //R[mid]<=R[i]
          low = mid+1;
      }
      R[0] = R[i];
      for(j=i-1; j>=high+1; j--)
        R[j+1] = R[j];
      R[j+1] = R[0];
    }
}
void ShellSort(int *R, int n){
  int i,j;
  for(int dk=n/2; dk>=1; dk/=2)
    for(i=dk+1; i<=n; i++)
      if(R[i] < R[i-dk]){
        R[0] = R[i];
        for(j=i-dk; R[j]>R[0] && j>0; j-=dk)
          R[j+dk] = R[j];
        R[j+dk] = R[0];
      }
}
void PopSort(int *R, int n){
  int flage;
  for(int i=1; i<n; i++){
    flage = 1;
    for(int j=n; j>i; j--)
      if(R[j-1]>R[j]){
        R[0] = R[j-1];
        R[j-1] = R[j];
        R[j] = R[0];
        flage=0;
      }
    if(flage)
      break;
  }
}
int Partion(int *R, int low, int high){
    R[0] = R[low];
    while(low<high){
      while(low<high && R[0]<=R[high])
        high--;
      if(low<high)
        R[low] = R[high];
      while(low<high && R[low]<=R[0])
        low++;
      if(low<high)
        R[high] = R[low];
    }
    R[low] = R[0];
    return low;
}
void QuickSort(int *R, int low, int high){
  if(low<high){
    int part = Partion(R, low, high);
    QuickSort(R, low, part-1);
    QuickSort(R, part+1, high);
  }
}
void SelectSort(int *R, int n){
  int max, maxp;
  for(int i=1; i<n; i++){
    max = R[i]; //用R[0]暂存当前最小元素
    maxp = i;
    for(int j=i+1; j<=n; j++)
      if(R[j]<max){
        max = R[j];
        maxp = j;
      }
    if(maxp!=i){
      R[0] = R[maxp];
      R[maxp] = R[i];
      R[i] = R[0];
    }
  }
}
void adjustDown(int *R, int k, int n){
  R[0] = R[k];
  for(int i=2*k; i<=n; i*=2){
    if(i<n&&R[i]<R[i+1])//取较大节点的下标
      i++;
    if(R[0]>=R[i])
      break;            //筛选结束
    else{
      R[k] = R[i];
      k=i;
    }
  }
  R[k] = R[0];
}
void BuildMaxHeap(int *R, int n){
  for(int i=n/2; i>0; i--)
  adjustDown(R,i,n);
}
void HeapSort(int *R ,int n){
  BuildMaxHeap(R,n);
  for(int i=n; i>1; i--){
    R[0] = R[i];
    R[i] = R[1];
    R[1] = R[0];
    adjustDown(R,1,i-1);
  }
}

int main(){
  for(int i=0; i<21; i++)
    printf("%2d  ",arr[i]);
  printf("\n");
  //insertSort(arr,20);
  //BinarySearchInsertSort(arr,20);
  //ShellSort(arr,20);
  //QuickSort(arr,1,20);
  //PopSort(arr,20);
  //SelectSort(arr,20);
  HeapSort(arr,20);
  for(int i=0; i<21; i++)
    printf("%2d  ",arr[i]);
  printf("\n");
  return 0;
}
