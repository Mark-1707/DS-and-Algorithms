#include<bits/stdc++.h>
using namespace std;

typedef struct exp1{
    int coefficient1;
    int power1;
    struct exp1 *next1;
    
}Exp1;

typedef struct exp2{
    int coefficient2;
    int power2;
    struct exp2 *next2;
}Exp2;

Exp1 *head1=NULL;
Exp2 *head2=NULL; 

void inputExp1(int coeff,int pow){
    Exp1 *p = (Exp1*)malloc(sizeof(Exp1*));
    Exp1 *temp=NULL;
    if(head1 == NULL){
         p->coefficient1 = coeff;
         p->power1 = pow;
         head1 = p;
         p->next1 = NULL;
         return;
     }else{
        temp = head1;
         while(temp->next1 != NULL){
             temp = temp->next1;
         }
        temp->next1 = p;
        p->coefficient1 = coeff;
        p->power1 = pow;
        p->next1 = NULL;
        return;
    }
}

void inputExp2(int coeff,int pow){
    Exp2 *p = (Exp2*)malloc(sizeof(Exp2*));
    Exp2 *temp=NULL;
    if(head2 == NULL){
         p->coefficient2 = coeff;
         p->power2 = pow;
         head2 = p;
         p->next2 = NULL;
         return;
     }else{
        temp = head2;
         while(temp->next2 != NULL){
             temp = temp->next2;
         }
        temp->next2 = p;
        p->coefficient2 = coeff;
        p->power2 = pow;
        p->next2 = NULL;
        return;
    }
}

void display1(){
    Exp1 *p = NULL,*temp;
    temp = head1;
    while(temp->next1 != NULL){
        cout<<temp->coefficient1<<"X^"<<temp->power1;
        temp = temp->next1;
        if(temp->next1 != NULL)
            cout<<"+";
    }
    cout<<endl;
}

void display2(){
    Exp2 *p = NULL,*temp;
    temp = head2;
    while(temp->next2 != NULL){
        cout<<temp->coefficient2<<"X^"<<temp->power2;
        temp = temp->next2;
        if(temp->next2 != NULL)
            cout<<"+";
    }
    cout<<endl;
}

void add(){
    Exp1 *p,*temp1;
    Exp2 *q,*temp2;
    temp1=head1;
    while(temp1->next1 != NULL){
        temp2=head2;
        while(temp2->next2 != NULL){
            if(temp1->power1==temp2->power2){
                temp1->coefficient1=temp1->coefficient1+temp2->coefficient2;
            }
            temp2 = temp2->next2;
        }
        temp1 = temp1->next1;
    }
    display1();
}

int main(){
    int coeff,pow;
    char stat='+';
    cout<<"Enter First Expression : "<<endl;
    while(stat == '+'){
        cin>>coeff;
        cout<<"X^";
        cin>>pow;
        cin>>stat;
        inputExp1(coeff,pow);
        if(stat!='+')
            inputExp1(0,0);
    }

    stat='+';
    cout<<"Enter Second Expression : "<<endl;
    while(stat == '+'){
        cin>>coeff;
        cout<<"X^";
        cin>>pow;
        cin>>stat;
        inputExp2(coeff,pow);
        if(stat!='+')
            inputExp2(0,0);
    }

    cout<<"Polynomial 1 : ";
    display1();
    cout<<"Polynomial 2 : ";
    display2();
    cout<<"Addition : ";
    add();
}