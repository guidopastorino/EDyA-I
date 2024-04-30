#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// void reverseString(char* str){
//   int len = strlen(str);
//   for(int i = 0; i<len/2; i++){
//     char temp = str[i];
//     str[i] = str[len-i-1];
//     str[len-i-1] = temp;
//   }
// }

char* reverseString(const char* str){
  int len = strlen(str);
  char* res = (char*)malloc(sizeof(char) * (len + 1));
  for(int i = 0; i<len; i++){
    res[i] = str[len-i-1];
  }
  res[len] = '\0';
  return res;
}

int main(){
  const char str[] = "javascript";
  char* res = reverseString(str);
  printf("%s", res);
  free(res);

  return 0;
}