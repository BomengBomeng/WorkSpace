#include<stdio.h>
#include<malloc.h>
//数据格式
#define Elemtype int
//数组大小
#define MAXSIZE 100
//链表结构
typedef struct Node{
  Elemtype data;
  struct Node *PNext;
}Node;

//快速排序
int partition(Elemtype R[], int low, int high){
  //R[0]中为存有效元素
  R[0] = R[low];
  while(low<high){
    while(R[high]>R[0] && low<high)
      high--;
    if(low<high)
      R[low] = R[high];
    while(R[low]<R[0] && low<high)
      low++;
    if(low<high)
      R[high] = R[low];
  }//while
  R[low] = R[0];
  return low;
}
void QuickSort(int R[], int low, int high){
  if(low>=high)
    return;
  int mid = partition(R,low,high);
  QuickSort(R,low,mid-1);
  QuickSort(R,mid+1,high);
}

//归并排序__数组形式
Elemtype B[MAXSIZE];
void Merge(Elemtype R[], int low, int mid, int high){
  int i,j,k;
  for(i=low; i<=high; i++)
    B[i] = R[i];
  //顺序归并
  for(i=low,k=low, j=mid+1; i<=mid&&j<=high; )
    if(B[i]<=B[j])
      R[k++]=B[i++];
    else
      R[k++]=B[j++];
  //归并剩余
  while(i<=mid)
    R[k++]=B[i++];
  while(j<=high)
    R[k++]=B[j++];
}
void Merge_sort(Elemtype R[], int low, int high){
  if(low<high){
    int mid = (low+high)/2;
    Merge_sort(R,low,mid);
    Merge_sort(R,mid+1,high);
    Merge(R,low,mid,high);
  }
}


//归并排序__链表形式
void port(Node *Head, Node **la, Node **lb){//将单链表剖分为两份
  if(Head==NULL || Head->PNext==NULL){
    *la=Head;
    *lb=NULL;
    return;
  }
  Node *p = Head;
  Node *q = Head->PNext;
  while(q!=NULL){
    q=q->PNext;
    if(q!=NULL){
      p=p->PNext;
      q=q->PNext;
    }
  }
  *la = Head;
  *lb = p->PNext;
  p->PNext = NULL;
}
Node *Merge_list(Node *la, Node *lb){//归并两个单链表
  if(la==NULL)
    return lb;
  if(lb==NULL)
    return la;
  Node *p, *q, *r, *t;
  //处理第一个节点
  if(la->data<=lb->data){
    r=la; q=lb; p=la->PNext;
    r->PNext=NULL;
  }else{
    r=lb; q=lb->PNext; p=la;
    r->PNext=NULL;
  }
  la=r; //最后返回la
  while(p!=NULL && q!=NULL){
    if(p->data<=q->data){
      t = p->PNext;
      p->PNext = r->PNext;
      r->PNext = p;
      r=r->PNext;
      p = t;
    }else{
      t = q->PNext;
      q->PNext = r->PNext;
      r->PNext = q;
      r=r->PNext;
      q = t;
    }
  }//while
  if(p)
    r->PNext = p;
  if(q)
    r->PNext = q;
  return la;
}
void MergeSort_List(Node **L){//排序
  Node *Head = *L;
  if(Head==NULL || Head->PNext==NULL)
    return; //无需排序
  Node *la, *lb;
  port(Head, &la, &lb);
  //分别排序
  MergeSort_List(&la);
  MergeSort_List(&lb);
  //归并之
  *L = Merge_list(la,lb);
}
void CreateList(Node **L){//创建单链表
  Elemtype ch;
  Node *p;
  scanf("%d",&ch);
  if(ch==10000){
    *L==NULL;
    return;
  }else{
    p = (Node*)malloc(sizeof(Node));
    p->data = ch;
    p->PNext = NULL;
    *L = p;
  }
  scanf("%d",&ch);
  while(ch!=10000){
    p = (Node*)malloc(sizeof(Node));
    p->data = ch;
    p->PNext = (*L)->PNext;
    (*L)->PNext = p;
    scanf("%d",&ch);
  }
}
void PrintList(Node *L){//打印单链表
  while(L!=NULL){
    printf("%2d  ",L->data);
    L = L->PNext;
  }
  printf("\n");
}


int main(){
  Node *p;
  CreateList(&p);
  PrintList(p);
  MergeSort_List(&p);
  PrintList(p);
  return 0;
}
