//ʵ��13.c 
//by midi

#include<stdio.h>
#include<stdlib.h>

typedef int Elemtype;

typedef struct LNode {
    Elemtype data;
    struct LNode *next;
}LNode,*LinkList;


void createlist(LinkList *head)
{
    int i;
    *head=(LinkList)malloc(sizeof(LNode));
    
    (*head)->data = 0;
    LinkList p,tem;
    tem = *head;
	int value,length;
	printf("�����������ĳ���:\n");
	scanf("%d",&length);
	
//	ͷ�巨 ѭ��������  
    for(i=0;i<length;i++)
    {
        p=(LinkList)malloc(sizeof(LNode));
        printf("������������%d��ֵ:",i+1);
        
        scanf("%d",&value);
        p->data = value;
        tem->next = p;
        tem = p;
        
//        (*head)->data++;   //������ 
    }

//	tem->next = *head;
	tem->next = NULL;
	printf("�����������!\n");

}

void print(LinkList head)
{
    LinkList p;
    p=head->next;
    
    do {
		printf("%d ",p->data);
		p = p->next;
	}while(p!=NULL);

    
}



void AandBtoC(LinkList Ahead,LinkList Bhead,LinkList *Chead) {
	LinkList Ap,Bp;
	Ap=Ahead->next;
	Bp=Bhead->next;
	
	// Cͷ���  ������Ҫ���ռ�� 
	*Chead=(LinkList)malloc(sizeof(LNode));
	(*Chead)->data = 0;
	
	LinkList tem;
	tem = *Chead;

	
	
	printf("\n");
	do {
		
		if(Ap->data < Bp->data) {
			
//			printf("%d ",Ap->data);
			tem->next = Ap;
			tem = Ap;
			Ap = Ap->next;
		} else if(Ap->data > Bp->data) {
			
//			printf("%d ", Bp->data);
			tem->next = Bp;
			tem = Bp;
			Bp = Bp->next;
		} else {
			Bp = Bp->next;  //������ ����B�� ���Ԫ�� 
		}
			
	}while(Ap!=NULL&&Bp!=NULL);
	
	if(Ap!=NULL) {
		
		do{
//			printf("%d ",Ap->data);
			tem->next = Ap;
			tem = Ap;
			Ap = Ap->next;
		}while(Ap!=NULL);
	}
	
	if(Bp!=NULL) {
		do{
//			printf("%d ",Bp->data);
			tem->next = Bp;
			tem = Bp;
			Bp = Bp->next;
		}while(Bp!=NULL);
	}
	
	tem = NULL;
	
//	LinkList p;
//	p = *Chead;
//    do {
//		printf("%d ",p->data);
//		p = p->next;
//	}while(p!=NULL);
	
}



int main() {
	
	
	LinkList Ahead,Bhead;     //head ͷָ�� 
	printf("����A����:\n");
	createlist(&Ahead);
	printf("A����Ϊ:\n");
	print(Ahead);
	printf("\n����B����:\n");
	createlist(&Bhead);
	printf("B����Ϊ:\n");
	print(Bhead);
	printf("\n");
	
	LinkList Chead;
	AandBtoC(Ahead,Bhead,&Chead);
	printf("�ϲ����C����Ϊ:\n");
	print(Chead);

	//�����AB Ĭ���Ѿ������ 
	
	
	return 0;
}
