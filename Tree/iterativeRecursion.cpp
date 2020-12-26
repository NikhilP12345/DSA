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

Node* Creation(vector<int> v, Node* root, int i, int n){
    if(i < n){
        Node* temp = new Node(v[i]);
        root = temp;
        root->left = Creation(v, root->left, 2*i + 1, n);
        root->right = Creation(v, root->right, 2*i + 2, n);
    }
    return root;
}
 void inorder(Node* root){
    stack<Node* >s;
    Node* curr = root;
    while(curr != NULL || s.empty() == false){
        while(curr != NULL){
            s.push(curr);
            curr = curr->left;
        }
        curr = s.top();
        s.pop();
        cout << curr->data << " ";
        curr = curr->right;
    }
 }
 void preorder(Node* root){
     stack<Node*> s;
     s.push(root);
     while(!s.empty()){
        Node* temp = s.top();
        s.pop();
        cout << temp->data << " ";
        if(temp->right){
            s.push(temp->right);
        }
        if(temp->left){
            s.push(temp->left);
        }
    }
}

void postorder(Node* root){
    stack<Node*> s1;
    stack<Node*> s2;
    s1.push(root);
    while(!s1.empty()){
        Node* temp = s1.top();
        s1.pop();
        s2.push(temp);
        if(temp->left){
            s1.push(temp->left);
        }
        if(temp->right){
            s1.push(temp->right);
        }
    }
    while(!s2.empty()){
        Node* temp = s2.top();
        s2.pop();
        cout << temp->data << " ";
    }
}

int main(){
    vector<int> v = {1,2,3,4,5};
    Node* root = Creation(v, root, 0, v.size());
    cout << "Inorder: ";
    inorder(root);
    cout << "\n";
    cout << "Preorder: ";
    preorder(root);
    cout << "\n";
    cout << "Postorder: ";
    postorder(root);
}