#include<stdio.h>
#include<math.h>

void push(int);
int pop();
int eval(char, int, int);

int top = -1, stack[30], ch, res;

void main(){
	char pf[50];
	int i, op1, op2, x;
	printf("Enter the postfix expression: ");
	gets(pf);
	for(i=0; pf[i]!=NULL; i++){
		ch = pf[i];
		if(ch>='0' && ch<='9'){
			push(ch-'0');
		}
		else{
			op2 = pop();
			op1 = pop();
			res = eval(ch, op1, op2);
			push(res);
		}
	}//for
	x = pop();
	printf("result : %d", x);
}

int eval(char ch, int op1, int op2){
	switch(ch){
		case '+' : return(op1+op2);
		case '-' : return(op1-op2);
		case '*' : return(op1*op2);
		case '/' : return(op1/op2);
		case '^' : return(pow(op1, op2));
	}
}

void push(int n){
	top++;
	stack[top] = n;
}

int pop(){
	return stack[top--];
}
