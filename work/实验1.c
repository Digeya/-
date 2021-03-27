//ʵ��1.c 
//by midi


#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAXSIZE 200

typedef struct {
	char id[100];
	char name[50];
	double price;
	
	
}Book;

typedef struct {
	Book *elem;
	int length;
}SqList;




void CreateSqlist(SqList *book) {
	(*book).elem=(Book *)malloc(MAXSIZE*sizeof(Book));

	(*book).length = 0;
	printf("˳������ɹ�!\n");
}


void add_book(SqList *book) {
	
	int i =1;
	for(i;;i++) {
		char t_id[100];
		char t_name[50];
		double t_price;
		scanf("%s %s %lf", t_id,t_name,&t_price);
		
		if(strcmp(t_id, "0") == 0 && strcmp(t_name, "0") == 0 && t_price == 0 ) {
			
		
			
			break;
			
		}
		
		strcpy((*book).elem[i].id , t_id);
		strcpy((*book).elem[i].name , t_name);
		(*book).elem[i].price = t_price;
		(*book).length++;

//		printf("%s %s %lf \n",t_id,t_name,t_price);

//		printf("%s %s %.2lf \n",(*book).elem[i].id,(*book).elem[i].name,(*book).elem[i].price);
	}
	
}


void print_book(SqList *book) {
	
	printf("%d\n",(*book).length);
	int i;
	for(i=1;i<(*book).length +1 ;i++) {
		printf("%s %s %.2lf \n",(*book).elem[i].id,(*book).elem[i].name,(*book).elem[i].price);
	}
	
	
}


void sort_book(SqList *book) {
//	(*book).elem[i].price
// ��������  ð�� 

	
	int i,j;
	for(i=1;i<(*book).length;i++) {
		for(j=1;j<(*book).length-i+1;j++) {
			
			if((*book).elem[j].price < (*book).elem[j+1].price) {
				
				char t_id[100];
				char t_name[50];
				double t_price;
				
				strcpy(t_id,(*book).elem[j].id);
				strcpy(t_name,(*book).elem[j].name);
				t_price = (*book).elem[j].price;
				
				strcpy((*book).elem[j].id,(*book).elem[j+1].id);
				strcpy((*book).elem[j].name,(*book).elem[j+1].name);
				(*book).elem[j].price = (*book).elem[j+1].price;							
				
				strcpy((*book).elem[j+1].id,t_id);
				strcpy((*book).elem[j+1].name,t_name);
				(*book).elem[j+1].price	= t_price;			
				
			}
			
		}
	}
	
	
	
}




double average_book(SqList *book) {
	
	double book_sum,book_average;
	int i;
	for(i=1;i<(*book).length +1 ;i++) {
		book_sum += (*book).elem[i].price;
	}
	
	book_average = book_sum / (*book).length;
	
//	printf("%.2lf",book_average);
	
	return book_average;
	
}


void print_book_average(SqList *book, double book_average) {
	
//	printf("%d\n",(*book).length);
	printf("%.2lf\n",book_average);
	
	int i;
	for(i=1;i<(*book).length +1 ;i++) {
		if((*book).elem[i].price >= book_average) {
			
			(*book).elem[i].price = (*book).elem[i].price * 1.10;
		}else {
			
			(*book).elem[i].price = (*book).elem[i].price * 1.20;
		}
		
	}
	

	for(i=1;i<(*book).length +1 ;i++) {
		printf("%s %s %.2lf \n",(*book).elem[i].id,(*book).elem[i].name,(*book).elem[i].price);
	}
		
	
	
}




void add_reverse_book(SqList *book) {
	
	
	int num;
	scanf("%d",&num);
	
	int i;
	for(i=num;i>=1;i--) {
		scanf("%s %s %lf", (*book).elem[i].id,(*book).elem[i].name,&(*book).elem[i].price);
//		printf("%d\n",i);
		(*book).length++;
	}
//	printf("%d",(*book).length);


}

