#ifndef DLIST_H
#define DLIST_H

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

/*
  Estructura que representa un nodo de una lista doblemente enlazada
*/
typedef struct _DNodo
{
  int dato;           // Dato del nodo
  struct _DNodo *sig; // Puntero al siguiente nodo
  struct _DNodo *ant; // Puntero al nodo anterior
} DNodo;

/*
  Estructura que representa una con referencias a sus nodos del inicio y del final de una lista doblemente enlazada
*/
typedef struct
{
  DNodo *primero; // Puntero al primer nodo
  DNodo *ultimo;  // Puntero al segundo nodo
} DList;

/*
  enum que representa de que forma se va a recorrer la lista
*/
typedef enum
{
  DLIST_RECORRIDO_HACIA_ADELANTE, // Recirrido de izquierda a derecha
  DLIST_RECORRIDO_HACIA_ATRAS     // Recirrido de derecha a izquierda
} DListOrdenDeRecorrido;

/*
  Crear la lista
*/
DList* crear_lista(DNodo* nodo);

/*
  Crear un nuevo nodo
*/
DNodo* crear_nodo(int dato);

/*
  Agregar un nodo al inicio de la lista
*/
void insertar_inicio(DList **lista, int dato);

/*
  Agregar un nodo al final de la lista
*/
void insertar_final(DList **lista, int dato);

/*
  Agregar un nodo en una posicion especifica de la lista
*/
void insertar_posicion(DList **lista, int dato);

/*
  Eliminar el primer nodo de la lista
*/
void eliminar_inicio(DList **lista);

/*
  Eliminar el nodo final de la lista
*/
void eliminar_final(DList **lista);

/*
  Eliminar el nodo de una posicion específica de la lista
*/
void eliminar_posicion(DList **lista, int pos);

/*
  Obtener la cantidad de nodos
*/
int longitud_lista(DList *lista);

/*
  Imprimir la lista de izquierda a derecha. Recibe un tipo, el cual indica si se recorre hacia adelante o hacia atrás
*/
void imprimir_adelante(DList *lista);

void imprimir_atras(DList *lista);

void dlist_recorrer(DList *lista, DListOrdenDeRecorrido tipo);

/*
  Libera la memoria ocupada por los nodos de la lista
*/
void liberar_lista(DList *lista);

#endif // DLIST_H