#include <stdio.h>

int cheb(int n, int x)
{
  if(n == 0)
  {
    return 1;
  }
  else if(n == 1)
  {
    return x;
  }
  else
  {
    return 2*x*cheb(n-1,x)-cheb(n-2,x);
  }
}

int main(int argc, char * argv[])
{

  // for (int i = 1 ; i < 19 ; i++ )
  // {
  //   printf("%d  ",fib(i));
  // }
  printf("%d \n",cheb(6,2));
  return 0;
}
