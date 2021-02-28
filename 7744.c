/*输出所有形如aabb的四位完全平方数*/
#include<stdio.h>
#include<math.h>

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
