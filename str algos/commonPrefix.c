// Finds the common prefix between two strings.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* commonPrefix(char str1[], char str2[]){
  str1 = strlwr(str1);
  str2 = strlwr(str2);

  int len1 = strlen(str1);
  int len2 = strlen(str2);

  int i = 0;
  while(i<len1 && i<len2 && str1[i] == str2[i]){
    i++;
  }

  char* prefix = (char*)malloc(sizeof(char) * (i + 1));
  if(prefix == NULL){
    printf("Error when allocating memory\n");
    exit(EXIT_FAILURE);
  }
  strncpy(prefix, str1, i);
  prefix[i] = '\0';

  return prefix;
}

int main(){
  char str1[] = "abcdefgh";
  char str2[] = "abcdejkl";

  char* prefix = commonPrefix(str1, str2);

  printf("Common prefix: %s", prefix);

  free(prefix);

  return 0;
}