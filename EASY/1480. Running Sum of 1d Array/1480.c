#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int *runningSum(int *nums, int numsSize, int *returnSize)
{
  /*
  runningSum[i] = sum(nums[0]…nums[i])
  1 <= nums.length <= 1000
  -10^6 <= nums[i] <= 10^6
  */

  // 1. prefix sum
  // 2. no overfitting -> int
  *returnSize = numsSize; // size for the new array to be returned

  for (int i = 1; i < numsSize; i++)
  {
    nums[i] += nums[i - 1];
  }
  return nums;
}