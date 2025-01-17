#include<iostream>
#include<string>
#include<vector>
using namespace std;

/*
Given two strings ransomNote and magazine, return true if ransomNote can be constructed by using the letters from magazine and false otherwise.

Each letter in magazine can only be used once in ransomNote.

* 1 <= ransomNote.length, magazine.length <= 10^5
* ransomNote and magazine consist of lowercase English letters.
*/

class Solution {
public:
    bool canConstruct(const string& ransomNote, const string& magazine) {
        vector<int> v(26);
        for(auto c : magazine) v[c-'a']++;
        for(auto c : ransomNote) {
            v[c-'a']--;
            if (v[c-'a'] < 0) return false;
        }
        return true;
    }
};