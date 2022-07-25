#include<stdio.h> 
#include<stdlib.h>

struct node {
	int data; 
	struct node *link;
}*front, *rear, *new, *ptr1, *ptr;

void enq(); 
void dq(); 
void display();

int ch,i,item; 

void main() {
	front=rear=NULL;
	while(1)
		{
		printf("\n1.Enqueue \n2.Dequeue \n3.Display \n4.Exit\n");
		printf("Enter ur choice: ");
		scanf("%d",&ch);
		switch(ch)
		{
		case 1: enq();
		break;
		case 2: dq();
		break;
		case 3: display();
		break;
		case 4: exit(0);
		default: printf("Wrong choice.\n");
		}
	}
}

void enq(){
	new = malloc(sizeof(struct node));
	printf("Enter the element you want to insert: \n");
	scanf("%d", &item);
	new->data = item;
	
	if(front == NULL && rear == NULL){
		front = rear = new;
	}
	else{
		rear->link = new;
		new->link = front;
		rear = rear->link;
	}
}

void dq(){
	if(front == NULL && rear == NULL)
	printf("Queue is empty\n");
	else if(front == rear){
		printf("The deleted item from queue is %d\n", front->data);
	}
	else{
		printf("The deleted item from queue is %d\n", front->data);
		ptr = front;
		front = front->link;
		rear->link = front;
		free(ptr);
	}
}

void display(){
	ptr = front;
	if(front == NULL && rear == NULL)
	printf("Queue is empty\n");
	else{
		while(ptr->link!= front){
			printf("%4d", ptr->data);
			ptr = ptr->link;
		}
		printf("%4d", ptr->data);
	}
}
