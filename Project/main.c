#include <stdio.h>
#include <locale.h>
#include <time.h>
#include <ncurses.h>


#define H 30
#define W 30



bool gameover = false;
typedef enum eDirection { STOP=0, UP, DOWN, LEFT, RIGHT, JUMP} eDirection;
eDirection dir;
int x, y, brickx ,bricky , score;

int brickl[W];

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
    }
  }
  mvprintw(H+3,10,"Score: %d",score);
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
       case LEFT: x--; break;
      // case DOWN: y++; break;
       case RIGHT: x++; break;
       case JUMP:  for(int i = 0 ; i < 18 ; i++)
                      {
                        if(i < 9)
                        {
                          y--;
                          usleep(60000);
                          draw();
                          //input();
                          //logic();
                        }else
                        {
                        y++;
                        usleep(60000);
                        draw();
                        //input();
                        //logic();
                        }
                      }

                  // y--;usleep(100000);draw();y--;usleep(100000);draw();y--;usleep(100000);draw();
                  // y--;usleep(100000);draw();y--;usleep(100000);draw();y--;usleep(100000);draw();
                  // usleep(150000);
                  // y++;usleep(100000);draw();y++;usleep(100000);draw();y++;usleep(100000);draw();
                  // y++;usleep(100000);draw();y++;usleep(100000);draw();y++;usleep(100000);draw();
                  // usleep(150000);break;


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