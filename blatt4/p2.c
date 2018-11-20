#include <stdio.h>


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

int main (int argc, char * argv[])
{
printf("%lf\n",myexp(8));
  return 0;
}
