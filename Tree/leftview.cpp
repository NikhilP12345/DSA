#include "creationBST.h"
using namespace std;

void leftview(Node* root){
    if(root == NULL){
        return;
    }
}

int main(){
    vector<int> v = {1,2,3,4,5};
    Node* root = creation(v, root, 0);
    inorder(root);
    leftview(root);
}