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
    if(root == NULL){
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}
void preorder(Node* root){
    if(root == NULL){
        return;
    }
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}
void postorder(Node* root){
    if(root == NULL){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

int main(){
    vector<int> v = {1,2,3,4,5, NULL, 6, 7};
    Node* root = Creation(v, root, 0, v.size());
    cout << "Inorder: ";
    inorder(root);
    cout << "\n";
    cout << "Preorder: ";
    preorder(root);
    cout << "\n";
    cout << "Postorder: ";
    postorder(root);
    cout << "\n";
    queue<Node*> q;
    q.push(root);
    vector<vector<int>> v1;
    while(!q.empty()){
        int n = q.size();
        vector<int> v2 = {};
        for(int i = 0 ; i < n ; i++){
            Node* temp = q.front();
            q.pop();
            v2.push_back(temp->data);
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }
        v1.push_back(v2);

    }
    cout << "Level Order Traversal = \n";
    for(auto i: v1){
        for(auto j: i){
            cout << j << " ";
        }
        cout << endl;
    }
}