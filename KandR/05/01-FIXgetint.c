/*
  Exercise 5-1:
  As written, getint treats a + or - not followed by a digit as
  a valid representation of zero. Fix it to push such a character
  back on the input.
 */
#include <stdio.h>
#include <ctype.h>

/* return 1 on success, 0 if not a number and EOF on end of file */
int getint(int* pn);

int main(void)
{
  int res, n;

  do{
    printf("> ");
    res = getint(&n);
    switch (res){
    case 0:
      printf("Not an integer!\n");
      break;
    case 1:
      printf("Integer: %d\n", n);
      break;
    case EOF:
      printf("End Of File!\n");
      break;
    }
  }while (res > 0);
o
  return 0;
}


/* getint: get next int from input into *pn */
int getint(int *pn)
{
      int c, sign;
      while(isspace(c=getc(stdin))); // skipp white space

      if(c == EOF)
	{

	  return EOF;
	}
      
      if(!isdigit(c) && c != '+' && c != '-')
	{
	 ungetc(c,stdin); //it is not a number
	  
	  return 0;
	}
      sign = (c == '-') ? -1 : 1;
      if(c =='+' || c == '-')
	{
	  c = getc(stdin);
	}
      if(!isdigit(c))
	{
	  ungetc(c,stdin);

	  return 0;
	}

      *pn = 0;
      while(isdigit(c))
	{
	  *pn = 10 * *pn + (c - '0');
	  c = getc(stdin);
	}
      *pn *= sign;
      ungetc(c,stdin);

      return 1;
}