void print_reverse_book(SqList *book) {
	
//	printf("%d\n",(*book).length);
	int i;
	for(i=1;i<(*book).length +1 ;i++) {
		printf("%s %s %.2lf \n",(*book).elem[i].id,(*book).elem[i].name,(*book).elem[i].price);
	}
	
	
}


int max_price_book(SqList *book) {
	// ���Ѿ�sort�����򣩺õĽṹ���� m������
	 double max = (*book).elem[1].price;
	 int i;
	 int max_count=1;
	 for(i=2;i<(*book).length +1 ;i++) {
	 	
	 	if((*book).elem[i].price == max) {
	 		max_count++;
		 }
		 else {
		 	break;
		 }
	 	
	 }
	 
	return max_count;
}






void printf_nums_book(SqList *book, int nums) {
	
	int i;
	for(i=1;i<nums +1 ;i++) {
		printf("%s %s %.2lf \n",(*book).elem[i].id,(*book).elem[i].name,(*book).elem[i].price);
	}
	
}



void find_book_by_name(SqList *book) {
	int nums;
	scanf("%d",&nums);
	int finded_id_list[nums];
	int count_list[nums];
	int k=0;  //����     finded_id �� count �� 
	while(nums--) {
		char t_name[50];
		scanf("%s", t_name);
		int count=0;
		int finded_id;
		int i;
		for(i=1;i<(*book).length +1 ;i++) {
			if( strcmp((*book).elem[i].name,t_name) == 0 ) {
				count++;
				finded_id = i;

			}
		}
		finded_id_list[k] = finded_id;
		count_list[k]= count;
		k++;
		

	}
	
	
	

	int i;
	for(i=0;i<k;i++) {
		if(count_list[i]==0) {
			printf("��Ǹ��û������\n");
		}else {
			printf("%d\n",count_list[i]);
			printf("%s %s %.2lf \n",(*book).elem[finded_id_list[i]].id,(*book).elem[finded_id_list[i]].name,(*book).elem[finded_id_list[i]].price);
		}
	}
	
	
	
}





void add_order_book(SqList *book) {
	
	
	int num;
	scanf("%d",&num);
	
	int i;
	for(i=1;i<=num;i++) {
		scanf("%s %s %lf", (*book).elem[i].id,(*book).elem[i].name,&(*book).elem[i].price);
//		printf("%d\n",i);
		(*book).length++;
	}
//	printf("%d",(*book).length);


}




void find_book_by_index(SqList *book) {
	int nums;
	scanf("%d",&nums);
	
	int finded_id_list[nums];
	int count_list[nums];
	int k=0;  //����     finded_id �� count �� 	
	while(nums--) {
		int index;
		scanf("%d", &index);
//		int count=0;
		int finded_id;
		int i;
		
		if(index<=0 || index>(*book).length) {
			finded_id = 0;
		} else{
			
			finded_id = index;
		}

		finded_id_list[k] = finded_id;
//		count_list[k]= count;
		k++;
				

	
	}
	
	int i;
	for(i=0;i<k;i++) {
		if(finded_id_list[i]==0) {
			printf("��Ǹ�����λ���ϵ�ͼ�鲻���ڣ�\n");
		}else {

			printf("%s %s %.2lf \n",(*book).elem[finded_id_list[i]].id,(*book).elem[finded_id_list[i]].name,(*book).elem[finded_id_list[i]].price);
		}
	}
	
}


void new_book_add(SqList *book) {
	int index;
	scanf("%d",&index);
	if((index<1)||(index>(*book).length+1)) {
		printf("��Ǹ�����λ�÷Ƿ���\n");
		return;
	}
	char t_id[100];
	char t_name[50];
	double t_price;
	scanf("%s %s %lf", t_id,t_name,&t_price);
	int i;
	for(i=(*book).length;i>index-1;i--) {
		(*book).elem[i+1] = (*book).elem[i];
	}

	strcpy((*book).elem[index].id , t_id);
	strcpy((*book).elem[index].name , t_name);
	(*book).elem[index].price = t_price;
	(*book).length++;
}


