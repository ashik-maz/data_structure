#include<iostream>
using namespace std;

class BinarySearchTree{
    struct Node{
        int value;
        Node* left;
        Node* right;

        Node(int value){
            this->value=value;
            left=nullptr;
            right=nullptr;
        }
    };
    
    Node* root;

    public:

    BinarySearchTree(){
        root=nullptr;
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
                // Value already exists, do nothing
                delete newNode; // Free the memory allocated for the new node
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

    void inorderTraversal(Node* current){
        if(current != nullptr){
            inorderTraversal(current->left);
            cout<<current->value<<" ";
            inorderTraversal(current->right);
        }
    }

    void inorderTraversal(){
        inorderTraversal(root);
        cout<<endl;
    }
    void preorderTraversal(Node* current){
        if(current != nullptr){
            cout<<current->value<<" ";
            preorderTraversal(current->left);
            preorderTraversal(current->right);
        }
    }
    void preorderTraversal(){
        preorderTraversal(root);
        cout<<endl;
    }
    void postorderTraversal(Node* current){
        if(current != nullptr){
            postorderTraversal(current->left);
            postorderTraversal(current->right);
            cout<<current->value<<" ";
        }
    }
    void postorderTraversal(){
        postorderTraversal(root);
        cout<<endl;
    }

    //contains function(if you need)
    // bool contains(int value){
    //     Node* temp;
    //     while(temp !=nullptr){
    //         if(value < temp->value){
    //             temp=temp->left;
    //         }
    //         else if(value > temp->value){
    //             temp=temp->right;
    //         }
    //         else{
    //             return true;
    //         }
    //     }
    //     return false;
    // }


};


int main(){
    BinarySearchTree tree;
    int value;
    while (true)
    {
        cout << "Enter a number(0 to stop): ";
        cin >> value;
        if (value == 0)
        {
            cout<<"\nInorder Traversal of Binary Tree: ";
            tree.inorderTraversal();
            cout<<"\nPostorder Traversal of Binary Tree: ";
            tree.postorderTraversal();
            cout<<"\npreorder Traversal of Binary Tree: ";
            tree.preorderTraversal();
            break;
        }

        else
        {
            tree.insert(value);
        }
    }

}