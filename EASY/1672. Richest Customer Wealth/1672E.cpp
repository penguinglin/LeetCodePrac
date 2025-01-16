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
// sol 2 : using accumulate, max to improve the code

class Solution
{
public:
  int maximumWealth(vector<vector<int>> &accounts)
  {
    int maxWealth = 0, sum;
    for (const auto &customer : accounts)
    {
      // accumulate : sum of the elements in the range [first, last)
      int wealth = accumulate(customer.begin(), customer.end(), 0);
      // max : return the largest of the two values
      maxWealth = max(maxWealth, wealth);
    }

    return maxWealth;
  }
};