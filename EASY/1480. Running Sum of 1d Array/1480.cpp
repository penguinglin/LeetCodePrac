// include all standard libraries in C++.
#include <bits/stdc++.h>
using namespace std;

// Because of the cache behavior, use extra variable to store the num of array is more efficient
class Solution
{
public:
  vector<int> runningSum(vector<int> &nums)
  {
    int sum = nums[0];
    for (int i = 1; i < nums.size(); i++)
    {
      sum += nums[i];
      nums[i] = sum;
    }
    return nums;
  }
};