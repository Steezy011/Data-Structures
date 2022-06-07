#include<stdio.h>
#include<stdlib.h>

void enqueue(int);
void dequeue();
void peek();
void display();

struct node {
	int data;
	struct node *link;
};

struct node *front = 0, *rear = 0, *neu, *temp;
int ele, item;

void main(){
	while(1){
		printf("1.Push\n2.Pop\n3.Display\n4.Exit\n");
		printf("Enter your choice: ");
		scanf("%d", &ele);
		
		switch(ele){
			case 1:enqueue(item);
				break;
			case 2:dequeue();
				break;
			case 3:display();
				break;
			case 4:exit(0);
			default: printf("Wrong Choice\n");
		}
	}
}

void enqueue(int item){
	neu = (struct node*)malloc(sizeof(struct node));
	printf("Enter element you want to Insert: ");
	scanf("%d", &item);
	neu->data = item;
	neu->link = NULL;
	if(front == NULL && rear == NULL)
		front = rear = neu;
	else{
		rear->link = neu;
		rear = neu;
	}
}

void dequeue(){
	temp = front;
    if(front == NULL)
		printf("Queue is empty\n");
	else{
		printf("The popped element is %d\n", front->data);
		front = front->link;
		free(temp);
	}
}

void display(){
    if(front == NULL)
		printf("Queue is empty\n");
	else{
		for(temp=front; temp!=NULL; temp=temp->link)
			printf("%4d", temp->data);
	}
	printf("\n");
}
