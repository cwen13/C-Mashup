#include <stdio.h>

/*
  Exercise 1-8:
   Write a program to count blanks, tabs, and newlines.
*/

int main()
{
  int blanks=0, tabs=0, newlines=0;
  int ch;

  while((ch = getchar()) != EOF)
    {
      switch(ch)
	{
	case ' ':
	  blanks++;
	  break;
	case '\n':
	  newlines++;
	  break;
	case '\t':
	  tabs++;
	  break;
	default:
	  break;
	}
    }

  printf("Blanks\tTabs\tnewlines\n");
  printf("%6d\t %6d\t%6d\n", blanks,  tabs, newlines);

  return 0;
}
