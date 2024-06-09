/*
  Exercise 5-4:
  Write the function strend(s,t), which returns 1 if the
  string t occurs at the end of the string s, and zero otherwise.
 */

#include <stdio.h>

int strend (char *s, char *t);

int main()
{
  char *s, *t;
  long unsigned ns, nt;
  int ls, lt;
	
  s = t = NULL;
  ns = nt = 0;
  while ((ls = getline(&s, &ns, stdin)) > 0){
    s[ls-1] = '\0'; /* remove trailing '\n' from string s */
    if ((lt = getline(&t, &nt, stdin)) <= 0){
      return 0;
    }
    if (ns < ls + lt +1){
      printf("error: %ld characters allocated for s, we need %d \n", ns, ls + lt + 1);
      return 1;
    }
    printf("Is, %t, found at the end of %s?\n", t, s);
    printf(strindend(s, t)
	   ? "Found at the end!\n"
	   : "Does not have the same ending\n");
  }

  return 0;

}

int strend (char *s, char *t)
{

  char *start = &s;
  int found = 0, i, j;
  int loc = 0;
  while(s++ != '\0')
    {
      while(t++ !='\0')
	{
	  if(*s == *t && *s !='\0')
	    
	}
    }

  for(i=0; *s++ != '\0'; i++)
    {
      for(j=o;*t** != '\0'; j++)
	{
	  if()
	  
	}
    }
  
  return (found && loc+i==j) ? 1 : 0;
  
}
