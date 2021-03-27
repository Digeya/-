//ʵ��11.c 
//by midi

#include<stdio.h>
#include<stdlib.h>


#define M 100
#define true 1
#define false 0

// bfs + D ���� 
// -------------------------------------------
// BFS���õ��Ķ��� 
typedef int Elemtype;
typedef struct QNode{
    Elemtype data;
    struct QNode *next;
}QNode, *QueuePrt;

typedef struct {
    QueuePrt front, rear;
}LinkQueue;
//��ʼ��
void initQueue(LinkQueue *q){
    q->front = q->rear = (QueuePrt)malloc(sizeof(QNode));
    if(!q->front)
        exit(0);
    q->front->next = NULL;
}
//����һ���ڵ�
void InsertQueue(LinkQueue *q, Elemtype e){
    QueuePrt p;
    p = (QueuePrt)malloc(sizeof(QNode));
    if(p == NULL)
        exit(0);
    p->data = e;
    p->next = NULL;
    
    //���ȥ
    q->rear->next = p;
    q->rear = p;
}
//������
void DeleteQueue(LinkQueue *q, Elemtype *e){
    QueuePrt p;
    if( q->front == q->rear ){
        return;
    }
    
    p = q->front->next;
    *e = p->data;
    
    q->front->next = p->next;
    if(q->rear == p)
        q->rear = q->front;
    free(p);
}
//����һ������
void DestroyQueue(LinkQueue *q){
    while (q->front) {
        q->rear = q->front->next;
        free(q->front);
        q->front = q->rear;
    }
}
//�����Ƿ�Ϊ��
int isEmpty(LinkQueue* a)
{
    if(a->front == a->rear)
        return 1;
    return 0;
}

// ------------------------------------------- 


typedef char Element;
typedef int BOOL;
//�ڽӱ�Ľڵ�
typedef struct Node{
    int adj_vex_index;  //��ͷ���±꣬Ҳ���Ǳ�ָ����±�
    Element data;       //Ȩ��ֵ
    struct Node * next; //��ָ��
}EdgeNode;

//����ڵ��
typedef struct vNode{
    Element date;          //�����Ȩֵ
    EdgeNode * firstedge;  //������һ����˭��
}VertexNode, Adjlist[M];

//��ͼ��һЩ��Ϣ
typedef struct Graph{
    Adjlist adjlist;       //�����
    int arc_num;           //�ߵĸ���
    int node_num;          //�ڵ����
    BOOL is_directed;      //�ǲ�������ͼ
}Graph, *GraphLink;

void creatGraph(GraphLink *g){
    int i, j, k;
    EdgeNode *p;
    EdgeNode *tem;
    printf("���붥����Ŀ,�������Ƿ����򣿣�\n");
    scanf("%d %d %d", &(*g)->node_num, &(*g)->arc_num, &(*g)->is_directed);
    
    printf("���붥����Ϣ��\n");
    for (i = 0; i < (*g)->node_num; i++) {
        getchar();
        scanf("%c", &(*g)->adjlist[i].date);
        (*g)->adjlist[i].firstedge = NULL;
    }
    printf("�������Ϣ��\n");

    for (k = 0; k < (*g)->arc_num; k++){

        getchar();
        scanf("%d %d", &i, &j);
        
        //�½�һ���ڵ��Ǳ����
        p = (EdgeNode *)malloc(sizeof(EdgeNode));
        //��ͷ���±�
        p->adj_vex_index = j;
        
        p->next = NULL;
        
        // β�巨 ���ҵ����һ�����
        tem = (*g)->adjlist[i].firstedge;
        if((*g)->adjlist[i].firstedge == NULL) {
        	(*g)->adjlist[i].firstedge = p;
		} else {
			
			while(tem->next!=NULL) {
				tem = tem->next;
			}
			tem->next = p;
		}
		

        //����ͼ 
        if(!(*g)->is_directed)
        {
            // j -----> i
            p = (EdgeNode *)malloc(sizeof(EdgeNode));
            p->adj_vex_index = i;
            p->next = (*g)->adjlist[j].firstedge;
            (*g)->adjlist[j].firstedge = p;
        }
    }
}


