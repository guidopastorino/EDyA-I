#include <stdio.h>
#include <stdlib.h> // qsort()

typedef struct {
  int grupo;
  char nombre[256];
  int index; // Indice que mantienen al ser insertados en un arreglo.
} Persona;

int comparar_personas(const void* p1, const void* p2){
  Persona* p1_ptr = (Persona*)p1;
  Persona* p2_ptr = (Persona*)p2;
  if(p1_ptr->grupo != p2_ptr->grupo){
    return p1_ptr->grupo - p2_ptr->grupo;
  } else { // si los grupos son iguales, comparar por índice (mantener estabilidad)
    return p1_ptr->index - p2_ptr->index;
  }
}

void imprimir_persona(Persona* p){
  printf("Grupo: %d, Nombre: %s, Indice: %d\n", p->grupo, p->nombre, p->index);
}

int main(){
  Persona* personas[] = {
    &(Persona){1, "Persona 1", 0},
    &(Persona){2, "Persona 2", 1},
    &(Persona){1, "Persona 3", 2},
    &(Persona){3, "Persona 4", 3},
    &(Persona){2, "Persona 5", 4},
  };
  int size = sizeof(personas) / sizeof(personas[0]);

  printf("Array personas desordenado:\n");
  for(int i = 0; i<size; i++)
    imprimir_persona(personas[i]);

  qsort(personas, size, sizeof(Persona*), comparar_personas);

  printf("Array personas ordenado:\n");
  for(int i = 0; i<size; i++)
    imprimir_persona(personas[i]);

  return 0;
}