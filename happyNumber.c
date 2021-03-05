#include<stdio.h>

int happy(int num){
	char arr[30];
	int n=0;
	while(num!=0){
		arr[n++]=num%10;
		num /= 10;
	}
	for(int i=0; i<n; i++)
		num += arr[i]*arr[i];
	return num;
}

int IsHappyNumber(int num){
	int C1 =num, C2 = num;
	do{
		C1 = happy(C1);
		C2 = happy(C2);
		if(C1!=1)
			C1 = happy(C1);
	}while(C1!=1&&C2!=C1);
	if(C1==C2)
		return 0;
	else
		return 1;	
}

int main(){
	int num;
	scanf("%d",&num);
	printf("%d\n",IsHappyNumber(num));
	return 0;
}
