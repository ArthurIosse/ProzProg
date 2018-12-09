#include <stdio.h>
#include "t1funk.h"



const int field[9][9] = { {4,1,0,0,6,5,0,0,7},
                          {0,0,6,0,0,7,4,8,0},
                          {2,0,7,4,9,0,0,0,6},

                          {0,6,0,0,7,0,1,0,0},
                          {3,0,1,5,0,0,0,7,2},
                          {0,9,0,0,4,2,3,0,8},

                          {1,0,8,6,0,0,0,2,9},
                          {0,2,0,0,1,8,6,4,0},
                          {6,0,0,3,0,0,0,1,0}};


int playfield[9][9];







int main (int argc, char * argv[])
{
  int wrong = 0;

  printfield(1,3,0,0);
  printinstructions();
   int x = 0;


  while (x != 1212){
  scanf("%d",&x);
  if((x >= 100 && x <= 999) || x == 1212)
  {
  int z = x / 100;
  int s = x % 100 / 10;
  int n = x % 10;

  playfield[z-1][s-1] = n ;
  wrong = checkline(playfield);
  printfield(z,s,n,wrong);
  printinstructions();




  }
  else
  {
    printf("Wrong number, try again please\n");
  }
}

  return 0;
}
