#include<stdio.h>

int main(){
	printf("pleas input 3 int num:\n");
	int a,b,c;
	char ch;
	scanf("%3d%3d%3d",&a,&b,&c);
	FILE *fp;
	if((fp=fopen("test.dat","w"))==NULL){
		printf("Create file Error:\n");
		return -1;
	}
	else{
		fprintf(fp,"%d%d%d",a,b,c);
		fclose(fp);
	}

	if((fp=fopen("test.dat","r"))==NULL){
		printf("Open file Error\n");
		return -1;
	}
	else{
		while(!feof(fp)){
			ch = getc(fp);
			putchar(ch);
		}
		fclose(fp);
	}
	
	return 0;
}
