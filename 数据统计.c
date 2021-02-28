/*输入、输出从定向*/
#include<stdio.h>
#define INF 10000000
int main(){

#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	printf("Local demo:\n");
#endif
	int x, n=0, min = INF, max = -INF, s = 0;
	while(scanf("%d", &x)==1){
		s += x;
		if(x<min) min = x;
		if(x>max) max = x;
		n++;
	}
	printf("%d %d %.3lf\n", min, max, (double)s/n);
	return 0;
}
