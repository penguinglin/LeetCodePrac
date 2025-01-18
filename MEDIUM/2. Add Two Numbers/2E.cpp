#include<iostream>
using namespace std;

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
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
struct ListNode
{
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

#include <filesystem>
#include <iostream>
#include <string>
#include <fstream>

inline bool isDigit(const char c) {
    return (c >= '0') && (c <= '9');
}
void parse_and_solve(const std::string& s1, const std::string& s2, std::ofstream& out) {
    const int S1 = s1.size();
    const int S2 = s2.size();
    if (S1 < S2) {
        parse_and_solve(s2, s1, out);
        return;
    }
    int carry = 0;
    int i = 0;
    int j = 0;
    while (i < S1 - 1) {
        while (i < S1 && (!isDigit(s1[i]))) { ++i; }
        while (j < S2 && (!isDigit(s2[j]))) { ++j; }
        const int n1 = s1[i] - '0';
        const int n2 = (j < S2) ? (s2[j] - '0') : 0;
        const int n = carry + n1 + n2;
        carry = n / 10;
        out << (n % 10);
        if (i < S1 - 2) {
            out << ",";
        }
        ++i;
        ++j;
    }
    if (carry > 0) {
        out << "," << carry;
    }
}

using namespace std;

static bool Solve = [](){
    std::ofstream out("user.out");
    std::string s1, s2;
    while (std::getline(std::cin, s1) && std::getline(std::cin, s2)) {
        out << "[";
        cout<<s1<<" "<<s2<<endl;
        parse_and_solve(s1, s2, out);
        out << "]\n";
    }
    out.flush();
    exit(0);
    return true;
}();

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        int carry = 0;
        int twoPlus;

        twoPlus = l1->val + l2->val + carry;

        carry = twoPlus/10;

        l1 = l1->next;
        l2 = l2->next;

        ListNode* head = new ListNode(twoPlus % 10); // first node
        ListNode* nodeIn = head;

        while(!(l1 == nullptr && l2 == nullptr)){
            twoPlus = carry;
            if (l1 != nullptr) {
                twoPlus += l1->val;
                l1 = l1->next;
            }
            if (l2 != nullptr) {
                twoPlus += l2->val;
                l2 = l2->next;
            }
            carry = twoPlus / 10;
            nodeIn->next = new ListNode(twoPlus % 10);
            nodeIn = nodeIn->next;
        }

        if (carry != 0) nodeIn->next = new ListNode(carry);

        return head;
    }
};