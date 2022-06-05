#include<stdio.h>  
#include<stdlib.h>  
#define size 5

void  push();
void  pop();
void peek();
void display();

int top = -1, stack[size], i;
void main(){

	int ch;
	while(1){
		printf("\n1.Push\n 2.Pop\n 3.Peek\n 4.Display\n 5.Quit\n");
		printf("Enter your choice : ");
		scanf("%d",&ch);
		switch(ch){
			case 1 :push();
				break;
			case 2 :pop();
				break;
			case 3:	peek();
				break;
			case 4: display();
				break;
			case 5:	exit(0);
			default:printf("Wrong choice\n");
		}//switch
	}//while
}//main

void push(){
	if(top == size-1)
		printf("Stack Overflow\n");
	else{
		top++;
		int ele;
		printf("Enter element you want to push: ");
		scanf("%d", &ele);
		stack[top] = ele;
	}
}

void pop(){
	if(top == -1)
		printf("Stack Underflow\n");
	else{
		printf("deleted item from stack is %d\n", stack[top]);
		top--;
	}
}

void peek(){
	if(top == -1)
		printf("Stack Underflow\n");
	else{
		printf("%d\n", stack[top]);
	}
}

void display(){
	if(top == -1)
		printf("Stack Underflow\n");
	else{
		printf("Elements in stack are: ");
		for(i=0; i<=top; i++)
			printf("%4d", stack[i]);
	}
}
