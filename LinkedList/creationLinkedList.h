#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};

Node* creation(vector<int> v){
    Node* head = new Node(0);
    Node* temp = head;
    for(int i = 0 ; i < v.size() ; i++){
        temp->next = new Node(v[i]);
        temp = temp->next;
    }
    return head;
}

void printList(Node* head){
    while(head != NULL){
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}