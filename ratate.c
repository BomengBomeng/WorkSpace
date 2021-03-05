#include<stdio.h>
#define MAXN 40
int arr[40][40];

int main(){
	int n;
	scanf("%d",&n);
	printf("before ratating:\n\n");
	int num=0, tmp;
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			arr[i][j] = ++num;
			printf("%2d ",arr[i][j]);
		}
		printf("\n");
	}
	printf("\nafter ratating:\n\n");
	for(int i=0; i<=0; i++){
		for(int j=0; j<n-i; j++){
			tmp = arr[i][j];
			arr[i][j] = arr[j][n-i-1];
			arr[j][n-i-1] = arr[n-i-1][n-j-1];
			arr[n-i-1][n-j-1] = arr[n-j-1][i];
			//arr[n-j-1][i] = tmp;
		}
	}
	
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			printf("%2d ",arr[i][j]);
		}
		printf("\n");
	}
	return 0;
}
