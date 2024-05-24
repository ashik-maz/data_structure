#include <iostream>

using namespace std;


class Node { 
    public:
        int value;
        Node* next;

        Node(int value) {
            this->value = value;
            next = nullptr;
        }
}; 


class LinkedList {
    private:
        Node* head;
        Node* tail;
        int length;

    public:
        LinkedList(int value) {
            Node* newNode = new Node(value);
            head = newNode;
            tail = newNode;
            length = 1;
        }

        void getHead() {
            cout << "Head: " << head->value << endl;
        }

        void getTail() {
            cout << "Tail: " << tail->value << endl;
        }

        void getLength() {
            cout << "Length: " << length << endl;
        }

        void printList() {
            Node* temp = head;
            while (temp != nullptr) {
                cout << temp->value << endl;
                temp = temp->next;
            }
        }

        void append(int value) {
            Node* newNode = new Node(value);
            if (length == 0) {
                head = newNode;
                tail = newNode;
            } else {
                tail->next = newNode;
                tail = newNode;
            }
            length++;
        }

        Node* removeLast() {
            if (length == 0) return nullptr;
            Node* temp = head;
            Node* pre = head;
            while(temp->next) {
                pre = temp;
                temp = temp->next;
            }
            tail = pre;
            tail->next = nullptr;
            length--;
            if (length == 0) {
                head = nullptr;
                tail = nullptr;
            }
            return temp;
        }

};



int main() {
        
    LinkedList* myLinkedList = new LinkedList(1);
    myLinkedList->append(2);

    // (2) Items - Returns 2 Node
    cout << myLinkedList->removeLast()->value << endl;
    // (1) Item -  Returns 1 Node
    cout << myLinkedList->removeLast()->value << endl;
    // (0) Items - Returns nullptr
    cout << myLinkedList->removeLast() << endl;
        
}

