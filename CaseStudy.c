#include<stdio.h>
#include<stdlib.h>
#include <string.h>

typedef struct score{
    int marks[4];
    struct score *next1;
}scores;

typedef struct info{
    char fname[20],lname[20];
    struct info *next;
    scores *scoreptr;
    int total=0;
    float average=0;
}node_info;

node_info *head = NULL;
scores *head1 = NULL;

void student_info(char fname[20],char lname[20]){
    node_info *ptr=NULL,*temp;
    ptr = (node_info*)malloc(sizeof(node_info));
    if(head == NULL){
        ptr->next = NULL;
        head = ptr;
        strcpy(ptr->fname,fname);
        strcpy(ptr->lname,lname);
        //printf("Enter marks of %s %s : ",ptr->fname,ptr->lname);
        return;
    }else{
        temp = head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = ptr;
        strcpy(ptr->fname,fname);
        strcpy(ptr->lname,lname);
        //printf("Enter marks of %s %s : ",ptr->fname,ptr->lname);
        ptr->next = NULL;
        return;
    }
}

void mark(node_info *ptr){
    int sum=0;
    scores *ptr1,*temp1;
    ptr1 = (scores*)malloc(sizeof(scores));
    printf("Enter Marks of %s %s\n",ptr->fname,ptr->lname);
    if(head1==NULL){
        ptr1->next1=NULL;
        head1 = ptr1;
        for(int i=0;i<4;i++){
            scanf("%d",&ptr1->marks[i]);
            ptr->total = ptr->total + ptr1->marks[i];
        }
        ptr->average = ptr->total/4;
    }else{
        temp1 = head1;
        while (temp1 ->next1!=NULL){
            temp1 = temp1->next1;
        }
        //temp1->next1=ptr1;
        for(int i=0;i<4;i++){
            scanf("%d",&temp1->marks[i]);
            ptr->total = ptr->total + temp1->marks[i];
        }
        temp1->next1=ptr1;
        ptr->average = ptr->total/4;
        ptr1->next1=NULL;
    }
    ptr->scoreptr=ptr1;
}

void display(){
    node_info *ptr;
    ptr = head;
    while(ptr->next!=NULL){
        mark(ptr);
        ptr=ptr->next;
    }
    ptr = head;
    while(ptr->next!=NULL){
        printf("\nMarks of %s %s",ptr->fname,ptr->lname);
        printf("\nTotal : %d\nAverage : %f",ptr->total,ptr->average);
        printf("\n---------------------------------------------------------------------\n");
        ptr=ptr->next;
    }
}

int main(){
    FILE *fptr = fopen("name.txt","r") ;
    char fname[20] = "name.txt";
    node_info *p = (node_info*)malloc(sizeof(node_info));
    while(!feof(fptr)){
    fscanf(fptr, "%s %s" ,p->fname,p->lname);
    student_info(p->fname,p->lname);
    }
    fclose(fptr);
    display();
}