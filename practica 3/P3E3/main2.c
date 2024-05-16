#include "pila.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

typedef struct Persona {
  char* nombre;
  int edad;
} Persona;

void* copiar_persona(void* dato){
  Persona* actual = (Persona*)dato;
  Persona* copia = (Persona*)malloc(sizeof(Persona));
  assert(copia != NULL);
  copia->nombre = (char*)malloc(sizeof(char) * (strlen(actual->nombre) + 1));
  assert(copia->nombre != NULL);
  strcpy(copia->nombre, actual->nombre);
  copia->edad = actual->edad;
  return copia;
}

void destruir_persona(void* dato){
  Persona* p = (Persona*)dato;
  free(p->nombre);
  free(p);
}

void imprimir_persona(void* dato){
  Persona* p = (Persona*)dato;
  printf("%s %d\n", p->nombre, p->edad);
}

int main(){
  Pila pila = pila_crear();

  Persona personas[] = {
    {"Persona1", 30},
    {"Persona2", 27},
    {"Persona3", 24},
  };

  for(int i = 0; i<3; i++){
    pila_apilar(pila, &personas[i], copiar_persona);
  }

  pila_destruir(pila, destruir_persona);

  return 0;
}