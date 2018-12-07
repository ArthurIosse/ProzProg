#include <stdio.h>
#include <stdlib.h>

int n = 3;

double dotproduct(double a[],double b[])
{
double c;
for (int i = 0 ; i < n ; i++)
{
  c += a[i]*b[i];
}
  return c;
}



int main (int argc, char * argv[])
{
  double x;
  double y;

  printf("give the dimension please:");
  scanf("%d",&n);


double * myvector1 = (double*)malloc(n*sizeof(double));
double * myvector2 = (double*)malloc(n*sizeof(double));

for(int i = 0 ; i<n ; i++)
{
  printf("please give the %d member of the 1st vector:",i+1);
  scanf("%lf",&x);
  myvector1[i] = x;
}
for(int i = 0 ; i<n ; i++)
{
  printf("please give the %d member of the 2nd vector:",i+1);
  scanf("%lf",&y);
  myvector2[i] = y;
}

printf("%lf \n",dotproduct(&myvector1[0],&myvector2[0])); //arrays call by referenz
printf ("%lf that\n",myvector2);

free(myvector1);
free(myvector2);
  return 0;
}
