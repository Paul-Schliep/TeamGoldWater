#include <stdlib.h>
#include <stdio.h>
#include "mergesort.h"

void mergesort(int size, int values[]){
  mergesortRange(values, 0, size);
}

void mergesortRange(int values[], int startIndex, int endIndex){
  int rangeSize = endIndex - startIndex;
  if (needsSorting(rangeSize)) {
     int midPoint = (startIndex + endIndex) / 2;
     printf("##### recursing from %d to %d \n", startIndex, midPoint);
     mergesortRange(values, startIndex, midPoint);
     printf("##### recursing from %d to %d \n", midPoint, endIndex);
     mergesortRange(values, midPoint, endIndex);
     printf("!!!!! merging %d-%d and %d-%d \n", startIndex, midPoint, midPoint, endIndex);
     mergeRanges(values, startIndex, midPoint, endIndex);
  }

}


void mergeRanges(int values[], int startIndex, int midPoint, int endIndex) {
  int rangeSize = endIndex - startIndex;
  //int destination[rangeSize+1];
  int *destination = (int*)malloc(rangeSize * sizeof(int));
  int firstIndex = startIndex;
  int secondIndex = midPoint;
  int copyIndex = 0;
    printf("In mergeRanges: rangeSize=%d firstIndex=%d secondIndex=%d \n", rangeSize, firstIndex, secondIndex);
    
    
  while(firstIndex < midPoint && secondIndex < endIndex) {
    printf("Deciding ");
    if (values[firstIndex] < values[secondIndex]) {
      printf("1: destination[%d] = values[%d] (%d)\n", copyIndex, secondIndex, values[secondIndex]);
      destination[copyIndex] = values[firstIndex];

      ++firstIndex;
     // printf("values[firstIndex] < values[secondIndex], destination[%d] = values[%d]", copyIndex, secondIndex);
    } else {
      printf("2: destination[%d] = values[%d] (%d)\n", copyIndex, secondIndex, values[secondIndex]);
      destination[copyIndex] = values[secondIndex];
      ++firstIndex;
    }
    ++copyIndex;
  } 

 while (firstIndex < midPoint) {
//printf("Entering second while loop");
   destination[copyIndex] = values[firstIndex];
   ++copyIndex;
   ++firstIndex;
 }

 while (secondIndex < endIndex) {
//printf("Entering third while loop");
   destination[copyIndex] = values[secondIndex];
   ++copyIndex;
   ++secondIndex;
 }
 int i;
 printf("rangeSize: %d, startIndex: %d \n", rangeSize, startIndex);
 for (i = 0; i < rangeSize; ++i) {
    printf("setting values[%d] to %d (destination[%d])\n", i+startIndex, destination[i], i);
    values[i + startIndex] = destination[i];      
  }
  free(destination);
}

bool needsSorting(int rangeSize){
  return rangeSize >= 2;
}
