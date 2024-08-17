#include <iostream>

using namespace std;

template <typename Type>

class Stack
{
    class Node
    {
    public:
        Node *prev;
        Type data;
        Node *next;

        Node(Type data)
        {
            prev = nullptr;
            this->data = data;
            next = nullptr;
        }
    };
    Node *Head;
    Node *Top;

public:
    Stack()
    {
        Head = nullptr;
        Top = nullptr;
    }

    bool isEmpty()
    {
        if (Head == nullptr)
            return true;
        return false;
    }

    void push(Type data)
    {
        Node *newNode = new Node(data);
        if (isEmpty())
        {
            Head = newNode;
            Top = newNode;
        }
        else
        {
            newNode->prev = Top;
            Top->next = newNode;
            Top = newNode;
        }
    }
    void printstack()
    {
        if (!isEmpty())
        {
            cout << "The stack is: ";
            Node *Temp = Head;
            while (Temp != nullptr)
            {
                cout << Temp->data << " ";
                Temp = Temp->next;
            }
            cout << "\n";
        }
        else
            cout << "Stack is Empty\n";
    }
    void reversestack()
    {

        if (!isEmpty())
        {
            cout << "The stack is: ";
            Node *Temp = Top;
            while (Temp != nullptr)
            {
                cout << Temp->data << " ";
                Temp = Temp->prev;
            }
            cout << "\n";
        }
        else
            cout << "Stack is Empty\n";
    }

    void size()
    {
        int sz = 0;
        Node *Temp = Head;
        while (Temp != nullptr)
        {
            sz++;
            Temp = Temp->next;
        }
        cout << "Size= " << sz << "\n";
    }

    void pop()
    {
        if (isEmpty())
            cout << "can't pop! Stack is Empty\n";
        else if (Head == Top)
        {
            Head = Top = nullptr;
        }
        else
        {
            Node *Temp = Top;
            Top->prev->next = nullptr;
            Top = Top->prev;
            delete Temp;
        }
    }

    void TopElement()
    {
        cout<<"Top element is : "<<Top->data<<"\n";

    }
};
int main()
{
    Stack<int> st;
    st.push(1);
    st.push(19);
    st.push(11);
    st.size();
    st.TopElement();
    st.printstack();
    st.pop();
    st.pop();
    st.pop();
    st.pop();

    st.reversestack();

    
}
