#include<iostream>
#include<string>
using namespace std;

/*
Given two strings ransomNote and magazine, return true if ransomNote can be constructed by using the letters from magazine and false otherwise.

Each letter in magazine can only be used once in ransomNote.

* 1 <= ransomNote.length, magazine.length <= 10^5
* ransomNote and magazine consist of lowercase English letters.
*/

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int ranLen = ransomNote.length(), magLen = magazine.length();

        // Early return
        if (ranLen > magLen) {
            return false;
        }

        // check item in ransomNote
        for (int i = 0; i < ranLen; i++) {
            size_t found = magazine.find(ransomNote[i]);
            if (found == string::npos) {
                return false; // early return
            }
            magazine[found] = '*';
        }

        return true;
    }
};