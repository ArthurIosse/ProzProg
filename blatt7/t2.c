// #include <stdio.h>
// #include <stdlib.h>
#include "libBMP.h"

#define x_MIN -2.0
#define x_MAX  1.0
#define y_MIN -1.0
#define y_MAX  1.0


#define BMP_B 80
#define BMP_H 80

void toMath(int X, int Y, double* x, double* y) {
//wenn funkwert liegt auserhalb BMP
  if ((X < 0) || (X > BMP_B) || (Y < 0) || (Y > BMP_H)) {
    printf("Fehler: 0 <= %d <= %d\n", X, BMP_B);
    printf("   oder 0 <= %d <= %d verletzt!\n", Y, BMP_H);
    *x = x_MIN;
    *y = y_MIN;
    return;
  }
  *x = x_MIN + ((double) X * (x_MAX - x_MIN)) / BMP_B;
  *y = y_MIN + ((double) (BMP_H - Y) * (y_MAX - y_MIN)) / BMP_H;
  printf("x = %lf ,\ny = %lf .\n",*x,*y);
}

//x Realteil
//y Imaginaerteil
//nZx next Realteil
//nZy next Imaginaerteil

int mandelbrot(double x, double y, double nZx, double nZy, int n_max)
{
int n = 0;
  if(n<=n_max || ((x+y)*(x+y)) >=2 ){
    double zr_next = (nZx*nZx -nZy*nZy + x);
    double zi_next = (2*nZx*nZy+y);
    } else
    {

    }
  return n;
}


int main(int argc,char* argv[])
{
uint32_t * data = (uint32_t*)malloc(BMP_B*BMP_H*sizeof(uint32_t));
  //white background
    for (int i = 0 ; i < BMP_H ; i++)
    {
      for(int j = 0 ; j < BMP_B ; j++)
      {
        int n_max = 400;

        double x;
        double y;
        toMath(j,i,&x,&y);
        data[i * BMP_B + j] = COLOR_WHITE;
      }
    }




    bmp_create("mybmp.bmp",data,BMP_B,BMP_H);
  free(data);
  return 0;
}
