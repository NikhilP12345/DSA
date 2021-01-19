#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
    Node(int data){
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

Node* levelOrder(vector<int> v, Node* root, int i, int n){
    if(i < n){
        Node* temp = new Node(v[i]);
        root = temp;
        root->left = levelOrder(v, root->left, 2 * i + 1, n);
        root->right = levelOrder(v, root->right, 2 * i + 2, n);
    }
    return root;
}

int main(){
    vector<int> v = { 1, 2, 3, 4, 5, 6, 6, 6, 6 };
    Node* root = levelOrder(v, root, 0, v.size());
}