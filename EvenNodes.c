/*
1.Move even nodes of the linked list at the end of linked list 
in reverse order For example, 
if the linked list is 1,3,2,6,8,9,11 then output list shall be 1,2,8,11,9,6,3
*/

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct node{
    int data;
    struct node *next;
}NODE;

NODE *start = NULL;

NODE* create(){
    printf("Enter Elements in Linked list (To exit press 0): ");
    start = NULL;
    int ele=1;
    NODE *temp = NULL;
    while(ele!=0){
        NODE *ptr = (NODE*)malloc(sizeof(NODE));
        scanf("%d",&ele);
        if(ele == 0){
            free(ptr);
            break;
        }
        if(start == NULL){
            ptr->data = ele;
            ptr->next = NULL;
            start = ptr;
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
    return start;
}