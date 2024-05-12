
/* DID NOT COMPLETE ON OWN
   but i was on he right track, i had set upi th enet to catch hyphens
   but big part I was missing was teh check against j, s2 posiiton, was
   less than the max line length
/*
  Exercise 3-3:
  Write a function expand(s1,s2) that expands shorthand notations like a-z
  in the string s1 into the equivalent complete list abc...xyz in s2.
  Allow for letters of either case and digits, and be prepared to handle
  cases like a-b-c and a-z0-9 and -a-z. Arrange that a leading or
  trailing - is taken literally.
*/

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h> 

#define MAXLINE 1000

int expand(const char s1[], char s2[], int n);

int main()
{
  char *s1;
  char s2[MAXLINE];
  int len,  i;
  long unsigned int n;

  s1 = NULL;
  
  while((len = getline(&s1, &n, stdin)) > 0)
    {
      if(expand(s1, s2, MAXLINE) == -1)
	{
	  printf("ERROR EXPAND: insufficnet length for s2(max size: %d)\n", MAXLINE);
	  
	  return -1;
	}
    }
  
  free(s1);

  return 0;
}

int expand(const char s1[], char s2[], int n)
{
  int i, j, k;
  int start, mid, end;

  i = 0;
  j = 0;

  while(s1[i] != '\0')
    {
      start = s1[i];
      mid = s1[i+1];
      end = mid != '\0' ? s1[i+2]: '\0';

      if(mid == '-' && end > start
	 && ((isdigit(start) && isdigit(end))
	     || (isupper(start) && isupper(end))
	     || (islower(start) && islower(end))))
	{
	  while(end!=start)
	    {
	      s2[j++] = start++;
	      if(j>=n)
		{
		  
		  return -1;
		}
	    }
	  i++;
	}
      else
	{
	  s2[j++] = s1[i];
	  if(j>=n)
	    {
		  
	      return -1;
	    }
	}
      i++;
    }
  s2[j] = '\0';
}
