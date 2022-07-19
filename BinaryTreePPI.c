#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *lchild, *rchild;
};

typedef struct node bnode;

// void preorder(bnode*);
// void inorder(bnode*);
// void postorder(bnode*);

bnode *root = (bnode*)malloc(sizeof(bnode));


bnode *getnode(int ele){
	bnode *q = (bnode*)malloc(sizeof(bnode));
	
	if(q){
		q->data = ele;
		q->lchild = NULL;
		q->rchild = NULL;
		return q;
	}
	else {
		printf("\n Unable to create node");
		exit(0);
	}
	return 0;
}

void preorder(bnode *root){
	if(root){
		printf("%5d", root->data);
		preorder(root->lchild);
		preorder(root->rchild);
	}
}

void inorder(bnode *root){
	if(root){
		inorder(root->lchild);
		printf("%5d", root->data);
		inorder(root->rchild);
	}
}

void postorder(bnode *root){
	if(root){
		postorder(root->lchild);
		postorder(root->rchild);
		postorder("%5d", root->data);
	}
}

bnode *insert(bnode *root, int ele){
	if(!root){
		bnode* q = getnode(ele);
		root = q;
	}
	else if(root->data < ele)
		root->rchild = insert(root->rchild, ele);
	else if(root->data > ele)
		root->lchild = insert(root->lchild, ele);
	else{
		printf("\nDuplicate data");
	}
	return root;
}

void main(){
	int ch, ele;
	bnode* root = NULL;
	printf("\nBinary search tree operations: ");
	printf("\n\t1.Insert \n\t2.preorder\n\t3.Inorder \n\t4.postorder\n\t5.Exit ");
	while(1){
		printf("\nEnter your choice: ");
		scanf("%d", &ch);
		switch(ch){
			case 1: printf("\n Enter an element: ");
			scanf("%d", &ele);
			root = insert(root, ele);
			break;
			
			case 2: preorder(root);
			break;
			
			case 3: inorder(root);
			break;
			
			case 4: postorder(root);
			break;
			
			case 5: exit(0);
			default: printf("\n Invalid choice");
		}
	}
}
