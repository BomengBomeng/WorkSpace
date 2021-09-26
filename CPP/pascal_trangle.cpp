#include<stdio.h>

int func(int i, int j){
	if(j==1 || i==j)
		return 1;
	else
		return func(i-1,j-1) + func(i-1,j);
}

int main(){
	int i=0, j=0;
	while(2==scanf("%d%d",&i, &j)){
		printf("%d\n",func(i,j));
	}
	return 0;
}
