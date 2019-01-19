#include <stdio.h>
#include <string.h>

int stringcompare(char * a, char * b)
{
  if(strcmp(a,b)==0){
  return 1;
}else{
  return 0;
}
}

int main (int argc, char * argv[])
{
  char a[20] = "Jack";
  char b[20] = "Jack";
  printf("returned %d\n",stringcompare(a,b));

  return 0;
}
