/*
  Exercise 5-6:
  Rewrite appropriate programs from earlier chapters and exercises
  with pointers instead of array indexing.
  Good possibilities include
  -getline (Chapters 1 and 4),
  -atoi, itoa, and their variants (Chapters 2, 3, and 4),
  -reverse (Chapter 3), and
  -strindex and getop (Chapter 4).
 */

#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAXLINE 80
#define CINTLEN 20
#define V_LEN 6

enum {NUMBER};
enum {POSITIVE, NEGATIVE};

int mygetline(char *s, int n);
int atoi(const char* nptr);
void itoa(int n, char *str);
void reverse(char *str);
int strindex(char *s, char *t);
int getop(char *s);


int main()
{

  char s[MAXLINE], t[MAXLINE], number[MAXLINE];
  int slen, tlen;
  int n;

  while(1)
    {
      do
	{
	  printf("> ");
	}while((slen = mygetline(s, MAXLINE)) == 0);
	if(slen == -1)
	  {

	    return -1;
	  }
      do
	{
	  printf("> ");
	}while((tlen = mygetline(t, MAXLINE)) == 0);
	if(tlen == -1)
	  {

	  return -1;
	}

      // test functions
      printf("%03d: %s\n", slen, s);
      reverse(s);
      printf("rev: %s\n", s);
      reverse(s);

      printf("int: %d\n", n = atoi(s));

      itoa(n, number);
      printf("str: %s\n", number);

      printf("pos: %d\n", strindex(s, t));

      // read an operator (and discard rest of the line)
      printf("> ");
      getop(s);

      mygetline(t, MAXLINE);
      printf("ope: %s\n", s);

    }

  return 0;
}


int mygetline(char *s, int n)
{
  int c, i;
  for(i=0; i < n-1 && (c = getchar()) != EOF; i++)
  {
    *(s+i) = c;
    if(c == '\n')
      {
	*(s+i) = '\0';
	
	return i;
      }
  }
  
  return -1;
}

void reverse(char *str)
{
  int i,j,c;
  i = j = 0;
  printf("START str: %s\n", str);
  while(*(str+j++) != '\0');
  j -= 2;
  printf("J %d\n", j);
  while(i < j)
    {
      c = *(str+i);
      *(str+i++) = *(str+j);
      *(str+j--) = c;
    }

  return;
}

int atoi(const char *nptr)
{

  int i, n, sign;
  for(i=0; isspace(*(nptr+i)); i++);
  sign=(*(nptr+i) == '-') ? -1 : 1;
  if(*(nptr+i) == '+' || *(nptr+i) == '-')
    {
      i++;
    }

  for(n=0; isdigit(*(nptr+i) - '0');)
    {
      n = 10 * n + *(nptr+i++) - '0';
    }
  
  return (sign * n);
}

void itoa(int n, char *str)
{
       int i, sign;
       if((sign = n) < 0)
	 {
	   n = -n;
	 }
       i=0;
       do
	 {
	   *(str+i++) = n % 10 + '0';
	 }while((n /= 10) > 0);
       if(sign<0)
	 {
	   *(str+i++) = '-';
	 }
       *(str+i) = '\0';
       reverse(str);

       return;
}

int getop(char *s)
{
  int i, c;
  while((*(s) = c = getchar()) == ' ' || c == '\t');
  *(s+1) = '\0';
  if(isdigit(c) && c != '.')
    {
      
      return c;
    }
  i=0;
  if(isdigit(c))
    {
      while(isdigit(*(s+i++) = c = getchar()));
    }
  if(c=='.')
    {
      while(isdigit(*(s+i++) = c = getchar()));
    }
  *(s+i) = '\0';
  if(c!= EOF)
    {
      ungetc(c, stdin);
    }

  return NUMBER;      
}

int strindex(char *s, char *t)
{
  int i, j, k;
  for(i=0; *(s+i) != '\0'; i++)
    {
      for(j=i, k=0; *(t+k) != '\0' && *(s+j) == *(t+k); j++, k++);
      if(k>0 && *(t+k) == '\0')
	{

	  return i;
	}
    }

  return -1;
}
