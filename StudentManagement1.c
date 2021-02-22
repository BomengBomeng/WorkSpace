/*
学生管理程序：
	从键盘读入N个学生的信息存入文件中
	从文件中读入学生信息，并按序号打印一张学生成绩表
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 3

typedef struct{
	int num;
	char name[20];
	int age;
	char sex;
	int score1,score2,score3;
}Student;

void Openfile(FILE **fp, char *file, char *r_w){
	//打开文件
	if((*fp=fopen(file,r_w))==NULL){
		printf("openfile:  %s  at the modle of  %s  ERROR!\n", file, r_w);
		exit(-1);
	}
}

void Sort(Student cl[]){
	//以学号为关键字对学生数组排序v
	int i,j,min;
	//选择排序
	for(i=1; i<N; i++){
		min = i;
		for(j=i+1; j<=N; j++)
			if(cl[j].num<cl[min].num)
				min=j;
		if(min!=i){
			cl[0] = cl[min];
			cl[min] = cl[i];
			cl[i] = cl[0];
		}
	}
}

void ReadKeyBoard(Student cl[]){
	//从键盘读入信息
	printf("Please input the infomation of students: num name age sex score1 score2 score3\n");
	for(int i=1; i<=N; i++)
		scanf("%d %s %d %c %d %d %d", &cl[i].num, cl[i].name, &cl[i].age, &cl[i].sex, &cl[i].score1, &cl[i].score2, &cl[i].score3);
}

void WriteTofile(FILE **fp , Student cl[]){
	//将排序v后的学生信息写入到文件
	for(int i=1; i<=N; i++)
		fprintf(*fp, "%d %s %d %c %d %d %d\n", cl[i].num, cl[i].name, cl[i].age, cl[i].sex, cl[i].score1, cl[i].score2, cl[i].score3);
}

void PrintFromfile(FILE *fp){
	Student cl;
	for(int i=1; i<=N; i++){
		fscanf(fp,"%d %s %d %c %d %d %d", &cl.num, cl.name, &cl.age, &cl.sex, &cl.score1, &cl.score2, &cl.score3);
		printf("%d %s %d %c %d %d %d\n", cl.num, cl.name, cl.age, cl.sex, cl.score1, cl.score2, cl.score3);
	}
}

int main(int args, char *argv[]){
	if(args<2){
		printf("Missing parameters!\n");
		exit(-1);
	}
	FILE *fp;
	Student cl[N+1];
	Openfile(&fp,argv[1],"w");
	ReadKeyBoard(cl);
	Sort(cl);
	WriteTofile(&fp, cl);
	fclose(fp);
	Openfile(&fp,argv[1],"r");
	PrintFromfile(fp);
	fclose(fp);
	return 0;
}
