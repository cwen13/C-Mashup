/* DID NO COMPLETE
   Reviewed solution and it widdles down the availbe options until there are
   only three left and then puts logic in place to select the correct one.
 */
/*
  Exercise 3-1:
  Our binary search makes two tests inside the loop, when one would
  suffice (at the price of more tests outside.) Write a version with only
  one test inside the loop and measure the difference in run-time.
 */

/* Exercise 3-1 in seciton 3.3 Else if */
/* Binary search: find x in v[0]....v[n-1] */

#include <stdio.h>

int binarySearch(int x, int v[], int n);

int main()
{

  int integers[] = {1,3,5,8,12,14,19,20};
  int guess = 3;
  int found;
  int length = sizeof(integers)/sizeof(integers[0]);

  found = binarySearch(guess, integers, length);
  printf("The array search result is: %d.\n",found);

  return 0;
}

int binarySearch(int x, int v[], int n)
{
  int low,high,mid;
  low = 0;
  high = n-1;

  while((high-low) > 1)
    {
      mid = (low+high)/2;
      printf("\nHihgh: %d\nLow: %d\nMid: %d\n", high, low, mid);
      if(x < v[mid])
	high = mid-1;
      else 
	low = mid;
    }
  
  if(v[low] == x)
    {
      return low;
    }
  else if(v[mid] == x)
    {
      return mid;
    }
  else if(v[high] == x)
    {
      return high;
    }

    return -1; // no match
}
