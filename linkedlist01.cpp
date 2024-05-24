#include <bits/stdc++.h>
using namespace std;
class Node{
    public:
    int value;
    Node* next;
    Node(int value){
        this->value=value;
    }
};

class Linkedlist{
    private:
    Node* head;
    Node* tail;
    int length;
    public:
    Linkedlist(int value){
        Node* newNode= new Node(value);
        head = newNode;
        tail = newNode;
        length=1;
    }

    void printList(){
        Node* temp = head;
        while (temp != nullptr){
            cout<<temp->value<<" "<<endl;
            temp = temp->next;

        }
        
    }
};