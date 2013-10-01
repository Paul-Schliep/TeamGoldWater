#include <stdio.h>
#include <stdlib.h>

#include "array_merge.h"

int main(int argc, char* argv[]) {
  
  int *values[3]; // = {{3, 2, 0, 5}, {8, 9}, {6, 3, 2, 0, 5}};
  int one[4] = {3, 2, 0, 5};
  int two[2] = {8, 9};
  int three[5] = {6, 3, 2, 0, 5};
  values[0] = one;
  values[1] = two;
  values[2] = three;
  int sizes[3] = {4, 2, 5};
  int num_arrays = 3;
  int i;
  //printf("starting \n");
  int* temp = array_merge(num_arrays, sizes, values);
  printf("done. Size: %d \n", temp[0]);
  for(i = 1; i < temp[0]+1; ++i){
    printf("%d ",temp[i]);
  }

  return 0;
}
