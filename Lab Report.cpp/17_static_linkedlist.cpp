#include<iostream>
using namespace std;

struct Node
{
    int value;
    Node* next;

    Node(int value){
        this->value=value;
        next=nullptr;
    }
};

int main(){
    Node *a= new Node(1);
    Node *b= new Node(2);
    Node *c= new Node(19);
    a->next=b;
    b->next=c;
    c->next=nullptr;

    Node *temp=a;
    while(temp != nullptr){
        cout<<temp->value<<" ";
        temp=temp->next;
    }
}
