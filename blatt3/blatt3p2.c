#include <stdio.h>


int main (int argc, char * argv[])
{
int i = 6;
int z = i;
int x = 1;
do {
  x = i * x;
  i--;
}while( i > 0 );
printf("\n \n%d fakultaet = %d \n \n",z,x);

  return 0;
}
