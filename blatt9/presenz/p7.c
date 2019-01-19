#include <stdio.h>


int main (int argc, char * argv[])
{
  FILE * fp = fopen(argv[1],"r");
  FILE * cpy = fopen(argv[2],"w");
  char ch;

    while((ch = fgetc(fp))!= EOF)
    {
      fprintf(cpy,"%c",ch);
    }


  fclose(fp);
  fclose(cpy);
  return 0;
}
