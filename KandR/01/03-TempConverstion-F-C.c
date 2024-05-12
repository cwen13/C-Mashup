#include <stdio.h>

/*
  Print temperature table converting F->C
  for fhahr=0,20,...,300

  Exercise 1-3:
   Modify the temperature conversion program to print a heading above the table.
*/

int main()
{
  float fahr, celsius;
  float lower, upper, step;

  lower = 0;
  upper = 300;
  step  = 20;

  fahr = lower;
  printf("Fahr\tCelsius\n");
  while(fahr <= upper)
    {
      printf("%3.0f\t%6.1f\n", fahr, 5 * (fahr-32) / 9);
      fahr += step;
    }
  

  return 0;
}
