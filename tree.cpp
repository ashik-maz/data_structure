#include<iostream>
using namespace std;

class Binarytree{
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

    public:
    Node *insertrecursively(Node* current,int value){
        if(current==nullptr){
            return new Node(value);
        }

        else if(value<current->value){
            current->left=insertrecursively(current->left, value);
        }

        else if(value>current->value){
            current->right=insertrecursively(current->right, value);
        }
        return current;
    }

    Node* root;
    Binarytree(){
        root=nullptr;
    }

    void insert(int value){
        root=insertrecursively(root,value);
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
};


int main(){
    Binarytree tree;
    int value;
    while (true)
    {
        cout << "Enter a number(-0 to stop): ";
        cin >> value;
        if (value == -0)
        {
            cout<<"\nInorder Traversal of Binary Tree: ";
            tree.inorderTraversal();
            break;
        }

        else
        {
            tree.insert(value);
        }
    }
}