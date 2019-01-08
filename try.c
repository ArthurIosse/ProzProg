#include <stdio.h>
#include <math.h>




int main(int argc, char * argv[])
{
int a ;
int b ;
int c ;

printf("enter a in : aX^2  + bX  +  c ");
scanf("%d",&a);
printf("enter b in : aX^2  + bX  +  c ");
scanf("%d",&b);
printf("enter c in : aX^2  + bX  +  c ");
scanf("%d",&c);

double det = sqrt((b*b)-(4*a*c));

double null1 = ((-b)+det)/(2*a);
double null2 = ((-b)-det)/(2*a);


printf("x1 = %lf, x2 = %lf \n",null1,null2);

  return 0;
}
