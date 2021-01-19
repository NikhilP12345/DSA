#include "creationLinkedList.h"

Node* shift(Node* head, int k){
    Node* p = head;
    int l = 1;
    while(p->next != NULL){
        p = p->next;
        l++;
    }
    int off = abs(k) % l;
    if(off == 0){
        return head;
    } 
    int newPos = k > 0 ? l - off : off;
    Node* cutNode = head;
    for(int i = 1 ; i < newPos ; i++){
        cutNode = cutNode->next;
    }
    Node* requiredNode = cutNode->next;
    cutNode->next = NULL;
    p->next = head;
    return requiredNode;
}

int main(){
    vector<int> v = { 2, 6, 7, 8};
    Node* head = creation(v);
    printList(head);
    int k = 2;
    Node* temp = shift(head, k);
    printList(temp);
}