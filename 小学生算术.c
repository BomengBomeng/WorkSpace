#include<stdio.h>
int main(){
	int a,b;
	int c=0, ans=0;
	while(scanf("%d%d",&a,&b)==2){
		if(!a && !b)
			break;
		c=0; ans=0;
		for(int i=9; i>=0; i--){
			//c = (a%10+b%10+c)>9? 1:0;
			c = (a%10+b%10+c)/10;
			ans += c;
			a /= 10;
			b /= 10;
		}
		printf("%d\n",ans);
	}
	return 0;
}
