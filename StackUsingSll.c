#include<stdio.h>
#include<stdlib.h>

void push(int);
void pop();
void peek();
void display();

struct node {
	int data;
	struct node *link;
};

struct node *top = 0, *rear, *neu;
int ele, item;

void main(){
	while(1){
		printf("1.Push\n2.Pop\n3.Peek\n4.Display\n5.Exit\n");
		printf("Enter your choice: ");
		scanf("%d", &ele);
		
		switch(ele){
			case 1:push(item);
				break;
			case 2:pop();
				break;
			case 3:peek();
				break;
			case 4:display();
				break;
			case 5:exit(0);
			default: printf("Wrong Choice\n");
		}
	}
}

void push(int item){
	neu = (struct node*)malloc(sizeof(struct node));
	printf("Enter element you want to Insert: ");
	scanf("%d", &item);
	neu->data = item;
	neu->link = top;
	top = neu;
	
}

void peek(){
	if(top == NULL)
		printf("Queue is empty\n");
	else{
		printf("%d\n", top->data);
	}
	
}

void pop(){
	rear = top;
    if(top == NULL)
		printf("Queue is empty\n");
	else{
		printf("The dequeueped element is %d\n", top->data);
		top = top->link;
		free(rear);
	}
}

void display(){
    if(top == NULL)
		printf("Queue is empty\n");
	else{
		for(rear=top; rear!=NULL; rear=rear->link)
			printf("%4d", rear->data);
	}
	printf("\n");
}
