#include<stdio.h>
#include<stdlib.h>
#include<time.h>

double PI(){
	int x,y;
	int i=0;
	int count=0;
	while(i<1000000000){
		i++;
		x = rand() % 10000;
		y = rand() % 10000;
		if(x*x + y*y <= 100000000)
			count++;
	}
	return 4*((double)count / (double)i);
}

int main(){
	srand(time(NULL));
	printf("%f\n",PI());
	return 0;
}
