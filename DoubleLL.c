#include<stdio.h>		
#include<stdlib.h>
void insertion();		
void deletion();		
void traverse();      
int i,pos,item,ch;
struct node  {
	int data;
	struct node *next;
	struct node *prev;
}*new,*header,*ptr,*ptr1,*ptr2;
void main()  {
	header=NULL;
	printf(" ***** MENU ****");
	printf("\n1.Insertion \n2.Deletion \n3.Traverse \n4.Exit\n");
	while(1) {
		printf("\n\nEnter your choice: ");
		scanf("%d",&ch);
		switch(ch)  {
			case 1:	insertion();	break;
			case 2:	deletion();		break;
			case 3:	traverse();		break;
			case 4:	exit(0);
			default: printf("\nWrong choice");
		}//switch
	}//while
}//main

void insertion()  
{
	ptr=header;
	new=malloc(sizeof(struct node));
	printf("\nEnter the item to be inserted: ");
	scanf("%d",&item);
	new->data=item;
	if(header==NULL)	{
		new->prev=NULL;
		new->next=NULL;
		header=new;
	}
	else{
		printf("\nSelect the place:");
		printf("\n1.Start \n2.Middle \n3.End\n");
		scanf("%d",&ch);
		if(ch==1)	
		{
			new->next=ptr;
			new->prev=NULL;
			ptr->prev=new;
			header=new;
		}//choice 1
		if(ch==2)
		{
		printf("\nEnter the position to place the new element: ");
		scanf("%d",&pos);
			for(i=1;i<pos-1;i++)
				ptr=ptr->next;
			ptr1=ptr->next;

			new->next=ptr1;
			new->prev=ptr;
			ptr1->prev=new;
			ptr->next=new;

		}//choice 2
		if(ch==3)
		{
			while(ptr->next!=NULL)
				ptr=ptr->next;
			new->next=NULL;
			new->prev=ptr;
			ptr->next=new;
		} //choice 3

	}//else
}//insertion

void deletion()
{
	 ptr=header;
	if(header==NULL)
		printf("The list is empty\n");
	else if(ptr->next==NULL)
	{	
		printf("Deleted  item  is:%d",ptr->data);
		free(ptr);
		header=NULL;
	}
	else
	{
		printf("\n Select the place:");
		printf("\n1.Start \n2.Middle \n3.End\n");
		scanf("%d",&ch);
		if(ch==1)
		{
			printf("\nThe deleted item is: %d",ptr->data);
			ptr1=ptr->next;
			header=ptr1;
			ptr1->prev=NULL;
			free(ptr);
		}//choice 1
		if(ch==2)
		{
		printf("\nEnter the position to delete the element: ");
		scanf("%d",&pos);
		for(i=1;i<pos;i++)
		     ptr=ptr->next;
		printf("\nThe deleted item is: %d",ptr->data);
		ptr1=ptr->prev;
		ptr2=ptr->next;
		ptr1->next=ptr2;
		ptr2->prev=ptr1;
		free(ptr);
		}//choice 2
		if(ch==3)
 		{
		while(ptr->next!=NULL)
		ptr=ptr->next;
		printf("\n\nThe deleted node is: %d",ptr->data);
		ptr1=ptr->prev;
		ptr1->next=NULL;
		free(ptr);
		}//choice 3
   }//else
}//deletion

void traverse()
{
	ptr=header;
	if(header==NULL)
		printf("The list is empty\n");
	else
	{
		printf("\n\nThe elements in farword order: ");
		for(;ptr!=NULL;ptr=ptr->next)
		{
			printf("%4d",ptr->data);
			  ptr1=ptr;
		}
		printf("\n\nThe elements in reverse order: ");
		for(;ptr1!=NULL;ptr1=ptr1->prev)
			printf("%4d",ptr1->data);
	}//else
}//traverse



