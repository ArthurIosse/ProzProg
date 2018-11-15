#include <stdio.h>


int main (int argc, char * argv[])
{

for ( int i = 1 ; i < 21 ; i ++)
{
  for (int j = 1 ; j < 21 ; j++)
  {
    if (i*j < 10)
    {
      printf("  ");
    }
    if (i*j < 100 && i*j >= 10)
    {
      printf(" ");
    }

    printf("%d ",i*j);
  }
  printf("\n");
}

  return 0;
}
