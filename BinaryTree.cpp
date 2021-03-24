#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct TNode{
	int have_val;
	int val;
	struct TNode *left,*right;
}Node;

//inital
Node *root;
char s[200];

Node *newNode(){
	Node* u = (Node*)malloc(sizeof(Node));
	if(u!=NULL){
		u->have_val = 0;
		u->left = u->right = NULL;
	}
	return u;
}

int addNode(int val, char *s){
	int n = strlen(s);
	Node *u = root;
	for(int i=0; i<n; i++)
		if(s[i]=='L'){
			if(u->left==NULL)
				u->left = newNode();
			u = u->left;
		}else if(s[i]=='R'){
			if(u->right==NULL)
				u->right = newNode();
			u = u->right;
		}else	//s[i]!'L' && s[i]!='R'	ignore
			;
	if(u->have_val)
		return 0;	//Error
	u->val = val;
	u->have_val = 1;
	return 1;		//ok
}

int read_input(){
	root = newNode();
	while(1){
		if(scanf("%s",s)!=1)
			return 0;	//the end of inputing
		printf("%s  \n",s);
		if(!strcmp(s,"()"))
			break;
		int v;
		sscanf(&s[1],"%d",&v);
		addNode(v,strchr(s,',')+1);
	}
	return 1;
}

int n=0, ans[200];
int bfs(){
	int front=0, rear=1;
	Node *q[200];
	q[0]=root;
	Node *u;
	while(front<rear){
		u = q[front++];
		if(!u->have_val)
			return 0;
		ans[n++] = u->val;
		if(u->left!=NULL)
			q[rear++] = u->left;
		if(u->right!=NULL)
			q[rear++] = u->right;
	}
	return 1;
}


int main(){
	freopen("BinaryTree.in", "r", stdin);
	read_input();
	bfs();
	for(int i=0; i<200; i++)
		printf("%d  ",ans[i]);
	printf("\n");
	return 0;
}
