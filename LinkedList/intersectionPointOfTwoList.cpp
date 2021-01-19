#include "creationLinkedList.h"

int intersection(Node* head1, Node* head2){
    Node* ptr1 = head1;
    Node* ptr2 = head2;
    while(ptr1 != ptr2){
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
        if(ptr1 == ptr2){
            return ptr1->data;
        }
        if(ptr1 == NULL){
            ptr1 = head2;
        }
        if(ptr2 == NULL){
            ptr2 = head1;
        }
    }
    return ptr1->data;
}

int main() {
    vector<int> v1 = { 3, 6, 15, 30};
    vector<int> v2 = { 10};
    Node* head1 = creation(v1);
    Node* head2 = creation(v2);
    head2->next->next = head1->next->next->next;
    printList(head1);
    printList(head2);
    cout<< intersection(head1->next, head2->next);
}