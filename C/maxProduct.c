#include<stdio.h>
#include<limits.h>
int s[19];

int main(){
	int n;
	scanf("%d",&n);
	for(int i=0; i<n; i++)
		scanf("%d", &s[i]);
	long long max=INT_MIN, x;
	for(int i=0; i<n-1; i++)
		for(int j=i+1; j<n; j++){
			x = 1;
			for(int k=i; k<=j; k++)
				x *= s[k];
			if(x>max){
				max = x;
			}
		}
	printf("%lld\n", max>0? max : -1);
	return 0;
}
