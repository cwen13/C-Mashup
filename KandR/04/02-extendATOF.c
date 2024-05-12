/*
  Exercise 4-2:
  Extend atof to handle scientific notation of the form 123.45e-6
  where a floating-point number may be followed by e or E and an
  optionally signed exponent.
 */

#include <stdio.h>
#include <ctype.h>

double atof(char s[]);

int main()
{

  char *number;
  long unsigned int n;

  number=NULL;
  n=0;

  while(getline(&number, &n, stdin) > 0)
    {
      printf("%f\n", atof(number));

    }

  return 0;
}

double atof(char s[])
{
  double val, power, exp;
  int sign, expsign, i;

  for(i=0; isspace(s[i]); i++) // skipp whitespace
    ;
  sign = (s[i] == '-') ? -1 : 1;
  if(s[i] == '+' || s[i] == '-')
    {
      i++;
    }
  for(val = 0.0; isdigit(s[i]); i++)
    {
      val = 10.0 * val + (s[i] -'0');
    }
  if(s[i] == '.')
    {
      i++;
    }
  for(power = 1.0; isdigit(s[i]); i++)
    {
      val = 10.0 * val +(s[i] -'0');
      power *= 10;
    }
  if(s[i] == 'e' || s[i] == 'E')
    {
      i++;
    }
  expsign = (s[i] == '-') ? -1 : 1;
  if(s[i] == '+' || s[i] == '-')
    {
      i++;
    }
    for(exp = 0.0; isdigit(s[i]); i++)
    {
      exp = 10.0 * exp + (s[i] -'0');
    }

    return((sign * val / power) * (10.0 * expsign * exp));
}
  
