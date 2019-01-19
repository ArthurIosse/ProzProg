#include <stdio.h>


int main (int argc, char * argv[])
{
  char ch;
  FILE *file = fopen("data.txt","r");
  int i = 0 ;
  while((ch = fgetc(file)) != EOF)
    {
      if (ch == ' ')
      {
        printf("\n");
        i ++;
      }
      if(i == 10)
      {
        break;
      }
      printf("%c", ch);
    }
  fclose(file);
  return 0;
}
