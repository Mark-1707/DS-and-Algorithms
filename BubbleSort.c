#include<stdio.h>
#include<stdlib.h>

void swap(int *s1,int *s2){
    int temp = *s1;
    *s1 = *s2;
    *s2 = temp;
}

void BubbleSort(int arr[],int n){
    int i=0;
    while(i<n-1){
        int init = 0;
        for(int j=init+1;j<n;j++){
            if(arr[init]>arr[j])
                swap(&arr[init],&arr[j]);
            init++;
        }
        /*printf("\n Pass %d ",i+1);
        for(int k=0;k<n;k++)
            printf("%d ",arr[k]);*/
        
        i++;
    }
}

int main(){
    int n;
    printf("\nEnter No. of elements : ");
    scanf("%d",&n);
    int arr[n];
    printf("\nEnter Elements in array : ");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    BubbleSort(arr,n);
    printf("\nSorted Array : ");
    for(int i=0;i<n;i++)
        printf("%d ",arr[i]);
}