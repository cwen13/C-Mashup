#include <stdio.h>

/*
  Exercise 1-5:
   Modify the temperature conversion program to print the table in reverse order,
   that is, from 300 degrees to 0.
*/

int main()
{
  float celsius, fahr;
  float lower, upper, step;

  lower = 0;
  upper = 300;
  step  = 20;

  celsius = upper;
  printf("Celsius\tFahr\n");
  while(celsius >= lower)
    {
      printf("%3.0f\t%.1f\n",celsius, ((celsius * 9.0)/5.0) + 32);
      celsius -= step;
    }

  return 0;
}
