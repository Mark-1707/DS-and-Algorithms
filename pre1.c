/*
Prefix Evaluation
One way to evaluate a prefix expression is to use a queue. To evaluate the expression, scan it repeatedly until you know the final expression value. In each scan read the tokens and store them in a queue. In each scan replace an operator that is followed by two operands with their calculated values.
For example, the following expression is a prefix expression that is evaluated to 159:
- + * 9 + 2 8 * + 4 8 6 3
We scan the expression and store it in a queue. During the scan when an operator is followed by two operands, such as + 2 8, we put the result, 10, in the queue.
After the first scan, we have
- + * 9 10 * 12 6 3
After the second scan, we have
- + 90 72 3
After the third scan, we have
- 162 3
After the fourth scan, we have
159
*/

#include <stdio.h>
#include <stdlib.h>
#include<ctype.h>
#include <string.h>
typedef struct node
{
    char data[16];
    struct node *link;
} NODE;
typedef struct queue
{
    NODE *front;
    NODE *rear;
    int count;
} QUEUE;
QUEUE* CreateQueue()
{
    QUEUE* q = (QUEUE*)malloc(sizeof(QUEUE));  
    q->front = NULL;                           
    q->rear = NULL;                            
    q->count = 0;                              
    return q;
}
void Enqueue(QUEUE *q, char* dataIn)
{
    NODE *newNode = (NODE*)malloc(sizeof(NODE));   
    strcpy(newNode->data, dataIn);                 
    newNode->link = NULL;
    if (q->front == NULL)
        q->front = newNode;                        
    else
        q->rear->link = newNode;
    q->rear = newNode;
    //printf(" New node is %s", dataIn);
    q->count++;                            
}
void Dequeue(QUEUE *q, char *dataOut)
{
    NODE *temp = q->front;
    strcpy(dataOut, q->front->data);    
    if (q->count == 1)                  
        q->rear = NULL;                 
    q->front = q->front->link;          
    q->count--;                         
    free(temp);
}
int QueueCount(QUEUE *q)
{
    return q->count;         
}
void Display(QUEUE *q)
{
    NODE *pLoc = q->front; // first node
    printf("\n");
    printf("expression: ");
    while (pLoc != NULL)
    {
        printf("%s ", pLoc->data);
        pLoc = pLoc->link;
    }    
}
void DestroyQueue(QUEUE *q)
{
    NODE *temp;
    while (q->front != NULL)
    {
        temp = q->front;
        q->front = q->front->link;
        free(temp);
    }
    free(q);
}
int calculate(char a, int b, int c)
{
    
    if(a=='+')
        return (b+c);
    
    else if(a=='-')
        return (b-c);
    else if(a=='*')
        return (b*c);
    else if(a=='/')
        return (b/c);
    else
        return -1;
}
void stringcopy(char data1[],char* dataptr)
{
    int i=0;
    while(*dataptr!='\0')
    {
        data1[i]=*dataptr;
        dataptr++;
        i++;
    }
    data1[i]='\0';
}
int calculateExpression(QUEUE *q)
{
    char data[16], data1[16],data2[16],temp_opr, temp_op1, temp_op2, *dataptr;
    int i, operand1, operand2, value;
    while ((QueueCount(q)!=1)){ 
        Dequeue(q, data);
        temp_opr=data[0];
   if(ispunct(temp_opr))// if temp_opr is punctuation '+' or '_' or '*' or '/'
   {
    dataptr=q->front->data;//data pointer is pointing to the 2nd data in the queue
    temp_op1=*dataptr;
    stringcopy(data1,dataptr); // copies the string pointed by dataptr to data1
            
    dataptr=q->front->link->data;
    temp_op2=*dataptr;      //data pointer is poiting to the 3rd data in the queue
    stringcopy(data2,dataptr); // copies the string pointed by dataptr to data2
     if(!ispunct(temp_op1)&&!ispunct(temp_op2))
            {
                
                operand1= atoi (data1);      
                operand2= atoi (data2);       
                Dequeue(q, data1);   
                Dequeue(q, data2);   
                value=calculate(temp_opr,operand1, operand2);
                printf (" \n\nafter calculating %d %c %d = %d\n",operand1,temp_opr,operand2,value);
                // itoa (value, data, 10);      
                sprintf(data,"%d",value);
                dataptr=data;
                   Enqueue(q, dataptr);  
                Display(q);
            }
            else
            {
                dataptr=data;                   
                Enqueue(q, dataptr);   
                Display(q);
            }
        }
        else
        {
            dataptr=data;
            Enqueue(q, dataptr); 
            Display(q);
        }     
    }
    Dequeue(q, data);  
    return atoi(data); 
}
int main()
{
    char expr[128] = "- + * 9 + 2 8 * + 4 8 6 3";
    char *token;
    int finalvalue;
    QUEUE *q = CreateQueue();   
    token = expr;
    while ((token = strtok(token, " ")))
    {
        Enqueue(q, token);
        token = NULL;
    }
    finalvalue=calculateExpression(q);
    printf("\n\n value of the expression %d", finalvalue);    
    DestroyQueue(q);  
}