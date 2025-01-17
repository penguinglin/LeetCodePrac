#include<stdio.h>
#include<string.h>
#include<stdbool.h>

/*
Given two strings ransomNote and magazine, return true if ransomNote can be constructed by using the letters from magazine and false otherwise.

Each letter in magazine can only be used once in ransomNote.

* 1 <= ransomNote.length, magazine.length <= 10^5
* ransomNote and magazine consist of lowercase English letters.
*/

bool canConstruct(char* ransomNote, char* magazine) {
    int ransomNoteArray[26], magazineArray[26];
    int ranmin = 26, magmin = 26;

    // initialize arrays
    memset(ransomNoteArray, 0, sizeof(ransomNoteArray));
    memset(magazineArray, 0, sizeof(magazineArray));

    // record the number of each character in the ransomNote and magazine
    char *checkitem = ransomNote;
    while(*checkitem!='\0'){
        ransomNoteArray[*checkitem-'a']++;
        ranmin = ranmin < *checkitem-'a' ? ranmin : *checkitem-'a';
        checkitem++;
    }
    checkitem = magazine;
    while(*checkitem!='\0'){
        magazineArray[*checkitem-'a']++;
        magmin = magmin < *checkitem-'a' ? magmin : *checkitem-'a';
        checkitem++;
    }

    // record the min index of the array, so that we can skip the first few elements and Early return
    if(ranmin < magmin){
        return false;
    }
    for(int i=ranmin; i<26; i++){
        if(ransomNoteArray[i]>magazineArray[i]){
            return false;
        }
    }

    return true;
}