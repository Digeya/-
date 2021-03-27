//ʵ��4.c 
//by midi

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>


#define MAXSIZE 100

//˳��ջ 

typedef struct Stack_number{
	double data[MAXSIZE];
	int top;
	
}Stack_number;

typedef struct Stack_operator{
	char data[MAXSIZE];
	int top;
	
}Stack_operator;


//��ʼ�� 
void init_number_stack(Stack_number *stack) {
	stack->top = 0;
}

void init_operator_stack(Stack_operator *stack) {
	stack->top = 0;
}



//��ջ    data[0]��������  topָ��ָ�����ϲ����� 
void Push_number(Stack_number *stack, double number) {
	stack->top++;
	stack->data[stack->top] = number;
} 

void Push_operator(Stack_operator *stack, char oper) {
	stack->top++;
	stack->data[stack->top] = oper;
}


//��ջ
//��Ҫȡ����ǰ����
void Pop_number(Stack_number *stack, double *number) {
	*number = stack->data[stack->top];
	stack->top--;
}

void Pop_operator(Stack_operator *stack, char *oper) {
	*oper = stack->data[stack->top];
	stack->top--;
}


//ȡջ��Ԫ��
double GetTop_number(Stack_number stack) {
	return stack.data[stack.top];
}


char GetTop_operator(Stack_operator stack) {
	return stack.data[stack.top];
}

//�ж�ջ��

int isEmpty_number(Stack_number *stack) {
	if(stack->top == 0) {
		return 1;
	} else {
		return 0;
	}
}

int isEmpty_operator(Stack_operator *stack) {
	if(stack->top == 0) {
		return 1;
	} else {
		return 0;
	}
}



//�ж��������ջ������������������֮�����ȹ�ϵ
char Role(char c1,char c2) {
	
    char c;
    switch(c1){
        case '+':
        case '-':
	    	switch(c2){
		        case '+':
	            case '-':
		        case ')':
	            case '#':c='>';break;
		        default:c='<';
	    	}
			break;
        case '*':
        case '/':
            if(c2=='('){
				c='<';
			}
			else{
				c='>';
			}
            break;
        case '(':
		    if(c2==')'){
				c='=';
			}
		    else{
				c='<';
			}
            break;
        case ')':c='>';break;
        case '#':
		    if(c2=='#'){
				c='=';
			}
		    else{
				c='<';
			}
    }
    return c;
}





//�Ƿ�������� 
int isOperator(char c) {
	char ch[7] = "+-*/()#";   //   # ���ܶ������� ������ѭ�� һֱ�ж��� ���� 
	
	int i,flag=0;
	for(i=0;i<7;i++) {
		if(ch[i]==c) {
			flag=1;
			break;
		}
	}
	
	
	return flag;
	
} 


//���� +-*/ 
double jisuan(double a,char oper, double b) {
	double sum;
    switch(oper)
    {
    	case '+':sum=a+b;break;
		case '-':sum=a-b;break;
        case '*':sum=a*b;break;
        case '/':sum=a/b;break;
    }
    return sum;
}



void is_legal(char *s) {
	//1 ��������  (���ű����� )ǰ��
	int i;
	int flag1=0,flag2=0;
	
	for(i = 0;i < strlen(s);i++) {
		if(s[i] == '(') {
			flag1 = 1;
		}
		if(s[i] == ')') {
			flag2 = 1;
			break;
		}
		
	}
	
	if(flag1 == flag2) {
		//�Ϸ�
	}
	if(flag1 ==1 && flag2 ==0) {
		//ȱ�������� 
		printf("�����ʽ��������ȱ�������ţ��� \n");
		getchar();
		exit(0);
	} 
	if(flag1 ==0 && flag2 ==1) {
		//�������ȳ��� 
		printf("�����ʽ����������������ȳ��� ���� \n");
		getchar();
		exit(0);
	}
	
	//2 �������������  �������� �����������������ǰ��
	for(i = 0;i < strlen(s);i++) {
		if(i > 0 && i < strlen(s) - 1 && isOperator(s[i]) && (isOperator(s[i - 1]) || isOperator(s[i + 1]))
			&&(s[i] != '(' && s[i] != ')') && (s[i - 1] != '(' && s[i - 1] != ')')
			&&(s[i + 1] != '(' && s[i + 1] != ')')) {
				
				
			printf("�����ʽ�����������������������\n");
			getchar();
			exit(0);
	}
	
	
}
}
 


double Yunsuan(char *s) {
	
	//�����������������Ϸ���
	is_legal(s);
	
	
	
	//������Ķ���ʽ���м�飡��
	int i=0,flag=0;
	char e;
	double a,b;
	double result;
	
	Stack_number SN;
	Stack_operator SO;
	
	init_number_stack(&SN);
	init_operator_stack(&SO);
	
	int len = strlen(s);
	char c1=s[0];  //����һ���ַ�����С������ 
	s[len] = '#';
	s[len+1] = '\0';   //��һ����/0���ǳ�# ��Ҫ���¼� /0 ����
	Push_operator(&SO,'#');
	
	while(s[i]!='#'|| GetTop_operator(SO) != '#') {
//		printf("yes1 ");
//		printf("%d",i);
		
		if(s[i] == ' '){
			i++;
			continue;
		}
		//�жϸ��ַ��� ���黹�������  
		if( !isOperator(s[i])) {  //�����������ʱ�� 
			
			
			if(c1=='.'){//�����һ���ַ���С����
		        flag++;
		    }
		    if(flag){
		    	double t;
		    	Pop_number(&SN,&t);
				Push_number(&SN,t + (double)(s[i] - '0') / pow(10,flag));//��С�����Ĳ��� ��λ�����㲢��ջ 
				flag++;
			}
			
			if(s[i]!='.'&&!flag){
	            if(!isOperator(c1)&&!isEmpty_number(&SN)){ //�����һ���ַ������֣�˵���Ƕ�λ���� ����λ���������ջ
	            	double t;
	            	Pop_number(&SN,&t);
	                Push_number(&SN,t * 10 + s[i] - '0');
	            }
	            else//����ѹ��������ջ
	            	Push_number(&SN,(double)(s[i]-'0'));
		    }

	    	c1=s[i];
			i++; //��ȡ��һ���ַ�
		}
		
		else {
//			printf("no ");
			
			flag = 0;
			switch(Role(GetTop_operator(SO),s[i])) {
				case '>':
					Pop_operator(&SO,&e);
					Pop_number(&SN,&b);
					Pop_number(&SN,&a);
					Push_number(&SN,jisuan(a,e,b));
					break;
				case '=':
					Pop_operator(&SO,&e);
					c1 = s[i++];
					break;
				case '<':
					Push_operator(&SO,s[i]);
					c1 = s[i++];
					break;
					
			}
			
		}
		
	}
	result = GetTop_number(SN);
	
	return result;
}



int main() {
	
	
	char s[100];
	printf("��������ʽ��\n");
	gets(s);

	double result = Yunsuan(s);
	
	printf("%lf",result);

//	printf("%c", Role('+','+'));
	
	return 0;
}
