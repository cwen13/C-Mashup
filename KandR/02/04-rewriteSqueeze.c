
/*
  DID NOT COMPELTE
  In the solition they create new strings 
 */
/*
  Exercise 2-4:
   Write an alternative version of squeeze(s,e) that deletes each character
   in s that matches any character in the string e.
*/

#include <stdio.h>
#include <ctype.h>

#define MAXWORD 100
#define HAS 0
#define NHAS 1

void squeeze(char s[], char e[]);
int inString(char string[], char letter);
void removeLetter(char str[], char ch);
  
int main()
{
  char c = ' ';
  int i;
  char *s = NULL;
  char *e = NULL;
  long unsigned int ls;
  long unsigned int le;
  
  while(c != EOF)
    {
      printf("S: ");
      if(getline(&s, &ls, stdin) == -1)
	{
	  printf("ERROR GETLINE: possible EOF!\n");
	  return 1;
	}
	
      printf("E: ");
      if(getline(&e, &le, stdin) == -1)
	{
	  printf("ERROR GETLINE: possible EOF!\n");
	  return 1;
	}

      printf("PRESQEEZE\n");
      squeeze(s, e);
      printf("S with out the letters from E: %s\n", s);
    }
  
  return 0;
}

void squeeze(char s[], char e[])
{
  int i, j, k;

  printf("SQUEEZE\n");
  
  k = 0;
  for(i=0; s[i] != '\0'; i++)
    {
      for(j=0; s[2] != '\0'; j++)
	{
	  if(!isblank(e[i]) && inString(s, e[j]))
	    {
	      removeLetter(s, e[i]);
	      break;
	    }
	}
    }
}

int inString(char string[], char letter)
{
  int i;
  for(i=0;string[i] !='\0'; i++)
    {
      if(string[i] == letter)
	{
	  
	  return HAS;
	}
    }
  
  return NHAS;
}
 
void removeLetter(char str[], char ch)
{
  int i=0;
  int j=0;

  while(str[i] != '\0')
    {
      if(str[i] == ch)
	{
	  for(j=i; str[j] != '\0'; j++)
	    {
	      str[j] = str[j+1];
	    }
	}
      i++;
    }
   
}
