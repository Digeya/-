//ʵ��3.c 
//by midi

#include<stdio.h>
#include<stdlib.h>

#define TIMES 1000
// Ѱ�Ҵ��� 

#define NUMS 10
// ������

 
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
	
//	ͷ�巨 ѭ��������  
    for(i=0;i<NUMS;i++)
    {
        p=(LinkList)malloc(sizeof(LNode));
        tem->next = p;
        tem = p;
        
//        (*head)->data++;   //������ 
    }

	tem->next = *head;

}


void initlist(LinkList head)
{
    LinkList p;
    p=head->next;
    
    do {
    	p->data=1;
    	p=p->next;
	}while(p!=head);

    
}

void findrabbit(LinkList head)
{
    LinkList p;
    int i,j=1,q,n,u;
    p=head->next;
    //��������
    for(i=0;i<TIMES;i++)
    {
        u=((1.0/2)*j*(j+1));  //ÿ�ε�u������ 

        u=u%NUMS;
//        printf("%d ",u);
        p=head->next;
        
        if(u==0) {
        	for(q=0;q<NUMS-1;q++) { //�������  ���� ��ʱ��ʮ�������ǵ�һ���� ���� һ����ʮ������ 
            	p=p->next;
        		}
        		p->data=0;
        		j++;
		}else {
			
			
			
			
			for(q=1;q<u;q++) { //ȷ��ʮ����ѭ����,j�������ɽ����
            	p=p->next;
        		}
        	p->data=0;
        	j++;
	
			}

    }
}


void outputlist(LinkList head)
{
    LinkList p;
    p=head->next;
    int count=1; 

	do {
		

	   	if(p->data == 1) {
	   		
			printf("�ö�����: %d �Ŷ��� \n",count);
			p=p->next;
			count++;
			
			}
		else {
				p=p->next;
				count++;
			}
   	
   }while(p!=head);
//   printf("total:%d", (*head).data);
}

int main()
{
    LinkList head;     //head ͷָ�� 
    createlist(&head);
    initlist(head);
    findrabbit(head);
    
    printf("\n"); 
    outputlist(head);
    return 0;
}
