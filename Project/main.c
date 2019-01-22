#include <stdio.h>
#include <locale.h>   //setlocale(); ASCII signs
#include <time.h>     // srand(time(0));
#include <ncurses.h>  //create window
#include <unistd.h>   //usleep(); warning


#define H 30
#define W 30



bool gameover = false;
typedef enum eDirection { STOP=0, UP, DOWN, LEFT, RIGHT, JUMP} eDirection;
eDirection dir;
int x, y, brickx ,bricky , score;

int brickl[6];

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

  brickx = 5;
  bricky = 24;




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
        if(i == bricky && j == brickx)
        {
          for (int b = 0 ; b<8 ; b++)
             mvprintw(i,j+b,"█");
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
       //case UP: y--; break;
       case LEFT: if(x==1){break;} x--; break;
      // case DOWN: y++; break;
       case RIGHT: if(x==W){break;} x++; break;
       case JUMP:  for(int i = 0 ; i < 18 ; i++)
                      {
                        if(i < 9){
                          y--;
                          //usleep(40000);
                          input();
                          if(dir == RIGHT) x++;
                          if(dir == LEFT) x--;
                          dir = STOP;
                          draw();

                        }else{
                        y++;
                        //usleep(40000);
                        input();
                        if(dir == RIGHT) x++;
                        if(dir == LEFT) x--;
                        dir = STOP;
                        draw();

                        }
                      }
       default: break;
   }
   dir = STOP;
}




int main(int argc,char * argv[])
{
  //  srand(time(0));   // brickl = rand()%W;
    setlocale(LC_ALL, "");

    setup();
    while (!gameover)
    {
      draw();
      input();
      logic();
    }


    getch();
    endwin();

  return 0;
}
