/*
  Exercise 3-2:
  Write a function escape(s,t) that converts characters like newline and tab
  into visible escape sequences like \n and \t as it copies the string t to s.
  Use a switch.
  Write a function for the other direction as well, converting escape sequences
  into the real characters.
 */

#include <stdio.h>
#include <stdlib.h>

#define MAXLEN 1000

char escape(char s[], const char t[]);
char unescape( char s[], const char t[]);

int main()
{
  int len;
  char s[MAXLEN];
  char *t;
  long unsigned int n;

  t = NULL;
  n = 0;
  while(len = getline(&t, &n, stdin) > 0)
    {
      if(len > MAXLEN)
	{
	  printf("The input is too long!\nEnter a new entry:\n");
	  return 1;
	}
      
      escape(s, t);
      printf("The escaped line is:\n%s\n\n", s);
      //      unescape(s, t);
      //printf("The unescaped line is:\n%s\n\n", s);
  
    }
  
  return 0;
}

char escape(char s[], const char t[])
{
  int i =0, j = 0;

  for(i=0, j=0; t[i] != '\0'; ++i, ++j)
    {
      switch(t[i])
	{
	case '\t':
	  s[j] = '\\';
	  s[++j] = 't';
	  break;
	case '\n':
	  s[j] = '\\';
	  s[++j] = 'n';
	  break;
	case '\a':
	  s[j] = '\\';
	  s[++j] = 'a';
	  break;
	default:
	  s[j] = t[i];
	  
	}
      
    }
  s[j] = '\0';
  
  return *s;
}

//char unescape( char s[], const char t[])
//{
//
//}

