//ʵ��2.c 
//by midi

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//��ͷ����

typedef struct pNode{
	int coef; //ϵ��
	int exp;//ָ��
	struct pNode* link;
}pNode;


typedef struct{
	int n;
	struct pNode *head;
} poly;


void Create(poly *p) {//���ɱ�ͷ���
	pNode *pn,*pre,*q;
	p->head=(pNode*)malloc(sizeof(pNode));
	p->head->exp=-1;
	p->head->link=NULL;
	
	
	p->n=0;
	while(1) {
		pn=(pNode*)malloc(sizeof(pNode));
		
		printf("coef:\n");
		scanf("%d",&pn->coef); //�������ϵ��
		
		printf("exp:\n");
		scanf("%d",&pn->exp); //�������ָ��
		
		if (pn->exp<0) break; //��������ָ���������������
		
		pre=p->head;
		q=p->head->link;
		
		while(q&&q->exp < pn->exp) {   //��������
			pre=q;
			q=q->link;
		}
		pn->link=q;
		pre->link=pn;
		p->n++;
	}
}


//��ʦ�ṩ�Ĵ�����ͷ�ڵ� �ο����޸��˲��� 
void Add(poly *px,poly *qx)  {
	pNode *q,*q1=qx->head,*p,*temp;  //q1ָ���ͷ���
	pNode *u,*pre;
	p=px->head->link;  //pָ�����ʽpx�ĵ�һ�����
	q=q1->link;  //q1��q��ǰ��
	
	pre = p;
	int x;

	while(( p != NULL ) && ( q != NULL )) {
		if(p->exp < q->exp) {
			pre = p;  p = p->link;
		}else if(p->exp == q->exp) {
			x = p->coef + q->coef;
			if(x!=0) {
				
				p->coef = x;
				pre = p;
			}else {
				pre->link = p->link;
                free(p);
			}
			p = pre->link;
            u=q;
            q=q->link;
            free(u);

		}else {
			u=q->link;
            q->link=p;
            pre->link=q;
            pre=q;
			q=u;
		}
	}
	if ( q!= NULL){
		pre->link=q;
	}

	
}
	
 
// һԪ����ʽ��ʽ��� 
int print_poly(poly list1){
	int i=0;
	pNode *pn;
	if(!list1.head)
		return 0;
	pn=list1.head;
	for(i=0; i<list1.n; i++){
		pn=pn->link;
		if(i != list1.n-1) {
			printf("%d*x^%d+",pn->coef,pn->exp);
		}else {
			printf("%d*x^%d",pn->coef,pn->exp);
		}

	}
	return 1;
}


//����ʽ��Ӻ��������    ����ӵĽ�������� px�ϣ� 
void output(poly *p) {
	pNode *q;
	if(!p->head->link) //�ж϶���ʽ�Ƿ�Ϊ�� ��׳��  ͷ�ڵ�ô� 
		return ;
	q=p->head->link; //���������һ��
	printf("%d*x^%d",q->coef,q->exp);
	q=q->link;
	while(q){
		if(q->exp==0) //�Գ��������� 
			if(q->coef>0) //����ϵ��>0�����
				printf("+%d",q->coef);
			else printf("%d",q->coef); //����ϵ��<0�����
		else if(q->coef>0) //�ǳ�������ϵ��>0���
			printf("+%d*x^%d",q->coef,q->exp);
		else //�ǳ�����ϵ��<0�����
			printf("%d*x^%d",q->coef,q->exp);
		q=q->link;
	}
}


int main(){
	poly list1;
	poly list2;
	
	
	printf("\n��һ��һԪ����ʽΪ:(ָ��Ϊ����ʱ ֹͣ����):\n");	
	Create (&list1);	
	

	print_poly(list1);
	printf("\n");
	
	printf("\n�ڶ���һԪ����ʽΪ:(ָ��Ϊ����ʱ ֹͣ����):\n");
	Create (&list2);
	
	print_poly(list2);
	printf("\n");
	
	Add(&list1,&list2);	
	printf("\nһԪ����ʽ��ӵĽ��Ϊ:\n");
	output(&list1);
//	
}
