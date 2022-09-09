#include<stdio.h>
#include<stdlib.h>
#define SIZE 5

void enq(int);
void dq();
void display();

int cq[SIZE], front=-1, rear=-1,  item, op;

int main(){
	while(1){
		printf("1.Insertion\n 2.Deletion \n 3.Display\n 4.Exit\n");
		printf("Choose any option: ");
		scanf("%d", &op);
		switch(op){
			case 1: 
			printf("Enter an item to insert: ");
			scanf("%d", &item);
			enq(item);
			break;
			case 2: dq();
			break;
			case 3: display();
			break;
			case 4: exit(0);
			default: printf("Wrong choice\n");
		}
	}
}

void enq(int item)  
{  
    if(front==-1 && rear==-1)   
    {  
        front=0;  
        rear=0;  
        cq[rear]=item;  
    }  
    else if((rear+1)%SIZE==front)    
    {  
        printf("cq overflow\n");  
    }  
    else  
    {  
        rear=(rear+1)%SIZE;       
        cq[rear]=item;     
    }  
}  
  
 
void dq()  
{  
    if((front==-1) && (rear==-1))   
    {  
        printf("cq underflow\n");  
    }  
	 else if(front==rear)  
	{  
	   printf("\nThe deleted item is %d", cq[front]);  
	   front=-1;  
	   rear=-1;  
	}   
	else  
	{  
	    printf("\nThe deleted element is %d", cq[front]);  
	   front=(front+1)%SIZE;  
	}  
}  

void display()  
{  
    int i=front;  
    if(front==-1 && rear==-1)  
    {  
        printf("cq underflow\n");  
    }  
    else  
    {  
        printf("Elements in cq are :");  
        while(i!=rear)  
        {  
            printf("%4d", cq[i]);  
            i=(i+1)%SIZE;  
        }  
        printf("%4d", cq[rear]);
    }  
}  
