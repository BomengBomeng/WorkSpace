#include<stdio.h>
#include<stdlib.h>

void bymodle(int n, int m){
	char *exiting = (char*)malloc(sizeof(char)*n);
	for(int i=0; i<n; i++)
		exiting[i] = 1;
	
	int num = n-1;
	int j=0, count=-1;
	while(num>=1){
		if(exiting[j]==1)
			count++;
		if(count==m){
			exiting[j]=0;
			printf("\t\t%d\n",j);
			count = -1;
			num--;
		}
		printf("%d ",j);
		j = (j+1)%n;
	}


	printf("\n");
	for(int i=0; i<n; i++)
		printf("%d ",exiting[i]);
	printf("\n");
}

/*
 f(n,m) = (f(n-1,m)-1+m)%n+1;
 */
int bymath(int n, int m){
	if(n==1)
		return 0;
	return (bymath(n-1,m)+m+1)%n;
}

int main(){
	int n,m;
	while(2==scanf("%d%d",&n,&m)){
		bymodle(n,m);
		printf("\n\n%d\n",bymath(n,m));
	}
	return 0;
}
