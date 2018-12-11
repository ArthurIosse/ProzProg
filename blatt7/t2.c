// #include <stdio.h>
// #include <stdlib.h>
#include "libBMP.h"

#define BMP_B 500
#define BMP_H 400


int main(int argc,char* argv[])
{
uint32_t * pic = (uint32_t*)malloc(BMP_B*BMP_H*sizeof(uint32_t));

    for (int i = 0 ; i < BMP_H ; i++)
    {
      for(int j = 0 ; j < BMP_B ; j++)
      {

        if(i <= 100){
        pic[i*BMP_H + j] = COLOR_RED;
      }else if(i > 100 && i < 300)
      {
        pic[i*BMP_H + j] = COLOR_GREEN;
      }else
      {
        pic[i*BMP_H + j] = COLOR_BLUE;
      }
      if(j > 150 && j < 350)
      {
        pic[i * BMP_H + j] = COLOR_BLACK;
      }
      }
    }
    bmp_create("mybmp.bmp",pic,BMP_B,BMP_H);
  free(pic);
  return 0;
}
