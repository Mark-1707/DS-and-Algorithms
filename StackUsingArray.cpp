#include<bits/stdc++.h>
using namespace std;

int Stack[100],n,top=-1;

void push();
void pop();
void show();

int main(){
    cout<<"Enter number of elements in Stack : ";
    cin>>n;
    int ch=0;
    while(ch!=4){
        cout<<"Enter Your Choice : "<<endl;
        cout<<"1) PUSH"<<endl<<"2) POP"<<endl<<"3) SHOW"<<endl<<"4) Exit"<<endl;
        cin>>ch;
        switch(ch){
            case 1:
            push();
            break;
            case 2:
            pop();
            break;
            case 3:
            show();
            break;
            case 4:
            break;
            default:
            cout<<"Enter valid Choice"<<endl;
        }
    }
    return 0;
}

void push(){
    int val;
    if(top==n-1)
        cout<<"Overflow"<<endl;
    else {
        cout<<"Enter Element : "<<endl;
        cin>>val;
        top++;
        Stack[top]=val;
    }
}

void pop(){
    if(top==-1)
        cout<<"Stack is Empty"<<endl;
    else{
        top--;
    }
}

void show(){
    for(int i=top;i>0;i--){
        cout<<Stack[i]<<" ";
    }
    if(top==-1)
        cout<<"Stack is Empty";
}