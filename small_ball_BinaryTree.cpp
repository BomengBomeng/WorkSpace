#include<stdio.h>
#include<string.h>

const int MAXD = 20;
int s[1<<MAXD];		//i<<MAXD == z^MAXD;

int test01(){
	int D, I;
	while(scanf("%d%d", &D, &I)==2){
		memset(s,0,sizeof(s));	//turn off
		int k, n = (1<<D)-1;
		for(int i=0; i<I; i++){
			k = 1;
			for(;;){
				s[k]=!s[k];
				k = s[k]? k*2 : k*2+1;
				if(k>n)	break;
			}
		}
		printf("%d\n", k/2);
	}
	return 0;
}
int test02(){
	int D, I;
	while(scanf("%d%d", &D, &I)==2){
		int k = 1;
		for(int i=0; i<D-1; i++)
			if(I%2){	//I is odd
				k = k*2;
				I = (I+1)/2;
			}else{		//I is even
				k = k*2+1;
				I = I/2;
			}
		printf("%d\n",k);
	}
	return 0;
}
int main(){
	test02();
	return 0;
}
