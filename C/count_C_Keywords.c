#include<stdio.h>

struct {
	char word[10];
	int count;
}Key,KeyWord[]={"char",0,"int",0};

FILE *fp;
char fname[20], buf[50];//letter is stored in buf[]
int num;

char *getword(FILE *fp){
	int i=0; char ch;
	while((ch=fgetc(fp))!=EOF && (ch==' ' || ch=='\t' || ch=='\n'));	//move to the start of letter
	if(ch==EOF)
		return(0);
	else
		buf[i++]=ch;
	while((ch=fgetc(fp))!=EOF && ch!=' ' && ch!='\t' && ch!='\n')
		buf[i++] = ch;
	buf[i] = '\0';
	return (buf);
}

void lookup(char *p){
	int i; char *q, *s;
	for(i=0; i<num; i++){
		q = &KeyWord[i].word[0];
		s=p;
		while(*s && *s==*q){
			s++; q++;
		}
		if(*s==*q){
			KeyWord[i].count++;
			break;
		}
	}
	return;
}

void main(){
	int i; char *word;
	printf("Input filename:\n");
	scanf("%s",fname);
	if((fp=fopen(fname,"r"))==NULL){
		printf("Open Error\n");
		return;
	}
	num = sizeof(KeyWord) / sizeof(Key);
	while((word=getword(fp))!=NULL){
		lookup(word);
	}
	fclose(fp);
	printf("the result:\n");
	for(i=0; i<num; i++)
		printf("%s:\t%d\n",KeyWord[i].word, KeyWord[i].count);
	return;
}
