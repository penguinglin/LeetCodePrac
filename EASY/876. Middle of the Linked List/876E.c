#include<stdio.h>
#include<stdlib.h>
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

/*
Given the head of a singly linked list, return the middle node of the linked list.

If there are two middle nodes, return the second middle node.

* The number of nodes in the list is in the range [1, 100]
* 1 <= Node.val <= 100
*/

struct ListNode {
    int val;
    struct ListNode *next;
};

//  use the fast-slow solution to find the middle
struct ListNode* middleNode(struct ListNode* head) {
    if (head == NULL) return NULL;
    struct ListNode* fast = head;
    struct ListNode* slow = head;

    // fast moves 2 steps, slow moves 1 step
    // we must carefully check the NULL case
    while (fast != NULL && fast->next != NULL) {
        fast = fast->next->next;
        slow = slow->next;
    }   
    return slow;
}