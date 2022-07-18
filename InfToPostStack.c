#include<stdio.h>	
#include<ctype.h>	
#include<string.h>    

priority(char);
push(char);
pop();

static char str[30];      
int top=-1;
void main()	{	
	char in[30],post[30],ch;			
	int i,j,l;
	printf("\n   Enter the string(Infix Expression): ");
	gets(in);		
	l=strlen(in);
	printf("\n   The length of the given string is: %d\n",l);
	for(i=0,j=0;i<l;i++)
		if(isalpha(in[i]) || isdigit(in[i]))
			post[j++]=in[i];
		else	{
			if(in[i]=='(')
				push(in[i]);
			else
			if(in[i]==')')
				while((ch=pop())!='(')
					post[j++]=ch;
			else	{
				while(priority(in[i])<=priority(str[top]))
					post[j++]=pop();
				push(in[i]);
			}//inner if
		}//outer if
	while(top!=-1)
			post[j++]=pop();
			post[j]='\0';
			printf("\nEquivalent infix to postfix is:%s ",post);
			getch();
}//main
priority (char c) {
	switch(c) {
		case '+':
		case '-':	return 1;
		case '*':
		case '/':	return 2;
		case '$':	return 3;
		case '^':	return 4;
	}//switch
	return 0;
}//priority
push(char c) {
	str[++top]=c;
	return;
}//push


pop(){
	return(str[top--]);
}//pop

