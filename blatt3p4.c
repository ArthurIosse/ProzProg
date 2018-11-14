#include <stdio.h>


int main (int argc, char * argv[])
{
  int k = 1;
      for(int i = 1 ; i <= 123456789 ; i++)
                {
                    int x = i;
                    printf("%d\n",i);
                    i = (i*10) + k;
                    k ++;
                  }

  return 0;
}
