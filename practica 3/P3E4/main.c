#include "gqueue.h"
#include <string.h>

void* copiarString(void* dato){
  char* str = (char*)dato;
  char* copia = (char*)malloc(sizeof(char) * (strlen(str) + 1));
  strcpy(copia, str);
  return copia;
}

void imprimirString(void* dato){
  printf("%s ", (char*)dato);
}

void destruirDato(void* dato){
  free(dato);
}

int main(){
  GQueue* queue = gqueue_crear();

  char* str1 = "Cadena";
  char* str2 = "String";

  queue = gqueue_encolar(queue, str1, copiarString);
  gqueue_recorrer(queue, imprimirString);

  queue = gqueue_encolar(queue, str2, copiarString);
  gqueue_recorrer(queue, imprimirString);

  gqueue_desencolar(queue, destruirDato);
  gqueue_recorrer(queue, imprimirString);

  gqueue_desencolar(queue, destruirDato);
  gqueue_recorrer(queue, imprimirString);

  gqueue_destruir(queue, destruirDato);

  return 0;
}