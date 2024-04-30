#include <stdio.h>
#include <string.h>

// Función para contar el número de ocurrencias de una subcadena en una cadena
int countOccurrences(char *str, char *subStr) {
  int len = strlen(subStr);
  int count = 0;
  while((str = strstr(str, subStr)) != NULL){
    count++;
    str += len;
  }
  return count;
}

int main() {
  char str[] = "zxyazxytttyzxyaaabc";
  char subStr[] = "zxy";
  
  int occurrences = countOccurrences(str, subStr);
  printf("Número de ocurrencias de '%s' en '%s': %d\n", subStr, str, occurrences);

  return 0;
}
