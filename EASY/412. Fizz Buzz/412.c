#include <stdio.h>
#include <stdlib.h>
/*
Given an integer n, return a string array answer (1-indexed) where:
  * answer[i] == "FizzBuzz" if i is divisible by 3 and 5.
  * answer[i] == "Fizz" if i is divisible by 3.
  * answer[i] == "Buzz" if i is divisible by 5.
  * answer[i] == i (as a string) if none of the above conditions are true.
*/

// 1 <= n <= 104

char **fizzBuzz(int n, int *returnSize)
{
  // return an double pointer array
  char **returnArray = (char **)malloc(sizeof(char *) * n);
  *returnSize = n;
  for (int i = 1; i <= n; i++)
  {
    // allocate memory for each string
    returnArray[i - 1] = (char *)malloc(sizeof(char) * 9);

    if (i % 15 == 0)
      strcpy(returnArray[i - 1], "FizzBuzz");
    else if (i % 3 == 0)
      strcpy(returnArray[i - 1], "Fizz");
    else if (i % 5 == 0)
      strcpy(returnArray[i - 1], "Buzz");
    else
      sprintf(returnArray[i - 1], "%d", i);
  }
  return returnArray;
}