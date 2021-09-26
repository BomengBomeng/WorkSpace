#include<stdio.h>

int main(){
	freopen("decimal.in","r",stdin);
	freopen("decimal.out","w",stdout);
	int a,b,c;
	scanf("%d %d %d",&a,&b,&c);
	printf("%.*lf\n",c,(double)a / b);
	return 0;
}
