#include "creationLinkedList.h"

Node* removeDuplicatesSorted(Node* head){
    Node* curr = head;
    Node* nextP = NULL;
    while(curr->next != NULL){
        if(curr->data == curr->next->data){
            nextP = curr->next->next;
            curr->next = nextP;
        }
        else{
            curr = curr->next;
        }
    }
    return head;
}
Node* removeDuplicatesUnSorted(Node* head){
    unordered_set<int> s;
    Node* curr = head;
    Node* prevP = NULL;
    while(curr != NULL){
        if(s.find(curr->data) == s.end()){
            s.insert(curr->data);
            prevP = curr;
            curr = curr->next;
        }
        else{   
            prevP->next = curr->next;
            curr = prevP->next;
        }
    }
    return head;

}

int main(){
    vector<int> v = {12, 11, 12, 21, 41, 43, 21};
    Node* temp = creation(v);
    printList(temp);
    // temp = removeDuplicatesSorted(temp);
    temp = removeDuplicatesUnSorted(temp);
    printList(temp);
    
}