#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *link;
}*front, *rear, *new, *ptr;

void enq();
void dq();
void display();

int item, ch;

void main(){
	front = NULL;
	rear = NULL;
	while(1){
		printf("\n1.Insertion\n2.Deletion\n3.display\n4.Exit");
		printf("\nEnter your choice:");
		scanf("%d", &ch);
		switch(ch){
			case 1:enq();
			break;
			case 2:dq();
			break;
			case 3:display();
			break;
			case 4:exit(0);
			default:printf("\n Wrong choice\n");
		}
	}
}

void enq(){
	new = malloc(sizeof(struct node));
	printf("Enter the element you want to insert: \n");
	scanf("%d", &item);
	new->data = item;
	new->link = NULL;
	if(front == NULL && rear == NULL){
		front = rear = new;
	}
	else{
		rear->link = new;
		rear = new;
	}
}

void dq(){
	if(front == NULL && rear == NULL){
		printf("Queue is empty\n");
	}
	else{	
		ptr = front;
		printf("The deleted item from queue is %d", ptr->data);
		front = front->link;
		free(ptr);
	}
}

void display(){
	if(front == NULL && rear == NULL){
		printf("Queue is empty\n");
	}
	else{
		ptr = front;
		while(ptr != NULL){
			printf("%4d", ptr->data);
			ptr = ptr->link;
		}
	}
}
