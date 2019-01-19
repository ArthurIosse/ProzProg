#include <stdio.h>
#include <stdlib.h> //strtol(char, end ptr, base);



int main (int argc, char * argv[])
{
  int sum;
  for (int i = 1 ; i< argc ; i ++)
  {
    sum += strtol(argv[i],NULL,10);

  }
  printf ("Summe = %d\n",sum);
  return 0;
}
