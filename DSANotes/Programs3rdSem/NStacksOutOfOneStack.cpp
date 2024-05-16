/*
Check BABBAR's Video
https://youtu.be/lrSXKLmnMV8?si=k00E7A95ZCt-vf32

Basiclly space optimisation can be done by following this 
TOP array stores the top index values of the N stacks
NEXT array stores the next available spot in ARR array index value
NEXT later after updation stores the value of previous top index value so that it can be used for pop operation

*/

#include <bits/stdc++.h> 
class NStack
{
    int *arr;
    int *top;
    int *next;
    int n, s, freespot;
public:
    // Initialize your data structure.
    NStack(int N, int S)
    {
        n=N;
        s=S;
        arr= new int[s];
        next= new int[s];
        top=new int[n];
        freespot=0;
        for(int i=0; i<s-1; i++)next[i]=i+1;
        next[s-1]=-1;
        for(int i=0; i<n; i++)top[i]=-1;

        // Write your code here.
    }

    // Pushes 'X' into the Mth stack. Returns true if it gets pushed into the stack, and false otherwise.
    bool push(int x, int m)
    {
        //check for  overflow
        if(freespot==-1){
            return false;
        }
        else{
            //store available freespot in index
            int index=freespot;
            //update free spot to the next availabe index
            freespot=next[index];
            //store x in arr[index]
            arr[index]=x;
            //update next to store the previous top element index
            //example 1 to -1,  to 1
            //this is used in pop operation
            next[index]=top[m-1];
            //update to to the new element
            //ex: 
            top[m-1]=index;
            return true;
        }
    }

    // Pops top element from Mth Stack. Returns -1 if the stack is empty, otherwise returns the popped element.
    int pop(int m)
    {
        if(top[m-1]==-1){
            return -1;
        }
        else{
            //reverse of push operation
            int index=top[m-1];
            top[m-1]=next[index];
            next[index]=freespot;
            freespot=index;
            return arr[index];
        }
        
    }
};