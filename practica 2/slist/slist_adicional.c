#include "slist_adicional.h"

SList *slist_crear(int data){
  SList* newList = (SList*)malloc(sizeof(SList));
  assert(newList != NULL);
  newList->primero = NULL;
  newList->ultimo = NULL;
  return newList;
}

void slist_agregar_inicio(SList* list, int data){
  Node* newNode = crear_nodo(data);
  if(list == NULL){
    list->primero = newNode;
    list->ultimo = newNode;
  } else {
    newNode->next = list->primero;
    list->primero = newNode;
  }
}

void slist_agregar_final(SList* list, int data){
  Node* newNode = crear_nodo(data);
  if(list == NULL){
    list->primero = newNode;
    list->ultimo = newNode;
  } else {
    list->ultimo->next = newNode;
    list->ultimo = newNode;
  }
}

// - Ventajas:

// Encapsulamiento mejorado: La estructura SList encapsula tanto el primer nodo como el último, lo que puede hacer que la gestión de la lista sea más clara y menos propensa a errores.
// Más fácil de extender: Si deseas agregar más metadatos a la lista (por ejemplo, longitud, puntero a un nodo específico, etc.), es más fácil hacerlo utilizando una estructura SList que utilizando solo un puntero al primer nodo.

// - Desventajas:

// Más complejidad: La nueva definición agrega una capa adicional de indirección, lo que puede aumentar la complejidad, especialmente si se realizan operaciones frecuentes de inserción y eliminación.
// Más sobrecarga de memoria: La estructura SList puede ocupar más memoria que solo mantener un puntero al primer nodo, especialmente si no se necesitan los punteros al último nodo en todas las operaciones.

// En general, la elección entre utilizar una estructura SList o simplemente un puntero al primer nodo depende del contexto específico y de los requisitos del programa. La estructura SList puede ser más adecuada para casos donde se necesita un mayor nivel de encapsulamiento y donde se planea extender la funcionalidad de la lista en el futuro. Por otro lado, mantener solo un puntero al primer nodo puede ser más eficiente en términos de memoria y complejidad para aplicaciones simples.