//����ڽӱ� 
void putGragh(GraphLink g){
    int i;
    printf("------------�ڽӱ�----------------\n"); 
    for (i = 0; i < g->node_num; i++) {
        EdgeNode * p = g->adjlist[i].firstedge;
        while (p) {
            printf("%c->%c ", g->adjlist[i].date, g->adjlist[p->adj_vex_index].date);
            p = p->next;
        }
        printf("\n");
    }
	printf("---------------------------------\n"); 
}


// BFS����������� 
int visited[M];
void BFSTraverse(Graph *g)
{
    int i;
    int tmp;
    EdgeNode *p;
    //��ʼ������
    LinkQueue q;
    initQueue(&q);
    
    for (i = 0; i < g->node_num; i++) {
        if(!visited[i]){
            visited[i] = true;
            printf("%c ",g->adjlist[i].date);
            
            //���в����һ���ڵ�
            InsertQueue(&q, i);
            //���в��ǿյ�ʱ��ʹӶ����������
            while (!isEmpty(&q)) {
                //�Ӷ���ȡһ���͵ðѺ������ŵĵ㶼���ȥ
                DeleteQueue(&q, &tmp);
                //��Ӻ������ŵ�����δ�����ĵ�
                p = g->adjlist[tmp].firstedge;
                while (p) {
                    if (!visited[p->adj_vex_index]) {
                        visited[p->adj_vex_index] = true;
                        printf("%c ",g->adjlist[p->adj_vex_index].date);
                        InsertQueue(&q, p->adj_vex_index);
                    }
                    p = p->next;
                }
            }
        }
    }

}


void D_Traverse(Graph *g) {
	int i;
    int tmp;
    EdgeNode *p;
    //��ʼ��stack
	int stack[M];
	int stackPoint = -1;
    
    
    for (i = 0; i < g->node_num; i++) {
        if(!visited[i]){
            visited[i] = true;
            printf("%c ",g->adjlist[i].date);
            
            //ջ�в����һ���ڵ�
            stack[++stackPoint] = i;
            //ջ�в��ǿյ�ʱ��ʹ�stack�������
            while (stackPoint != -1) {
                //��ջ��ȡһ�����������ӽ�����μӵ�ջ��(û���ʹ���) 
  
                tmp = stack[stackPoint--];
//                printf("\n:��ǰ��ջ����:%d\n",tmp);

                p = g->adjlist[tmp].firstedge;
                while (p) {
                    if (!visited[p->adj_vex_index]) {
                        visited[p->adj_vex_index] = true;
                        printf("%c ",g->adjlist[p->adj_vex_index].date);
                        stack[++stackPoint] = p->adj_vex_index;
//                        printf("\n��ǰ��ջ����:%d\n",p->adj_vex_index);
                    }
                    p = p->next;
                }
            }
        }
    }
}

int main() {
	
	int id;
	
	GraphLink g = (Graph *)malloc(sizeof(Graph));
	creatGraph(&g);
	putGragh(g);

	while(1) {
		

		printf("---------------------------------\n");
		printf("---------------------------------\n");
		printf("1.BFS\n");
		printf("2.D-����\n");
		printf("3.�˳�\n"); 
		printf("---------------------------------\n");
		printf("---------------------------------\n");
		printf("������������ʽ:\n");
		scanf("%d",&id);
		int i;
		for(i=0;i<M;i++) {
			visited[i]=false;
		} 
		switch(id) {
			case 1:printf("BFS�������Ϊ:\n");BFSTraverse(g);printf("\n");break;
			case 2:printf("D-�������Ϊ:\n");D_Traverse(g);printf("\n");break;
			case 3:printf("\n886\n");exit(0);
			default:printf("������������\n");
		}	
	}
	return 0;
} 

/*
ʵ����������ʾ��:
 ���붥����Ŀ,�������Ƿ����򣿣�
7 11 0
���붥����Ϣ��
1 2 3 4 5 6 7
�������Ϣ��
0 1
0 2
0 3
1 4
2 4
2 5
3 5
3 6
4 5
4 6
5 6
*/ 
