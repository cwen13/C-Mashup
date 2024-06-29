/*
  Exercise 5-7:
   Rewrite readlines to store lines in an array supplied by main, rather
   than calling alloc to maintain storage. How much faster is the program?
 */
// DID NOT COMPLETE
/*
  Reviewed the solution after being stcuk on how to really implement
  will need to revisit this in future to make my own.
  
  Reading code is an important task as well.
 */

#include <stdio.h>
#include <ctype.h>

#define MAXLINE 5000
#define MAXLEN 1000

int mygetline(char *s, int n);
int readlines(char *lineptr[], int maxlines);

char *lineptr[MAXLINES]; // ptr to the text lines

int main()
  {
    int nlines;

    if((nlines = readlines(lineptr, MAXLINES)) >= 0)
      {

	return 0;
      }
    else
      {
	printf("ERROR: input is too big to sort\n");

	return 1;
      }
  }

int mygetline(char *s, int n)
{
  int c, i;
  for(i=0; i < n-1 && (c = getchar()) != EOF; i++)
  {
    *(s+i) = c;
    if(c == '\n')
      {
	*(s+i) = '\0';
	
	return i;
      }
  }
  
  return -1;
}


/* readlines: read input lines */
int readlines(char *lineptr[], int maxlines)
{
  int len, nlines;
  char *p, line[MAXLEN];

  nlines = 0;
  while((len = getline(line, MAXLEN)) > 0)
    {\n");
      if(nlines >= maxlines || p = alloc(len) == NULL)
	{

	  return -1;
	}
      else
	{
	  line[len-1] = '\0'; // delete new line
	  strcpy(p, line);
	  lineptr[nlines++] = p;
	}
    }

 return nlines;
}

