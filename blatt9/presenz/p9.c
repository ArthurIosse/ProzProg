#include <stdio.h>


int filecompare(char * a, char * b)
{
FILE * f1 = fopen(a,"r");
FILE * f2 = fopen(b,"r");
char ch1,ch2;
  while((ch1 = fgetc(f1))!=EOF){
    ch2 = fgetc(f2);
    printf("%c\n%c\n",ch1,ch2);
      //compare the single chars
      if(ch1 != ch2)
      {
        fclose(f1);
        fclose(f2);
        return 0;
      }
  }
  //get the next char from f2 if its not \0 then f2 longer
  ch2 = fgetc(f2);
    if (ch2 != EOF)
    {
      return 0;
    }

    fclose(f1);
    fclose(f2);
    return 1;
}


int main (int argc, char * argv[])
{
  printf("returned = %d\n",filecompare("one.txt","two.txt"));

  return 0;
}
