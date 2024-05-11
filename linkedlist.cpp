#include <iostream>

using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int data) : data(data), next(nullptr) {}
};

void push(Node** head_ref, int new_data) {
    // 1. Allocate node
    Node* new_node = new Node(new_data);

    // 2. Make next of new node as head
    new_node->next = *head_ref;

    // 3. Move the head to point to the new node
    *head_ref = new_node;
}

void display(Node* head) {
    Node* current = head;
    while (current) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

int main() {
    Node* head = nullptr;
    int elements[] = {1, 2, 3, 4, 5};
    int n = sizeof(elements) / sizeof(elements[0]);

    cout << "Inserting elements at the head of the linked list:" << endl;
    for (int i = 0; i < n; i++) {
        push(&head, elements[i]);
        display(head);
    }

    return 0;
}
