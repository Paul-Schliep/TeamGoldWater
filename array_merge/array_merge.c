#include <stdlib.h>
#include <stdio.h>
#include "array_merge.h"

int* array_merge(int num_arrays, int* sizes, int** values){
	int i;
	int totalSize = 0;
	for (i = 0; i < num_arrays; i++) {
		totalSize += sizes[i];
	}

	int* newArray = calloc(totalSize+1, sizeof(int));


	int j;
	int k = 0;
	int max = 0;
	
	//find largest value in array
	for (i = 0; i < num_arrays; i++) {
		for (j = 0; j < sizes[i]; j++) {
			newArray[k] = values[i][j];
			if (values[i][j] > max) {
				max = values[i][j];
			}
			k++;
		}
	}
	int* countArray = calloc(max, sizeof(int));
	for (i = 0; i < totalSize; i++) {
		countArray[newArray[i]]++;
	}	
	for (i = 0; i < 10; i++) {
	}
	for (i = 0, k = 1; i <= max; i++) {
		if (countArray[i] > 0) {
			newArray[k] = i;
			k++;
		}
	}
	
	newArray[0] = k-1;
	free(countArray);
	return newArray;


}
