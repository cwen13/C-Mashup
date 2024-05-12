//COMPLETED
/*
  Exercise 2-5:
  Write the function any(s1,s2), which returns the first location in a
  string s1 where any character from the string s2 occurs, or -1
  if s1 contains no characters from s2.
  (The standard library function strpbrk does the same job but
  returns a pointer to the location.)
*/

#include <stdio.h>

#define MAXWORD 100

int any(char s1[], char s2[]);

int main()
{
  int c, i;
  long unsigned ls, le;
  char *s, *e;
  
  while(c != EOF)
    {
      printf("S: ");
      if(getline(&s, &ls, stdin) == -1)
	{
	  printf("ERROR GETLINE: possible EOF!\n");
	  return 1;
	}
	
      printf("E: ");
      if(getline(&e, &le, stdin) == -1)
	{
	  printf("ERROR GETLINE: possible EOF!\n");
	  return 1;
	}
		
      printf("Lettters in S2 are found in S1 at index: %d\n", any(s, e));
    }
  
  return 0;
}

int any(char s[], char l[])
{
  int index, jndex;

  for(index=0; s[index] != '\0'; index++)
    {
      for(jndex=0; l[jndex] != '\0'; jndex++)
	{

	  if(l[jndex] == s[index])
	    {
	      printf("There is a match!\n");
	      return index;
	    }
	}
    }

  return -1;
}

