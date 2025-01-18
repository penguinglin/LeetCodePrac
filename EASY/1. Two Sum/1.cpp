#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

/*
Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.


* 2 <= nums.length <= 10^4
* -10^9 <= nums[i] <= 10^9
* -10^9 <= target <= 10^9
* Only one valid answer exists.
*/


// sol: hash table
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // create a hash table to store the number and the index
        unordered_map<int, int> hashTable;
        // create a vector to store the answer
        vector<int> ans;
        // iterate through the nums array
        for(int i = 0; i < nums.size(); i++) {
            // if the number is in the hash table
            if(hashTable.find(target - nums[i]) != hashTable.end()) {
                // store the index of the two number
                ans.push_back(hashTable[target - nums[i]]);
                ans.push_back(i);
                return ans;
            }
            // store the number and the index
            hashTable[nums[i]] = i;
        }
        return ans;
        
    }
};