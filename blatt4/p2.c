#include <stdio.h>

// e
double myexp(double x){
double c=1;
double y=c;
double yalt=y+1.0;

for(int k=1; y!=yalt;k++){
    c=c*(x/k);
    yalt=y;
    y=y+c;
    //printf("%f\n",y);    //Zwischenergebnisse
}
return y;
}
//cos
double mycos(double x){
double c=1;
double y=c;
double yalt=y+1.0;

for(int k=1; y!=yalt;k++){
    c=-c*(x*x)/((2*k)*(2*k-1));
    yalt=y;
    y=y+c;
    //printf("%f\n",y);    //Zwischenergebnisse
}
return y;
}

int main (int argc, char * argv[])
{
printf("exp(8) = %lf\n",myexp(8));
printf("cos(8) = %lf\n",mycos(8));

  return 0;
}
