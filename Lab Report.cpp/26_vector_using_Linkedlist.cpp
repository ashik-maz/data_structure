#include<iostream>
using namespace std;

template <typename Type>
class vector{
    struct Node{
        Type value;
        Node* next;

        Node(Type value){
            this->value=value;
            this->next=nullptr;
        }
    };

    Node* Head;
    public:
    vector(){
        Head=nullptr;
    }

    void pushback(Type value){
        Node *newNode= new Node(value);
        if(Head==nullptr){
            Head=newNode;
        }
        else{
            Node* temp=Head;
            while(temp->next !=nullptr){
                temp=temp->next;
            }
            temp->next=newNode;
        }
    }

    void pop(){

        if(Head==nullptr){
            cout<<"vector is empty.!\n";
            return;
        }
        else if(Head->next==nullptr){
            Node *temp=Head;
            Head=nullptr;
            delete temp;
            size()--;
            return;

        }
        else {
            Node *temp=Head;
            while(temp->next->next !=nullptr){
                temp=temp->next;
            }
            delete temp->next;
            temp->next=nullptr;
            size()--;
        }
    }

    int size(){
        int Size=0;
        Node *temp=Head;
        while(temp!=nullptr){
            temp=temp->next;
            Size++;
        }
        return Size;
    }

    Type operator [](int index){
        if(index<0 || index>=size()){
            cout<<"Invalid index !\n";
            
        }
        else{
            Node* temp=Head;
            for(int i=0;i<index;i++){
                temp=temp->next;
            }
            return temp->value;
        }
        
        
    }

};
int main(){
    vector<int>v;
    v.pushback(1);
    v.pushback(2);
    v.pushback(3);
 
    cout<<"\nvector size:"<<v.size();
    cout<<"\nvector element:";

    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }

    return 0;
}
