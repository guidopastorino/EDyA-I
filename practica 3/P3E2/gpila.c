#include "gpila.h"
#include <string.h>

GStack stack_crear(){
  GStack stack = (GStack)malloc(sizeof(Stack));
  assert(stack != NULL);
  stack->top = NULL;
  return stack;
}

void stack_destruir(GStack stack, FuncionDestructora destroy){
  GList current = stack->top;
  while(current != NULL){
    GList temp = current;
    current = current->next;
    destroy(current->data);
    free(current);
  }
  free(stack);
}

int stack_vacia(GStack stack){
  return stack->top == NULL;
}

void stack_recorrer(GStack stack, FuncionVisitante visit){
  for(GList current = stack->top; current != NULL; current = current->next){
    visit(current->data);
  }
}

int compare(void* dato1, void* dato2){
  int a = *(int*)dato1;
  int b = *(int*)dato2;
  return (a == 0) ? 0 : (a < b) ? -1 : 1;
}


// inserta un nuevo elemento en la lista
GStack stack_insertar(GStack stack, void *dato, FuncionCopia copy, FuncionComparadora cmp){
  GList nuevoNodo = (GList)malloc(sizeof(GNode));
  nuevoNodo->next = NULL;
  nuevoNodo->data = copy(dato);
  assert(nuevoNodo != NULL);

  nuevoNodo->next = stack->top;
  stack->top = nuevoNodo;

  return stack;
}

int stack_buscar(GStack stack, void *dato, FuncionComparadora cmp){
  for(GList current = stack->top; current != NULL; current = current->next){
    if(cmp(current->data, dato) == 0) return 1;
    current = current->next;
  }
  return 0;
}

GStack stack_arr(void **arr, int size, FuncionCopia copy, FuncionComparadora cmp){
  GStack stack = stack_crear();
  for(int i = 0; i<size; i++){
    stack = stack_insertar(stack, arr[i], copy, cmp);
  }

  // ordenar la lista enlazada
  for(GList current = stack->top; current != NULL; current = current->next){
    for(GList next = current->next; next != NULL; next = next->next){
      if(cmp(current->data, next->data) > 0){
        void* temp = current->data;
        current->data = next->data;
        next->data = temp;
      }
    }
  }
}
