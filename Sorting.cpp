#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,temp;
    cout<<"Enter size of Array : ";
    cin>>n;
    int arr[n];
    cout<<"Enter"<<n<<"Elements : "<<endl;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    for(int i =0;i<n;i++){
        for(int j=i+1;j<n;j++){
           if(arr[i]>arr[j]){
           temp = arr[i];
           arr[i] = arr[j];
           arr[j] = temp; 
           }
        }
    }
    cout<<"\nSorted elements : "<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}