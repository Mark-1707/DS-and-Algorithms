#include<bits/stdc++.h>  
using namespace std; 
struct node   
{  
    int data;  
    struct node *next;   
};  
struct node *head;  
  
void beginsert ();   
void lastinsert ();  
void randominsert();  
void begin_delete();  
void last_delete();  
void random_delete();  
void display();  
void search();  
int main ()  
{  
    int choice =0;  
    while(choice != 7)   
    {  
        cout<<"*********Main Menu*********"<<endl;  
        cout<<"Choose one option from the following list ..."<<endl;  
        cout<<"==============================================="<<endl;  
        cout<<"1.Insert in begining\n2.Insert at last\n3.Delete from Beginning\n4.Delete from last\n5.Search for an element\n6.Show\n7.Exit"<<endl;  
        cout<<"Enter your choice?"<<endl;         
        cin>>choice;  
        switch(choice)  
        {  
            case 1:  
            beginsert();      
            break;  
            case 2:  
            lastinsert();         
            break;  
            case 3:  
            begin_delete();       
            break;  
            case 4:  
            last_delete();        
            break;  
            case 5:  
            search();         
            break;  
            case 6:  
            display();        
            break;  
            case 7:  
            exit(0);  
            break;  
            default:  
            cout<<"Please enter valid choice :";  
        }  
    }  
    return 0;
}  
void beginsert()  
{  
    struct node *ptr,*temp;   
    int item;   
    ptr = (struct node *)malloc(sizeof(struct node));  
    if(ptr == NULL)  
    {  
        cout<<"OVERFLOW";  
    }  
    else   
    {  
        cout<<"Enter the node data : ";  
        cin>>item;  
        ptr -> data = item;  
        if(head == NULL)  
        {  
            head = ptr;  
            ptr -> next = head;  
        }  
        else   
        {     
            temp = head;  
            while(temp->next != head)  
                temp = temp->next;  
            ptr->next = head;   
            temp -> next = ptr;   
            head = ptr;  
        }   
        cout<<"node inserted"<<endl;  
    }  
              
}  
void lastinsert()  
{  
    struct node *ptr,*temp;   
    int item;  
    ptr = (struct node *)malloc(sizeof(struct node));  
    if(ptr == NULL)  
    {  
        cout<<"OVERFLOW"<<endl;  
    }  
    else  
    {  
        cout<<"Enter Data : ";  
        cin>>item;  
        ptr->data = item;  
        if(head == NULL)  
        {  
            head = ptr;  
            ptr -> next = head;    
        }  
        else  
        {  
            temp = head;  
            while(temp -> next != head)  
            {  
                temp = temp -> next;  
            }  
            temp -> next = ptr;   
            ptr -> next = head;  
        }  
          
        cout<<"node inserted"<<endl;  
    }  
  
}  
  
void begin_delete()  
{  
    struct node *ptr;   
    if(head == NULL)  
    {  
        cout<<"UNDERFLOW";    
    }  
    else if(head->next == head)  
    {  
        head = NULL;  
        free(head);  
        cout<<"node deleted"<<endl;  
    }  
      
    else  
    {   ptr = head;   
        while(ptr -> next != head)  
            ptr = ptr -> next;   
        ptr->next = head->next;  
        free(head);  
        head = ptr->next;  
        cout<<"node deleted"<<endl;  
  
    }  
}  
void last_delete()  
{  
    struct node *ptr, *preptr;  
    if(head==NULL)  
    {  
        cout<<"UNDERFLOW";  
    }  
    else if (head ->next == head)  
    {  
        head = NULL;  
        free(head);  
        cout<<"node deleted"<<endl;  
  
    }  
    else   
    {  
        ptr = head;  
        while(ptr ->next != head)  
        {  
            preptr=ptr;  
            ptr = ptr->next;  
        }  
        preptr->next = ptr -> next;  
        free(ptr);  
        cout<<"node deleted"<<endl;  
  
    }  
}  
  
void search()  
{  
    struct node *ptr;  
    int item,i=0,flag=1;  
    ptr = head;   
    if(ptr == NULL)  
    {  
        cout<<"Empty List"<<endl;  
    }  
    else  
    {   
        cout<<"Enter item which you want to search :"<<endl;   
        cin>>item;  
        if(head ->data == item)  
        {  
        cout<<"item found at location "<<i+1;  
        flag=0;  
        }  
        else   
        {  
        while (ptr->next != head)  
        {  
            if(ptr->data == item)  
            {  
                cout<<"item found at location : "<<i+1;  
                flag=0;  
                break;  
            }   
            else  
            {  
                flag=1;  
            }  
            i++;  
            ptr = ptr -> next;  
        }  
        }  
        if(flag != 0)  
        {  
            cout<<"Item not found"<<endl;  
        }  
    }     
          
}  
  
void display()  
{  
    struct node *ptr;  
    ptr=head;  
    if(head == NULL)  
    {  
        cout<<"nothing to print";  
    }     
    else  
    {  
        cout<<" printing values ... "<<endl;  
          
        while(ptr -> next != head)  
        {  
          
            cout<<"\n"<< ptr -> data;  
            ptr = ptr -> next;  
        }  
        cout<<"\n"<< ptr -> data;  
    }  
              
}  