#include<stdio.h>
int same(int R[], int k);
int input[6];					//生命函数

void func(int arr[], int n){
	if(n==0){				//arr数组中已经完成5个数的排列，输出之
		for(int i=1; i<=5; i++)
			printf("%d ",arr[i]);
		printf("\n");
		return ;
	}
	for(int i=1; i<=5; i++){		//为当前的arr[n]添加一个input[]中的数,不重复
		arr[n] = input[i];
		if(!same(arr,n))		//将input[i]放入数组不造成重复
			func(arr,n-1);		//递归调用func函数完成下一元素的填入
	}
}
int same(int R[], int k){			//判断新加入数组的这个数是否与先前加入的重复；重复，返回1；不重复返回0
	for(int i=k+1; i<=5; i++)
		if(R[k]==R[i])
			return 1;
	return 0;
}
/*主函数*/
int main(){
	int arr[6];				//创建一个工作数组
	for(int i=1; i<=5; i++)			//输入5个数到input数组中
		scanf("%d",&input[i]);
	printf("the result:\n");
	func(arr,5);				//调用func函数
	return 0;
}
