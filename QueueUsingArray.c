#include<stdio.h>
#include<stdlib.h>
#define SIZE 5

void enq(int);
void dq();
void display();

int q[SIZE], front=-1, rear=-1, i , item, op, temp;

void main(){
	while(1){
		printf("1.Insertion\n 2.Deletion \n 3.Display\n");
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
	if(rear>=SIZE){
		printf("\nQueue Overflow\n");
	}
	else{
		printf("Enter an element to push: ");
		scanf("%d", &item);
		rear++;
		q[rear] = item;
		if(front==-1){
			front++;
		}
	}
}

void dq(){
	if((front==-1)|| (front>rear))
	printf("\nQueue Underflow\n");
	else{
		temp = q[front];
		printf("The deleted item is %d\n", temp);
		front++;
	}
}

void display(){
	if((front==-1)|| (front>rear))
	printf("\nQueue Underflow\n");
	else{
		printf("elements in Queue are :");
		for(i=front; i<=rear; i++){
			printf("%4d", q[i]);
		}
		printf("\n");
	}
}
