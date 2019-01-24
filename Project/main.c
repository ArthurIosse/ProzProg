#include <stdio.h>
#include <locale.h>   //setlocale(); ASCII signs
#include <time.h>     // srand(time(0));
#include <ncurses.h>  //create window

#define H 30
#define W 30
#define BL 5



bool gameover = false;
typedef enum eDirection { STOP=0, UP, DOWN, LEFT, RIGHT, JUMP} eDirection;
eDirection dir;
int x, y , score = 0;
bool flor = true;
//int * bricks = (int*)malloc(2*4*sizeof(int));
int bricks[4][2] = {{5,24},{10,16},{1,10},{13,5}};

int spikes[5][3];


int checkspikes()
{
  for(int v = 0; v < 5; v++) {
    for (int i = 0 ; i<BL ; i++)
    {
      if((x == spikes[v][0]) && (y == spikes[v][1]-1)){
        return 1;
      }
    }
  }
  return 0;
}
// void newlevel()
// {
//   //free(bricks);
//   for (int i = 0 ; i < 4 ;i++)
//   {
//     for(int j = 0 ; j < 2 ;j++)
//     {
//       briks(i*)
//     }
//   }
//   bricks = {{15,24},{20,18},{21,12},{16,7}};
// }

bool checkflor()
{
  for(int v = 0; v < 5; v++) {
    for (int i = 0 ; i<BL ; i++)
    {
      if((x == bricks[v][0]+i) && (y == bricks[v][1]-1)){
        // score++;
        return 1;
      }
    }
  }
  for (int i = 0 ; i < W ; i++)
  {
    if(y == H){
      // score = 0;
      return 1;
    }
  }
  return 0;
}

void setup()
{

  initscr();
  //raw();
  clear();
  noecho();
  cbreak();
  curs_set(0);
  printw("Jumping O");

  score = 0;
  x = W/2;
  y = H;

  for (int i = 0 ; i < 4 ; i++)
  {
    for (int j = 0 ; j < 2 ; j ++)
    {
      spikes[i][j] = bricks[i][j];
    }
  }



}

void draw()
{
  clear();
  for(int i = 0 ; i<H+2 ; i++)
  {
    for(int j = 0 ; j < W+2; j++)
    {
        if (j==0 || j == W+1 || i == 0 || i == H+1)
        {
          mvprintw(i,j,"█");
        }
        else if (i == y && j == x)
        {
            mvprintw(i, j, "¶");
        }
        for(int v = 0; v < 5; v++) {
          if(i == bricks[v][1] && j == bricks[v][0])
          {
            for (int b = 0 ; b<BL ; b++)
               mvprintw(i,j+b,"█");
          }
        }
        for(int v = 0; v < 5; v++) {
          if(i == spikes[v][1] && j == spikes[v][0])
            {
               mvprintw(i-1,j,"v");
             }
           }
    }
  }

  mvprintw(H+3,10,"Score: %d\n\nPress 'q' to quit.",score);
  refresh();

}



void input()
{
  keypad(stdscr,TRUE);
  halfdelay(1);          //delay after input(speed)

  int c = getch();

  switch(c)
  {
      case KEY_UP: dir = JUMP; break;
      case KEY_LEFT: dir = LEFT; break;
      case ' ': dir = JUMP; break;
      case KEY_RIGHT: dir = RIGHT; break;
      case 113: gameover = true; break;
  }
}


void logic()
{


  switch(dir)
   {
       case LEFT: if(x==1){break;} x--;dir=STOP; break;

       case RIGHT: if(x==W){break;} x++;dir=STOP; break;

       case JUMP:     if(!flor)break;
                      for(int i = 0 ; i < 18 ; i++)
                      {
                        if(i < 9){
                          y--;
                          input();
                          if(dir == RIGHT){
                            if(x==W){x--;}
                             x++;
                           }
                          if(dir == LEFT){
                          if(x==1){x++;}
                           x--;
                         }
                          dir = STOP;
                          draw();
                        }else{
                          if(checkflor())break;

                        y++;
                        input();
                        if(dir == RIGHT){
                          if(x==W){x--;}
                           x++;
                         }
                        if(dir == LEFT){
                        if(x==1){x++;}
                         x--;
                       }
                        dir = STOP;
                        draw();
                        }
                      }
       default: break;
   }

   if(checkspikes())
   gameover = true;

   if(checkflor()){
   dir = STOP; flor = true;}
   else {y++;flor = false;}
}




int main(int argc,char * argv[])
{
    // srand(time(0));   // brickl = rand()%W;
    setlocale(LC_ALL, "");

    setup();
    while (!gameover)
    {
      draw();
      input();
      logic();
      //if(y==0)newlevel();
    }


    getch();
    endwin();

  return 0;
}
