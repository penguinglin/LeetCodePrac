#include<iostream>
#include<string>
#include<vector>
#include<map>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
      map<char, int> record;
      int maxLen = 0, start = 0;

      for (int curIndex = 0; curIndex < s.size(); curIndex++) {
        char nowChar = s[curIndex];

        if (record.find(nowChar) != record.end() && record[nowChar] >= start) {
          start = record[nowChar] + 1;
        }

        record[nowChar] = curIndex;

        int curLen = curIndex - start + 1;
        if (curLen > maxLen) {
          maxLen = curLen;
        }
      }

      return maxLen;
    }
};