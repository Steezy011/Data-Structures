#include<stdio.h> 
#include<stdlib.h>
int choice,i,item; struct node {
int data; 
struct node *link;
}*front,*rear,*new,*ptr1,*ptr;
int enqueue(); 
int dequeue(); 
int display();
void main() {
	front=rear=NULL;
	printf("\n select menu\n");
	while(1)
		{
		printf("\n1.Enqueue \n2.Dequeue \n3.Display \n4.Exit");
		printf("\nEnter ur choice: ");
		scanf("%d",&choice);
		switch(choice)
		{
		case 1: enqueue();
		break;
		case 2: dequeue();
		break;
		case 3: display();
		break;
		case 4: exit(0);
		default: printf("\nWrong choice.");
		}/*end of switch*/
	}/*end of while*/
}/*end of main*/

int enqueue()
{
	new=malloc(sizeof(struct node));
	printf("\nEnter the item: ");
	scanf("%d",&item);
	new->data=item;
	if(front==NULL)
		front=new;
	else
		rear->link=new;
		rear=new;
		rear->link=front;
		return;
}/*end of enqueue()*/

int dequeue()
{
	if(front==NULL) 
	printf("\nThe circular list is empty.");
	else if(front==rear) {
		printf("\nThe deleted element is: %d",front->data); 
		front=rear=NULL;
	}
	else {
		printf("\nThe deleted element is: %d",front->data); 
		front=front->link; 
		rear->link=front;
	} return; 
}/*end of dequeue*/

int display() {
	ptr=front; 
	if(front==NULL) 
		printf("\nThe circular list is empty.");
		else {
		printf("\nElements in the list are: "); 
		do {
			printf(" %d",ptr->data); 
			ptr=ptr->link;
		} while(ptr!=front); 
		return;
	}/*end of else*/
}/*end of display*/
