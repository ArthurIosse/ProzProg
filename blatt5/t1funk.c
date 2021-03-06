#include "t1funk.h"


void printfield(int z, int s, int n,int wrong)
{
  COLOR_YELLOW;
  printf("\n\n\n\n\n\n    1  2  3   4  5  6   7  8  9 \n");
  COLOR_RESET;
  for(int i = 0 ; i<9 ; i++)
  {
    if ( i == 0 || i == 3 || i == 6)
    {
      printf("  +---------+---------+---------+\n");
    }
    for (int j = 0 ; j<9 ; j++)
    {
      if (j == 0 )
      {
        COLOR_YELLOW;
        printf("%d ",i+1);
        COLOR_RESET;
        printf("|");
      }
      else if (j == 3 || j == 6)
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
            if (wrong)
            {
              printf(" \x1B[31m%d\x1B[0m ",playfield[i][j]);
              wrong = 0;
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
printf("  +---------+---------+---------+\n");
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


int checkline(int playfield[9][9])
{
    //line check
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
            printf("wrong line!!!\n");
            return 1;
          }
        }
       }
      }
    }
    //column check
    for(int i = 0 ; i < 9 ; i++)
    {
      for(int j = 0 ; j < 9 ; j++)
        {
      if ( playfield[j][i] != 0)
        {
        for(int k = 0 ; k < 9 ; k++)
        {
          if (k == j)
          {
            k++;
          }
          if (playfield[j][i] == playfield[k][i])
          {
            printf("wrong column!!!\n");
            return 1;
          }
        }
       }
      }
    }

    //box check
    int count1 = 0;
    int count2 = 0;
    int i1;
    int j1;
    int k1;
    int p1;
    while (count1 < 9){
      while(count2 < 9){
    for (i1 = count2 ; i1 < count2+3 ; i1++ )
    {
      for (j1 = count1 ;j1 < count1 + 3 ; j1++ )
      {
        if ( playfield[i1][j1] != 0)
        for (k1 = count2 ; k1 < count2+3 ; k1++ )
        {
          for (p1 = count1 ; p1 < count1+3 ; p1++ )
          {
            if(k1 == i1 && p1 == j1){ p1++ ;}
            if (playfield[i1][j1] == playfield[k1][p1])
            {
              printf("wrong box!!!\n");
              return 1;
          }

        }
      }
    }
  }
  count2 += 3;
  }
  count2 = 0;
  count1 += 3;
}
 return 0;

}
