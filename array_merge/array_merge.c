#include <stdlib.h>
#include <stdio.h>
#include "array_merge.h"

int* array_merge(int num_arrays, int* sizes, int** values){
	//printf("starting array merge\n");
	int i;
	int totalSize = 0;
	for (i = 0; i < num_arrays; i++) {
		totalSize += sizes[i];
		//printf("size %d: %d, total size: %d \n", i, sizes[i], totalSize);
	}

	//printf("total size: %d \n", totalSize);

	int* newArray = calloc(totalSize+1, sizeof(int));
	//printf("new array created.\n");


	int j;
	int k = 0;
	int max = 0;
	
	//find largest value in array
	for (i = 0; i < num_arrays; i++) {
		for (j = 0; j < sizes[i]; j++) {
			newArray[k] = values[i][j];
			//printf("newArray[%d] set to %d \n", k, values[i][j]);
			if (values[i][j] > max) {
				max = values[i][j];
			}
			k++;
		}
	}
	//printf("Maximum value: %d \n", max);
	int* countArray = calloc(max, sizeof(int));
	for (i = 0; i < totalSize; i++) {
		countArray[newArray[i]]++;
		//printf("At i=%d -- Occurences of %d: %d \n",i, newArray[i], countArray[newArray[i]]);
	}	
	for (i = 0; i < 10; i++) {
		//printf("value: %d, count: %d \n", i, countArray[i]);
	}
	for (i = 0, k = 1; i <= max; i++) {
		//printf("i=%d, k=%d count of %d is %d \n", i, k, i, countArray[i]);
		if (countArray[i] > 0) {
			//printf("%d exists. Setting  it to newArray[%d] \n", i, k);
			newArray[k] = i;
			k++;
		}
	}
	//printf("%d \n", k);
	
	newArray[0] = k-1;
	free(countArray);
	return newArray;


}
