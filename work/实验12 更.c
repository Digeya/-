//ʵ��12.c 
//by midi

#include<stdio.h>
#include<stdlib.h>
#define MAX 100
int arr[MAX];
//ֱ��˳����� 
// 1. ˳����� �������� �Ӻ���ǰ 
// 2. ˳����� �ݹ�ʵ�� 



int search(int arr[],int i,int key) {
	if(arr[i] == key) {
		return i;
	} else {
		return search(arr,i-1,key);
	}
} 



int main() {
	
	
	int nums,i;
	printf("һ���ж��ٸ���~?\n");
	scanf("%d",&nums);
	for(i=1;i<=nums;i++) {
		printf("�������%d����:\n",i); 
		scanf("%d",&arr[i]);
	}
	printf("������Ҫ���ҵ���:\n");
	int key;
	scanf("%d",&key);
	arr[0] = key;
	
	while(1) {
		printf("------------------------\n");
		printf("������Ҫ���ҵķ���:\n");
		printf("1.˳����� �������� �Ӻ���ǰ \n");
		printf("2.˳����� �ݹ�\n");
		printf("3.�˳�\n");
		printf("������Ҫ���ҵķ�ʽ:\n");
		printf("------------------------\n");
		int way;
		scanf("%d",&way);
		int result;
		switch(way) {
			case 1:
				while(arr[i] != key) {
					i--;
				}
			//	printf("%d",i);	
				if(i==0) {
					printf("û�ҵ�����!\n");
					 
				} else {
					printf("�ҵ��ˣ����ǵ�%d����\n",i); 
				}
				;break;
			case 2:
				result = search(arr,nums,key);
				//	printf("%d",result);
				if(result) {
					printf("�ҵ��ˣ����ǵ�%d����\n",result);
				} else {
					printf("û�ҵ�����!\n");
				};
				break;
			case 3:printf("\n886\n");exit(0);
				
			default:printf("��������!\n"); 
		} 
	}
	
	
	 

	return 0;
}
