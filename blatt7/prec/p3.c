#include <stdio.h>

int fib(int n)
{
  if(n < 2)
  {
    return n;
  }
  else
  {
    return fib(n-1)+fib(n-2);
  }
}

int main(int argc, char * argv[])
{

  for (int i = 1 ; i < 19 ; i++ )
  {
    printf("%d  ",fib(i));
  }
  printf("\n");
  return 0;
}
