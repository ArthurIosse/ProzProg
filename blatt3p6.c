#include <stdio.h>


int main (int argc, char * argv[])
{

  int k = 7;
      for(int i = 9 ; i <= 987654321 ; i++)
                {
                    printf("%d\n",i);
                    i = (i*10) + k ;
                    k --;
                  }


  return 0;
}
