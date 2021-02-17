#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	int data;
	struct node *left;
	struct node *right;
}Node;

Node* create(){
	Node* node = (Node*)malloc(sizeof(Node));
	int x;
	printf("\nEnter Value : ");
	scanf("%d",&x);
	if(x == -1 )
	return NULL;

	node->data =x;

	printf("\nEnter Left Child of %d : ",x);
	node->left = create();
	printf("\nEnter Right Child of %d : ",x);
	node->right = create();

	return node;
}

void preorder(Node *root){
	if(root == NULL)
		return;
	printf("%d ",root->data);
	preorder(root->left);
	preorder(root->right);
}

void postorder(Node *root){
	if(root == NULL)
		return;
	postorder(root->left);
	postorder(root->right);
	printf("%d ",root->data);
}

void inorder(Node *root){
	if(root == NULL)
		return;
	inorder(root->left);
	printf("%d ",root->data);
	inorder(root->right);
}

int main(){
	Node *root = NULL;
	root = create();

	printf("\nInorder traversal : ");
	inorder(root);
	printf("\nPreorder traversal : ");
	preorder(root);
	printf("\nPostorder traversal : ");
	postorder(root);

	return 0;
}