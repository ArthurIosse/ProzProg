#include <stdio.h>
#include <math.h>

//sinus Funktion
double sin(double x){
double c=x;
double y=c;
double yalt=y+1.0;

for(int k=1; y!=yalt;k++){
    c=-c*(x*x)/((2*k+1)*(2*k));
    yalt=y;
    y=y+c;
    //printf("%f\n",y);    //Zwischenergebnisse
}
return y;
}
//arctan Funktion
double arctan(double x){
double c=x;
double y=c;
double yalt=y+1.0;

for(int k=1;y!=yalt;k++){
    c=-c*(x*x*(2*k-1))/(2*k+1);
    yalt=y;
    y=y+c;
    //printf("%f\n",y);     //Zwischenergebnisse
}
return y;
}
//ln Funktion
double ln(double x){
double c=(x-1);
double y=c;
double yalt=y+1.0;

for(int k=2; yalt!=y;k++){
    c=-c*((x-1)*(k-1))/k;
    yalt=y;
    y=y+c;
    //printf("%f\n",y);     //Zwischenergebnisse

}

return y;

}


int main (int argc, char * argv[])
{

printf("sin  %f\n",sin(12.0));
printf("arctan %f\n",arctan(0.3));
printf("ln %f\n",ln(0.4));

  return 0;
}
