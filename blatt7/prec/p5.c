#include <stdio.h>

int ggt(int a,int b)
{
  if(b == 0)
  {
    return a;
  }
  else
  {
    return ggt(b,a%b);
  }
}

int main(int argc, char * argv[])
{

  // for (int i = 1 ; i < 19 ; i++ )
  // {
  //   printf("%d  ",fib(i));
  // }
  int a = 49;
  int b = 63;
  printf("ggt %d und %d = %d \n",a,b,ggt(a,b));
  return 0;
}
