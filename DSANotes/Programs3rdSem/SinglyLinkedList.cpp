//#include<bits/stdc++.h>

#include<iostream>
using namespace std;
class Node{
    public:
        int data;
        Node* next;
        Node(int data){
            this->data=data;
            this->next=NULL;
        }
        // ~Node() {
        // // Delete any dynamically allocated resources here
        // // For a linked list, you may need to recursively delete nodes
        // if (next != NULL) {
        //     this->next=NULL;
        //     delete next;
        //     cout<<"DES";
        // }
        // }
};
//INSERTIONS
void insertAtHead(Node* &head, int data){
    Node* newnode= new Node(data); //new node is created
    newnode->next= head; //newnode is connected to head
    head=newnode; //Newnode is made as the head
}

void insertAtTail(Node* &tail, int data){
    Node* newnode=new Node(data);
    tail->next=newnode;
    tail=tail->next;
    //newnode=NULL;
}
 
void insertInMiddle(Node* &head, Node* &tail, int position, int data){
    //head add
    if(position==1){
        insertAtHead(head, data);
        return;
    }
    Node* temp= head;
    int count=1;
    while(count<position-1){
        temp=temp->next;
        count++;
    }
    //tail add
    if(temp->next==NULL){
        insertAtTail(tail, data);
        return;
    }
    Node* newnode=new Node(data);
    newnode->next=temp->next;
    temp->next=newnode;
}
//TRAVERSAL
void printLinkedList(Node* &head){
    Node* temp= head;
    int len=0;
    cout<<"The Linked List is: ";
    while(temp!=NULL){
        len++;
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl<<"Linked List Length = "<< len <<endl<<endl;
}
//DELETION
void deleteNode(Node* &head,Node* &tail, int position){
    if(position==1){
        Node* delnode=head;
        head=head->next;
        delnode->next=NULL;
        delete delnode;//free(delnode)
        return;
    }
    Node* prevnode=head;
    Node* delnode=head->next;
    int count=1;
    while(count<position-1){
        if(delnode->next==NULL){
            prevnode->next=NULL;
            tail=prevnode;
            delete delnode;
            return;
        }
        count++;
        prevnode=prevnode->next;
        delnode=delnode->next;
    }
    prevnode->next=delnode->next;
    delnode->next=NULL;
    delete(delnode);
    return;

}

int main(){
    Node* n1= new Node(3);
    Node* head=n1;
    Node* tail=n1;
    printLinkedList(head);
    insertAtHead(head, 7);
    printLinkedList(head);
    insertAtHead(head, 1);
    printLinkedList(head);
    insertInMiddle(head, tail, 2, 4);
    printLinkedList(head);
    deleteNode(head, tail, 3);
    printLinkedList(head);
    cout<<"HEAD IS "<<head->data<<endl<<"TAIL IS "<<tail->data;

 return 0;
}