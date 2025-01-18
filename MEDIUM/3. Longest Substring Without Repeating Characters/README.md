# 3. Longest Substring Without Repeating Characters

## Statement

Given a string s, find the length of the longest substring without repeating characters.

* `0 <= s.length <= 5 * 10^4`
* `s` consists of English letters, digits, symbols and spaces.

## Topic
`Hash Table`, `String`, `Sliding Window`

## Sol Explain

1. use array[128] to record the substring's character
  
  > The longest string might be one of the below:
  > (1) substring + now item (if item doesn't appear in the substring)
  > (2) substring (if now item appear in the substring)
  > (3) (substring - the same item as now item) + now item

  => Time limit exceeded && may have some bugs!!!!

2. slide window
   
  > Use two pointer to record the substring's start/end position.

  => Time Complexity: O(n)
  => Space Complexity: O(1)


* `C++` can use map to record the <char, int> relationship easily