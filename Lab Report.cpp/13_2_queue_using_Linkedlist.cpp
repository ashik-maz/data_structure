
#include <iostream>
using namespace std;

template <typename Type>
class Queue
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
    Queue()
    {
        Head = nullptr;
    }

    void pushfront(Type value)
    {
        Node *Newnode = new Node(value);
        Newnode->next = Head;
        Head = Newnode;
    }

    void pushback(Type value)
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

    void popback()
    {
        if (Head == nullptr)
        {
            cout << "Queue is Emptly !";
            return;
        }
        if (Head->next == nullptr)
        {
            delete Head;
        }

        Node *temp;
        while (temp->next->next != nullptr)
        {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = nullptr;
    }

    void popfront()
    {
        if (Head == nullptr)
        {
            cout << "the Queue is Empty !";
        }
        Node *temp = Head;
        Head = Head->next;
        delete temp;
    }

    int size()
    {
        int sz = 0;
        
        Node *temp = Head;
        while (temp != nullptr)
        {
            temp = temp->next;
            sz++;
        }
        return sz;
    }

    Type front(){
        return Head->value;
    }

    Type back(){
        Node* temp=Head;
        while(temp->next != nullptr){
            temp= temp->next;
        }
        return temp->value;
    }


};

int main()
{
    Queue<int> qu;

    qu.pushback(1);
    qu.pushback(2);
    qu.pushback(3);
    qu.pushfront(19);

   

    cout << "size=" << qu.size()<<"\n";
    cout << "Front=" << qu.front()<<"\n";
    cout << "back=" << qu.back()<<"\n"<<"Queue Element: ";

    while(qu.size() !=0){
        cout<<qu.front()<<" ";
        qu.popfront();
    }


    return 0;
}