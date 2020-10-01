#include<bits/stdc++.h>
using namespace std;

int front=-1,rear=-1;
int arr[100];

void Insert(int);
void Delete(int);
void Display(int);

int main(){
    int max,ch=0;
    cout<<"Enter size of Queue : ";
    cin>>max;
    while(ch!=4){
        cout<<"Enter Choice : "<<endl;
        cout<<"1)Insert Element"<<endl<<"2)Delete Element"<<endl<<"3)Display"<<endl<<"4)Exit"<<endl;
        cin>>ch;
        switch (ch)
        {
        case 1:
            Insert(max);
            break;
        case 2:
            Delete(max);
            break;
        case 3:
            Display(max);
            break;
        case 4:
            break;
        default:
            cout<<"Enter valid choice"<<endl;
            break;
        }
    }
}

void Insert(int max){
    int item;
    if(rear==max-2){
        cout<<"Overflow"<<endl;
        return;
    }else if(front==-1&&rear==-1){
        cout<<"Enter Element : ";
        cin>>item;
        front=0;
        rear=0;
    }else{
        cout<<"Enter Element : ";
        cin>>item;
        rear=rear+1;
    }
    arr[rear]=item;
}

void Delete(int max){
    int item;
    if(front==-1||front>rear){
        cout<<"Underflow"<<endl;
        return;
    }else{
        item=arr[rear];
        if(front==rear){
            front=-1;
            rear=-1;
        }else{
            front=front+1;
        }
    }
}

void Display(int max){
    if(rear==-1){
        cout<<"Queue is Empty.";
        return;
    }else{
        cout<<"Values : ";
        for(int i=front;i<=rear;i++){
            cout<<arr[i];
        }
    }
}