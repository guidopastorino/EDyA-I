#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Función para revertir el orden de las palabras en una frase
void reverseWords(char* str) {
  int len = strlen(str);
  int start = 0;
  // revertimos toda la cadena primero
  for(int i = 0; i<len/2; i++){
    char temp = str[i];
    str[i] = str[len-i-1];
    str[len-i-1] = temp;
  }
  // revertimos las palabras (separadas por ' ')
  for(int i = 0; i<len; i++){
    if(str[i] == ' '){
      int end = i - 1;
      while(start < end){
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
      }
      start = i + 1;
    }
  }
  // revertimos la ultima palabra por las dudas
  int end = len - 1;
  while(start < end){
    char temp = str[start];
    str[start] = str[end];
    str[end] = temp;
    start++;
    end--;
  }
}

int main() {
  char str[] = "Hello world! How are you?";
  printf("Frase original: %s\n", str);

  reverseWords(str);
  printf("Frase con palabras revertidas: %s\n", str);

  return 0;
}
