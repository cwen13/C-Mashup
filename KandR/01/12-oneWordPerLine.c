/*
  Exercise 1-12:
   Write a program that prints its input one word per line.
*/

#include <stdio.h>

int main()
{
  int letter;

  while((letter = getchar()) != EOF)
    {
      if(letter == ' ' || letter == '\n')
	{
	  putchar('\n');
	}
      else
	{
	  putchar(letter);
	}
      
    }
  putchar('\n');
  
  return 0;
}
