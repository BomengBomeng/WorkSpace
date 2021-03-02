#include<stdio.h>

void func(char ch1[], char ch2[], char str[]){
	char ch;
	int i=0,j=0,k=0;
	while(ch1[i]!='\0')
		str[k++] = ch1[i++];
	while(ch2[j]!='\0')
		str[k++] = ch2[j++];
	str[k] = '\0';
}

int main(int argc, char **argv){
	FILE *f1,*f2;
	char ch;
	char str[100];
	if(argc<2){
		printf("Parameters missing!\n");
		return -1;
	}
	func(argv[1],"_Binary",str);

	if((f1=fopen(argv[1],"rb"))==NULL || (f2=fopen(str,"wb"))==NULL){
		printf("Can not open file!\n");
		return -1;
	}

	fread(&ch,1,1,f1);
	while(!feof(f1)){
		fprintf(f2,"%x",ch);
		fread(&ch,1,1,f1);
	}
	fprintf(f2,"\n");
	fclose(f1);
	fclose(f2);

	return 0;
}
