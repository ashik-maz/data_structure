#include<iostream>
#include<iostream>
using namespace std;

struct Node{
    Node* prev;
    int value;
    Node* next; 
};
Node* Head=NULL;
Node* Top=NULL;

bool isEmpty(){
    if(Head==NULL)
        return true;
    return false;
}
void push(int val){
    Node* newNode;
    newNode= new Node();
    newNode->value=val;
    if(isEmpty()){
        newNode->prev=NULL;
        newNode->next=NULL;
        Head=newNode;
        Top=newNode;
    }
    else{
        Top->next=newNode;
        newNode->next=NULL;
        newNode->prev=Top;
        Top=newNode;
    }
}
void pop(){
    Node* temp;
    temp==Top;
    if(isEmpty())
    cout<<"Stack is Empty\n";
    else if(Head==Top){
        Top=NULL;
        Head=NULL;
        delete temp;
    }
    else{
        Top->prev->next=NULL;
        Top=temp->prev;
        delete temp;
    }
}
void printStack(){
    cout<<"The Stack is: ";
    Node* temp=Head;
    while(temp !=NULL){
        cout<<temp->value<<" ";
        temp=temp->next;
    }
    cout<<"\n";
}
void printreverse(){
    cout<<"The reverse Stack is: ";
    Node* temp=Top;
    while(temp !=NULL){
        cout<<temp->value<<" ";
        temp=temp->prev;
    }
    cout<<"\n";
}
void stackSize(){
    int sz=0;
    Node *temp=Head;
    while(temp!=NULL){
        sz++;
        temp=temp->next;
    }
    cout<<"\nSize="<<sz<<endl;
}

void topElement(){
    if(isEmpty())
    cout<<"Stack is Empty.\n";
    else
    cout<<Top->value;
}
int main(){
    push(1);
    push(2);
    push(3);
    printreverse();

    printStack();
    // topElement();
    // pop();
    stackSize();

}
