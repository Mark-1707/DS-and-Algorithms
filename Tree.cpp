#include <stdio.h>
#include<stdlib.h>
struct node
{
  int data;
  struct node *rchild;
  struct node *lchild;
};
typedef struct node NODE;

void inorder(NODE*p);
void preorder(NODE*p);
void postorder(NODE*p);
NODE*insert(NODE*p,int digit);
void search (NODE*p,int digit);


int main()
{
  int ch;
  int digit;
  NODE *root=NULL,*p=NULL;
  
  do
  {
    printf("\n 1. insert \n 2. inorder \n 3. preorder \n 4. postorder\n 5. search \n 6. break ");
    scanf("%d",&ch);
    switch(ch)
    {
      case 1: printf("\nEnter the element to insert :");
              scanf("%d",&digit);
              root=insert(root,digit);
              break;
      case 2: inorder(root);
               break;
      case 3: preorder(root);
              break;
      case 4 :postorder(root);
              break;
      case 5 :printf("\nenter the element you want to search:");
              scanf("%d",&digit);
              search(root,digit);
              break;
      case 6: break;
      default: printf("\n given choice is invalid");
    }
  } while(ch!=6);
}


NODE*insert(NODE*p,int digit)
{
  if(p==NULL)
  {
    p=(NODE*)malloc(sizeof(NODE));
    p->data=digit;
    p->lchild=NULL;
    p->rchild=NULL;
    
    return p;
    
  }
  else if(digit<p->data)
  {
    p->lchild=insert(p->lchild,digit);
  }
  else
 {
  p->rchild=insert(p->rchild,digit);
 }
  
}

void inorder(NODE*p)
{
  
  if(p!=NULL)
  {
    inorder(p->lchild);
    printf("\n%d",p->data);
    inorder(p->rchild);
    
  } 
  
}

void preorder(NODE*p)
{
  if(p!=NULL)
  {
    printf("\n%d",p->data);
    preorder(p->lchild);
    preorder(p->rchild);
    
  }
}

void postorder(NODE*p)
{
  if(p!=NULL)
  {
    postorder(p->lchild);
    postorder(p->rchild);
    printf("\n%d",p->data);
    
  }
}
void search (NODE*p,int digit)
{
  if(p==NULL)
  {
    printf("\n search Unsuccessful\n");
  }
  else if(digit==p->data)
  {
    printf("\n search Successful\n");
  }
  else if (digit<p->data)
  {
   search(p->lchild,digit); 
    
  }
  else
{
  search(p->rchild,digit);
}
  
}