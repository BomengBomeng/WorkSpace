#include<stdio.h>
#define Size 100
int UFsets[Size];

void  initial(int *S){
	for(int i=0; i<Size; i++)
		S[i]=-1;
}
int Find(int *S, int x){
	while(S[x]>=0)
		x = S[x];
	return x;
}
void Union(int *S, int Root1, int Root2){
	S[Root1]=Root2;
}

int main(){
	initial(UFsets);
	Union(UFsets,6,0);
	Union(UFsets,7,0);
	Union(UFsets,8,0);
	Union(UFsets,4,1);
	Union(UFsets,9,1);
	Union(UFsets,3,2);
	Union(UFsets,5,2);
	//Union(UFsets,6,0);
	for(int i=0; i<20; i++)
		printf("%2d  ",UFsets[i]);
	printf("\n");
	printf("the root of 9 :  %d\n",Find(UFsets,9));
	Union(UFsets,1,0);
	printf("the root of 9 :  %d\n",Find(UFsets,9));
	printf("the root of 4 :  %d\n",Find(UFsets,4));
	return 0;
}
