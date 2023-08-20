#include<stdio.h>
#include<stdlib.h>
#define OK 1
#define ERROR 0
#define OVERFlOW -2
#define LIST_INIT_SIZE 10
typedef int Status;
typedef int ElemType;

//����
//�������������� 
typedef struct student{
	char num[8]; 
	char name[8]; 
	int score; 
}student;//�������ݿ⣺ѧ�ţ��������ɼ� 
//������ 
typedef struct Lnode{
	student data;//������ 
	struct Lnode *next;//ָ���� 
}Lnode,*LinkList; 
 
 
//������ĳ�ʼ��
Status InitList_L(LinkList &L){
	L = new Lnode;//�� L = (LinkList) malloc (sizeof(Lnode)); 
	L->next=NULL;
	return OK;
}

//�ж������Ƿ�Ϊ��
Status ListEmpty(LinkList L){
	if(L->next)
		return 0;
	else
		return 1;
}

//���ٵ�����L
Status DestoryList_L(LinkList &L){
	Lnode *p;
	while(L){
		p = L;
		L = L->next;
		delete p;
	}
}

//��յ�����
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

//������ĳ��Ȳ����� 
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

//���������ҵ���i��Ԫ�أ��������ݸ�ֵ��e
/*
Status GetElem_L(LinkList L,int i,student &e){
	LinkList p = L->next;
	int j=1;
	while(p&&j<i){
		p = p->next;
		++j;
	}
	if(!p||j>i)
	return ERROR;//��i��Ԫ�ز����� 
	student e = p->data;
	return OK;
}
*/

//��ֵ����ָ�����ݲ�����ָ�� 
Lnode*LocateElem_L(LinkList L,student e){
	LinkList p=L->next;
	while(p!=0&&p->data.num!=e.num)
		p=p->next;
	return p;
}

int main(){
	
	return 0;
}
