#include "creationLinkedList.h"

Node* mergeList(Node* h1, Node* h2){
    Node* p1 = h1;
    Node* p2 = h2;
    Node* prev = NULL;

    while(p1 != NULL && p2 != NULL){
        if(p1->data < p2->data){
            prev = p1;
            p1 = p1->next;
        }
        else{
            if(prev != NULL){
                prev->next = p2;
            }
            prev = p2;
            p2 = p2->next;
            prev->next = p1; 
        }
    }
    if(p1 == NULL){
        prev->next = p2;
    }
    return h1->data < h2->data ? h1: h2;
}

int main() {
    vector<int> v1 = { 2, 6, 7, 8};
    vector<int> v2 = { 1, 3, 4, 5, 9, 10};
    Node* head1 = creation(v1);
    Node* head2 = creation(v2);
    printList(head1);
    printList(head2);
    Node* head3 = mergeList(head1->next, head2->next);
    printList(head3);
}