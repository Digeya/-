//ʵ��12.c 
//by midi

#include<stdio.h>
#include<stdlib.h>
#define MAX 100
int arr[MAX];
//ֱ��˳����� 
// 1. ˳����� �������� �Ӻ���ǰ 
// 2. �۰���� �ݹ�ʵ�� 

int zheban(int arr[],int l,int r,int key) {
	
	if(l>r) {
		return -1;
	} 
	int mid = (l+r)/2;
	if(arr[mid]==key) {
		return mid;
	} else if(key<arr[mid]) {
		return zheban(arr,l,mid-1,key);
	} else {
		return zheban(arr,mid+1,r,key);
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
		printf("2.�۰���� �ݹ�\n");
		printf("3.�˳�");
		printf("������Ҫ���ҵķ�ʽ:\n");
		printf("------------------------\n");
		int way;
		scanf("%d",&way);
		switch(way) {
			case 1:
				while(arr[i] != key) {
					i--;
				}
			//	printf("%d",i);	
				if(i==0) {
					printf("û�ҵ�����!\n");
					 
				} else {
					printf("�ҵ��ˣ����ǵ�%d����\n"); 
				}
				;break;
			case 2:
				if(zheban(arr,1,nums,key) == -1) {
					printf("û�ҵ�����!\n");
				} else {
					printf("�����ڵ�%d��\n",zheban(arr,1,nums,key));
				} 
				break;
			case 3:printf("\n886\n");exit(0);
				
			default:printf("��������!\n"); 
		} 
	}
	
	
	 
	
	
	
//	while(arr[i] != key) {
//		i--;
//	}
////	printf("%d",i);	
//	if(i==0) {
//		printf("û�ҵ�����!\n");
//		 
//	} else {
//		printf("�ҵ��ˣ����ǵ�%d����\n"); 
//	}
	

//	int id = zheban(arr,1,nums,key);
//	if(id == -1) {
//		printf("û�ҵ�����!\n");
//	} else {
//		printf("�����ڵ�%d��",id);
//	} 

	
	
	
	return 0;
}
