#include<stdio.h>
#include<time.h>
int main(){
	const int MOD = 1000000;
	int i, j, n, s=0;
	scanf("%d",&n);
	if(n>25)
		n=25;
	for(i=1; i<=n; i++){
		int factorical = 1;
		for(j=1; j<=i; j++)
			factorical = (factorical * j % MOD);
		s = (s+factorical) % MOD;
	}
	printf("%d\n",s);
	printf("Time used: %.2lf\n",(double)clock() / CLOCKS_PER_SEC);

	return 0;
}
