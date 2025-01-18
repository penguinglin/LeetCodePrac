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

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

// compare function for qsort
int cmpfunc(const void* a, const void* b) {
  return ((int*)a)[0] - ((int*)b)[0];
}

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
  // sort the nums array 
  // create an array of nums and the index of the nums array[numSize][2]
  int *numsIndex = (int*)malloc(numsSize*sizeof(int)*2);
  // insert the num and the index
  for(int i = 0; i < numsSize; i++) {
    numsIndex[i*2] = nums[i];
    numsIndex[i*2+1] = i;
  }
  // sort the array by the value of the nums(make index follow the number move when it sort)
  qsort(numsIndex, numsSize, sizeof(int)*2, cmpfunc);

  // print array
   for(int i = 0; i < numsSize; i++) {
     printf("%d %d\n", numsIndex[i*2], numsIndex[i*2+1]);
  }

  // create an array[2] to store ans
  int* ansReturn = (int*)malloc(2*sizeof(int));
  
  // use two pointer to find the sum
  int left = 0, right = numsSize - 1;
  while(left < right) {
    // if the sum of the two number is equal to the target
    if(numsIndex[left*2] + numsIndex[right*2] == target) {
      // store the index of the two number
      ansReturn[0] = numsIndex[left*2+1];
      ansReturn[1] = numsIndex[right*2+1];
      *returnSize = 2;
      return ansReturn;
    }
    else if(numsIndex[left*2] + numsIndex[right*2] < target) 
      left++;
    else 
      right--;
  }

  return ansReturn;
}