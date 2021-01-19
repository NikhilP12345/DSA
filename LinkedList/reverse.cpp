#include "creationLinkedList.h"

//iterative
Node* reverse(Node* head){
    Node* curr = head->next;
    Node* prev = NULL, *next = NULL;
    while(curr != NULL){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
    return head;
}

//recursive
Node* recursiveReverse(Node* head){
    if(head == NULL || head->next == NULL){
        return head;
    }
    Node* rest = recursiveReverse(head->next);
    head->next->next = head;
    head->next = NULL;
    return rest;
}

int main(){
    vector<int> v = {1, 2, 3,4};
    Node* temp = creation(v);
    printList(temp);
    temp = recursiveReverse(temp->next);
    printList(temp);
}