#include<stdio.h>
#include<iostream>
#include<stack>
#include<queue>
#define Elemtype char
using namespace std;

typedef struct ThreadNode {
	Elemtype data;
	struct ThreadNode *lchild, *rchild;
	char ltag=0, rtag=0;
}*ThreadTree, ThreadNode;

void CreateBinaryTree(ThreadTree &T){
	Elemtype data;
	cin >> data;
	if(data=='#'){
		T==NULL;
		return;
	}
	T = new ThreadNode;
	T->data = data;
	CreateBinaryTree(T->lchild);
	CreateBinaryTree(T->rchild);
}
void PrePrint(ThreadTree T){
	if(T){
		printf("%d   %c   %d\n",T->ltag, T->data, T->rtag);
		PrePrint(T->lchild);
		PrePrint(T->rchild);
	}
}
void Inorder(ThreadTree T){
	stack<ThreadTree>S;
	ThreadTree p = T;
	while(p || !S.empty()){
		if(p){
			S.push(p);
			p = p->lchild;
		}else{
			p = S.top();
			S.pop();
			cout << p->data << " ";
			p = p->rchild;
		}
	}
}
void levelorder(ThreadTree T){
	queue<ThreadTree>Q;
	ThreadTree q =  T;
	Q.push(q);
	while(!Q.empty()){
		q = Q.front();
		Q.pop();
		cout << q->data << " ";
		if(q->lchild)
			Q.push(q->lchild);
		if(q->rchild)
			Q.push(q->rchild);
	}
}
//-------------------------------------------------------------中序线索二叉树
void inThread(ThreadTree &p, ThreadTree &pre){
	if(p!=NULL){
		inThread(p->lchild,pre);
		if(p->lchild==NULL){
			p->lchild = pre;
			p->ltag = 1;
		}
		if(pre!=NULL && pre->rchild==NULL){
			pre->rchild = p;
			pre->rtag = 1;
		}
		pre = p;
		inThread(p->rchild,pre);
	}
}
void CreateInorder(ThreadTree &T){
	ThreadTree pre = NULL;
	if(T!=NULL){
		inThread(T,pre);
		pre->rchild = NULL;
		pre->rtag = 1;
	}
}
ThreadNode *FirstNode(ThreadNode *p){
	while(p->ltag==0)
		p = p->lchild;
	return p;
}
ThreadNode *nextNode(ThreadNode *p){
	if(p->rtag==0)
		return FirstNode(p->rchild);
	else
		return p->rchild;
}
void Inorder_Thread(ThreadNode *T){
	for(ThreadNode *p = FirstNode(T); p!=NULL; p=nextNode(p))
		cout << p->data << " ";
}
//-------------------------------------------------------------------------
int main(){
	ThreadTree T;
	CreateBinaryTree(T);
	cout << "preorder:" << endl;
	PrePrint(T);
	cout << endl << "inorder:" << endl; 
	Inorder(T);
	cout << endl << "levelorder:" << endl;
	levelorder(T);
	cout << endl << "inThread:" <<endl;
	CreateInorder(T);
	Inorder_Thread(T);
	cout << endl;
	return 0;
}
