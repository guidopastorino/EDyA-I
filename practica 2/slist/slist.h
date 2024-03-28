#ifndef SLIST_H
#define SLIST_H

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

/*
  Estructura que representa un Nodo de una lista enlazada simple
*/
typedef struct _SNode
{
  int data;            // Dato actual del nodo
  struct _SNode *next; // Puntero al siguiente nodo
} Node;

/*
  Crea un nodo asignandole el dato pasado por parámetro y devuelve un puntero al nodo creado.
*/
Node *crear_nodo(int data);

/*
  Inserta al inicio de la lista enlazada el nuevo nodo
*/
void insertar_inicio(Node **head, int data);

/*
  Inserta al final de la lista enlazada el nuevo nodo
*/
void insertar_final(Node **head, int data);

/*
  Inserta en una posición específica de la lista enlazada el nuevo nodo
*/
void insertar_posicion(Node **head, int pos, int data);

/*
  Elimina el primer nodo de la lista enlazada si esta no es NULL
*/
void eliminar_inicio(Node **head);

/*
  Elimina el último nodo de la lista enlazada si esta no es NULL
*/
void eliminar_final(Node **head);

/*
  Elimina el nodo en la posición indicada de la lista enlazada si esta no es NULL
*/
void eliminar_posicion(Node **head, int pos);

/*
  Imprime los nodos de la lista enlazada (10 -> 20 -> 30 -> NULL)
*/
void imprimir_lista(Node *head);

/*
  Libera la memoria ocupada por los nodos de la lista
*/
void liberar_lista(Node *head);

/*
  Devuelve la longitud de una lista
*/
int slist_longitud(Node* head);

/*
  Devuelve la concatenación de dos listas, modificando la primera.
*/
void slist_concatenar(Node** head1, Node* head2);

/*
  Determina si un elemento está en una lista dada.
*/
int slist_contiene(Node* head, int el);

/*
  Devuelve la posición de la primera ocurrencia de un elemento si el mismo está en la lista dada, y -1 en caso que no esté.
*/
int slist_indice(Node* head, int el);

/*
  Devuelve una nueva lista con los elementos comunes (independientemente de la posición) de dos listas dadas por parámetro. Las listas originales no se modifican.
*/
Node* slist_intersecar(Node* head1, Node* head2);

/*
  Función de comparación
*/
int compare(int a, int b);

/*
  Trabaja como la anterior pero recibe un parámetro extra que es un puntero a una función de comparación que permite definir la noción de igualdad a ser usada al comparar elementos por igualdad.
*/
Node* slist_intersecar_custom(Node* head1, Node* head2, int(*funcPtr)(int, int));

/*
  Ordena una lista de acuerdo al criterio dado por una función de comparación (que usa los mismos valores de retorno que strcmp()) pasada por parámetro.
*/
void slist_ordenar(Node** head, int(*funcPtr)(int, int));

/*
  Obtiene el reverso de una lista.
*/
Node* slist_reverso(Node* head);

/*
  Dadas dos listas, intercala sus elementos en la lista resultante. Ejemplo:
  l1 = [1, 2, 3, 4]
  l2 = [5, 6]
  res =[1, 5, 2, 6, 3, 4].
*/
Node* slist_intercalar(Node* head1, Node* head2);

/*
  Divide una lista a la mitad. En caso de longitud impar (2n + 1), la primer lista tendrá longitud n + 1 y la segunda n. Retorna un puntero al primer elemento de la segunda mitad, siempre que sea no vacía.
*/
Node* slist_partir(Node* head);

#endif // SLIST_H