#include<stdio.h>

#define MAX_N 1000
//#define max(a,b)  ((a)>(b) ? (a):(b))

int s[MAX_N+5], top;
int l[MAX_N+5], r[MAX_N+5];

int max_matrix_area(int *h, int n){
	h[0] = h[n+1] = -1;
	//找到每一块木板，左边第一块木板比其矮的木板的编号
	top = -1;  s[++top]=0;
	for(int i=1; i<=n; i++){
		while(top>=0 && h[s[top]]>=h[i])
			--top;
		l[i] = s[top];
		s[++top] = i;
	}
	//找到每一块木板，右边第一块木板比其矮的木板的编号
	top = -1;  s[++top] = n+1;
	for(int i=n; i>=1; i--){
		while(top>=0 && h[s[top]]>=h[i])
			--top;
		r[i] = s[top];
		s[++top] = i;
	}
	//在所有木板中找到面积最大的矩形
	int ans = 0;
	for(int i=1; i<=n; i++){
		//ans = max(ans, (r[i]-l[r]));
		ans = ans>(r[i]-l[i]-1)*h[i] ? ans : (r[i]-l[i]-1)*h[i];
	}
	return ans;
}

int main(){
	int wall[10] = {0,2,1,4,5,1,3,3,0,0};
	int ans = max_matrix_area(wall,7);
	printf("%d\n",ans);
	return 0;
}
