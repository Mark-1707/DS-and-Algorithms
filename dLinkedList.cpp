#include<bits/stdc++.h>
using namespace std;

typedef struct node{
    struct node *prev;
    int data;
    struct node *next;
}Node;

Node *head=NULL;

void bigInsert(){
    Node *ptr;
    int item;
    ptr = (Node*)malloc(sizeof(Node*));
    cout<<"Enter value at Begining : ";
    cin>>item;
    if(head==NULL){
        ptr->prev=NULL;
        ptr->data=item;
        ptr->next=NULL;
        head=ptr;
    }else{
        ptr->data=item;
        ptr->prev=NULL;
        ptr->next=head;
        head=ptr;
    }
    cout<<"Node Inserted"<<endl<<endl;
}

void lastInsert(){
    Node *ptr,*temp;
    int item;
    ptr=(Node*)malloc(sizeof(Node*));
    cout<<"Enter Element";
    cin>>item;
    if(head==NULL){
        ptr->next=NULL;
        ptr->data=item;
        ptr->next=NULL;
        head=ptr;
    }else{
        temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=ptr;
        ptr->prev=temp;
        ptr->data=item;
        ptr->next=NULL;
    }
    cout<<"Node Inserted"<<endl<<endl;
}

void locInsert(){
    Node *ptr,*temp;
    int item,loc;
    ptr=(Node*)malloc(sizeof(Node*));
    if(head==NULL){
        cout<<"List is Empty";
        return;
    }else{
        temp=head;
        cout<<"Enter Location : ";
        cin>>loc;
        for(int i=0;i<loc;i++){
            temp=temp->next;
            if(temp==NULL){
                cout<<"Can't insert  Node ";
                return;
            }
        }
        cout<<"Enter Element : ";
        cin>>item;
        ptr->data=item;
        ptr->next=temp->next;
        ptr->prev=temp;
        temp->next=ptr;
        temp->next->prev=ptr;
    }
    cout<<"Node Inserted"<<endl<<endl;
}

void begin_delete(){
    Node *ptr;
    if(head==NULL) {
        cout<<"List is Empty"<<endl<<endl;
        return;
    }else if(head->next==NULL){
        free(head);
        cout<<"Only Element from list is Deleted"<<endl<<endl;
        return;
    }else{
        ptr=head;
        head=head->next;
        head->prev=NULL;
        free(ptr);
        cout<<"Firs Node is Deleted"<<endl<<endl;
    }
}

void last_delete(){
    Node *ptr,*ptr1;
    if(head==NULL) {
        cout<<"List is Empty"<<endl<<endl;
        return;
    }else if(head->next==NULL){
        free(head);
        cout<<"Only Element from list is Deleted"<<endl<<endl;
        return;
    }else{
        ptr1=head;
        while(ptr1->next!=NULL){
            ptr1=ptr1->next;
        }
        ptr1->prev->next=NULL;
        free(ptr1);
        cout<<"Last Node is Deleted"<<endl<<endl;
    }
}

void loc_delete(){
    Node *ptr, *temp,*ptr1;  
    int val;  
    cout<<" Enter the data after which the node is to be deleted :";  
    cin>>val;  
    ptr = head;
    while(ptr -> data != val){
        ptr1=ptr;  
        ptr = ptr -> next;
    }
    if(ptr -> next == NULL)  
    {  
        cout<<"Can't delete"<<endl<<endl;  
    }  
    else if(ptr -> next -> next == NULL)  
    {  
        ptr ->next = NULL;  
    }  
    else  
    {   
        temp=ptr;
        ptr1->next=temp->next;
        ptr1->next->prev=ptr1;
        free(temp);
        cout<<"node deleted"<<endl<<endl;
    }     
}

void display()  
{  
    struct node *ptr;  
    cout<<" printing values...";  
    ptr = head;  
    while(ptr != NULL)  
    {  
        cout<<"  "<<ptr->data;  
        ptr=ptr->next;  
    }  
} 

int main(){
    int ch;
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
}