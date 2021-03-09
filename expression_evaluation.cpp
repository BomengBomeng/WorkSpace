#include<cstdio>
#include<stdio.h>
#include<string.h>
#include<stack>

using namespace std;

char input[200];
char suff[200];

int GetPriority(char sy){
	switch(sy){
		case '+':
		case '-':	return 1;
		case '*':
		case '/':	return 2;
	}
}

void reverse(){
	stack<char>s;
	int len = strlen(input);
	int j=0;
	for(int i=0; i<len; i++){
		switch(input[i]){
			case '(' : s.push(input[i]);	break;

			case ')' : 
				   while(!s.empty() && s.top()!='('){
				   	suff[j++] = s.top();
					s.pop();
				   } 
				   s.pop();
				   break;
			case '+':
			case '-':
				   if(s.top()=='(' || GetPriority(input[i])>GetPriority(s.top())){
					   s.push(input[i]);
				   }
				   else{
				   
					   while(!s.empty() && GetPriority(input[i])<=GetPriority(s.top())){
						//suff[j++] = s.pop();
				   		suff[j++] = s.top();
						s.pop();
					   }
					   s.push(input[i]);
					   
				   }
				   break;
			case '*':
			case '/':  
				   s.push(input[i]);
				   break;
			default:
				   suff[j++] = input[i];

		}
	}
	while(!s.empty()){
		//suff[j++] = s.pop();
		suff[j++] = s.top();
		s.pop();
	}
}
int main(){
	fgets(input,200,stdin);
	puts(suff);
	return 0;
}
