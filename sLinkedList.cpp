#include<bits/stdc++.h>
using namespace std;

typedef struct node{
    int data;
    struct node *next;
}Node;

Node *head;

void bigInsert(){
    Node *ptr=NULL;
    ptr=(Node*)malloc(sizeof(Node*));
    cout<<"Enter Value at Begining : ";
    cin>>ptr->data;
    if(head==NULL){
        ptr->next=NULL;
        head=ptr;
        cout<<"Node Added"<<endl;
    }else{
        ptr->next=head;
        head=ptr;
        cout<<"Node Added"<<endl;
    }
}

void lastInsert(){
    Node *ptr=NULL,*temp;
    int item;
    ptr=(Node*)malloc(sizeof(Node*));
    cout<<"Enter Value at End : ";
    cin>>item;
    if(head==NULL){
        ptr->next=NULL;
        head=ptr;
        cout<<"Node Added"<<endl;
    }else{
        temp=head;
        while(temp->next!=NULL){    
            temp=temp->next;
        }
        temp->next=ptr;
        ptr->data=item;
        ptr->next=NULL;
        cout<<"Node Added"<<endl;
    }
}

void locInsert(){
    Node *temp,*ptr;
    int loc,item;
    ptr=(Node*)malloc(sizeof(Node*));
    cout<<"Enter Loction after which you want to insert : ";
    cin>>loc;
    cout<<"Enter Element : ";
    cin>>item;
    ptr->data=item;
    if(head==NULL) cout<<"Your list is EMPTY";
    else{
        temp=head;
        for(int i=0;i<loc;i++){
            temp=temp->next;
            if(temp==NULL){
                cout<<"Can't insert the node"<<endl;
                return;
            }
        }
        ptr->next=temp->next;
        temp->next=ptr;
        cout<<"Node inserted"<<endl;

    }
}

void begin_delete()  
{  
    struct node *ptr;  
    if(head == NULL)  
    {  
        printf("\nList is empty\n");  
    }  
    else   
    {  
        ptr = head;  
        head = ptr->next;  
        free(ptr);  
        printf("\nNode deleted from the begining ...\n");  
    }  
}  
void last_delete()  
{  
    struct node *ptr,*ptr1;  
    if(head == NULL)  
    {  
        printf("\nlist is empty");  
    }  
    else if(head -> next == NULL)  
    {  
        head = NULL;  
        free(head);  
        printf("\nOnly node of the list deleted ...\n");  
    }  
          
    else  
    {  
        ptr = head;   
        while(ptr->next != NULL)  
        {  
            ptr1 = ptr;  
            ptr = ptr ->next;  
        }  
        ptr1->next = NULL;  
        free(ptr);  
        printf("\nDeleted Node from the last ...\n");  
    }     
}  
void loc_delete()  
{  
    struct node *ptr,*ptr1;  
    int loc,i;    
    printf("\n Enter the location of the node after which you want to perform deletion \n");  
    scanf("%d",&loc);  
    ptr=head;  
    for(i=0;i<loc;i++)  
    {  
        ptr1 = ptr;       
        ptr = ptr->next;  
              
        if(ptr == NULL)  
        {  
            printf("\nCan't delete");  
            return;  
        }  
    }  
    ptr1 ->next = ptr ->next;  
    free(ptr);  
    printf("\nDeleted node %d ",loc+1);  
}

void display()  
{  
    struct node *ptr;  
    ptr = head;   
    if(ptr == NULL)  
    {  
        printf("Nothing to print");  
    }  
    else  
    {  
        printf("\nprinting values . . . . .\n");   
        while (ptr!=NULL)  
        {  
            printf("\n%d",ptr->data);  
            ptr = ptr -> next;  
        }  
    }  
}     


int main(){
    int ch=0;
    while(ch!=8){
    cout<<"Operations : "<<endl;
    cout<<"1)Insert at Begining\n2)Insert at End\n3)Insert at Given Location\n4)Delete First Element\n5)Delete last Element\n6)Delete at given location\n7)Display\n8)Exit"<<endl;
    cout<<endl<<"Enter your Choice : ";
    cin>>ch;
    switch(ch){
        case 1:
        bigInsert();
        break;
        case 2:
        lastInsert();
        break;
        case 3:
        locInsert();
        break;
        case 4:
        begin_delete();
        break;
        case 5:
        last_delete();
        break;
        case 6:
        loc_delete();
        break;
        case 7:
        display();
        break;
        case 8:
        return 0;
        default:
        cout<<"Wrong choice.";
        }
    }
    return 0;
}