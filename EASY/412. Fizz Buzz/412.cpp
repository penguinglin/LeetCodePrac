#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
  vector<string> fizzBuzz(int n)
  {
    vector<string> returnArray(n);
    for (int i = 1; i <= n; ++i)
    {
      if (i % 3 == 0 && i % 5 == 0)
        returnArray[i - 1] = "FizzBuzz";
      else if (i % 3 == 0)
        returnArray[i - 1] = "Fizz";
      else if (i % 5 == 0)
        returnArray[i - 1] = "Buzz";
      else
        // C++11 to_string
        returnArray[i - 1] = to_string(i);
    }
    return returnArray;
  }
};