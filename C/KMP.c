#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int indexedl(char *str, char *tt){
  int len_str = strlen(str);
  int len_tt = strlen(tt);
  int i=0, j=0;
  while(i<len_str && j<len_tt){
    if(str[i]==tt[j]) { i++; j++; }
    else {  i=i-j+1; j=0;  }
  }
  if(j==len_tt)
    return  i-j;
  else
    return -1;
}

int *GetNext(char *tt){
  int len_tt = strlen(tt);
  int *next = (int *)malloc(sizeof(int)*len_tt);
  next[0] = -1;
  int i=0, j=-1;
  while(i<len_tt-1){
    if(j==-1 || tt[i]==tt[j]){
      i++;  j++;
      next[i] = j;
    }else
      j = next[j];
  }
  return next;
}
int *GetNextval(char *tt){
  int len_tt = strlen(tt);
  int *nextval = GetNext(tt);
  for(int i=1; i<len_tt; i++)
    if(tt[i]==tt[nextval[i]])
      nextval[i] = nextval[nextval[i]];
    else
      nextval[i] = nextval[i];
  return nextval;
}

int index_kmp(char *str, char *tt){
  int *nextval = GetNextval(tt);
  int len_str = strlen(str);
  int len_tt = strlen(tt);
  int i=0,j=0;
  while(i<len_str && j<len_tt){
    if(j==-1||str[i]==tt[j])  { i++; j++; }
    else  j = nextval[j];
  }
  if(j==len_tt)
    return i-j;
  else
    return -1;
}


int main(){
  char str[] = "googlogooglababaaabegooglo";
  char tt[] = "ababaaab";
  printf("%d\n",indexedl(str,tt));
  printf("%d\n",index_kmp(str,tt));
  return 0;
}
