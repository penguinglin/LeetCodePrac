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

int CountLength(struct ListNode* head) {
    int count = 0;
    struct ListNode* tmp = head;
    while(tmp != NULL) {
        count++;
        tmp = tmp->next;
    }
    return count;
}

struct ListNode* middleNode(struct ListNode* head) {
    struct ListNode* tmp = head;
    /*
    count the step we need to move:
      *even length: /2
      *odd length: /2
    (the middle node is length/2+1 node, need to move length/2 steps)
    */
    int count = CountLength(head)/2;

    while(count){
        tmp = tmp->next;
        count--;
    }
    return tmp;
}