#include "creationLinkedList.h"

Node* reverseGroup(Node* head, int k){
    Node* curr = head;
    Node* next = NULL;
    Node* prev = NULL;
    int count = 0;
    while(curr != NULL && count < k){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        count++;
    }
    if(next != NULL){
        head->next = reverseGroup(next, k);
    }
    return prev;
}
int main(){
    vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8};
    Node* temp = creation(v);
    printList(temp);
    temp = reverseGroup(temp->next, 3);
    printList(temp);
}