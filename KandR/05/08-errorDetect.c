/*
  Exercise 5-8:
  There is no error checking in day_of_year or month_day. Remedy this defect.
*/

#include <stdio.h>
#include <stdlib.h>

#define MAXLINE 1000

int day_of_year(int year, int month, int day);
void month_day(int year, int yearday, int *pmonth, int *pday);

static char daytab[2][13] = {
  {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
  {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};


int main()
{

  char *year, *month, *day;
  char *validDate, *newQuery;
  size_t n;

  int numYear, numMonth, numDay;
  
  n = MAXLINE;
  //  char newQuery = ' ';
  
  while(1)
    {
      printf("What year is the date in?: ");
      getline( &year, &n, stdin);

      printf("What montj is the date in?: ");
      getline(&month, &n, stdin);

      printf("What day is the date in?: ");
      getline(&day, &n, stdin);

      numYear = atoi(year);
      numMonth = atoi(month);
      numDay = atoi(day);
      

      if((*validDate = day_of_year(numYear, numMonth, numDay)) == -1)
	{
	  printf("Invalid date: enter a proper date.\n");
	  printf("%d is not a month.\nEnter a valid month.\n", numMonth);
	  continue;
	}
      else if(*validDate == -2)
	{
	  printf("Invalid date: enter a proper date.\n");
	  printf("%d is not a day.\nEnter a valid day.\n", numDay);
	  continue;
	}
      else
	{
	  printf("Day of the year: %d.\n", *validDate);
	  printf("New query date?(y or n): ");
	  getline(&newQuery, &n, stdin);
	  *(newQuery+1) = '\0';
	  if(*newQuery != 'y') break;
	}
    }

  return 0;
}


/*
  day_of_year: set day of the year from month and day
  returns
   -on completion: 'day_of_year' as an int
   -on out of range month: -1 
   -on out of range day: -2 
 */
int  day_of_year(int year, int month, int day)
{
  int i, leap, mdays;
  leap = year%4 == 0 && year%100 != 0 || year%400 == 0;

  // check the month, once checkd can check day
  if(month < 0 || month > 12)
    {

      return -1;
    }
  

  mdays = daytab[leap][month];
  if(day < 0 || day > mdays)
    {

      return -2;
    }
  
  for(i=1; i< month; i++)
    {
      day += daytab[leap][i];
    }

  return day;
}

/* month_day: set month, day from day of year*/
//void month_day(int year, int yearday, int *pmonth, int *pday)
//{
//  int i, leap;
//  leap = year%4 == 0 && year%100 != 0 || year%400 == 0;
//  for(i=1; yearday > daytab[leap]i]; i++)
//      {
//	*pmonth = i;
//	*pday = yearday;
//      }
//}
