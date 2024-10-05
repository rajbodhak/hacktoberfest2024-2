#include <iostream>
using namespace std;

// Definition for singly-linked list node.
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

// Function to reverse the singly linked list
ListNode* reverseList(ListNode* head) {
    ListNode* prev = NULL;  // Previous pointer
    ListNode* curr = head;  // Current pointer

    while (curr != NULL) {
        ListNode* nextTemp = curr->next;  // Store next node
        curr->next = prev;                // Reverse the current node's pointer
        prev = curr;                      // Move previous pointer forward
        curr = nextTemp;                  // Move current pointer forward
    }
    return prev;  // New head is the previous node
}

// Utility function to print the linked list
void printList(ListNode* head) {
    while (head != NULL) {
        cout << head->val << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

int main() {
    // Creating the linked list 1 -> 2 -> 3 -> 4 -> 5
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    cout << "Original List: ";
    printList(head);

    // Reversing the linked list
    head = reverseList(head);

    cout << "Reversed List: ";
    printList(head);

    return 0;
}
