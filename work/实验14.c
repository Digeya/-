//ʵ��14.c 
//by midi

#include "stdlib.h"
#include "stdio.h"
#define vertexnum 9   //���嶥����
struct node{    //ͼ����ṹ�����ڽӱ�洢
	int vertex; //�ڽӶ�������
	struct node *next; //��һ���ڽӶ���
};
typedef struct node *graph; //����ͼ�ṹ
struct node head[vertexnum]; 
int visited[vertexnum]; //���ڱ�ǽ���Ƿ��ѷ���

// ----���нṹ 
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
// ----���нṹ ----end 

void bfs(int vertex) {
	graph pointer;
	
	int tem;
	visited[vertex]=1;
	printf(" [%d]==>",vertex);
    LinkQueue q;
    initQueue(&q);//��ʼ������
    InsertQueue(&q,vertex);
    while(!isEmpty(&q)) {
    	DeleteQueue(&q,&tem);
    	pointer=head[tem].next;
    	while(pointer) {
    		if(!visited[pointer->vertex]) {
    			visited[pointer->vertex] = 1;
    			printf(" [%d]==>",pointer->vertex);
    			InsertQueue(&q,pointer->vertex);
			}
			pointer=pointer->next; //��һ���ڽӵ�
		}
	}
}

void dfs(int vertex){ //�������������
	graph pointer;
	visited[vertex]=1; //��Ǵ˽���ѷ���
	printf(" [%d]==>",vertex);
	pointer=head[vertex].next;
	while(pointer!=NULL){
		if(visited[pointer->vertex]==0)
			dfs(pointer->vertex); //�ݹ����
		pointer=pointer->next; //��һ���ڽӵ�
	}
}
void create_graph(int vertex1,int vertex2){//�����ڽӶ��㵽�ڽӱ���
	graph pointer,new_p;
	new_p=(graph)malloc(sizeof(struct node));//�����ڴ�
	if(new_p!=NULL){//�ɹ�
		new_p->vertex=vertex2; //�ڽ��ӵ�
		new_p->next=NULL;
		pointer=&(head[vertex1]); //��Ϊ��������֮�׽��
		while(pointer->next!=NULL)
			pointer=pointer->next; //��һ�����
		pointer->next=new_p; //������β
	}
}
void print_graph(struct node *head){ //������ڽӱ�����
	graph pointer;
	pointer=head->next; //ָ��ָ���׽��
	while(pointer!=NULL){
		printf("[%d]",pointer->vertex);
		pointer=pointer->next; //���½��
	}
	printf("\n");
}
void main(){ //������
	int i;
	int vertex;	
	int node[20][2]={	{1,2},{2,1},{1,3},{3,1},
						{2,4},{4,2},{2,5},{5,2},
						{3,6},{6,3},{3,7},{7,3},
						{4,8},{8,4},{5,8},{8,5},
						{6,8},{8,6},{7,8},{8,7}		};
	//ͼG3�����н����ڽӵ���ڽӱ�
	for (i=0;i<vertexnum;i++){ 
		head[i].vertex=i;
		head[i].next=NULL;
	} 
	for (i=0;i<vertexnum;i++)   //�������н���δ����
		visited[i]=0;
	for (i=0;i<20;i++)
		create_graph(node[i][0],node[i][1]);//�����ڽӱ�
	printf("graph\n");
	for (i=1;i<vertexnum;i++){
		printf("vertex[%d]: ",i);
		print_graph(&head[i]);
	}
	printf("\nPlease enter the start node:");
	scanf("%d",&vertex);
	printf("\nthe depth of the graph is (starting from node %d):\n",vertex);
	printf(" [��ʼ]==>");
//	dfs(vertex);  //���ȴӽ��1��ʼ
	bfs(vertex);
	printf(" [����] \n\n");
}