void old_book_del(SqList *book) {
	int index;
	scanf("%d",&index);
	
	if((index<1)||(index>(*book).length+1)) {
	printf("��Ǹ������λ�÷Ƿ���\n");
	return;
	}
	
	int i;
	for(i=index;i<(*book).length;i++) {    //  length ���ܼ�1 �������   �����󸲸ǣ� 
		(*book).elem[i] = (*book).elem[i+1];
	}
	(*book).length--;

}


void remove_same_book(SqList *book) {
	int i;
	for(i=1;i<(*book).length;i++) {
		
		if(strcmp((*book).elem[i].id,(*book).elem[i+1].id) ==0) {
			
			int j;
			for(j=i;j<(*book).length;j++) {    //  length ���ܼ�1 �������   �����󸲸ǣ� 
					(*book).elem[j] = (*book).elem[j+1];
				}
			(*book).length--;
			
			i--;
			
		}
		
		
	}
}

int main() {
	
while(1) {
	
	
	printf("-----------------------------\n");
	SqList *L=( SqList *)malloc(sizeof(SqList));
	CreateSqlist(L);
	
	
	int title_id;
	printf("���������1-10:\n");
	scanf("%d",&title_id);
	
	printf("��������������:\n");

	switch(title_id) {
		
		case 1:add_book(L);print_book(L);break;
		case 2:add_book(L);sort_book(L);print_book(L);break;
		case 3:add_book(L);double book_average = average_book(L);print_book_average(L,book_average);break;
		case 4:add_reverse_book(L);print_reverse_book(L);break;
		case 5:add_reverse_book(L);sort_book(L);int max_count = max_price_book(L);printf("%d\n",max_count);printf_nums_book(L,max_count);break;
		case 6:add_reverse_book(L);find_book_by_name(L);break;
		case 7:add_order_book(L);find_book_by_index(L);break;
		case 8:add_order_book(L);new_book_add(L);print_book(L);break;
		case 9:add_order_book(L);old_book_del(L);print_book(L);break;
		case 10:add_order_book(L);sort_book(L);remove_same_book(L);print_book(L);break;
		default:printf("������������\n");
	}
	
//1. ����˳��洢�ṹ��ͼ����Ϣ��Ĵ��������
//	add_book(L);
//	print_book(L);
//	
//	printf("---------------------------\n");
////	2. ����˳��洢�ṹ��ͼ����Ϣ�������     ��������
//	sort_book(L);
//	print_book(L);
//	printf("---------------------------\n");
//
////  3. ����˳��洢�ṹ��ͼ����Ϣ����޸�
//	double book_average = average_book(L);
//	print_book_average(L,book_average);
//	
	
	
//	printf("---------------------------\n");
	
//	4. ����˳��洢�ṹ��ͼ����Ϣ�������洢

	
//	add_reverse_book(L);
//	print_reverse_book(L);
	
//  5. ����˳��洢�ṹ��ͼ����Ϣ������ͼ��Ĳ���
//	add_reverse_book(L);
//	sort_book(L);
//	int max_count = max_price_book(L);
//	printf("%d\n",max_count);
//	printf_nums_book(L,max_count);


// 6. ����˳��洢�ṹ��ͼ����Ϣ����ͼ��Ĳ���  
//	add_reverse_book(L);
//	find_book_by_name(L);
	
// 7.����˳��洢�ṹ��ͼ����Ϣ��İ�λ�ò���
//	add_order_book(L);
//	find_book_by_index(L);

// 8.����˳��洢�ṹ��ͼ����Ϣ�����ͼ������   ������˸��鱾�ܸ��� ����д������������� 
//	add_order_book(L);
//	new_book_add(L);     //��ûд�Ƿ�������ж� 
//	print_book(L);
	
//  9.����˳��洢�ṹ��ͼ����Ϣ��ľ�ͼ��ĳ���  ������˸��鱾�ܸ��� ����д������������� 
//	add_order_book(L);
//	old_book_del(L);   //��ûд�Ƿ�������ж� 
//	print_book(L);

//  10.����˳��洢�ṹ��ͼ����Ϣ���ͼ��ȥ��
//	add_order_book(L);
//	sort_book(L);
//	remove_same_book(L);
//	print_book(L);
}	
} 
