#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;
/*
  You are given an m x n integer grid accounts where accounts[i][j] is the amount of money the i​​​​​​​​​​​th​​​​ customer has in the j​​​​​​​​​​​th​​​​ bank.
  Return the wealth that the richest customer has.

  A customer's wealth is the amount of money they have in all their bank accounts.
  The richest customer is the customer that has the maximum wealth.
*/

// m == accounts.length
// n == accounts[i].length
// 1 <= m, n <= 50
// 1 <= accounts[i][j] <= 100

class Solution
{
public:
  int maximumWealth(vector<vector<int>> &accounts)
  {
    int maxWealth = 0, sum;
    for (int i = 0; i < accounts.size(); i++)
    {
      sum = 0;
      for (int j = 0; j < accounts[i].size(); j++)
        sum += accounts[i][j];
      if (sum > maxWealth)
        maxWealth = sum;
    }

    return maxWealth;
  }
};