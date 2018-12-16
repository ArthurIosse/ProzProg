#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "sort.h"


void print()
{
  //printf("\n\n\n\n\n\n\n\n\n\n\n\n\n");
  printf("┌─────────────────────────────────────────────────────────────┐\n");
  printf("│ 1) Array-Groesse festlegen        4) Bubblesort (downwards) │\n");
  printf("│ 2) Zahlen Von Tastatur einlesen   5) Mergesort              │\n");
  printf("│ 3) Zufallszahlen erzeugen         6) Programm beenden       │\n");
  printf("└─────────────────────────────────────────────────────────────┘\n");
  //printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
}


void printarray(int arr[],int size)
{
  printf("arr[%d] = { ",size);
  for(int i = 0 ; i < size ; i++)
  {
    printf("%d,",arr[i]);
  }
  printf("}\n");
}


void myswap(int *a,int *b)
{
  int temp = *a;
  *a = *b;
  *b = temp;
}


int main(int argc, char * argv[]){

srand(time(0));
int size;
int choice = 0;
int * arr ;
print();

while(choice != 6)
{
  scanf("%d",&choice);
  switch(choice)
  {
    case 1:
    free(arr);
    printf("Array Groesse eingeben:");
    scanf("%d",&size);
    arr = (int*)malloc(size*sizeof(int));
    break;

    case 2:
    for(int i = 0 ; i < size ; i++)
    {
      printf("arr[%d] = ",i);
      scanf("%d",&arr[i]);
    }
    printarray(arr,size);
    break;

    case 3:
    for(int i = 0 ; i < size ; i++)
    {
      arr[i] = rand()%100;
    }
    printarray(arr,size);
    break;

    case 4:
    bubblesort(arr,size);
    printarray(arr,size);
    break;
    case 5:
    mymergesort(arr,size);
    printarray(arr,size);
    break;
    case 6:  break;

    default:printf("nicht gueltige Eingabe"); break;
  }

}
free(arr);


  return 0;
}
