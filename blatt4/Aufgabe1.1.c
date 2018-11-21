#include <stdio.h>
#include <math.h>


  //"My"functions implementation
//sinus Funktion
double mysin(double x){
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
double myarctan(double x){
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
double myln(double x){
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

   //main function
int main (int argc, char * argv[])
{
  //scanning a number
double input;
printf("Give a number Sir!");
scanf("%lf",&input);

  //printing the results of "My"functions
printf("  myFunctions for %lf \n\n",input);
printf("  sin(%lf) = %lf\n",input,mysin(input));
if (input > -1.0 && input < 1.0)
{
  printf("  arctan(%lf) = %lf\n",input,myarctan(input));
}
if (input > 0 && input < 2.0){
  printf("  ln(%lf) = %f\n",input,myln(input));
}
printf("\n");


  //the comparison the the "<math.h>" functions of the same input
char y;
printf("do you want to compare with <math.c> Sir?(y/n)\n");
scanf(" %c",&y);
switch (y)
{
  case 'y': printf("calculating, please wait...\n   <math.h> Functions for %lf \n\n",input);
            printf("  sin(%lf) = %lf\n",input, sin(input));
            printf("  arctan(%lf) = %lf\n",input, atan(input));
            printf("  ln(%lf) = %lf\n",input, log(input));
  break;
  case 'n': printf("Goodbye!"); break;
  default : printf("Wrong char");
}
printf("\n");


  return 0;
}
