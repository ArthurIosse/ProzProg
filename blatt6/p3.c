#include <stdio.h>
#include <stdlib.h>


int main (int argc, char * argv[])
{


srand(time(0));

for (int i = 0 ; i<6; i++){
printf("%d \n",rand() % 50);
}


  return 0;
}
