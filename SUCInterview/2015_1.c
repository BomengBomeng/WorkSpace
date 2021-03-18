#include<stdio.h>

int GetNumber(int a, int n){
	int sum = 0;
	while(n>0){
		sum = sum*10 + a;
		n--;
	}
	return sum;
}

int main(){
	int n,a;
	while(2==scanf("%d %d",&a, &n)){
		if(a<=0 || a>9 || n<0){
			printf("input error!\n");
			continue;
		}
		int res=0;
		for(int i=1; i<=n; i++)
			res+=GetNumber(a,i);
		printf("res=%d\n",res);
	}

	return 0;
}
