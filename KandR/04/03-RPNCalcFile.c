/* firs think of it in a single file
   Afterwards there is a disscussion of what to do to seperate them into files */
#include <stdio.h>
#include <stdlib.h> // for atof()
#include <ctype.h>

#define MAXOP 100   // max number of op/operands
#define MAXVAL 100
#define BUFSIZE 100
#define NUMBER '0'  // signal a number was found

char buf[BUFSIZE];  // buffer for ungetch
double val[MAXVAL];
int bufp = 0;       // next free position in buffer
int sp = 0;           // stack index needs to be shared by push and pop, main does not need to know

// Functions used
int getop(char []);
void push(double);
double pop(void);
int getch(void); 
void ungetch(int);

/* RPN Calculator */
int main()
{
  int type;
  double op2;
  char s[MAXOP];
  int number;

  while((type = getop(s)) != EOF)
    {
      printf("-----------\n");
      switch(type)
	{
	case NUMBER:
	  printf("This is s: %s\n", s);
	  number = atof(s);
	  printf("Number: %d\n", number);
	  push(number);
	  break;
	  // since '+' and '*' are cummutative operand order does not matter
	case '+':
	  printf("PLUS: %c\n", s);
	  push(pop() + pop());
	  break;
	case '*':
	  push(pop() * pop());
	  break;
	case '-':
	  op2 = pop();
	  push(pop() - op2);
	  break;
	case '/':
	  op2 = pop();
	  if(op2 != 0.0)
	    {
	      push(pop() / op2);
	    }
	  else
	    {
	      printf("error: zero divisor\n");
	    }
	  printf("\t%.8g\n", pop());
	  break;
	case '\n':
	default:
	  printf("This is the default case: %c\n", s);
	  printf("error: unknown command %s\n", s);
	}
    }

  return 0;
}

/* PUSH AND POP TO INTERACT WITH STACK */
/* push: push f onto value stack */
void push(double f)
{
  if(sp<MAXVAL)
    val[sp++] = f;
  else
    printf("error: stack is full, can not push %g\n", f);
}

/* pop: pop and return top value from stack */
double pop(void)
{
  if(sp>0)
    return val[--sp];
  else
    {
      printf("error: stack empty\n");
      
      return 0.0;
    }
}

/* GETOP TO GET OP AND OPERANDS*/
/* getop: get next char or number operand */
int getop(char s[])
{
  int i,c;
  i = 0;
  while((s[0] = c = getch()) == ' ' || c == '\t')
    {
      printf("C = %d\n", c);
      printf("S[0] = %d\n", s[0]); 
    }
  s[1] = '\0';

  if(!isdigit(c) && c != '.' && c != '-')
    {
      return c; // not a number
    }
  i = 0;
  if(isdigit(c)) // collect integerpat
    {
      while(isdigit(s[i++] = c = getch()))
	;
    }
  if(c=='.') // collect fraction
    while(isdigit(s[++i] = c = getch()))
      ;
  s[i] = '\0';
  if(c != EOF)
    ungetch(c);
  
  return NUMBER;
}

/* GET AND UNGET CHARS */
int getch(void) // get a character or one to push back in
{
  
  return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) // push char back into input, ungetch is a function in C lib
{
  if(bufp>=BUFSIZE)
    printf("ungetch: too many chars\n");
  else
    buf[bufp++] = c;

  return;
}


