//ʵ��6.c 
//by midi

#include <stdio.h>
#include <stdlib.h>


typedef struct monkey {
	int id;
	struct monkey *next;
}Monkey,*PMonkey;


//��������ѭ��������
PMonkey CreatList(int num) {
	PMonkey head,r,tmp;
	int i;
	
	head = (PMonkey)malloc(sizeof(Monkey));  //��ʼ�� ͷ���洢�������� 
	head->id = num; 
	head->next = NULL;

	r = head;

	for(i = 1;i <= num;i++){
//		ͷ�巨 
		tmp = (PMonkey)malloc(sizeof(Monkey));
		tmp->id = i;
		tmp->next = NULL;
		r->next = tmp;
		r = r->next;

	}
	r->next = head->next;

	return head;
}


int SearchKing(PMonkey L) {
	 int num,per;
	 int i;
	 PMonkey p,tmp;  // ��tmp���н�
	 num = L->id;  // ͷָ���е�id���ݼ�¼�ܺ������� 
     p = L;    
    
	 for(per = 13; num > 1; per--, num--){  //ɾ��ֻ��һֻ���Ӵ���
	
//		printf("per :%d num: %d \n",per,num);
        if(!per){   //��0����ѭ��
            per = 13;
        }
        for(i = 1; i < per; i++){

             p = p->next;  //ָ��Ҫɾ���ĺ��� p->next 
        }

        tmp = p->next;
        p->next = tmp->next;
        free(tmp);
    }    
    
    
    
    return p->id;
}



//void OutPut(PMonkey L) {
//	
//	PMonkey p,tmp;
//	
//	p = L->next;
//	
//	do {
//		
//		printf("%d", p->id);
//		p = p->next;
//		
//	} while(p != L->next);
//
//} 


int main() {
	PMonkey L;
	
	int num;
	printf("��������Ӹ���:\n");
	scanf("%d",&num);

	L = CreatList(num);
	
	int King_id; 
	King_id = SearchKing(L);
	printf("�� %d �������Ǻ���\n",King_id);
	
//	OutPut(L); //���Ե����� 
	return 0;

}
