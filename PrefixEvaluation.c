#include <stdio.h>
#include<string.h>

int array2[50],front=-1,rear=-1,i,x,j=1,operand1,operand2,result,result1=0,count=0;
char queue[50],exp[50];

void enqueuechar(char c);
void check(char c1,char c2,char c3);
int operation(char op,int operand1,int operand2);
void enqueueint(int integer);
void dequeue();

int main(){
  printf("\nEnter the Prefix Expression:");
  scanf("%s",exp);
  
  for(i=0;exp[i]!='\0';i++){
    enqueuechar(exp[i]);
  }
  queue[i]='\0';
  
  for(i=0;queue[i]!='\0';i++) {
     count++;  
  }  
 while(count!=1){
    rear=-1;
    front=-1;
    for(i=0;queue[i]!='\0';i++){ 
      check(queue[i],queue[i+1],queue[i+2]);
      
      if(x==1){
        enqueuechar(queue[i]);
      }
        else{
        operand1=array2[i+1];
        operand2=array2[i+2];
        
        result=operation(queue[i],operand1,operand2);
        
        enqueueint(result); 
        
        i=i+2;
      }   
      
    }
    enqueuechar('\0');
    printf("\nAfter %d scan,we have\n",j);
    j++;
    count=0; 
    for(i=0;queue[i]!='\0';i++) {
     dequeue();
     count++;  
    }  
    printf("\n");
  }
  printf("\nResult of Prefix Expression:%d\n",array2[0]);
  return 0;
}


void enqueuechar(char c){
  if(rear==49)
     printf("\nQueue Overflow");
  else{
     if(front==-1 && rear==-1){
       front=front+1;
       rear=rear+1;
     }
     
     else{
       rear=rear+1;
     }
     
     queue[rear]=c;
     if(queue[rear]!='+' && queue[rear]!='-' && queue[rear]!='*' && queue[rear]!='/' && queue[rear]!='\0'){ 
        array2[rear]=c-48;       
      }
   }
}

void enqueueint(int integer){
  if(rear==49)
     printf("\nQueue Overflow");
  else{
     if(front==-1 && rear==-1){
       front=front+1;
       rear=rear+1;
     }
     
     else{
       rear=rear+1;
     }
     
     queue[rear]=integer;
     if(queue[rear]!='+' && queue[rear]!='-' && queue[rear]!='*' && queue[rear]!='/' && queue[rear]!='\0'){ 
        array2[rear]=integer;       
      }
   }
}

void dequeue(){
  if(front==-1)
     printf("\nQueue Underflow");
  else{
     if(queue[front]!='+' && queue[front]!='-' && queue[front]!='*' && queue[front]!='/' && queue[front]!='\0'){ 
        printf("%d\t",array2[front]);       
      }
      else{
        printf("%c\t",queue[front]);
      }
     front+=1;
     if(front>rear){
       front=-1;
       rear=-1;
     }
    }
}

void check(char c1,char c2,char c3){
  x=0;
  
  if(c2=='\0')
     x=1;
    
     
  if(c1!='+' && c1!='-' && c1!='*' && c1!='/') 
     x= 1;
     
  else{
    if(c2=='+' || c2=='-'|| c2=='*'|| c2=='/')
       x=1;
       
    else{
      if(c3=='+' || c3=='-'|| c3=='*'|| c3=='/')
         x=1;
    }
  }  
  
}


int operation(char op,int operand1,int operand2){
  switch(op){
    case '+':
             result1=operand1+operand2;
             break;
             
    case '-':
             result1=operand1-operand2;
             break;   
             
    case '*':
             result1=operand1*operand2;
             break;
             
    case '/':
             result1=operand1/operand2;
             break;  
             
    default:
            printf("\nOperation cannot be performed");                     
             
  }
  
  return result1;
}