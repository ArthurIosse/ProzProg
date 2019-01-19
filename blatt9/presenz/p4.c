#include <stdio.h>
#include <stdlib.h>


int main (int argc, char * argv[])
{
  int a, b;
  a = strtol(argv[1],NULL,10);
  b = strtol(argv[2],NULL,10);
  int pot = a;
  for (int i = 1 ; i<b ; i++)
  {
    pot = a * pot;
  }

  FILE *fp = fopen(argv[3],"w");

  fprintf(fp,"a^b = %d\n",pot);


  fclose(fp);
  return 0;
}
