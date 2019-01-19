#include <stdio.h>
#include <string.h>

int main(int argc, char * argv[])
{

  printf("argc = %d\n",argc-1);

  int len = strlen(argv[1]);

  for (int i = 0 ; i < len ; i++)
  {
    printf("%c%c",argv[1][i],argv[1][i]);
  }
  printf("\n");
  return 0;
}
