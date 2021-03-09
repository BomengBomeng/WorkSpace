#include<stdio.h>
#include<string.h>
#include<malloc.h>

//violence
int pattern_matching(char *L, char *str){
	int len_L = strlen(L);
	int len_str = strlen(str);
	for(int i=0; i<len_L; i++){
		int j = 0;
		for(;j<len_str;)
			if(L[i]==str[j]){
				j++;
				i++;
			}else{
				i = i-j+1;
				j = 0;
			}
		if(j==len_str)
			return i-j;
	}
	return -1;
}


void GetNext(int next[], int len, char *str){
	int j=0, k=-1;
	next[0] = -1;
	while(j<len-1){
		if(k==-1 || str[j]==str[k]){
			j++;
			k++;
			next[j] = k;
		}else
			k = next[k];
	}
}
int KMP1(char *L, char *str){
	int len_L = strlen(L);
	int len_str = strlen(str);
	int* next = (int*)malloc(len_str+5);
	GetNext(next, len_str, str);
	for(int i=0; i<len_str+1; i++){
		printf("%d  ",next[i]);
	}
	printf("\n");
	int i=0, j=0;
	while(i<len_L && j<len_str){
		if(j==-1 || L[i]==str[j]){
			i++;
			j++;
		}else
			j = next[j];
	}
	if(j>=len_str)
		return i-len_str;
	else
		return -1;
}



int main(){
	printf("%d\n",pattern_matching("hello, my namnamee is dongzhongli", "name"));
	printf("%d\n",KMP1("hello, my namnaabbaaaaabbacmee is dongzhongli", "aabbac"));
	return 0;
}

