#include <math.h>
#include <stdio.h>
#include "libBMP.h"
#define N 200
#define M 120

#define X_MIN 1
#define X_MAX 17
#define Y_MIN 10                    //Y_MAX und Y_MIN sind vertauscht
#define Y_MAX -5


void toMath(int X, int Y, int* x, int* y){

    *x = X_MIN+((double)X*(X_MAX-X_MIN))/M;
    *y = Y_MIN+((double)Y*(Y_MAX-Y_MIN))/N;

}

void toBMP(    ){     //tomath umgekehrt

   // *X
   // *Y

}




int main() {

    uint32_t* data = (uint32_t*) malloc (N*M*sizeof(uint32_t));

    for (int i=0; i<M ;i++){

        //x Achse
        if(i==M/2){
            for (int j=0; j<M ;j++){
                    data[i*N+j] = COLOR_BLACK;
        }
        }else{

        for (int j=0; j<N ;j++){
            data[i*N + j] = COLOR_WHITE;
        }
        //y Achse
        for (int j=0; j<M ;j++){
            if(j==N/2)
            data[i*N+j] = COLOR_BLACK;
          }

        }

    }

    for(int x=X_MIN; x<X_MAX; x++){
        //for(int y=Y_MIN; y<Y_MAX; y++){
        int y =x*x;
        toMath(N,M,&x,&y);
        data[x*N+y*y] = COLOR_RED;
        }







    bmp_create("plot.bmp", data, N, M);

    free(data);

    return 0;
}
