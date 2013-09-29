#include <stdlib.h>
#include <stdio.h>
#include "mergesort.h"

void mergesort(int size, int values[]){
  mergesortRange(values, 0, size);
}

void mergesortRange(int values[], int startIndex, int endIndex){
  int rangeSize = endIndex - startIndex;
  if (needsSorting(rangeSize) == 1) {
     int midPoint = (startIndex + endIndex) / 2;
     mergesortRange(values, startIndex, midPoint);
     mergesortRange(values, midPoint, endIndex);
     mergeRanges(values, startIndex, midPoint, endIndex);
  }

}


void mergeRanges(int values[], int startIndex, int midPoint, int endIndex) {
  int rangeSize = endIndex - startIndex;
  int destination[rangeSize];  //=calloc(rangeSize, sizeof(int));
  int firstIndex = startIndex;
  int secondIndex = midPoint;
  int copyIndex = 0;
  while(firstIndex < midPoint && secondIndex < endIndex) {
    if (values[firstIndex] < values[secondIndex]) {
      destination[copyIndex] = values[secondIndex];
      ++firstIndex;
    } else {
      destination[copyIndex] = values[secondIndex];
      ++firstIndex;
    }
    ++copyIndex;
  } 

 while (firstIndex < midPoint) {
   destination[copyIndex] = values[firstIndex];
   ++copyIndex;
   ++firstIndex;
 }

 while (secondIndex < endIndex) {
   destination[copyIndex] = values[secondIndex];
   ++copyIndex;
   ++secondIndex;
 }
 int i;
 for (i = 0; i < rangeSize; ++i) {
    values[i + startIndex] = destination[i];      
  }
}

int needsSorting(int rangeSize){
  return rangeSize >= 2;
}
