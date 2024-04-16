// Startingto write C
// write a c programto repeat arguments
// if no args ask for a scentance
#include <stdio.h>
#include <stdlib.h>

int printProg(char *name);
int printArgs(int length, char *arr[]);

int main(int argc, char *argv[]){
  // if are there args
  if(argc > 1)
    {
      // cycle through args and print them
      printArgs(argc, argv);
    }
  else
    {
      // else ask for a scentence to print out
      printProg(argv[0]);
    }

  printf("\nThis is the end of the programm\n");
  
  return 0;
}
    
int printProg(char *name){
  char *words;
  size_t size = 100;
  size_t chars;

  words = (char *)malloc(size * sizeof(chars));
  
  printf("-----------------------------\nThe program name is %s.", name);
  printf("\nPlease enter a scentence to print out: ");
  //  scanf("%s", &words);
  
  getline(&words,&size,stdin);

  // output the string
  printf("This is the inpout string: %s", words);

  // output individual words from the string
  char *word = (char *)malloc((size / 2) * sizeof(chars));
  
  int i=0, delta=0;
  while(1)
    {
      if(words[i]==' '|| words[i]=='\n')
	{
	  // insert null term so only print out the word
	  *(word + (i - delta)) = '\0';	  
	  //	  printf("There is a <SPACE> in my boot!\n");
	  printf("The word is: %s\n", word);
	  
	  delta = i + 1;
	  
	}
      else
	{
	  printf("This is the letter: %c\n", words[i]);
	  //	  printf("This is i minus delt: %d\n", (i - delta));
	  *(word + (i - delta)) = words[i];
	}

      i++;
      if(words[i] == '\0')
	{
	  break;
	}

    }  
  free(word);
  free(words);
  
  return 0;
}

int printArgs(int length, char *argv[]){
  for(int i=0;i < length; i++)
    {
      if(i==0)
	{
	  printf("The program is named: %s", argv[i]);
	  continue;
	}
      printf("\nThe arguments are: %s", argv[i]);
    }

  return 0;
}
