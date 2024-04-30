// Determines if a string is a palindrome.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int isPalindrome(const char* str){
  int len = strlen(str);
  int start = 0;
  int end = len - 1;
  while(start < end){
    if(str[start] != str[end]){
      return 0;
    }
    start++;
    end--;
  }
  return 1;
}

int main(){
  char *palabras[] = {"radar", "nivel", "reconocer", "somos", "oso", "mundo"};
  int size = sizeof(palabras) / sizeof(palabras[0]);

  for(int i = 0; i<size; i++){
    char* palabra = palabras[i];
    int palindrome = isPalindrome(palabra);
    printf("%s: %s\n", palabra, palindrome ? "palindromo" : "no es palindromo");
  }

  return 0;
}