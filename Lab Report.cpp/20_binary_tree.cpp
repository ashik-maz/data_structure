#include<bits/stdc++.h>
using namespace std;

class Binarytree{
    private:
    struct Node
    {
        int data;
        Node *left;
        Node *right;
        Node(int value): data(value), left(nullptr), right(nullptr){}
    };
    
    public:

    Node *insertrecursive(Node *current, int value){
        if(current==nullptr){
            return new Node(value);
        }

        if(value < current->data){
            current->left=insertrecursive(current->left, value);
        }
        else if(value > current->data){
            current->right=insertrecursive(current->right, value);
        }

        return current;

    }

    Node* root;
    Binarytree() : root(nullptr){}
    
    void insert(int value){
        root = insertrecursive(root, value);
    }

    void inorderTraversal(Node* current){
        if(current !=nullptr){
            inorderTraversal(current->left);
            cout<<current->data<<" ";
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
    tree.insert(1);
    tree.insert(6);
    tree.insert(3);
    tree.insert(4);

    cout<<"Inoderder Traversal of the binary tree: ";
    tree.inorderTraversal();

    return 0;

}