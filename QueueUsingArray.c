#include<stdio.h>  
#include<stdlib.h>  
#define size 5
void  enqueue();
void  dequeue();
void display();
int queue[size], front = 0, rear = 0, i, ele;

void main(){

	int ch;
	while(1){
		printf("\n1.Insert\n 2.Delete\n 3.Display\n 4.Quit\n");
		printf("Enter your choice : ");
		scanf("%d",&ch);
		switch(ch){
			case 1 :enqueue();
				break;
			case 2 :dequeue();
				break;
			case 3:	display();
				break;
			case 4:	exit(0);
			default:printf("Wrong choice\n");
		}//switch
	}//while
}//main

void enqueue() {
	if(rear == size)
		printf("*** queue is full ***\n");
	else  {
		printf("enter item into queue:");
		scanf("%d",&ele);
		queue[rear] = ele;
		rear++;
	}//else
}//insertion


void dequeue(){
	if(front == rear)
		printf("Queue Underflow\n");
	else {
		printf("deleted item is %d", queue[front]);
		for(i=0; i<rear-1; i++)
			queue[i] = queue[i+1];
		rear--;
	}
}
void display(){
	if(front == rear)
		printf("Queue Underflow\n");
	else{
		printf("The elements in queue are: ");
		for(i=0; i<rear; i++){
			printf("%4d", queue[i]);
		}
	}
}

