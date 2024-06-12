
// also print reverse order
//delete all specific data

#include<bits/stdc++.h>
using namespace std;

class LinkedList {
    struct Node {
        int data;
        Node* next;
        Node(int val) : data(val), next(nullptr) {}
    };

    Node* head;

public:
    LinkedList() : head(nullptr) {}

    void printLinkedlist() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << "\n";
    }

    void insertHead(int value) {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
    }

    void insertTail(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    void insertIndex(int index, int value) {
        if (index == 0) {
            insertHead(value);
            return;
        }
        Node* newNode = new Node(value);
        Node* temp = head;
        for (int i = 0; temp != nullptr && i < index - 1; ++i) {
            temp = temp->next;
        }
        if (temp == nullptr) {
            cout << "Index out of bounds\n";
            return;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }

    void insertAfterNode(int afterValue, int value) {
        Node* temp = head;
        while (temp != nullptr && temp->data != afterValue) {
            temp = temp->next;
        }
        if (temp == nullptr) {
            cout << "Node not found\n";
            return;
        }
        Node* newNode = new Node(value);
        newNode->next = temp->next;
        temp->next = newNode;
    }

    void deleteHead() {
        if (head == nullptr) {
            cout << "List is empty you can't delete\n";
            return;
        }
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    void deleteTail() {
        if (head == nullptr) {
            cout << "List is empty you can't delete\n";
            return;
        }
        if (head->next == nullptr) {
            delete head;
            head = nullptr;
            return;
        }
        Node* temp = head;
        while (temp->next->next != nullptr) {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = nullptr;
    }

    void deleteIndex(int index) {
        if (head == nullptr) {
            cout << "List is empty you can't delete\n";
            return;
        }
        if (index == 0) {
            deleteHead();
            return;
        }
        Node* temp = head;
        for (int i = 0; temp != nullptr && i < index - 1; ++i) {
            temp = temp->next;
        }
        if (temp == nullptr || temp->next == nullptr) {
            cout << "Index out of bounds\n";
            return;
        }
        Node* nodeToDelete = temp->next;
        temp->next = temp->next->next;
        delete nodeToDelete;
    }

    void deleteNode(int value) {
        if (head == nullptr) {
            cout << "List is empty you can't delete\n";
            return;
        }
        if (head->data == value) {
            deleteHead();
            return;
        }
        Node* temp = head;
        while (temp->next != nullptr && temp->next->data != value) {
            temp = temp->next;
        }
        if (temp->next == nullptr) {
            cout << "Node not found\n";
            return;
        }
        Node* nodeToDelete = temp->next;
        temp->next = temp->next->next;
        delete nodeToDelete;
    }
};

int main() {
    LinkedList list;
    int choice;
    while (true) {
        cout << "Update Linkedlist: ";
        list.printLinkedlist();

        cout << "Menu\n1. Insert\n2. Delete\n3. Exit\nEnter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1: {
                int insertChoice;
                cout << "1. Insert at Head\n2. Insert at Tail\n3. Insert in an index\n4. Insert data after specific node\n";
                cin >> insertChoice;
                int value, index;
                switch (insertChoice) {
                    case 1:
                        cout << "Enter value: ";
                        cin >> value;
                        system("cls");
                        cout << "Old Linkedlist: ";
                        list.printLinkedlist();
                        list.insertHead(value);
                        break;
                    case 2:
                        cout << "Enter value: ";
                        cin >> value;
                        system("cls");
                        cout << "Old Linkedlist: ";
                        list.printLinkedlist();
                        list.insertTail(value);
                        break;
                    case 3:
                        cout << "Enter index and value: ";
                        cin >> index >> value;
                        system("cls");
                        cout << "Old Linkedlist: ";
                        list.printLinkedlist();
                        list.insertIndex(index, value);
                        break;
                    case 4:
                        cout << "Enter value of existing node and new value: ";
                        cin >> index >> value;
                        system("cls");
                        cout << "Old Linkedlist: ";
                        list.printLinkedlist();
                        list.insertAfterNode(index, value);
                        break;
                    default:
                        cout << "Invalid Choice\n";
                        break;
                }
                break;
            }
            case 2: {
                int deleteChoice;
                cout << "1. Delete Head\n2. Delete Tail\n3. Delete index\n4. Delete specific node\n";
                cin >> deleteChoice;
                int value, index;
                switch (deleteChoice) {
                    case 1:
                        system("cls");
                        cout << "Old Linkedlist: ";
                        list.printLinkedlist();
                        list.deleteHead();
                        break;
                    case 2:
                        system("cls");
                        cout << "Old Linkedlist: ";
                        list.printLinkedlist();
                        list.deleteTail();
                        break;
                    case 3:
                        system("cls");
                        cout << "Old Linkedlist: ";
                        list.printLinkedlist();
                        cout << "Enter index: ";
                        cin >> index;
                        list.deleteIndex(index);
                        break;
                    case 4:
                        system("cls");
                        cout << "Old Linkedlist: ";
                        list.printLinkedlist();
                        cout << "Enter value: ";
                        cin >> value;
                        list.deleteNode(value);
                        break;
                    default:
                        cout << "Invalid Choice\n";
                        break;
                }
                break;
            }
            case 3:
                system("cls");
                cout<<"Linkedlist: ";
                list.printLinkedlist();
                cout << "\nExiting program." << endl; 
                return 0;
            default:
                cout << "Invalid Choice\n";
                break;
        }
    }
}
