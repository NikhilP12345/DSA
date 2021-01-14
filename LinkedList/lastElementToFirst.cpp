#include "creationLinkedList.h"

Node* moveFirst(Node* head){
    Node* first = head;
    Node* second = NULL;
    while(first->next != NULL){
        second = first;
        first = first->next;
    }
    second->next = NULL;
    first->next = head->next;
    head->next = first;
    return head;
}

int main(){
    vector<int> v = {1, 2, 3, 4, 5};
    Node* temp = creation(v);
    printList(temp);
    temp = moveFirst(temp);
    printList(temp);
}