/*
  Exercise 1-13:
   Write a program to print a histogram of the lengths of words in its input. It is
   easy to draw the histogram with the bars horizontal; a vertical orientation is
   more challenging.
 */

#include <stdio.h>

#define IN 1
#define OUT 0
#define MAXWORDS 50

/* make histogram of words entered on each line */
/* assumes word wrapping is done where there is a space */
int main()
{

  int let, nlets, state, i, j;
  int wordLengths[MAXWORDS];

  i = 0;
  nlets = 0;
  state = OUT;
  while((let = getchar()) != EOF)
    {
      if(nlets != 0 && (let == ' ' || let == '\n' || let == '\t'))
	{
	  nlets++;
	  state = OUT;
	  printf("Num of letters: %d", nlets);
	  wordLengths[i] = nlets;
	  nlets = 0;
	  i++;
	}
      else if(state == OUT)
	{
	  state = IN;
	}
      else
	{
	  nlets++;
	}
    }

  printf("The word histogram horizontally\n");
	 
  j = 0;
  while(wordLengths[j] != 0)
    {
      for(int k=0; k < wordLengths[j]; k++)
	{
	  putchar('*');
	}
      putchar('\n');
      j++;
    }
     
  return 0;
}

