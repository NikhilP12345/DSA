#include "creationBST.h"

int diameter(Node* root, int &maxEl){
    if(root == NULL){
        return 0;
    }
    int left = diameter(root->left,maxEl);
    int right = diameter(root->right,maxEl);
    maxEl = max(maxEl, left + right);
    return 1 + max(left, right);
}
int main(){
    vector<int> v = {1,2,3,4,5};
    Node* root = creation(v, root, 0);
    inorder(root);
    int maxEl = INT_MIN;
    diameter(root, maxEl);
    cout << maxEl + 1;
}