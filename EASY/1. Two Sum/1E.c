#include<stdio.h>
#include<stdlib.h>

/*
Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.


* 2 <= nums.length <= 10^4
* -10^9 <= nums[i] <= 10^9
* -10^9 <= target <= 10^9
* Only one valid answer exists.
*/

// target -> 10^9 -> need to store the index of the number
// space use good, but poor efficiency

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    int static sum[2];  // 使用静态数组
    *returnSize = 2;    // 设置返回大小为 2，因为返回两个索引
    
    // O(n^2) brute force
    for (int i = 0; i < numsSize; i++) {
        for (int j = i + 1; j < numsSize; j++) {
            if (nums[i] + nums[j] == target) {
                sum[0] = i;
                sum[1] = j;
                return sum;  // 返回静态数组的指针
            }
        }
    }
    
    *returnSize = 0;
    return NULL; 
}