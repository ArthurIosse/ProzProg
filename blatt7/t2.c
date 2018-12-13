// #include <stdio.h>
// #include <stdlib.h>
#include <math.h>
#include "libBMP.h"

#define x_MIN -2.0
#define x_MAX  1.0
#define y_MIN -1.0
#define y_MAX  1.0


#define BMP_B 1000
#define BMP_H 1000

void toMath(int X, int Y, double* x, double* y)
{
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
  //printf("x = %lf ,\ny = %lf .\n",*x,*y);
}





//x Realteil
//y Imaginaerteil
//nZx next Realteil
//nZy next Imaginaerteil
int mandelbrot(double x, double y, double nZx, double nZy,int n, int n_max,double edge)
{

  if(n<=n_max && (sqrt(nZx * nZx + nZy * nZy) <= 2)){
      //z^2
    // double zr_next = (nZx*nZx - nZy*nZy) + x;
    // double zi_next = (2*nZx*nZy) + y;

     //z^3
     double zr_next = (nZx*nZx*nZx - 2*nZy*nZy*nZx - nZy*nZy*nZx) + x;
     double zi_next = (nZx*nZx*nZy + 2*nZx*nZx*nZy - nZy*nZy*nZy) + y;

     //z^4
     // double zr_next = (nZx*nZx*nZx*nZx - 4*nZy*nZy*nZx*nZx - nZy*nZy*nZx*nZx +nZy*nZy*nZy*nZy) + x;
     // double zi_next = (2*nZx*nZx*nZx*nZy + 2*nZx*nZx*nZx*nZy - 2*nZx*nZy*nZy*nZy - 2*nZx*nZy*nZy*nZy ) + y;


    if ((zr_next == nZx) && (zi_next == nZy)) {
      return n_max;
    }
    n = mandelbrot(x,y,zr_next,zi_next,n+1,n_max,edge);
    }
  return n;
}


int main(int argc,char* argv[])
{
  //variables
uint32_t * data = (uint32_t*)malloc(BMP_B*BMP_H*sizeof(uint32_t));
int n_max = 400;
double edge = 4.0;


    for (int i = 0 ; i < BMP_H ; i++)
    {
      for(int j = 0 ; j < BMP_B ; j++)
      {
        double x;
        double y;
        toMath(j,i,&x,&y);

        int n = mandelbrot(x,y,0.0,0.0,0,n_max,edge);
        //printf("%d \n", n);
        uint32_t color = COLOR_BLACK;
        if (n < 6) {
          color = COLOR_RED;
        }
         else if (n < 14) {
          color = COLOR_GREEN;
        } else if (n < 25) {
          color = COLOR_BLUE;
        } else if (n < n_max) {
          color = COLOR_WHITE;
        }

        //if( n<401 ){color = COLOR_WHITE;}


        data[i * BMP_B + j] = color;

      }
    }



    bmp_create("mybmp.bmp",data,BMP_B,BMP_H);
  free(data);
  return 0;
}
