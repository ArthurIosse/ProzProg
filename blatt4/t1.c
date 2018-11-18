#include <stdio.h>
#include <math.h>

double sin(double x)
{
  double c = x;
  double y = c;
  double yalt = y + 1.0;
  
  for (int k = 1 ; y != yalt ; k++)
  {
    c=-c*(x*x)/((2*k+1)*(2*k));
    yalt=y;
    y=y+c;
  }
  return y;
}


int main (int argc, char * argv[])
{

printf("%f\n",sin(12.0));

  return 0;
}
