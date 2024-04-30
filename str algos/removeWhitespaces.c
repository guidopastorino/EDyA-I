#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Función para eliminar todos los espacios en blanco de una cadena
void removeSpaces(char* str) {
  int len = strlen(str);
  int count = 0;
  for(int i = 0; str[i]; i++){
    if(str[i] != ' '){
      str[count++] = str[i];
    }
  }
  str[count] = '\0';
}

int main() {
  char str[] = "hola a todos";
  printf("Cadena original: %s\n", str);

  removeSpaces(str);
  printf("Cadena sin espacios en blanco: %s\n", str);

  return 0;
}
