#include<bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    Node* left;
    Node* right;
    Node(int data){
        this->data = data;
        this->left = this->right = NULL;
    }
};

Node* creation(vector<int> v, Node* root, int i){
    if(i < v.size()){
        Node* temp = new Node(v[i]);
        root = temp;
        root->left = creation(v, root->left, 2 * i + 1);
        root->right = creation(v, root->right, 2 * i + 2);
    }
    return root;
}

void inorder(Node* root){
    if(root == NULL){
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}