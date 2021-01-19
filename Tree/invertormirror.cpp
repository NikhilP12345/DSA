#include "creationBST.h"
using namespace std;

int main(){
    vector<int> v = {1,2,3,4,5};
    Node* root = creation(v, root, 0);
    inorder(root);
    cout << "\n";
    queue<Node *> q;
    q.push(root);
    while(!q.empty()){
        Node* temp = q.front();
        q.pop();
        swap(temp->left, temp->right);
        if(temp->left){
            q.push(temp->left);
        }
        if(temp->right){
            q.push(temp->right);
        }
    }
    inorder(root);
}