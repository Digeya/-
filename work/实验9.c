//ʵ��9.c 
//by midi

#include<stdio.h>
#include<stdlib.h>
#define Maxsize 10
typedef struct{     	//������Ԫ���
	int i,j;
	int v;
}TriTupleNode;
typedef struct{  		//������Ԫ���
	TriTupleNode data[Maxsize];
	int m;
	int n;
	int t;	 			//�����У��м���Ԫ�����
}TriTupleTable;

// ��Ԫ��Ľṹ��ʵ��7����һ��  �����ԭ���1��ʼ��¼����  0��������¼ ���� ���� ����Ч���� 
int flag;


void easy_way() {
	
	int m,n;
	printf("���������� ����:3 3\n");
	scanf("%d %d",&m,&n);
	int arr[m][n];
	int b[n];
	int i,j,k;
	//���� 
	printf("������%d����:\n",m*n);
	for(i=0;i<m;i++) {
		
		for(j=0;j<n;j++) {
			scanf("%d",&arr[i][j]);
		}
	}
	
	
		//��� 
	printf("\n-----------------------\n");
	printf("\n����Ķ�ά����Ϊ:\n");
	for(i=0;i<m;i++) {
		
		for(j=0;j<n;j++) {
			printf("%d ",arr[i][j]);
		}
		printf("\n");
	}
	printf("\n-----------------------\n");
	int s,count=0;
	// 
	int min,max;
	for(j=0;j<m;j++) {
		
		min = arr[j][0];
		for(i=0;i<n;i++) {
			if(arr[j][i] < min) {
				min = arr[j][i];
			}
		}
		//�ҳ�������Сֵ 
		
		s=0;
		for(i=0;i<n;i++) {
			if(arr[j][i] == min) {
				b[s] =i;
				s++;
			}
		}
		//�ҳ������м�����Сֵ
//		printf("min��%d\n",min);
		
		max = min;
		for(i=0;i<s;i++) {
			for(k=0;k<m;k++) {
				if(max < arr[k][b[i]]) {
					break;
				}
				if(k==m-1) { 
					printf("\n����[%d][%d]Ϊ����ֵΪ: %d\n",j,b[i],arr[j][b[i]]);
					count++;
				}
			}
		}

	}
	
	if(count == 0) {
		printf("��\n");
	}
	
}



// sort 
//��ֹ�û���������
void Tuplesort(TriTupleTable *a){
	int z,x,temp1,temp2,temp3;
	for(z=0;z<a->t;z++)
		for(x=1;x<a->t-z;x++)
		{	if(a->data[x].i==a->data[x+1].i){
				if(a->data[x].j>a->data[x+1].j){
				temp1=a->data[x].i;
				temp2=a->data[x].j;
				temp3=a->data[x].v;
				a->data[x].i=a->data[x+1].i;
				a->data[x].j=a->data[x+1].j;
				a->data[x].v=a->data[x+1].v;
				a->data[x+1].i=temp1;
				a->data[x+1].j=temp2;
				a->data[x+1].v=temp3;
				}
			}
			if(a->data[x].i>a->data[x+1].i){
				temp1=a->data[x].i;
				temp2=a->data[x].j;
				temp3=a->data[x].v;
				a->data[x].i=a->data[x+1].i;
				a->data[x].j=a->data[x+1].j;
				a->data[x].v=a->data[x+1].v;
				a->data[x+1].i=temp1;
				a->data[x+1].j=temp2;
				a->data[x+1].v=temp3;
				}
		}			
}



// ��ʼ�� �ٶȵ����뷽ʽ����׳�ԽϺã� 
void InitTriTupleNode (TriTupleTable *a){
	int i,j,k,val;
	i=j=0;
	k=1;
	printf("����������������: ");
		scanf("%d",&a->data[0].i);
		printf("����������������: ");
		scanf("%d",&a->data[0].j);		
		printf("�����������Ч���ֵĸ���: ");
		scanf("%d",&a->data[0].v);
		a->m =a->data[0].i;
		a->n =a->data[0].j;
		a->t =a->data[0].v;
	while(k<=a->t&&i!=-1&&j!=-1){   		//rol=-1||col=-1��������
Q:		printf("�������Ԫ�ص���: ");
		scanf("%d",&i);
		if(i>a->m){
			printf("�����������������!\n");
			goto Q; //��׳�� 
		} 
		else if(i==-1) 
			break;
W:		printf("�������Ԫ�ص���: ");
		scanf("%d",&j);		
		if(j>a->n){
			printf("�����������������!\n");
			goto W; //��׳�� 
		} 
		else if(i==-1) 
			break;
		printf("�������Ԫ�ص�ֵ: ");
		scanf("%d",&val);
		a->data[k].i=i;
		a->data[k].j=j;
		a->data[k].v=val;
		k++;
	}
	Tuplesort(a);  //��ֹ�û���������
} 


