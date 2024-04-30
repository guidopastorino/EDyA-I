// Lista general

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <ctype.h>

typedef void (*FuncionDestructora)(void*);
typedef void* (*FuncionCopia)(void*);
typedef void (*FuncionVisitante)(void*);
typedef void* (*FuncionTransformar)(void*);

typedef struct _GNodo {
  void* dato;
  struct _GNodo* sig;
} GNodo;

typedef struct {
  GNodo* primero;
  GNodo* ultimo;
} GList;

GList glist_crear(){
  GList lista;
  lista.primero = NULL;
  lista.ultimo = NULL;
  return lista;
}

void* copia_string(void* dato){
  char* str = (char*)dato;
  int len = strlen(str);
  char* copia_dato = (char*)malloc(sizeof(char) * (len + 1));
  assert(copia_dato != NULL);
  strcpy(copia_dato, str);
  return copia_dato;
}

GList glist_agregar_final(GList lista, void* dato, FuncionCopia copiar){
  GNodo* nuevoNodo = (GNodo*)malloc(sizeof(GNodo));
  nuevoNodo->dato = copiar(dato);
  if(lista.primero == NULL){
    lista.primero = nuevoNodo;
    lista.ultimo = nuevoNodo;
  } else {
    GNodo* actual = lista.primero;
    while(actual->sig != NULL){
      actual = actual->sig;
    }
    actual->sig = nuevoNodo;
    lista.ultimo = nuevoNodo;
  }
  return lista;
}

void destroy(void* dato){
  free(dato);
}

void glist_destruir(GList lista, FuncionDestructora destroy){
  GNodo* actual = lista.primero;
  while(actual != NULL){
    GNodo* temp = actual;
    actual = actual->sig;
    destroy(temp->dato);
    free(temp);
  }
}

// suponemos que el dato que nos pasan es un entero
// entonces imprimimos el entero
void print_int(void* dato){
  printf("%d ", *(int*)dato);
}

void print_str(void* dato){
  printf("%s ", (char*)dato);
}

void glist_recorrer(GList lista, FuncionVisitante visit){
  GNodo* actual = lista.primero;
  while(actual != NULL){
    visit(actual->dato);
    actual = actual->sig;
  }
}

// suponemos que el dato que nos pasan es un entero
// retorna el cuadrado del numero
void* transform(void* dato){
  int entero = *(int*)dato;
  int* res = (int*)malloc(sizeof(int));
  *res = entero * entero;
  return res;  
}

GList glist_map(GList lista, FuncionTransformar f, FuncionCopia c){
  GList nueva_lista = glist_crear();
  GNodo* actual = lista.primero;
  while(actual != NULL){
    // aplicamos la funcion transformacion
    void* dato_transformado = f(actual->dato);
    // copiamos el dato 
    void* dato_copiado = c(dato_transformado);
    // agregamos el elemento a la nueva lista
    nueva_lista = glist_agregar_final(nueva_lista, dato_copiado, c);

    actual = actual->sig;
  }
  return nueva_lista;
}

// Defina una funci´on stringMayuscula que cumpla con el prototipo de FuncionTransformar.
// La misma debe tomar un string y devolver un nuevo string igual al anterior pero con todos
// sus caracteres alfab´eticos en may´uscula.

void* stringMayuscula(void* dato){
  char* str = (char*)dato;
  int len = strlen(str);
  char* strMay = (char*)malloc(sizeof(char) * (len + 1));
  for(int i = 0; i<len; i++){
    strMay[i] = toupper(str[i]);
  }
  assert(strMay != NULL);
  strMay[len] = '\0';
  return strMay;
}

int main() {
    GList lista = glist_crear();
    char* str = "Licenciatura";
    lista = glist_agregar_final(lista, str, copia_string);
    str = "en";
    lista = glist_agregar_final(lista, str, copia_string);
    str = "Ciencias";
    lista = glist_agregar_final(lista, str, copia_string);
    str = "de la";
    lista = glist_agregar_final(lista, str, copia_string);
    str = "Computacion.";
    lista = glist_agregar_final(lista, str, copia_string);

    // Convertir todos los elementos de la lista a mayúsculas
    lista = glist_map(lista, stringMayuscula, copia_string);

    // Ahora puedes utilizar la lista con todos los elementos en mayúsculas

    // Liberar la memoria de la lista y los elementos
    glist_destruir(lista, destroy);

    return 0;
}
