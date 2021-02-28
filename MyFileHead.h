#include<stdio.h>
#include<stdlib.h>

void openfile(FILE **fp, char *filename,  char *r_w){
	if((*fp=fopen(filename, r_w))==NULL){
		printf("ERROR! Can not open the file %s  int the model of  %s !\n", filename, r_w);
		exit(-1); 
	}
		
}

void checkParameters(int args, int n){
	if(args<n){
		printf("ERROR! Missing paramters!\n");
		exit(-1);
	}
}


