#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>
using namespace std;

// other solution, not better memory usage but still can be recorded
class Solution
{
public:
  vector<string> fizzBuzz(int n)
  {
    static vector<string> returnArray;
    static int LargestIndex = 1;

    static string FizzBuzz = "FizzBuzz";
    static string Fizz = "Fizz";
    static string Buzz = FizzBuzz.substr(4); // "Buzz"

    if (n <= LargestIndex)
    {
      return vector<string>(returnArray.begin(), returnArray.begin() + n);
    }

    for (int i = LargestIndex; i < n + 1; ++i)
    {
      if (i % 15 == 0)
        returnArray.push_back(FizzBuzz);
      else if (i % 3 == 0)
        returnArray.push_back(Fizz);
      else if (i % 5 == 0)
        returnArray.push_back(Buzz);
      else
        returnArray.push_back(to_string(i));
    }

    if (n > LargestIndex)
      LargestIndex = n + 1;

    return returnArray;
  }
};