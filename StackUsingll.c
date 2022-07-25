#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *link;
}*top, *new, *ptr;

void push();
void pop();
void display();

int item, ch;

void main(){
	top = NULL;
	ptr = top;
	while(1){
		printf("\n1.Insertion\n2.Deletion\n3.display\n4.Exit");
		printf("\nEnter your choice:");
		scanf("%d", &ch);
		switch(ch){
			case 1:push();
			break;
			case 2:pop();
			break;
			case 3:display();
			break;
			case 4:exit(0);
			default:printf("\n Wrong choice\n");
		}
	}
}

void push(){
	new = malloc(sizeof(struct node));
	printf("Enter the element you want to insert: \n");
	scanf("%d", &item);
	new->data = item;
	new->link = top;
	top = new;
}


void pop(){
	ptr = top;
	if(top == NULL)
	printf("Stack is empty\n");
	else{
		printf("The deleted item is %d\n", top->data);
		top = top->link;
		free(ptr);
	}
}

void display(){
	ptr = top;
	if(top == NULL)
	printf("Stack is empty\n");
	else{
		printf("The elements in the list are: ");
		while(ptr!=NULL){
			printf("%4d", ptr->data);
			ptr = ptr->link;
		}
	}
}
