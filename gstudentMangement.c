#include"MyFileHead.h"

typedef struct {
	int num;
	char name[20];
	char sex;
	int age;
	char addr[5];
	char healthStatus[20];
	char Major[20];
}student;

int main(){
	FILE *fpin,*fpout;
	student stu;
	openfile(&fpin, "gstudent.dat", "r");
	openfile(&fpout, "简明的研究生专业.dat", "w");
	while(fread(&stu, sizeof(student), 1, fpin)!=0){
		fprintf(fpout, "%d\t%s\n",stu.num, stu.Major);
	}
	fclose(fpin);
	fclose(fpout);
	return 0;
}
