/*
  Exercise 1-9:
   Write a program to copy its input to its output, replacing each string of one or
   more blanks by a single blank.
 */

#include <stdio.h>

static const int MAXLINE = 1000;

int main()
{
  char prev, letter;
  char reshaped[MAXLINE];
    
  while((letter = getchar()) != EOF)
    {
      if(prev != ' ')
	{
	  putchar(letter);
	}
      prev = letter;
    }
  
  return 0;
}
