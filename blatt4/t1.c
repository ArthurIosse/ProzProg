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
double input;
printf("Give a number Sir!");
scanf("%lf",&input);


printf("sin(%lf) = %lf\n",input,sin(input));
if (input > -1.0 && input < 1.0)
{
  printf("arctan(%lf) = %lf\n",input,arctan(input));
}
if (input > -1.0 && input < 1.0){
  printf("ln(%lf) = %f\n",input,ln(input));
}
  return 0;
}
