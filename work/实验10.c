//ʵ��10.c 
//by midi

#include<stdio.h>
#include<stdlib.h>
#define MAXVEX 16   



typedef char VexType;                     /*�������������*/
typedef int AdjType;            /*�ڽӾ��������Ԫ�ص�����*/
typedef struct
{
	VexType vexs[MAXVEX];				//����
	AdjType arcs[MAXVEX][MAXVEX];		//�ڽӾ���
	int n;								//��¼��ǰͼ�Ķ�����
}GraphMatrix;



typedef struct treedata {
      char beg,en;   	/* beg,en�ǽ����� */
      int length;     	/* �߳� */
}edge;


GraphMatrix* CreateGraph(void)			//���������Ȩͼ
{
	int i,j,k,e,m;
	GraphMatrix *ga;
	ga=(GraphMatrix *)malloc(sizeof(GraphMatrix));
	printf("�����붥��ĸ���(������%d):",MAXVEX);
	scanf("%d",&(ga->n));
	getchar();

	printf("��˳���������������Ϣ(��ż���,��һ���ַ���ʾ):\n");
	for(i=0; i<ga->n; i++)
		ga->vexs[i]=getchar();     /*���붥����Ϣ�����������*/
	getchar();
	for(i=0; i<ga->n; i++)
		for(j=0; j<ga->n; j++){
			if(i==j) {
				ga->arcs[i][j]=0;
			} else {
				ga->arcs[i][j]=999;
			}
		}
			                /*�ڽӾ����ʼ��*/
	printf("������ߵĸ���:");
	scanf("%d",&e);

	printf("����������������������������:\n");
	for(k=0;k<e;k++)
	{
		scanf("%d%d%d",&i,&j,&m);                         /*������Լ�Ȩֵ*/
		ga->arcs[i][j]=m;
		ga->arcs[j][i]=m;
	}
	getchar();
	return ga;
}


void PrintGraph(GraphMatrix *ga)
{
	int i,j;
	printf("\n�����Ϊ:\n");
	for(i=0; i<ga->n; i++)
		printf("%4c",ga->vexs[i]);
	printf("\n�ڽӾ���Ϊ:\n");
	for(i=0; i<ga->n; i++)
	{
		for(j=0; j<ga->n; j++)
			printf("%4d",ga->arcs[i][j]);
		printf("\n");
	}
}

//�Ƿ����е㶼��ѡ�� ���ж���ѡ�� ���� 0 
int isall(int flag[],int n) {
	int i;
	for(i=0;i<n;i++) {
		if(flag[i]==0) {
			break;
		}
	}
	if(i>=n) {
		return 0;
	} else {
		return 1;
	}
}
 


void avoid_cycle(GraphMatrix *ga,VexType ch) {
	
	printf("��ʼ�ĵ�Ϊ:%c\n",ch);
	int i,start_index;
	int flag[MAXVEX];
	for(i=0;i<ga->n;i++) {
		flag[i]=0;
		if(ga->vexs[i] ==ch) {
			start_index = i;
		}
	}
	flag[start_index] = 1;
	//��һ����ʼ�ĵ�
	int j;
	
	int temp_x,temp_y;
	while(isall(flag,ga->n)) {
		int min_temp=100000;
		for(i=0;i<ga->n;i++) {
			if(flag[i]==1) {
				for(j=0;j<ga->n;j++) {
					if((ga->arcs[i][j] != 0) &&(ga->arcs[i][j]< min_temp) &&(flag[j]==0)) {
						min_temp = ga->arcs[i][j];
						temp_x = i;
						temp_y = j;
					}
				}
			}
		}
		printf("%c��%c\n",ga->vexs[temp_x],ga->vexs[temp_y]);
		
		flag[temp_y] = 1;
//		break;
		//�õ㱻ѡ�� 
		
	} 
} 



void prim(GraphMatrix *ga) {
	edge tree[MAXVEX];
	int v;
	int k,min,s,j,d;
	edge x;
	
	for (v=1;v<=ga->n-1;v++){
		
	    tree[v-1].beg = 0;
		tree[v-1].en = v;
	    tree[v-1].length = ga->arcs[0][v];
	}
	

	for (k=0; k< ga->n-2; k++) {
		
    	min = tree[k].length;
    	s = k;
    	for (j=k+1;j<=ga->n-2;j++) {    /* ����С���ܱ�����λ�� */
      		if(tree[j].length<min) {
      			min = tree[j].length;
      			s = j;
			}
		}
		v = tree[s].en;
		
		x = tree[s];
		tree[s] = tree[k];
		tree[k] = x;
		
		
		for (j=k+1;j<=ga->n-2;j++) { 
		     d = ga->arcs[v][tree[j].en];
		     if (d<tree[j].length) { 
		        tree[j].length = d;
		        tree[j].beg = v;
		     }
		}
	}
	
	int i;
	for(i=0;i<ga->n-1;i++) {
//		printf("%c",ga->vexs[i]);
//		printf("%d, %d, %d\n",tree[i].beg,tree[i].en,tree[i].length);
		printf("%c��%c\n",ga->vexs[tree[i].beg],ga->vexs[tree[i].en]);
	}
	


}


int main() {
	
	
	GraphMatrix *graph;
	graph = CreateGraph();
	PrintGraph(graph);
	while(1) {

	
	
	printf("---------------------\n");
	printf("---------------------\n");
	printf("1.prim\n");
	printf("2.̰�ķ���\n");
	printf("3.�˳�\n"); 
	printf("---------------------\n");
	printf("---------------------\n");
	printf("������Ҫʹ�õķ���:\n");
	int nums;
	scanf("%d",&nums);
	switch(nums) {
		case 1:
			prim(graph);break;

		case 2:
			getchar();
			printf("������Ҫ��ʼ�ĵ�:\n");
			char start;
			scanf("%c",&start);	
			avoid_cycle(graph,start);
			break;
		case 3:
			printf("\n886\n");exit(0); 
			
		default:printf("������������\n");
	}


	
	}
	
	
	/**
����������
 
�����붥��ĸ���(������16):6
��˳���������������Ϣ(��ż���,��һ���ַ���ʾ):
012345
������ߵĸ���:8
����������������������������:
0 1 1
0 2 5
0 3 2
1 4 7
1 2 3
2 5 6
3 5 8
4 5 4
	
	**/
	
	return 0;
}
