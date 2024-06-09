/*
 Exercise 4-12:
  Adapt the ideas of printd to write a recursive version of itoa; that
  is, convert an integer into a string by calling a recursive routine.
 */

#include <stdio.h>
#include <ctype.h>

#define CINTLEN 20

int itoa(char s[], int n);
char itoa_rec(char s[], unsigned int val);

int main()
{
  char s[CINTLEN];
  int n;

  while (scanf("%d", &n) == 1){
    itoa(s, n);
    printf("%s\n", s);
  }
	
  return 0;
}

int itoa(char s[], int n)
{
  /* handle negative numbers */
  unsigned int un;
  un = (unsigned int) n;
  if (n < 0){
    un = ~un + 1;
    s[0] = '-';
    ++s;
  }

  /* recursive logic */
  int total_digits;
  total_digits = itoa_rec(s, un);

  /* finish s with null character '\0' */
  s[total_digits] = '\0';
}

char itoa_rec(char s[], unsigned int n)
{  

  int digits;

  // base case
  if(n==0)
    {
      return 0;
    }

  // recursive
  digits = itoa_rec(s, n/10) + 1;
  printf("DIGIT: %d\n", digits);
  s[digits-1] = (n % 10) + '0';

  if(n<10)
    {
      s[digits]='\0';
    }

  return digits;
}
