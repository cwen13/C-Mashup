// DID NOIT SOLVE 
/*
  Exercise 4-9:
  Our getch and ungetch do not handle a pushed-back EOF correctly.
  Decide what their properties ought to be if an EOF is pushed back,
  then implement your design.
*/

#include "myio.h"
#include <stdio.h>
#include <ctype.h>

#define BUFSIZE 16

int buffchar;
int ibuf = 0;	/* 0 not saved and 1 saved */

int getch(void) 
{
  if(ibuf)
    {
      ibuf = 0;
      return buffchar;
    }

  return getchar();
}

int ungetch(int c) 
{
  if(ibuf) {

    return -1;
  }
  buffchar = c;
  ibuf = 1;

  return 0;
}

