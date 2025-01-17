#include <iostream>
using namespace std;

/*
Given an integer num, return the number of steps to reduce it to zero.
In one step, if the current number is even, you have to divide it by 2, otherwise, you have to subtract 1 from it.
*/

// 0 <= num <= 10^6

class Solution {
public:
    int numberOfSteps(int num) {
        int count = 0;
        while (num) {
            count++;
            if (num & 1) {
                num = num - 1;
            } else {
                num = num >> 1;
            }
        }
        return count;
    }
};