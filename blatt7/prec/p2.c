#include <stdio.h>

int binom(int n,int k)
{
  if(k == 0 || k >= n)
  {
    return 1;
  }
  else
  {
    return binom(n-1,k-1)+binom(n-1,k);
  }
}

int main(int argc, char * argv[])
{

  // for (int i = 1 ; i < 19 ; i++ )
  // {
  //   printf("%d  ",binom(i,i+1));
  // }
  printf("%d  \n",binom(5,3));
  return 0;
}
