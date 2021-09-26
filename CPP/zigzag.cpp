#include<stdio.h>
#include<stdlib.h>
#include<time.h>


int array[100][100];
int nNum;

int getval(int &i, int &j, int k, int n){
	/*
	int count = 1;
	while(k>count && count <=n)
		k = k - (count++);
	if(count <=n ){
		if(count%2==1){
			i=0; j=count;
			while(k--){
				i++; j--;}
		}else{
			j=0; i=count;
			while(k--){
				j++; i--;}
		}
		return array[i][j];
	}
	count -= 2;
	while(k>count)
		k = k - (count--);
	if(count%2==1){
		i=n-1; j=count-n;
		while(k--){
			i++; j--;}
	}else{
		i=count-n; j=n-1;
		while(k--){
			i--; j++;}
	}
	return array[i][j];
	*/
	i=0;j=0;
	int count = 0;
	bool fx=true;
	while(i<n && j<n){
		if(i<n&&j<n && count == k)
			break;
		if(fx){
			i--; j++; count++;
		}else{
			i++; j--; count++;
		}
		if(i<0){
			fx = !fx;
			i=0;
		}
		if(j<0){
			fx = !fx;
			j=0;
		}
	}
	return array[i][j];
}

void ChangArray(int n){
	int min_i, min_j, min;
	int tmp;
	int i,j,val;
	for(int k=0; k<n*n-1; k++){
		min = getval(min_i,min_j,k,n);
		for(int l=0; l<n*n; l++){
			val = getval(i,j,l,n);
			if(val<min){
				min = val; min_i = i; min_j = j;
			}
		}
		getval(i,j,k,n);
		if(min_i!=i || min_j!=j){
			tmp = array[i][j];
			array[i][j] = array[min_i][min_j];
			array[min_i][min_j] = tmp;
		}
	}
}


int  main(){
	int i,j;
	scanf("%d",&nNum);
	srand(time(NULL));
	for(int i=0; i<nNum; i++)
		for(int j=0; j<nNum; j++)
			array[i][j] = rand() % 100;
	for(int i=0; i<nNum; i++){
		for(int j=0; j<nNum; j++)
			printf("%2d ", array[i][j]);
		printf("\n");
	}
	for(int k=0; k<nNum*nNum; k++){
		printf("%d\t\t",getval(i,j,k,nNum));
		printf("%d:  %d %d\n", k,i,j);
	}
		
	return 0;
}
