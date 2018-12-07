#include <stdio.h>

void swap2(int* a, int* b)
{
int temp = *a;
*a = *b;
*b = temp;
}

int main (int argc, char * argv[])
{

int a = 10;
int b = 22;
printf("a = %d, b = %d, \n",a,b);
swap2(&a,&b);

printf("a = %d, b = %d, \n",a,b);


  return 0;
}
