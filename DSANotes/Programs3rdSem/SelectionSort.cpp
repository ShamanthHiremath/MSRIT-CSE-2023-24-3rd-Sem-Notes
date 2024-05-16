#include <bits/stdc++.h> 

void selectionSort(vector<int>& arr, int n)
{   //Pusing the lighter elements to the start
    for(int i=0;i<n-1;i++){
        int smallest=i;
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[smallest]){
                smallest=j;
            }
        }
        swap(arr[smallest],arr[i]);
    }
    // return arr;
}
void selectionSort(vector<int>& arr, int n)
{   //Pusing the lighter elements to the start
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(arr[i]>arr[j]){
                swap(arr[i],arr[j]);
            }
        }
    }
    // return arr;
}