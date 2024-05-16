#include<bits/stdc++.h>

#include<iostream>
using namespace std;

int main(){
    string s1="abcdefghi";
    string s2="hi";
    int n1=s1.size();
    int n2=s2.size();
    for(int i=0; i<=n1-n2; i++){
        if(s1[i+n2-1]==s2[n2-1]){
            int k=i;
            int j=0;
            for(; j<n2; j++){
                if(s1[k]==s2[j]){
                    k++;
                    // j++;
                }
                else{
                    break;
                }
            }
            if(j == n2){
                cout<<"THE SUBSTR IS FOUND AT "<<i<<" position";
                // exit();
                return 0;
            }
        }
    }
    cout<<"NOT FOUND BIATCH";

 return 0;
}