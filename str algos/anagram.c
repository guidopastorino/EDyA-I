//  Given two strings, determines if they are anagrams of each other.

#include <stdio.h>
#include <string.h>

int anagram(char str1[], char str2[]){
  str1 = strlwr(str1);
  str2 = strlwr(str2);

  int len1 = strlen(str1);  
  int len2 = strlen(str2);  

  if(len1 != len2) return 0;

  char count[256] = {0};

  for(int i = 0; i<len1; i++){
    count[str1[i]]++;
  }
  
  for(int i = 0; i<len2; i++){
    count[str2[i]]--;
  }

  for(int i = 0; i<256; i++){
    if(count[i] != 0){
      return 0;
    }
  }

  return 1;
}

int main(){
  char str1[] = "Hello";
  char str2[] = "OlelH";

  int res = anagram(str1, str2);

  printf("%s\n", (res == 1) ? "Both strings are anagrams." : "Both strings are not anagrams.");

  return 0;
}