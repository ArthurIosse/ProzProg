#include <stdio.h>
#include <string.h>

//str practice

char umdrehen(char c)
{
   c = getchar();
if (c == 10)
{
return c;
}
  else
  {
    c = umdrehen(c);
    return c;
    printf("%c",c);
  }
}


int main (int argc, char * argv[])
{
  printf("Give string sir\n");
  char str[10];
  char c;
  int i = 10;

  while (c != 10){
    int i = 0 ;
  c = getchar();
  str[i] = c;
    printf("%c",c);
    i++;
}
  printf("\n");
  printf("%s",str);


  return 0;
}
