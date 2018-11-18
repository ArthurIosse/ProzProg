#include <stdio.h>


int main (int argc, char * argv[])
{

double d1, d2;
float f1 , f2;
f2 = d1 = 0.25;
d2 = f1 = 0.25;

if(f1 == f2)
{
  printf("f1 = f2\n");
}
if(f1 != f2)
{
  printf("f1 != f2\n");
}
if(d1 == d2)
{
  printf("d1 = d2\n");
}
if(d1 != d2)
{
  printf("d1 != d2\n");
}

//printf("p1\n");
  return 0;
}
