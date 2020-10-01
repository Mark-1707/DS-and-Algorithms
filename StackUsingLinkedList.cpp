#include<bits/stdc++.h>
using namespace std;

typedef struct node{
    int value;
    struct node *next;
}Node;

Node *head=NULL;

void push();
void pop();
void display();

int main(){
    int choice=0;     
    cout<<"Stack operations using linked list"<<endl;  
    while(choice != 4)  
    {  
        cout<<"Choose one from the below options : "<<endl;  
        cout<<"1.Push"<<endl<<"2.Pop"<<endl<<"3.Show"<<endl<<"4.Exit"<<endl;  
        cout<<" Enter your choice"<<endl;        
        cin>>choice;  
        switch(choice)  
        {  
            case 1:  
            {   
                push();  
                break;  
            }  
            case 2:  
            {  
                pop();  
                break;  
            }  
            case 3:  
            {  
                display();  
                break;  
            }  
            default:  
            {  
                cout<<"Please Enter valid choice"<<endl;  
            }   
        }  
    } 
}

void push(){
    Node *ptr;
    int item;
    ptr=(Node*)malloc(sizeof(Node*));
    if(ptr==NULL){
        cout<<"Can't add Element"<<endl;
    }else{
        cout<<"Enter Item : ";
        cin>>item;
        ptr->value=item;
        if(head==NULL){
            ptr->next=NULL;
            head=ptr;
        }else{
            ptr->next=head;
            head=ptr;
        }
    }
}

void pop(){
    Node *ptr;
    int item;
    if(head==NULL){
        cout<<"Stack Underflow.";
    }else{
        item=head->value;
        ptr=head;
        head=ptr->next;
        free(ptr);
    }
}

void display(){
    Node *ptr;
    ptr=head;
    if(head==NULL){
        cout<<"Stack is Empty"<<endl;
    }else{
        while(ptr!=NULL){
            cout<<ptr->value<<" ";
            ptr=ptr->next;
        }
    }
}