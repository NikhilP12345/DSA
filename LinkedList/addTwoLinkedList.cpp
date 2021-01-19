#include "creationLinkedList.h"
#include <unordered_set>

Node* addList(Node* head1, Node* head2) {
    Node* curr1 = head1;
    Node* curr2 = head2;
    Node* prev1 = NULL;
    int flag = 0;
    while (curr1 != NULL || curr2 != NULL) {
        int val1 = 0;
        int val2 = 0;
        if (curr1) {
            val1 = curr1->data;
        }
        if (curr2) {
            val2 = curr2->data;
        }
        int sum = val1 + val2 + flag;
        if (sum > 9) {
            if (!curr1) {
                Node* newNode = new Node(sum % 10);
                prev1->next = newNode;
                curr1 = NULL;
                prev1 = prev1->next;
            }
            else {
                curr1->data = sum % 10;
            }
            flag = sum / 10;
        }
        else {
            if (!curr1) {
                Node* newNode = new Node(sum);
                prev1->next = newNode;
                curr1 = NULL;
                prev1 = prev1->next;
            }
            else {
                curr1->data = sum;
            }
            flag = 0;
        }
        if (curr1) {
            prev1 = curr1;
            curr1 = curr1->next;
        }
        if (curr2) {
            curr2 = curr2->next;
        }
    }
    return head1;
}



int main() {
    vector<int> v1 = { 3, 6, 5};
    vector<int> v2 = { 8, 4, 6, 4 };
    Node* head1 = creation(v1);
    Node* head2 = creation(v2);
    printList(head1);
    printList(head2);
    Node* temp = addList(head1->next, head2->next);
    printList(temp);

}