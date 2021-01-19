#include "creationLinkedList.h"

Node* buildingLoop(vector<int> v){
    Node* head = creation(v);
    Node* curr = head->next;
    Node* temp = NULL;
    while(curr->next != NULL){
        if(curr->data == 5){
            temp = curr;
        }
        curr = curr->next;
    }
    curr->next = temp;
    return head;
}

int findLoop(Node *head){
    Node* first = head->next;
    Node* second = head->next->next;
    while(first != second){
        first = first->next;
        second = second->next->next;
    }
    first = head;
    while(first != second){
        first = first->next;
        second = second->next;
    }
    return first->data;

}
int main(){
    vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9}; 
    Node* temp = buildingLoop(v);
    cout << findLoop(temp);
}