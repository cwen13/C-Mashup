// DID NOIT SOLVE 
/*
  Exercise 4-10:
  An alternate organization uses getline to read an entire input line;
  this makes getch and ungetch unnecessary. Revise the calculator
  to use this approach.
 */

#include "myio.h"
#include <stdio.h>
#include <ctype.h>

#define BUFSIZE 16

unsigned long int nb = 0;
char *buff = NULL;
int len=0; // number of chars read ine
int pos=0; // current buffer position

int fillBuff(void)
{
  if((len = getline(&buff, &nb, stdin)) < 0)
    {

      return -1;
    }
  pos=0;

  return 0;
}

int getch(void) 
{
  // fill buffer if it is empty
  if(len - pos == 0)
    {
      if(fillBuff() == -1)
	{
	  return -1;
	}
    }

  return buff[pos++];
}

int ungetch(int c) 
{
  if(pos==0);
    {
      return -1;
    }
  buff[--pos] = c;

  return 0;
}

