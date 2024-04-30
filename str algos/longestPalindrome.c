#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int isPalindrome(const char* str, int start, int end){
  while(start < end){
    if(str[start] != str[end]) return 0;
    start++;
    end--;
  }
  return 1;
}

char* longestPalindrome(const char* str){
  int maxLen = 0;
  int startIdx = 0;
  int len = strlen(str);
  for(int i = 0; i<len; i++){
    for(int j = i; j<len; j++){
      if(isPalindrome(str, i, j) && j - i + 1 > maxLen){
        maxLen = j - i + 1;
        startIdx = i;
      }
    }
  }
  char* res = (char*)malloc(sizeof(char) * (maxLen + 1));
  strncpy(res, str + startIdx, maxLen);
  res[maxLen] = '\0';
  return res;
}

int main(){
  const char* str = "abracadabrarbadacarbaaefofea";
  const char* res = longestPalindrome(str);
  printf("%s", res);

  return 0;
}