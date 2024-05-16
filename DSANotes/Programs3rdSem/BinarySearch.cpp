#include<iostream>
using namespace std;

int binarysearch(int arr[], int key, int s=0, int n=arr.size()){
    int s=0,e=n,mid=s+(e-s)/2;
    while(s<=e){
        if(arr[mid]==key){
            return mid;
        }
        if(arr[mid]<key){
            s=mid+1;
        }
        else{
            e=mid-1;
        }
        mid=s+(e-s)/2;
    }
    return -1;

}
