#include<stdio.h>

int main(){
	int n,m;
	while(scanf("%d %d",&m,&n)==2){
		if(n<0){
			printf("Input error\n");
			continue;
		}
		int res = 1, ori = m;
		while(n){
			if(n&1)
				res *= ori;
			ori *= ori;
			n >>= 1;
		}
		printf("res=%d\n",res);
	}
}
