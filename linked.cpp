#include <iostream>
using namespace std;

class Linkedlist
{
    struct Node
    {
        int value;
        Node *next;

        Node(int value)
        {
            this->value = value;
            next = nullptr;
        }
    };

public:
    Node *Head;
    Linkedlist()
    {
        Head = nullptr;
    }

    void push(int value)
    {
        Node *newnode = new Node(value);
        if (Head == nullptr)
        {
            Head = newnode;
        }
        else
        {
            Node *Temp = Head;
            while (Temp->next != nullptr)
            {
                Temp = Temp->next;
            }
            Temp->next = newnode;
        }
    }

    void display()
    {
        Node *Temp = Head;
        while (Temp != nullptr)
        {
            cout << Temp->value<<" ";
            Temp = Temp->next;
        }
    }
};

int main()
{
    Linkedlist arr;
    int value;
    while (true)
    {
        cout << "Enter a number(-0 to stop): ";
        cin >> value;
        if (value == -0)
        {
            cout<<"\nYour list: ";
            arr.display();
            break;
        }

        else
        {
            arr.push(value);
        }
    }
}