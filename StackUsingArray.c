#include<stdio.h>
#include<stdlib.h>
#define SIZE 5

void push(int);
void pop();
void display();
int isfull();
int isempty();

int stack[SIZE], top=-1, item, op, temp, i;

void main(){
	while(1){
		printf("1.Insertion\n 2.Deletion \n 3.Display \n 4.IsFull \n 5.IsEmpty \n");
		printf("Choose any option: ");
		scanf("%d", &op);
		switch(op){
			case 1: push(item);
			break;
			case 2: pop();
			break;
			case 3: display();
			break;
			case 4: isfull();
			break;
			case 5: isempty();
			break;
			case 6: exit(0);
			default: printf("Wrong Choice\n");
		}
	}
}

void push(int item){
	if(top >= SIZE){
		printf("\nStack Overflow");
	}
	else{
		printf("\nEnter an element to push: ");
		scanf("%d", &item);
		top++;
		stack[top] = item;
	}
}

void pop(){
    if(top == -1)
	printf("\nStack Underflow");
	else{
		temp = stack[top];
		printf("The deleted item is %d\n", stack[top]);
		top--;
	}
}

void display(){
	if(top == -1)
	printf("\nStack Underflow");
	else{
		printf("Elements in stack are: ");
		for(i=0; i<=top; i++)
			printf("%4d", stack[i]);
	}
	printf("\n");
}

int isfull(){
	if(top >= SIZE){
		printf("\nStack Overflow");
	}
	else{
		return 1;
	}
}

int isempty(){
	if(top == -1)
	printf("\nStack Underflow");
	else{
		return 1;
	}
}
