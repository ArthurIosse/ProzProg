#include "sort.h"




void bubblesort(int arr[],int size)
{
for(int i = 0 ; i < size-1 ; i++)
{
  for(int j = 0 ; j < size-i-1 ; j++)
  {
    if(arr[j] > arr[j+1])
    {
      myswap(&arr[j],&arr[j+1]);
    }
  }
}
}



void mymergesort(int arr[], int size){

     if(size > 1){

         int haelfte1[size/2];
         int haelfte2[(size + 1)/2];
         int i;
         for(i = 0; i < size/2; i++){
             haelfte1[i] = arr[i];
           }
         for(i = size/2; i < size; i++){
             haelfte2[i - size/2] = arr[i];
           }

         mymergesort(haelfte1,size/2);
         mymergesort(haelfte2,(size + 1)/2);

         int *pos1 = &haelfte1[0];
         int *pos2 = &haelfte2[0];
         for(i = 0; i < size; i++){
             if(*pos1 <= *pos2){
                 arr[i] = *pos1;
                 if (pos1 != &haelfte2[(size+1)/2 - 1]) { // pos1 nicht verändern, wenn der größte Wert mehrmals vorkommt
                     if(pos1 == &haelfte1[size/2 - 1]){
                         pos1 = &haelfte2[(size+1)/2 - 1];
                     }
                     else{
                         ++pos1;
                     }
                 }
             }
             else{
                 arr[i] = *pos2;
                 if(pos2 == &haelfte2[(size + 1)/2 - 1]){
                     pos2 = &haelfte1[size/2 - 1];
                 }
                 else{
                     ++pos2;
                 }
             }
         }
     }
 }
