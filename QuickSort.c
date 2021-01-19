#include<stdio.h>

void swap(int *p1,int *p2){
    int temp = *p1;
    *p1 = *p2; 
    *p2 = temp;
}

int partition(int arr[],int lb,int ub){
    int pivot = arr[lb];
    int start = lb;
    int end = ub;
    while(start<end){
        while (arr[start]<=pivot){
           start++;
        }
        
        while (arr[end]>pivot){
            end--;
        }
        if(start<end)
            swap(&arr[start],&arr[end]);
    }
    swap(&arr[lb],&arr[end]);
    return end;
}

void quickSort(int arr[],int start,int end){
    int loc;
    if(start < end){
        loc = partition(arr,start,end);
        quickSort(arr,start,loc-1);
        quickSort(arr,loc+1,end);
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
        
    quickSort(arr,0,n-1);

    printf("\nSorted Array : ");
    for(int i=0;i<n;i++)
        printf("%d ",arr[i]);
    printf("\n");
}