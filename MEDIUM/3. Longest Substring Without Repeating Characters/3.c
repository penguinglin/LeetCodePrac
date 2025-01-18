#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int lengthOfLongestSubstring(char* s) {
    int record[128]; 
    memset(record, -1, sizeof(record)); 

    int maxLen = 0, start = 0; 

    for (int curIndex = 0; s[curIndex] != '\0'; curIndex++) {
        char nowChar = s[curIndex];

        // update start if the ascii value of nowChar is already in the substring
        if (record[nowChar] >= start) {
            start = record[nowChar] + 1;
        }

        // update record to the latest index of Char
        record[nowChar] = curIndex;

        // update maxLen
        int curLen = curIndex - start + 1;
        if (curLen > maxLen) {
            maxLen = curLen;
        }
    }

    return maxLen;
}