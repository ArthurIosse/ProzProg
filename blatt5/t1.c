#include <stdio.h>
#include <stdbool.h>

bool wrong = false;

static int field[9][9] = {{4,1,0,0,6,5,0,0,7},
                          {0,0,6,0,0,7,4,8,0},
                          {2,0,7,4,9,0,0,0,6},

                          {0,6,0,0,7,0,1,0,0},
                          {3,0,1,5,0,0,0,7,2},
                          {0,9,0,0,4,2,3,0,8},

                          {1,0,8,6,0,0,0,2,9},
                          {0,2,0,0,1,8,6,4,0},
                          {6,0,0,3,0,0,0,1,0}};


   int playfield[9][9] = {{4,1,0,0,6,5,0,0,7},
                          {0,0,6,0,0,7,4,8,0},
                          {2,0,7,4,9,0,0,0,6},

                          {0,6,0,0,7,0,1,0,0},
                          {3,0,1,5,0,0,0,7,2},
                          {0,9,0,0,4,2,3,0,8},

                          {1,0,8,6,0,0,0,2,9},
                          {0,2,0,0,1,8,6,4,0},
                          {6,0,0,3,0,0,0,1,0}};



void printfield(int z, int s, int n)
{
  playfield[z-1][s-1] = n;
  for(int i = 0 ; i<9 ; i++)
  {
    if ( i == 0 || i == 3 || i == 6)
    {
      printf("+---------+---------+---------+\n");
    }
    for (int j = 0 ; j<9 ; j++)
    {
      if (j == 0 || j == 3 || j == 6)
      {
        printf("|");
      }

      if(field[i][j] == 0)
      {
          if (playfield[i][j] == 0)
          {
            printf("   ");
          }
          else{
            if (wrong == true)
            {
              printf(" \x1B[31m%d\x1B[0m ",playfield[i][j]);
            }else{
            printf(" \x1B[32m%d\x1B[0m ",playfield[i][j]);
          }
          }
       }else
       {
         playfield[i][j] = field[i][j];
         printf(" %d ",playfield[i][j]);
       }
  }
  printf("|\n");
}
printf("+---------+---------+---------+\n");
}

void printinstructions()
{
  printf("\n\nEnter a 3 digit Number Sir, where XXX\n");
  printf("                                  ^^^\n");
  printf("                                  |||->Nummer\n");
  printf("                                  ||->Spalte\n");
  printf("                                  |->Zeile\n");
  printf("Enter 1212 for Exit\n");
}



bool checkline(int playfield[9][9])
{
    for(int i = 0 ; i < 9 ; i++)
    {
      for(int j = 0 ; j < 9 ; j++)
        {
      if ( playfield[i][j] != 0)
        {
        for(int k = 0 ; k < 9 ; k++)
        {
          if (k == j)
          {
            k++;
          }
          if (playfield[i][j] == playfield[i][k])
          {
            printf("wrong!!!\n");
            return 1;
          }
        }
       }
      }
    }
    return 0;
}


int main (int argc, char * argv[])
{

  printfield(1,3,0);
  printinstructions();
   int x = 0;
  while (x != 1212){
  scanf("%d",&x);
  if((x >= 100 && x <= 999) || x == 1212)
  {
  int z = x / 100;
  int s = x % 100 / 10;
  int n = x % 10;


  wrong = checkline(playfield);
  printfield(z,s,n);
  printinstructions();


  }
  else
  {
    printf("Wrong number, try again please\n");
  }
}

  return 0;
}
