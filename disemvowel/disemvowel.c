#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "disemvowel.h"

char* disemvowel(char* str) {
  int i, len;
  len = strlen(str); 
  char* cloneStr = calloc(len, sizeof(char));
  char vowels[11] = "aeiouAEIOU"; // 11 for including \0
  for (i = 0; i < len; ++i) {
    cloneStr[i] = str[i];
  }
  //for (i = 0; i < len; ++i) {
  //  if (strchr(vowels, cloneStr[i]) != NULL) {
  //    // check for null char
  //    shiftLeft(cloneStr, i);
  //    i = i-1;
  //  }
  //}
  i = 0;
  while(i < len){
    if (strchr(vowels, cloneStr[i]) != NULL) {
      // check for null char
      shiftLeft(cloneStr, i);
      //i = i-1;
    } 
    i++;
  } 
  
  return cloneStr;
}

void shiftLeft(char* str, int index) {
  int i;
  for(i = index; i <= strlen(str); ++i) {
    str[i] = str[i + 1];
  }

}
