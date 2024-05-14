#include<iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

void print( Node* head){
   while(head !=nullptr){
    cout<<head->data<<" ";
    head=head->next;
   }
}
 int main()
 {
    Node* head=new Node();
    Node* second=new Node();
    Node* third=new Node();

    head->data=1;
    second->data=5;
    third->data=7;

    head->next=second;
    second->next=third;
    third->next=nullptr;

    print(head);
 }