#include <stdio.h>

/*
  Exercise 1-4:
   Write a program to print the corresponding Celsius to Fahrenheit table.
*/

int main()
{
  float fahr, celsius;
  float lower, upper, step;

  lower = 0;
  upper = 300;
  step  = 20;
  
  celsius = lower;
  printf("Celsius\tFahr\n");
  while(celsius <= upper)
    {
      printf("%3.0f\t%.0f\n",celsius, ((celsius * 9)/5) + 32);
      celsius += step;
    }

  return 0;
}
