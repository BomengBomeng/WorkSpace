#include<stdio.h>
#include<string.h>

#define MAXN 1000 + 10

char a[MAXN];  //a[i]==1 则为开灯，a[i]==-1 则为关灯

int main(){
	int n, k;
	scanf("%d %d", &n, &k);
	//初始化，全部关灯
	for(int i=1; i<=n; i++)
		a[i]=-1;
	for(int i=1; i<=k; i++)
		for(int j=i; j<=n; j+=i)
			a[j] *= -1;
	for(int i=1; i<=n; i++)
		if(a[i]==1)
			printf("%d ",i);
	printf("\n");
	return 0;
}
