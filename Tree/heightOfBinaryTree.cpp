#include "creationBST.h"

int heightOfBST(Node* root){
    if(root == NULL){
        return 0;
    }
    return 1 + max(heightOfBST(root->left), heightOfBST(root->right));
}


int main(){
    vector<int> v = {1,2,3,4,5};
    Node* root = creation(v, root, 0);
    inorder(root);
    cout << endl;
    cout << heightOfBST(root);
}