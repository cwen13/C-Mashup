/*
  Exercise 5-5:
  Write versions of the library functions strncpy, strncat,
  and strncmp, which operate on at most the first n characters
  of their argument strings. For example, strncpy(s,t,n) copies
  at most n characters of t to s. Full descriptions are in Appendix B.
 */
// padd with '0s if there is open space in the array

#include <stdio.h>
#include <ctype.h>

char *restrncpy(char *s,const char *t, long unsigned int n);
char *restrncat(char *s,const char *t, long unsigned int n);
int restrncmp(char *s,const char *t, long unsigned int n);

int main()
{

  char *s, *t;
  long unsigned int ns, nt;
  int ls, lt;
  
  s = t = NULL;
  ns = nt = 0;
  while((ls = getline(&s, &ns, stdin)) > 0)
    {
     if((lt = getline(&t, &nt, stdin)) <= 0)
       {
	 printf("error: %ld characters allocated for t, we need %d \n", ns, ls+lt+1);
       }
     t[lt-1] = '\0';
     s[ls-1] = '\0';

     // restrcmp
     printf("Compared: %d\n", restrncmp(s,t,ls)); 
     
     // restrncat
     restrncat(s, t, ns-ls);
     printf("Concated: %s\n", s);
     
     // restrncpy
     restrncpy(s, t, ns-ls);
     printf("Copied: %s\n", s);
    }// end of while loop
      
  return 0;
}
 

char *restrncpy(char *s, const char *t, long unsigned int n)
{
  char *save_s = s;
  while(n--  > 0 && (*s++ = *t++));
  
  return save_s;
}

char *restrncat(char *s,const char *t, long unsigned int n)
{

  char *save_s = s;
  
  while(*s++ != '\0');
  s--;
  while(n-- > 0 && (*s++ = *t++));
  *(--s) = '\0';

  return save_s;
}
    
int restrncmp(char *s,const char *t, long unsigned int n)
{
  while(*s++ == *t++ && *s != '\0');
    
  return *(s) - *(t); 
}
