#include<stdio.h>

void insertionSort(int arr[],int n){
    int j,temp;
    for(int i=1;i<n;i++){
        temp = arr[i];
        j = i-1;
        while(j>=0 && temp<= arr[j]){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = temp;
    }
}

int main(){
    int n;
    printf("\nEnter Number of elements : ");
    scanf("%d",&n);
    int arr[n];
    printf("\nEnter Elements in array : ");
    for(int i=0;i<n;i++)
        scanf("%d",&arr[i]);
    
    insertionSort(arr,n);

    printf("\nSorted Array : ");
    for(int i=0;i<n;i++)
        printf("%d ",arr[i]);
    printf("\n");
}