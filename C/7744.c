/*输出所有形如aabb的四位完全平方数*/
#include<stdio.h>
#include<math.h>

/*
int main(){
	int n;
	double m;
	for(int i=1; i<=9; i++)
		for(int j=0; j<=9; j++){
			n = i*1100 + j*11;
			m = sqrt(n);
			if(floor(m+0.5)==m)
				printf("%d\n",n);		
		}
	return 0;
}
*/

int main(){
	int x, n, hi, lo;
	for(x=1; ; x++){
		n = x * x;
		if(n<1000)  continue;
		if(n>9999)  break;
		hi = n/100;
		lo = n%100;
		if(hi%10==hi/10 && lo%10==lo/10)
			printf("%d\n",n);
	}
	return 0;
}

