#include<stdio.h>
#include<stdlib.h>
#define OK 1
#define ERROR 0
#define OVERFlOW -2
#define LIST_INIT_SIZE 10
typedef int Status;
typedef int ElemType;

//链表
//定义数据域内容 
typedef struct student{
	char num[8]; 
	char name[8]; 
	int score; 
}student;//定义数据库：学号，姓名，成绩 
//定义结点 
typedef struct Lnode{
	student data;//数据域 
	struct Lnode *next;//指针域 
}Lnode,*LinkList; 
 
 
//单链表的初始化
Status InitList_L(LinkList &L){
	L = new Lnode;//或 L = (LinkList) malloc (sizeof(Lnode)); 
	L->next=NULL;
	return OK;
}

//判断链表是否为空
Status ListEmpty(LinkList L){
	if(L->next)
		return 0;
	else
		return 1;
}

//销毁单链表L
Status DestoryList_L(LinkList &L){
	Lnode *p;
	while(L){
		p = L;
		L = L->next;
		delete p;
	}
}

//清空单链表
Status ClearList(LinkList &L){
	Lnode *p,*q;
	p = L->next;
	while(p){
		q = p->next;
		delete p;
		p = q;
	}
	L->next = NULL;
	return OK;
} 

//求链表的长度并返回 
Status ListLength_L(LinkList L){
	LinkList p;
	p = L->next;
	int i = 0;
	while(p){
		i++;
		p=p->next;
	}
	return i;
}

//从链表中找到第i个元素，并将内容赋值给e
/*
Status GetElem_L(LinkList L,int i,student &e){
	LinkList p = L->next;
	int j=1;
	while(p&&j<i){
		p = p->next;
		++j;
	}
	if(!p||j>i)
	return ERROR;//第i个元素不存在 
	student e = p->data;
	return OK;
}
*/

//按值查找指定数据并返回指针 
Lnode*LocateElem_L(LinkList L,student e){
	LinkList p=L->next;
	while(p!=0&&p->data.num!=e.num)
		p=p->next;
	return p;
}

int main(){
	
	return 0;
}
