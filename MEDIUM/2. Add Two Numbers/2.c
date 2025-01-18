#include<stdio.h>
#include<stdlib.h>

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
    // use two pointer to point the current node of l1 and l2
    struct ListNode *p1 = l1, *p2 = l2;

    // loop till all nodes in l1 and l2 are visited
    // use two int value record two nodes' value
    int val1, val2, carry = 0, firstNode = 1; 
    // create the head of the link list
    struct ListNode *head = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode *p = head;
    p->next = NULL;
    while(p1 != NULL || p2 != NULL || carry != 0){
      // set val1 and val2 to the value of current node
      val1 = (p1 == NULL) ? 0 : p1->val;
      val2 = (p2 == NULL) ? 0 : p2->val;

      // create new node and link it to the current node(remember to init the next and val to NULL)
      // if it is the first node, insert to current node
      int sum = val1 + val2 + carry;
      carry = sum / 10;
      if (firstNode) {
          p->val = sum % 10;
          firstNode = 0;
      } else {
          p->next = (struct ListNode*)malloc(sizeof(struct ListNode));
          p->next->val = sum % 10;
          p->next->next = NULL;
          p = p->next;
      }

      // move to the next node
      if (p1 != NULL) p1 = p1->next;
      if (p2 != NULL) p2 = p2->next;
    }


    // print the result
    struct ListNode *now = head;
    while(now != NULL){
      printf("%d ", now->val);
      now = now->next;
    }

    return head;
}