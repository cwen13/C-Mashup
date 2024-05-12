/*
  Exercise 1-14:
   Write a program to print a histogram of the frequencies of different characters
   in its input.
*/

#include <stdio.h>

#define MAXLETTERS 256
#define MAXWORDS 50

/*
  make histogram os some frequent letters
  top 5 in english: e, a, r, i o
*/

int findHighest(int height[], int length);

int main()
{
  int let, j, k;
  int lengths[MAXLETTERS];

  for(let=0;let<MAXLETTERS;let++)
    {
      lengths[let]=0;
    }
  
  while((let = getchar()) != EOF)
    {
      ++lengths[let];
    }
  int highest = findHighest(lengths , MAXLETTERS);  
  
  
  printf("Vert Histor of the leters\n---------------------\n");
  
  while(highest+1 >= 0)
    {
      for(j=0; j<MAXLETTERS; j++)
	{
	  if(lengths[j] == 0) continue;
	  if(lengths[j] > highest+1 || lengths[j] < 0)
	    {
	      putchar('*');
	    }
	  else
	    {
	      putchar(' ');
	    }	  
	}
      highest--;
      putchar('\n');
    }
      

  for(j=0; j<MAXLETTERS; j++)
    {
      if(lengths[j] != 0)
	{
	  printf("%c", j);
	}
		  
    }
  putchar('\n');
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
