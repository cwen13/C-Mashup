/*
  Exercise 5-2:
  Write getfloat, the floating-point analog of getint. What
  type does getfloat return as its function value?
 */


#include <stdio.h>
#include <ctype.h>
#include <math.h>

double getfloat(double *pf);

int main(void)
{
  int res;
  double db;

  do{
    printf("> ");
    res = getfloat(&db);
    switch (res){
    case 0:
      printf("Not an integer!\n");
      break;
    case 1:
      printf("Float: %6.3f\n", db);
      break;
    case EOF:
      printf("End Of File!\n");
      break;
    }
  }while (res > 0);

  return 0;

  return 0;
}

double getfloat(double *pf)
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

      *pf = 0;
      while(isdigit(c))
	{
	  *pf = *pf * 10.0 + (c - '0');
	  c = getc(stdin);
	}

      if(c == '.')
	{
	  int i = 1;
	  while((c=getc(stdin)) && isdigit(c))
	    {
	      printf("PF: %f\n", *pf);
	      *pf = *pf + pow(10, (-1*i++)) * (c - '0');
	    }
	}
      /* SOLUTION METHOD
       *if (c == '.') {
       *	int power = 1;
       *	c = getc(stdin);
       *	while (isdigit(c)) {
       *		isnum = 1;
       *		power *= 10;
       *		*pn = *pn * 10 + c - '0';
       *		c = getc(stdin);
       *	}
       *	*pn /= power;
       *}	
       */


      *pf *= sign;
      ungetc(c,stdin);

      return 1;
}
