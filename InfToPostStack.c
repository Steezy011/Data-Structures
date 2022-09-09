#include <stdio.h>
#include <ctype.h>
#define SIZE 50            

char stack[SIZE];
int top=-1;      
 
push(char elem)                     
    stack[++top]=elem;

char pop()                     
    return(stack[top--]);

 
int pr(char c)
{                 
    switch(c){
    	case '+':
    	case '-': return 1;
    	case '*':
    	case '/': return 2;
    	case '^': return 3;
	}
	return 0;
}
  /* Main Program */
void main()
{                        
    char infix[50],postfix[50],ch,elem;
    int i=0,k=0;
    printf("Enter Infix Expression : ");
    scanf("%s",infix);
    push('#');
    
    while(infix[i]!= NULL)   //ch=infix[i++]
    {	
    	ch = infix[i];
        if( ch == '(') 
			push(ch);
        else
            if(isalnum(ch)) {
            	postfix[k]=ch;
				k++;
//				poatfix[k++] = ch;
			}
				
            else
                if( ch == ')')
                {
                    while( stack[top] != '('){
                        postfix[k]=pop();       //poping from stack and appending in postfix[k++]
                        k++;
					}
                    elem=pop(); /* Remove ( */
                }
                else
                {       /* Operator */
                    while( pr(ch) <= pr(stack[top])){
                    	postfix[k] = pop();
                    	k++;
					}                        
                    push(ch);
                }
        i++;
    }
    while( stack[top] != '#')     /* Pop from stack till empty */
        postfix[k++]=pop();
//    postfix[k]= NULL;          /* Make postfix as valid string */
    printf("\nPostfix Expression =  %s\n",postfix);
}
