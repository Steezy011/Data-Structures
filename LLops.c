#include<stdio.h>
#include<stdlib.h>

void insertion();
void deletion();
void search();
void traverse();

int ch,i,pos,item;

struct node {
	int data;
	struct node *link;
}*header, *ptr, *ptr1, *new;

void main(){
	header = NULL;
	while(1){
		printf("\n1.Insertion\n2.Deletion\n3.Search\n4.Traverse");
		printf("Enter your choice");
		scanf("%d", &ch);
		switch(ch){
			case 1:insertion();
			break;
			case 2:deletion();
			break;
			case 3:search();
			break;
			case 4:traverse();
			break;
			case 5:exit(0);
			default:printf("\n Wrong choice\n");
		}
	}
}
void insertion(){
	ptr = header;
	new = malloc(sizeof(struct node));
	printf("\nEnter the item to insert\n");
	scanf("%d", &item);
	new->data = item;
	if(header == NULL){
		new->link = NULL;
		header = NULL;
		header = new;
	}//if
	else{
		printf("\nEnter the place to insert the item\n");
		printf("1.Start\n 2.Middle\n 3.End\n");
		scanf("%d", &ch);
		if(ch==1){
			new->link = header;
			header = new;
		}//if
		if(ch==2){
			printf("Enter the position to place abn item:");
			scanf("%d", &pos);
			for(i=1; i<pos-1; i++)
			ptr=ptr->link;
			new->link=ptr->link;
			ptr->link=new;
		}
		if(ch==3){
			while(ptr->link!=NULL)
			ptr=ptr->link;
			new->link=NULL;
			ptr->link=new;
		}
	}
}//insertion
void deletion(){
	ptr = header;
	if(header == NULL){
		printf("\n The list is empty");
	}
	else if(ptr->link==NULL){
		printf("Deleted Item is %d", ptr->data);
		header = NULL;
		free(ptr);
	}
	else{
		printf("1.Start\n 2.Middle\n 3.End\n");
		printf("\n Enter the place to delete the element from list");
		scanf("%d", &ch);
		if(ch==1){
			printf("\nThe deleted item from the list is %d:", ptr->data);
			header = header->link;
			free(ptr);
		}
		if(ch==2){
			printf("\n Enter the position to delete the element from list");
			scanf("%d", &pos);
			for(i=1; i<pos; i++)
			ptr1=ptr;
			ptr=ptr->link;
		}
		printf("\nThe deleted element is %d", ptr->data);
		ptr1->link=ptr->link;
		free(ptr);
		if(ch==3){
			while(ptr->link!=NULL){
				ptr1=ptr;
				ptr=ptr->link;
			}
			printf("\nThe deleted element is %d", ptr->data);	
			ptr1->link = NULL;
			free(ptr);	
		}
	}//else
}//deletion
void search(){
	int loc = 0, f=0;
	printf("\n Enter the element to be searched in the list");
	scanf("%d", &item);
	for(ptr=header; ptr!= NULL; ptr=ptr->link){
		loc++;
		if(ptr->data=item){
			f=1;
			break;
		}
		if(f=0)
		printf("\n Element not found");
		else
		printf("\n The element found at location %d", loc);
		
	}//for
}//search

void traverse(){
	if(header==NULL)
	printf("List is empty\n");
	else{
		printf("\nThe element in the list are:");
		for(ptr=header;ptr!=NULL;ptr=ptr->link)
		printf("%d",ptr->data);
	}
}//traverse

