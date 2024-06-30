#include <iostream>
using namespace std;

class BinarySearchTree {
    struct Node {
        int value;
        Node* left;
        Node* right;

        Node(int value) {
            this->value = value;
            left = nullptr;
            right = nullptr;
        }
    };

    Node* root;

public:
    BinarySearchTree() {
        root = nullptr;
    }

    void insert(int value) {
        Node* newNode = new Node(value);
        if (root == nullptr) {
            root = newNode;
            return;
        }

        Node* temp = root;
        while (true) {
            if (newNode->value == temp->value) {
                delete newNode; 
                return;
            }
            if (newNode->value < temp->value) {
                if (temp->left == nullptr) {
                    temp->left = newNode;
                    return;
                }
                temp = temp->left;
            } else {
                if (temp->right == nullptr) {
                    temp->right = newNode;
                    return;
                }
                temp = temp->right;
            }
        }
    }

    void inorderTraversal(Node* current) {
        if (current != nullptr) {
            inorderTraversal(current->left);
            cout << current->value << " ";
            inorderTraversal(current->right);
        }
    }

    void inorderTraversal() {
        inorderTraversal(root);
    }

    void preorderTraversal(Node* current) {
        if (current != nullptr) {
            cout << current->value << " ";
            preorderTraversal(current->left);
            preorderTraversal(current->right);
        }
    }

    void preorderTraversal() {
        preorderTraversal(root);
    }

    void postorderTraversal(Node* current) {
        if (current != nullptr) {
            postorderTraversal(current->left);
            postorderTraversal(current->right);
            cout << current->value << " ";
        }
    }

    void postorderTraversal() {
        postorderTraversal(root);
    }

    bool contains(int value) {
        Node* temp = root;
        while (temp != nullptr) {
            if (value < temp->value) {
                temp = temp->left;
            } else if (value > temp->value) {
                temp = temp->right;
            } else {
                return true;
            }
        }
        return false;
    }

    Node* deleteNode(Node* root, int value) {
        if (root == nullptr) return root;

        if (value < root->value) {
            root->left = deleteNode(root->left, value);
        } else if (value > root->value) {
            root->right = deleteNode(root->right, value);
        } else {
            // Node with only one child or no child
            if (root->left == nullptr) {
                Node* temp = root->right;
                delete root;
                return temp;
            } else if (root->right == nullptr) {
                Node* temp = root->left;
                delete root;
                return temp;
            }

            // Node with two children: Get the inorder successor (smallest in the right subtree)
            Node* temp = minValueNode(root->right);

            // Copy the inorder successor's content to this node
            root->value = temp->value;

            // Delete the inorder successor
            root->right = deleteNode(root->right, temp->value);
        }
        return root;
    }

    Node* minValueNode(Node* node) {
        Node* current = node;
        while (current && current->left != nullptr) {
            current = current->left;
        }
        return current;
    }

    void deleteNode(int value) {
        if (contains(value)) {
            root = deleteNode(root, value);
        } else {
            cout << "\nNode not found." << endl;
        }
    }
};

int main() {
    BinarySearchTree tree;
    int choice;
    while (true) {
        cout<<"\nInorder Traversal of Binary Tree: ";
        tree.inorderTraversal();
        cout<<"\nPostorder Traversal of Binary Tree: ";
        tree.postorderTraversal();
        cout<<"\npreorder Traversal of Binary Tree: ";
        tree.preorderTraversal();
        cout << "Menu:\n1. Insert Node\n2. Delete Node\n3.exit\nEnter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Enter Node: ";
                int value;
                cin >> value;
                tree.insert(value);
                break;
            case 2:
                cout << "\nEnter the Node, which you want to delete: ";
                cin >> value;
                tree.deleteNode(value);
                break;
            case 3:
                return 0;
            default:
                cout << "Invalid choice. Please enter again." << endl;
        }
    }
    return 0;
}
