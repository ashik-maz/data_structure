#include <iostream>
using namespace std;

class Node
{
    public:
        int data;
        Node *next;
};

void print(Node *head)
{
    while (head != nullptr)
    {
        cout << head->data << " ";
        head = head->next;
    }
}

int main()
{
    Node *head = nullptr;
    Node *current = nullptr;
    int value;

    while (true)
    {
        cout << "Enter a number (-1 to stop): ";
        cin >> value;
        if (value == -1)
            break;
            
        Node *newNode = new Node();
        newNode->data = value;
        newNode->next = nullptr;

        if (head == nullptr)
        {
            head = newNode;
            current = head;
        }
        else
        {
            current->next = newNode;
            current = current->next;
        }
    }

    print(head);

    // Free memory
    Node *temp;
    while (head != nullptr)
    {
        temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
