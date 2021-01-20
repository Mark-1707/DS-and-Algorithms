#include<stdio.h>

void swap(int *p1,int *p2){
    int temp = *p1;
    *p1 = *p2; 
    *p2 = temp;
}

void selectionSort(int arr[],int n){
    int min,j=0;
    for(int i=0;i<n;i++){
        min = i;
        for(int j=i;j<n;j++){
            if(arr[j]<arr[min])
                min = j;
        }
        swap(&arr[i],&arr[min]);
    }
}

int main(){
    int n;
    printf("\nEnter Number of Elements : ");
    scanf("%d",&n);
    int arr[n];
    printf("Enter Elements : ");
    for(int i=0;i<n;i++)
        scanf("%d",&arr[i]);
    
    selectionSort(arr,n);

    printf("\nSorted Array : ");
    for(int i=0;i<n;i++)
        printf("%d ",arr[i]);
    printf("\n");
}