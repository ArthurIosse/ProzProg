#include <math.h>
#include "libBMP.h"



#define x_MIN -2.0
#define x_MAX  2.0
#define y_MIN -4.0
#define y_MAX  4.0


#define BMP_H 400
#define BMP_W  500



void toBMP(double x, double y, int* X, int* Y) {
//wenn funkwert liegt auserhalb BMP
  if ((x < x_MIN) || (x > x_MAX) || (y < y_MIN) || (y > y_MAX)) {
    printf("Fehler: %f <= %f <= %f\n", x_MIN, x, x_MAX);
    printf("   oder %f <= %f <= %f verletzt!\n", y_MIN, y, y_MAX);
    *X = 0;
    *Y = 0;
    return;
  }
  *X = (int) ((x - x_MIN) * BMP_W / (x_MAX - x_MIN));
  *Y = BMP_H - (int) ((y - y_MIN) * BMP_H / (y_MAX - y_MIN));

}



void toMath(int X, int Y, double* x, double* y) {
//wenn funkwert liegt auserhalb BMP
  if ((X < 0) || (X > BMP_W) || (Y < 0) || (Y > BMP_H)) {
    printf("Fehler: 0 <= %d <= %d\n", X, BMP_W);
    printf("   oder 0 <= %d <= %d verletzt!\n", Y, BMP_H);
    *x = x_MIN;
    *y = y_MIN;
    return;
  }
  *x = x_MIN + ((double) X * (x_MAX - x_MIN)) / BMP_W;
  *y = y_MIN + ((double) (BMP_H - Y) * (y_MAX - y_MIN)) / BMP_H;
}




int main() {
  uint32_t* data = (uint32_t*) malloc (BMP_W * BMP_H * sizeof(uint32_t));

  // Weisser Hintergrund
  for (int X = 0; X < BMP_W; X++) {
    for (int Y = 0; Y < BMP_H; Y++) {
      data[Y * BMP_W + X] = COLOR_WHITE;
    }
  }

  //  XY-Achsen
  int XX, YY;

  toBMP(0.0, 0.0, &XX, &YY);
  //x
  for (int X = 0; X < BMP_W; X++) {
    data[YY * BMP_W + X] = COLOR_BLACK;
  }
  //y
  for (int Y = 0; Y < BMP_H; Y++) {
    data[Y * BMP_W + XX] = COLOR_BLACK;
  }

  // fk
  for (int X = 0; X < BMP_W; X++) {
    double x, y;
    toMath(X, 0, &x, &y);
    toBMP(x, x*x, &XX, &YY);
    data[YY * BMP_W + X] = COLOR_RED;
  }


  bmp_create("plot.bmp", data, BMP_W, BMP_H);
  free(data);

  return 0;
}
