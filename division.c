#include<stdio.h>

int compare(int arr[], int n){
	for(int i=0; i<n-1; i++)
		for(int j=i+1; j<n; j++)
			if(arr[j]==arr[i])
				return 0;
	return 1;
}

int test(){
	int x;
	scanf("%d",&x);
	int arr[10];
	int i=1234;
	while(i<=98765){
		arr[0] = i%10;
		arr[1] = i/10 %10;
		arr[2] = i/100 %10;
		arr[3] = i/1000 %10;
		arr[4] = i/10000;
		//for(int j=0; j<10; j++)
		//	printf("%d",arr[j]);
		//printf("  %d\n", i);
		int res = i * x;
		i++;
		if(res>98765)
			continue;	
		arr[5] = res%10;
		arr[6] = res/10 %10;
		arr[7] = res/100 %10;
		arr[8] = res/1000 %10;
		arr[9] = res/10000;
		if(compare(arr,10)){
			for(int j=9; j>=5; j--)
				printf("%d",arr[j]);
			printf(" / ");
			for(int j=4; j>=0; j--)
				printf("%d",arr[j]);
			printf(" = %d\n", x);
		}
	}
	return 0;
}

int main(){
	test();
	return 0;

}
