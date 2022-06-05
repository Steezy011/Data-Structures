#include<stdio.h>  
#include<stdlib.h>  
#define size 5
void  insert();
void  delete();
void display();
int cq[size], front = -1, rear = -1;

void main(){

	int ch;
	while(1){
		printf("\n1.Insert\n 2.Delete\n 3.Display\n 4.Quit\n");
		printf("Enter your choice : ");
		scanf("%d",&ch);
		switch(ch){
			case 1 :insert();
				break;
			case 2 :delete();
				break;
			case 3:	display();
				break;
			case 4:	exit(0);
			default:printf("Wrong choice\n");
		}//switch
	}//while
}//main
void insert()
{
	int item;
	if(front == (rear+1)%size)
	{
		printf("Queue Overflow \n");
		
	}
	else
    {
		printf("Input the element for insertion in queue : ");
		scanf("%d", &item);
		rear=(rear+1)%size;    //Circular Incrementation
		cq[rear] = item ;
	}
    if(front==-1)
        front++;
}//insert
void delete()
{
	int ele;
	if (front == -1)
	{
		printf("Queue Underflow\n");
	}
      else
      {
        	ele=cq[front];
 	   		printf("Element deleted from queue is : %d\n",ele);
         	if(front==rear)
         	{
            		front=-1;
            		rear=-1;
          	}
          	else
          	front=(front+1)%size;
     }  

}//delete
void display()
{
	int i;
    if(front==-1){
    printf("queue is empty");
	}	
   else{
    printf("\n queue elements are:");
	for (i=front ; i!=rear ; i=(i+1)%size)
		printf("%4d",cq[i]);
	}
	printf("%4d",cq[i]);
}//display





