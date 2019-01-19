#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct student
{
  char name[21];
  char vorname[21];
  char studiengang[4];
  int matrikel;
  int semester;

}student;

int main (int argc, char * argv[])
{
  student a;
  strcpy(a.name, "Arthur");
  printf("%s\n",a.name);

  return 0;
}
