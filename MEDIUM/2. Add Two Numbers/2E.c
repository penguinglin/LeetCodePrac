#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

/*
You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

The number of nodes in each linked list is in the range [1, 100].
0 <= Node.val <= 9
It is guaranteed that the list represents a number that does not have leading zeros.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode {
     int val;
     struct ListNode *next;
};

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
 struct ListNode* listHead = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* listTail = listHead;
    listTail->val = 0;
    while (true) {
        int val = (l1 ? l1->val: 0) + (l2 ? l2->val: 0) + listTail->val;

        listTail->val = val % 10;
        
        l1 = l1 ? l1->next : NULL;
        l2 = l2 ? l2->next : NULL;
        
        if (l1 || l2 || val/10) {
            listTail->next = (struct ListNode*)malloc(sizeof(struct ListNode));
            listTail->next->val = val/10;
            listTail = listTail->next;
            
        }
        else {
            listTail->next = NULL;
            return listHead;
        }
    }
}