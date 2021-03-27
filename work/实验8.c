//ʵ��8.c 
//by midi

#include "stdio.h"
#include "stdlib.h"
#include<stdlib.h>
#define MAX 20
#define Null 0

typedef  char TElemType;
typedef  int Status;
typedef struct BiTNode {
	TElemType data;
	struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;



Status CreateBiTree(BiTree *T) {
	char ch;
	ch=getchar();
	if (ch=='#') //#�����ָ��
	(*T)=Null; else {
		(*T)=(BiTree) malloc(sizeof(BiTNode));
		//������
		(*T)->data=ch;
		//���ɸ���� 
		CreateBiTree(&(*T)->lchild);
		//����������
		CreateBiTree(&(*T)->rchild) ;
		//����������
	}
	return 1;
}

// �ݹ� ������� 
void PreOrder(BiTree T) {
	if (T) {
		printf("%2c",T->data);
		//���ʸ���㣬�˴���Ϊ�������������ֵ
		PreOrder(T->lchild);
		//�������������
		PreOrder(T->rchild);
		//�������������
	}
}

void Norec_PreOrder(BiTree T) {
	if (T) {
		BiTree stack[10];
		int stackTop = -1;
		BiTree t = T;
		while(stackTop != -1 || t) {
			while(t) {
				printf(" %c", t->data);
				stack[++stackTop] = t;
				t = t->lchild;
			}
			if(stackTop != -1) {
				t = stack[stackTop--];
				t = t->rchild;
			}
		} 
	}
}



// �ݹ� ������� 
void MiddleOrder(BiTree T) {
	if (T) {

		MiddleOrder(T->lchild);
		//�������������
		printf("%2c",T->data);
		//���ʸ���㣬�˴���Ϊ�������������ֵ
		MiddleOrder(T->rchild);
		//�������������
	}
}

void Norec_MiddleOrder(BiTree T) {
	
	if (T) {
		BiTree stack[10];
		int stackTop = -1;
		BiTree t = T;
		while(stackTop != -1 || t) {
			while(t) {
				
				stack[++stackTop] = t;
				t = t->lchild;
			}
			if(stackTop != -1) {
				t = stack[stackTop--];
				printf(" %c", t->data);
				t = t->rchild;
			}
		} 
	}
}

void PostOrder(BiTree T) {
	if (T) {
		PostOrder(T->rchild);
		//�������������

		PostOrder(T->lchild);
		//�������������

		
		printf("%2c",T->data);
		//���ʸ���㣬�˴���Ϊ�������������ֵ
	}

} 

void Norec_PostOrder(BiTree T) {

	if (T) {
		BiTree stack[10];
		int stackTop = -1;
		BiTree t = T;
		BiTree temp;
		while(stackTop != -1 || t) {
			while(t) {
				
				stack[++stackTop] = t;
				t = t->lchild;
			}
			t = stack[stackTop];
			if(t->rchild == NULL || t->rchild == temp) {
				printf(" %c", t->data);
				stackTop--;
				temp = t;
				t = NULL;
			} else {
				t = t->rchild;
			} 
		} 
	}
} 



void LevleOrder(BiTree T) {
	//��α���������T���ӵ�һ�㿪ʼ��ÿ�������
	BiTree Queue[MAX],b;
	//��һά�����ʾ����
	int front,rear;
	// front��rear�ֱ��ʾ���׺Ͷ�βָ��
	front=rear=0;
	if(T) {
		//�����ǿ�
		Queue[rear++]=T;
		//����������
		while (front!=rear) {
			//�����зǿ�
			b=Queue[front++];
			//����Ԫ�س����У�������������
			printf("%2c",b->data);
			if (b->lchild!=Null) 		//�������ǿգ��������
			Queue[rear++]=b->lchild;
			if (b->rchild!=Null)		 //�������ǿգ��������
			Queue[rear++]=b->rchild;
		}
	}
}
//LevelOrder


int depth(BiTree T) {
	//������������
	int dep1,dep2;
	if (T==Null) 
		return 0; else {
		dep1=depth(T->lchild);
		dep2=depth(T->rchild);
		return dep1>dep2?dep1+1:dep2+1;
	}
}
//depth



void main() {
	printf("-----------------------------\n");
	BiTree T=Null;
	printf("\n������һ�Ŷ�����~��\n");
	CreateBiTree(&T);
	printf("\nһ�Ŷ������������~��\n");
	while(1) {
		printf("\n-----------------------------\n");
		int num;
		printf("���������1-8:\n");
		printf("1. ����ǵݹ����\n");
		printf("2. ����ݹ����\n");
		printf("3. ����ǵݹ����\n");
		printf("4. ����ݹ����\n");
		printf("5. ����ݹ����\n");
		printf("6. ��α���\n");
		printf("7. �������\n");
		printf("8. �˳�\n");
		printf("\n-----------------------------\n");
		scanf("%d",&num);
		
		switch(num) {
			case 1:Norec_PreOrder(T);printf("\n");break; 
			case 2:PreOrder(T);printf("\n");break;
//			//����һ�ö�����T
//			printf("\n��������Ľ��Ϊ:\n");
//			PreOrder(T);
//			printf("\n");
//			Norec_PreOrder(T);
//			//�������������
			
			case 3:Norec_MiddleOrder(T);printf("\n");break;
			case 4:MiddleOrder(T);printf("\n");break; 
		
//			printf("\n��������Ľ��Ϊ:\n");
//			MiddleOrder(T);
//			printf("\n");
//			Norec_MiddleOrder(T);
			
			case 5:PostOrder(T);printf("\n");break; 
			//�����ǵݹ�������ˡ������� 
//			printf("\n��������Ľ��Ϊ:\n");
//			PostOrder(T);
//			printf("\n");
//			Norec_PostOrder(T);
			case 6:LevleOrder(T);printf("\n");break; 
			case 7:printf("\nThe depth is:%d\n",depth(T));printf("\n");break; 
			case 8:printf("\n886\n");exit(0); 

	
	}
}
} 
