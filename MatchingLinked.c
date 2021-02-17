/*

!!!Given two linked lists, the task is to check whether the first list is present in 2nd list or not.

Input  : list1 =  10->20
         list2  = 5->10->20
Output : LIST FOUND
Input  : list1 =  1->2->3->4
     	 list2  = 1->2->1->2->3->4
Output : LIST FOUND
Input  : list1 =  1->2->3->4
   	     list2  = 1->2->2->1->2->3
Output : LIST NOT FOUND
*/

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct node{
    int data;
    struct node *next;
}NODE;

NODE *start= NULL;

NODE* create();
bool check(NODE *list1,NODE *list2);
void traverse(NODE *list,char);


int main(){
    NODE *list1 = NULL;
    NODE *list2 = NULL;
    bool status = true;
    list1 = create();
    list2 = create();
    traverse(list1,'1');
    printf("\n");
    traverse(list2,'2'); 
    printf("\n");

    status = check(list1,list2);
    if(status == true)
        printf("List Found\n");
    else
    {
        printf("List Not Found\n");
    }
}

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

bool check(NODE *list1,NODE *list2){
    printf("Status : ");
    NODE *temp1,*temp2;
    temp1 = list1;
    temp2 = list2;
    // while(temp2 != NULL){
    //     if(list1->data == temp2->data){
    //         temp1 = list1;
    //         check = temp2;
    //         while(temp1 != NULL){
    //             temp1 = temp1->next;
    //             check = check->next;
    //              if(temp1->data != check->data){ 
    //                 break;
    //             }
    //             if(temp1->next == NULL){
    //                 return true;
    //             }
    //             if(check->next == NULL)
    //                 return false;
    //         }
    //     }
    //     temp2 = temp2->next;
    // }
    // return false;

    while(temp1 != NULL && temp2 != NULL){
        if(temp1->data == temp2->data){
            temp1 = temp1->next;
            temp2 = temp2->next;
            if(temp1 == NULL)
                return true;
        }else{
            temp1 = list1;
            if(temp1->data != temp2->data)
                temp2 = temp2->next;
            if(temp2 == NULL)
                return false;
        }
    }
}

void traverse(NODE *list,char ch){
    NODE *temp = list;
    printf("Linked List %c = ",ch);
    while(temp != NULL){
        printf("%d ",temp->data);
        temp = temp->next;
    }
}
