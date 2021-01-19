#include "creationLinkedList.h"

Node* intersectionSorted(Node* head1, Node* head2){
    Node* ptr1 = head1;
    Node* ptr2 = head2;
    Node* temp = NULL;
    Node* currPtr = temp;
    while(ptr1 != NULL && ptr2 != NULL){
        if(ptr1->data == ptr2->data){
            if(currPtr){
                currPtr->next = new Node(ptr1->data);
                currPtr = currPtr->next;
            }
            else{
                currPtr = new Node(ptr1->data);
                temp = currPtr;
            }
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
        else if(ptr1->data < ptr2->data){
            ptr1 = ptr1->next;
        }
        else{
            ptr2 = ptr2->next;
        }
    }
    return temp;
}

int main() {
    vector<int> v1 = { 1, 2, 3 ,4, 6};
    vector<int> v2 = { 2, 4, 6, 8};
    Node* head1 = creation(v1);
    Node* head2 = creation(v2);
    printList(head1);
    printList(head2);
    Node* temp = intersectionSorted(head1->next, head2->next);
    printList(temp);
}