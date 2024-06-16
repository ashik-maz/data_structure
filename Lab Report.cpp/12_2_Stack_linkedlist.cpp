#include <iostream>
using namespace std;

template <typename Type>
class Stack
{
    struct Node
    {
        Type value;
        Node *next;

        Node(Type value)
        {
            this->value = value;
            next = nullptr;
        }
    };

    Node *Head;

public:
    Stack()
    {
        Head = nullptr;
    }
    void push(Type value)
    {
        Node *Newnode = new Node(value);
        if (Head == nullptr)
        {
            Head = Newnode;
        }
        else
        {
            Node *temp = Head;

            while (temp->next != nullptr)
            {
                temp = temp->next;
            }
            temp->next = Newnode;
        }
    }
    void pop()
    {
        if (Head == nullptr)
        {
            cout << "Queue is Emptly !\n";
            return;
        }
        else if (Head->next == nullptr)
        {
            delete Head;
            Head = nullptr;
            return;
        }
        else
        {
            Node *temp = Head;
            while (temp->next->next != nullptr)
            {
                temp = temp->next;
            }
            delete temp->next;
            temp->next = nullptr;
        }
    }
    void popfront(){
        Node *temp=Head;
        Head=Head->next;
        delete temp;
    }
    Type top()
    {
        Node *temp=Head;
        while (temp->next != nullptr)
        {
            temp=temp->next;
        }
        return temp->value;
        
    }
    Type front()
    {
        return Head->value; 
    }
    int size()
    {
        Node* temp=Head;
        
        int sz=0;
        while(temp != nullptr){
            temp=temp->next;
            sz++;
        }
        return sz;
    }

    Type operator[](int index)
    {
        if (index < 0 || index >= size())
        {
            cout << "Out of range !";
        }
        
        Node *temp= Head;
        for(int i=0;i<index;i++){
            temp=temp->next;
        }
        return temp->value;
    }
};

int main()
{
    Stack<int>st;
    int choice;
    while(true){
        // system("cls");
        cout<<"Stack size= "<<st.size()<<"\n";
        cout<<"Stack Elements= ";
        for(int i=0;i<st.size();i++){
            cout<<st[i]<<" ";
        }
        cout<<"\n1.push\n2.pop\n3.exit\n";
        cin>>choice;

        switch (choice){
            case 1:
                cout<<"Enter value=";
                int x;cin>>x;st.push(x);
                system("cls");
                break;
            case 2:
                st.pop();
                system("cls");
                break;
            case 3:
                return 0;
            default:
                cout << "Invalid choice! Please try again.\n";
                break;
        }
    }
    // Stack<int> st;
    // st.push(1);
    // st.push(19);
    // st.push(13);
    // st.push(32);
    // st.push(33);
    // st.pop();
    // cout << "size of Stack= " << st.size() << "\n";

    // cout << st[2];

    // cout << "element Are: ";
    
    // // for(int i=0;i<st.size();i++){
    // //     cout<<st[i]<<" ";
    // // }

    // while (st.size() !=0)
    // {
    //     cout<<st.front()<<" ";
    //     st.popfront();
    // }

    
}