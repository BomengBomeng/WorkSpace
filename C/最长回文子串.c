#include<stdio.h>
#include<string.h>
#include<ctype.h>

#define MAXN 5000+10
char buf[MAXN], S[MAXN];
int p[MAXN];

int main(){
	freopen("最长回文子串.in","r",stdin);
	freopen("最长回文子串.out","w",stdout);
	fgets(buf,sizeof(S), stdin);
	int max=0, x, y;
	int n = strlen(buf);
	int m=0;
	for(int i=0; i<n; i++)
		if(isalpha(buf[i])){
			p[m]=i;
			S[m++] = toupper(buf[i]);	
		}
	for(int i=0; i<m; i++){
		for(int j=0; i-j>=0 && i+j<m; j++){
			if(S[i-j] != S[i+j]) break;
			if(j*2+1 > max){
				max = j*2+1;
				x = p[i-j];
				y = p[i+j];
			}
		}
		for(int j=0; i-j>=0 && i+j+1<m; j++){
			if(S[i-j] != S[i+j+1]) break;
			if(j*2+2 >max){
				max = j*2+2;
				x = p[i-j];
				y = p[i+j+1];
			}
		}
	}
	for(int i=x; i<=y; i++)
		printf("%c",buf[i]);
	printf("\n");
	return 0;

}
