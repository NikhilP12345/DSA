#include "creationLinkedList.h"

Node* reverse(Node* head){
    Node* curr = head;
    Node* prev = NULL;
    Node* next = NULL;
    while(curr != NULL){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
    return head;
}

Node* addOne(Node* head){
    head = reverse(head);
    Node* temp = head;
    int flag = 1;
    while(flag != 0 && temp != NULL){   
        int val = temp->data;
        val += 1;
        if(val > 9){
            temp->data = 0;
            flag = 1;
        }
        else{
            temp->data = val;
            flag = 0;
        }
        temp = temp->next;
    }
    if(flag == 1 && temp == NULL){
        Node* newNode = new Node(1);
        newNode->next = head;
        head = newNode;
        return head;
    }
    head = reverse(head);
    return head;
}

int main(){
    vector<int> v = {1,2,9,9};
    Node* temp = creation(v);
    printList(temp);
    temp = addOne(temp->next);
    printList(temp);
}