void showMatrix(TriTupleTable *a){   	//���ϡ�����
	int p,q;
	int t=1;
	for(p=1;p<=a->m;p++){
		for(q=1;q<=a->n;q++){ 
			if(a->data[t].i==p&&a->data[t].j==q){
				printf("%d\t",a->data[t].v);
				t++;
			}
			else 
				printf("0\t");
		}
		printf("\n");
	}
}


//��ͨת�� ʵ�� 7 һģһ���Ĵ��� 
void TransposeSMatrix(TriTupleTable *a,TriTupleTable *b){
	int q,col,p;
	b->m=a->n;
	b->n=a->m;
	b->t=a->t;
	b->data[0].i = a->n;
	b->data[0].j = a->m;
	b->data[0].v = a->t;
	if(b->t){
		q=1;
		for(col=1;col<=a->n;++col)
			for(p=1;p<=a->t;++p)
				if(a->data[p].j==col){
					b->data[q].i=a->data[p].j;
					b->data[q].j=a->data[p].i;
					b->data[q].v=a->data[p].v;
					++q;
				}
	}
	
	
	
}


void isAD(TriTupleTable *a,int x,int min) {
	
	TriTupleTable *b;
	b=(TriTupleTable*)malloc(sizeof(TriTupleTable));
	TransposeSMatrix(a,b);
	//��ʱ��b�Ѿ�ת�ú���
//	printf("b:\n");
//	showMatrix(b); 

	int t=1;
	

	
	int index_x=0,index_y=0;
	int tem=0;
	// ͬ�����ҵ���һ��ֵ 
	for(t = 1; t<=a->t; t++) {
		if (b->data[t].i == x) {
			index_x = b->data[t].i;
			index_y = b->data[t].j;
			tem = b->data[t].v;
			break;
		} else {
			index_x = 0;
			index_y = 0;
			tem = 0;
		}
	}
	
	
	for(t = 1; t<=a->t; t++) {
		if (b->data[t].i == x) {
			if(tem < b->data[t].v) {
				index_x = b->data[t].i;
				index_y = b->data[t].j;
				tem = b->data[t].v;
			}
		}
	}
	
//	printf("\n(%d,%d)ֵΪ:%d\n",index_x,index_y,tem);

	if((index_x == x)&&(min == tem)&&(x!=0)) {
		printf("\n��(%d,%d)Ϊ����ֵΪ:%d\n",index_y,index_x,tem);
		flag = 1;
	}


	
} 
 
void find(TriTupleTable *a) {
	int p,q;
	int t=1;

	
	int index=1;
	int minlist[a->m];
	
	int index_x=0,index_y=0;
	int tem=0;
	
	p=1;
	for (p=1;p<=a->data[0].j;p++) {

	//���ҵ�  ��һ�е�һ��ֵ	
	for(t = 1; t<=a->t; t++) {
		if (a->data[t].i == p) {
			index_x = a->data[t].i;
			index_y = a->data[t].j;
			tem = a->data[t].v;
			break;
		} else {
			index_x = 0;
			index_y = 0;
			tem = 0;
		}
	}
	
//	printf("\n��һ����:%d,%d,%d\n",index_x,index_y,tem);
	
	for(t = 1; t<=a->t; t++) {
		if (a->data[t].i == p) {
			if(tem > a->data[t].v) {
				index_x = a->data[t].i;
				index_y = a->data[t].j;
				tem = a->data[t].v;
			}
		}
	}
//	printf("\n��%d����С����:��%d,%d)ֵΪ:%d\n",p,index_x,index_y,tem);
	// ����С��������� ������ index_y ���� ת�þ��� ����������ȥ�Ҹ������ֵ ���ҵ��� ��� index_k  
	// ���ҵ��� index_x �򷵻�˵����ǰ��� 

	isAD(a,index_y,tem);

	
	}
	
	if(flag != 1) {
		printf("û�а���!!\n");
	}
}






int main() {
	
//  ��ά����ֱ�Ӳ��� 
//	easy_way();
	
	TriTupleTable *a;
	a=(TriTupleTable*)malloc(sizeof(TriTupleTable));


	InitTriTupleNode(a);
	showMatrix(a);
	printf("\n");
	find(a);
	
	return 0;
}
