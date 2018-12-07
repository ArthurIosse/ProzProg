#include <stdio.h>
#include <stdlib.h>




int main(int argc, char * argv[])
{
int * prim = (int*)malloc(100*sizeof(int));

for (int i = 2 ; i <=100 ; i++)
{
  prim[i-2] = i;
}


for (int i = 2 ; i<=100 ; i++ )
{
  for(int j = i ; j<=98 ; j ++)
  {

    if(prim[j] % i == 0 )
    {
      prim[j] = 0 ;
    }
  }
}

for (int i = 0 ; i <=98 ; i++)
{
  printf("%d, ",prim[i]);
}
printf("\n");

free(prim);
  return 0;
}
