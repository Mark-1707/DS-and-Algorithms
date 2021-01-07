/*
    1.Construct a linked list by merging alternate nodes of two linked list
    For example, if given linked list are 1,9,3 and 6,11,5 
    then output list shall be 1,6,9,11,3,5
*/

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct node{
    int data;
    struct node *next;
}NODE;

NODE *start= NULL;
//Node2 * = NULL;

NODE* create();
NODE* merge(NODE *list1,NODE *list2);
void traverse(NODE *list,char);


int main(){
    NODE *list1 = NULL;
    NODE *list2 = NULL;
    NODE *mergedList = NULL;
    char ch;

    list1 = create();
    list2 = create();

    if(list1 == NULL && list2 == NULL){
        printf("Merge Cant be Performed");
        return 0;
    }
    traverse(list1,'1');
    printf("\n");
    traverse(list2,'2');

    mergedList = merge(list1,list2); 
    printf("\n");
    traverse(mergedList,'3');

}

NODE* create(){
    printf("Enter Elements in Linked list (To exit press 0): ");
    NODE *list = NULL;
    start = NULL;
    int ele=1;
    NODE *temp = NULL;
    while(ele!=0){
        NODE *ptr = (NODE*)malloc(sizeof(NODE));
        scanf("%d",&ele);
        if(ele == 0)
            break;
        if(start == NULL){
            ptr->data = ele;
            ptr->next = NULL;
            start = ptr;
            list = start;
        }else{
            temp = start;
            while(temp->next != NULL){
                temp = temp->next;
            }
            temp->next = ptr;
            ptr->data = ele;
            ptr->next = NULL;
        }
    }
    return list;
}

NODE* merge(NODE *list1,NODE *list2){
    printf("\nList Aftre Merging : ");
    NODE *start = NULL;
    NODE *temp1 = list1;
    NODE *temp2 = list2;
    NODE *p,*q;
    start = temp1;
    if(list1 == NULL && list2 != NULL){
        temp1 = temp2;
        return temp2;
    }else if(list2 == NULL && list1 != NULL){
        return temp1;
    }else
    while(temp1->next != NULL && temp2->next != NULL){
        p = temp1->next;
        q = temp2->next;

        temp1->next = temp2;
        temp2->next = p;

        temp1 = p;
        temp2 = q;
    }
    temp1->next = temp2;
    return start;
}

void traverse(NODE *list,char ch){
    if(list == NULL){
        printf("List is Empty\n");
        return;
    }
    NODE *temp = list;
    printf("Linked List %c = ",ch);
    while(temp != NULL){
        printf("%d ",temp->data);
        temp = temp->next;
    }
}