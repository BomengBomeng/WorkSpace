/*
#include<stdio.h>
#include<string.h>
int main(){
  char a[1005],b[1005];
  char res[1005],tres[1005];
  int maxlen;
  while(scanf("%s %s", a, b)==2){
    int len1 = strlen(a);
    int len2 = strlen(b);
    maxlen = 0;
    for(int i=0; i<len2; i++){
      int ii=i;
      int templen = 0;
      int k=0;
      for(int j=0; j<len1; j++){
        int s=j;
        while(b[ii]==a[s]){
          templen++;
          ii++;
          tres[k++] = a[s];
          s++;
        }
        tres[k] = '\0';
        if(templen>maxlen){
          maxlen = templen;
          strcpy(res,tres);
        }
        templen=0; ii=i; k=0;
      }//while()
    }
    printf("%s\n",res);
  }
  return 0;
}
*/
#include<stdio.h>
#include<string.h>

int main(){
  char a[105],b[105],res[105],tres[105];
  while(scanf("%s%s",a,b)==2){
    int maxlen=0;
    int len_a = strlen(a);
    int len_b = strlen(b);
    for(int i=0; i<len_b; i++){
      int ii=i;
      int tmplen=0;
      int k=0;
      for(int j=0; j<len_a; j++){
        int s=j;
        while(a[ii]==b[s]){
          tmplen++;
          ii++;
          tres[k++] = b[s++];
        }
        tres[k]='\0';
        if(tmplen>maxlen){
          maxlen = tmplen;
          strcpy(res,tres);
        }
        tmplen=0; ii=i; k=0;
      }
    }
    printf("%s\n",res);
  }//while
}
