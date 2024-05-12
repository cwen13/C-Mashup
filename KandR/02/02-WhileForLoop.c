// NOT FINNISHED
/*
  Exercise 2-2:
   Write a loop equivalent to the for loop above without using && or ||.

   LOOP ABOVE
   for (i=0; i < lim-1 && (c=getchar()) != '\n' && c != EOF; ++i)
   {
     s[i] = c;
   }
 */

#include <stdio.h>

int main()
{
  int c, i = 0;
  int length = sizeof(
  
  while(i<length-1 && (c=getchar()) != '\n' && c!=EOF)
    {
      s[i] = c;
      i++;
    }
  
  return 0;
}
