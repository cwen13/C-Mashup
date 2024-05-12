
/*
  Exercise 4-1:
  Write the function strindex(s,t) which returns the position of the rightmost
  occurrence of t in s, or -1 if there is none.
 */

#include <stdio.h>
#include <ctype.h>

#define MAXLINE 1000

int strindexRight(char s[], const char t[]);

int main()
{
  char *line;
  char *pat;

  int loc;
  long unsigned int nlin, npat;
  
  while(getline(&line, &nlin, stdin) > 0)
    {
      if(getline(&pat, &npat, stdin) <= 0)
	{
	  printf("getline: ERROR reading pattern!\n");
	  
	  return 1;
	}
      printf("Last position is at: %d\n", pat, strindexRight(line, pat));
    }

  return 0;
}

int strindexRight(char s[], const char t[])
{
  int i,j,k;
  int temp = 0;
  int found = -1;

  for(i=0; s[i] != '\0'; i++)
      {
	for (j=i, k=0; t[k]!='\0' && t[k]!='\n' && s[j] == t[k]; j++, k++)
	  ;
	if(k>0 && (t[k] == '\0' || t[k] == '\n'))
	  {
	    found = i;
	  }
      }
  
  return found;
}
