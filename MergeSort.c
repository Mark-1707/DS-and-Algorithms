#include<stdio.h>


void merge(int arr[],int lb,int mid,int ub){
    int i = lb;
    int j = mid+1;
    int k = lb;
    int t;
    int temp[ub+1];

    while (i<=mid && j<=ub){
        if(arr[i]<arr[j]){
            temp[k] = arr[i];
            i++;
        }
        else{
            temp[k] = arr[j];
            j++;
        }
        k++;
    }

    if(i>mid){
        while(j<=ub){
            temp[k] = arr[j];
            k++;
            j++;
        }
    }else{
        while(i<=mid){
            temp[k] = arr[i];
            k++;
            i++;
        }
    }
    
    t = lb;
    while (t<k){
        arr[t] = temp[t];
        t++;
    }
    
    
}

void mergeSort(int arr[],int lb,int ub){
    int mid;
    if(lb<ub){
        mid = (lb+ub)/2;
        mergeSort(arr,lb,mid);
        mergeSort(arr,mid+1,ub);
        merge(arr,lb,mid,ub);
    }
}

int main(){
    int n;
    printf("\nEnter Number of Elements : ");
    scanf("%d",&n);
    int arr[n];
    printf("\nEnter Elements in array : ");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    
    mergeSort(arr,0,n-1);

    printf("\nSorted Array : ");
    for(int i = 0;i<n;i++)
        printf("%d ",arr[i]);
    printf("\n");
}