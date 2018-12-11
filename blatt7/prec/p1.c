#include <stdio.h>

int fak(int n)
{
if (n == 0)
{
  printf("if ing\n");
return 1;
}
  else
  {
    printf("else ing\n");
    return n*fak(n-1);
  }
}


int main (int argc, char * argv[])
{
int x = 6;
printf("Fakultet %d = %d.\n",x,fak(x));

  return 0;
}
