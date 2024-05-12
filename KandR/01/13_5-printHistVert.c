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
int findHighest(int height[], int length);

int main()
{

  int let, nlets, state, i, j, k;
  int wordLengths[MAXWORDS];

  int highest;
  
  i = 0;
  nlets = 0;
  state = OUT;
  while((let = getchar()) != EOF)
    {
      if(nlets != 0 && (let == ' ' || let == '\n' || let == '\t'))
	{
	  nlets++;
	  state = OUT;
	  printf("Num of letters: %d\n", nlets);
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

  printf("\nThe words in verti histogram\n");
  
  highest = findHighest(wordLengths, i);
  // think of double loop as using a 2D array
    while(highest+1 >= 0)
    {
      putchar('|');
      for(k=0; k < i ; k++)
	{
	  if(wordLengths[k] > highest+1 || wordLengths[k]  < 0)
	    {
	      putchar('*');
	    }
	  else
	    {
	      putchar(' ');
	    }
	}
      putchar('|');
      putchar('\n');
      highest--;
    }

    printf("----------------------------------\n");
    
  return 0;
}


int findHighest(int height[], int length)
{
  int temp, i;

  temp = 0;
  for(i = 0; i < length; i++)
    {
      if(height[i] > temp)
	{
	  temp = height[i];
	}
    }
  return temp;
}
