#include<stdio.h>
int main(){
	int n;
	while(scanf("%d",&n)==1){
		int k=1, s=0;
		for(;;){
			s += k;
			if(s>=n){
				s -= k;
				if(k%2==1)
					printf("%d/%d\n",k-(n-s)+1, n-s);
				if(k%2==0)
					printf("%d/%d\n",n-s, k-(n-s)+1);
				break;
			}
			k++;
		}
	}
	return 0;
}
