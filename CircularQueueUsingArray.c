#include<stdio.h>
#include<stdlib.h>
#define SIZE 5

void enq();
void dq();
void display();

int cq[SIZE], front=-1, rear=-1, i , item, op;

void main(){
	while(1){
		printf("1.Insertion\n 2.Deletion \n 3.Display\n 4.Exit\n");
		printf("Choose any option: ");
		scanf("%d", &op);
		switch(op){
			case 1: enq(item);
			break;
			case 2: dq();
			break;
			case 3: display();
			break;
			case 4: exit(0);
			default: printf("Wrong Choice\n");
		}
	}
}

void enq(int item){
	if((rear+1)%SIZE == front)
	printf("Queue Overflow\n");
	
	else if(front==-1 && rear==-1){
		front = rear= 0;
		printf("Enter an element to insert: ");
		scanf("%d", &item);
		cq[rear] = item;
	}
	else{
		printf("Enter an element to insert: ");
		scanf("%d", &item);
		rear = (rear+1)%SIZE;
		cq[rear] = item;
	}
}

void dq(){
	if(front==-1 && rear==-1)
	printf("Queue Underflow");
	else if(front == rear){
		printf("The deleted item from Queue is %d\n", cq[front]);
		front = rear = -1;
	}
	else{
		printf("The deleted item from Queue is %d\n", cq[front]);
		front = (front+1)%SIZE;
	}
}

void display(){
	if(front==-1 && rear==-1)
	printf("Queue Underflow\n");
	else{	
		printf("The elements in stack are: ");
		for(i=front; i<=rear; i++){
			printf("%4d", cq[i]);
		}
		printf("\n");
	}
}
