#include<bits/stdc++.h>
#include<stdlib.h>
using namespace std;

template <typename T>

class Tree{
    class Node{
        public:
            T data;
            Node* left;
            Node* right;
    };
    Node *root;

    public:

    Tree() { root = NULL; }
    ~Tree() {}

    Node *newNode(T value)
    {
        Node *new_node =  new Node;
        if(!new_node){
            cout << "Error: Insufficient Storage";
            exit(1);
        }
        new_node -> data = value;
        new_node -> left = new_node -> right = NULL;
        return new_node;
    }

    T insert(T value)
    {
        Node *curr = root;
        Node *new_node = newNode(value);

        if(root == NULL){
            root = new_node;
            return new_node -> data;
        }

        while(1){
            if(value < curr -> data){
                if(curr -> left == NULL){
                    curr -> left = new_node;
                    return curr -> left -> data;
                }
                else{
                    curr = curr -> left;
                }
            }

            else if(value > curr -> data){
                if(curr -> right == NULL){
                    curr -> right = new_node;
                    return curr -> right -> data;
                }
                else{
                    curr = curr -> right;
                }
            }
        }
    }

    T remove(int value)
    {
        Node *curr = root;
        if(root == NULL){
            return NULL;
        }
        
        while(1){
            if(value < curr -> data){
                if(curr -> left == value){
                    return curr -> left -> data;
                }
                else{
                    curr = curr -> left;
                }
            }

            else if(value > curr -> data){
                if(curr -> right == value){
                    return curr -> right -> data;
                }
                else{
                    curr = curr -> right;
                }
            }
        }
    }

    void inorderTraverse()
    {
        inorder(root);
    }

    void inorder(Node *root)
    {
        Node *curr = root;
        if (curr == NULL)
            return;

        inorder(curr->left);
        cout << curr->data << ' ';
        inorder(curr->right);
    }
};
