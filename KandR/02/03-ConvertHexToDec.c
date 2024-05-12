/*
  FOLLOWING DAY COMPLETED
  Did not complete and looked at solution
  I was trying to go one by one and add up the value
  The solution creates a hex string then computes the number
  -used *isxdigit* and *ungetc*
*/
/*
  Exercise 2-3: Write a function htoi(s), which converts a string of hexadecimal
  digits (including an optional 0x or 0X) into its equivalent integer value.
  The allowable digits are 0 through 9, a through f, and A through F.
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define IN 1
#define OUT 0
#define MAXNUM 100
#define HEX 16

int getXValue(int number);
int pwr(int x, int y);

int main()
{
  // assuming hex number is given

  int c, i, j;
  int decimal = 0;
  int num;
  int hexNum[MAXNUM];

  i = 0;
  while((c = getchar()) != EOF)
    {
      if(c == '0' && ((c=getchar()) == 'x' || c== 'X'))
	{
	  while((c=getchar()) != '\n')
	    {
	      hexNum[i++] = c;
	    }
	  for(j=i-1; j >= 0; j--)
	    {
	      //num = getXValue(hexNum[j]);
	      //num = num * pwr(HEX, i-1-j);
	      //printf("Hex digit: %c, Dec digit: %d, base: %d\n", hexNum[j], num,  pwr(HEX, i-1-j));
	      // decimal += num;
	      decimal += getXValue(hexNum[j]) * pwr(HEX, (i-1-j));
	    }
	}
      printf("%d\n", decimal);
      i = 0 ;
      decimal = 0;
    }
  
  return 0;
}

int getXValue(int number)
{
  if(isdigit(number)) return(number - '0');
  switch(tolower((char) number))
    {
    case'a':

      return 10;
      break;
    case'b':

      return 11;
      break;
    case'c':

      return 12;
      break;
    case'd':

      return 13;
      break;
    case'e':

      return 14;
      break;
    case'f':

      return 15;
      break;
    default:
      
      return -1;
    }
}

int pwr(int x, int y)
{
  if(y == 0) return 1;
  return (x * pwr(x, y-1));
}
