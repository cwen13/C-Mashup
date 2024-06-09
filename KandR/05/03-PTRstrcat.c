/*
  Exercise 5-3:
  Write a pointer version of the function strcat that we
  showed in Chapter 2: strcat(s,t) copies the string t to
  the end of s.
 */
#include <stdio.h>

void PTRstrcat(char *s, char *t);

int main()
{
  int len1, len2;
  char *in1, *in2;
  long unsigned int n1, n2;
  in1 = in2 = NULL;
  n1 = n2 = 0;
  while((len1=getline(&in1, &n1, stdin)) > 0)
    {
      in1[len1-1] = '\0'; // remove trailing '\n' from string
      if((len2 = getline(&in2, &n2, stdin)) <= 0)
	{

	  return 1;
	}
      in2[len2-1] = '\0'; // remove trailing '\n' from string
      if(n1 < len1 + len2 + 1)
	{
	  printf("Error: %ld chars allocated for s, we need %d\n",
		 len1,
		 len1 + len2 + 1);
	  
	  return 1;
	}
      PTRstrcat(in1, in2);
      printf("Strings together: \"%s\"\n", in1);
    }
  
  return 0;
}

void PTRstrcat(char *s, char *t)
{
  while(*s++ != '\0');
  s--;
  while(*s++ = *t++);
  
  return;
}
