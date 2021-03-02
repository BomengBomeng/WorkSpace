#include<stdio.h>

int main(){
	char fname[30];
	printf("please input the file name:\n");
	scanf("%s",fname);
	FILE *fp;
	if( (fp = fopen(fname,"r"))==NULL ){
		printf("Open file Error");
		return -1;
	}
	int maxlength=0, maxline=0, length=0, line=0;
	char ch;
	while(!feof(fp)){
		ch = fgetc(fp);
		if(ch=='\n'){
			if(length>maxlength){
				maxlength = length;
				maxline = line;
			}
			line++;
			length=0;
		}else
			length++;
	}
	fclose(fp);
	
	printf("maxline: %d, maxlength: %d\n",maxline,maxlength);
	
	return 0;
}
