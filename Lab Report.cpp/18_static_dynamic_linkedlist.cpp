#include <iostream>
using namespace std;

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

int main()
{
    Node *Head = nullptr;

    int value;

    while (true)
    {
        cout << "Enter a number (-0 to stop): ";
        cin >> value;
        if (value == -0)
        {
            break;
        }
        Node *newnode = new Node(value);

        if (Head == nullptr)
        {
            Head = newnode;
        }

        else
        {
            Node *temp = Head;
            while (temp->next != nullptr)
            {
                temp = temp->next;
            }
            temp->next = newnode;
        }
    }

    Node *temp = Head;
    while (temp != nullptr)
    {
        cout << temp->value << " ";
        temp = temp->next;
    }
}
