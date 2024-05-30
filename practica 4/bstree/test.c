#include "bstree.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Casos de prueba para arboles de busqueda binaria generales
 */

#define N_PALABRAS 16

static void *copiar_cadena(void *dato) {
  char *str = malloc(sizeof(char) * (strlen(dato) + 1));
  assert(str != NULL);
  strcpy(str, dato);
  return str;
}

static int comparar_cadena(void *dato1, void *dato2) {
  return strcmp(dato1, dato2);
}
static void destruir_cadena(void *dato) { free(dato); }
static void imprimir_cadena(void *dato, __attribute__((unused)) void *extra) {
  /* __attribute__((unused)) le dice al compilador que esta variable puede no
   * ser usada, de esta forma las banderas no tiran warnings.*/
  printf("\"%s\" ", (char *)dato);
}

// int
static void* copiar_entero(void* dato) {
  int* copia = (int*)malloc(sizeof(int));
  assert(copia != NULL);
  *copia = *(int*)dato;
  return copia;
}

static int comparar_entero(void* dato1, void* dato2){
  return (*(int*)dato1) - (*(int*)dato2);
}

static void destruir_entero(void *dato) { free(dato); }

static void imprimir_entero(void* dato, __attribute__((unused)) void* extra) {
  printf("%d ", *(int*)dato);
}

int main() {

  char *palabras[N_PALABRAS] = {"gato",      "perro",    "casa",     "persona",
                                "parque",    "arbol",    "edificio", "calle",
                                "argentina", "santa fe", "rosario",  "unr",
                                "edya",      "farmacia", "tiempo",   "celular"};

  // Creamos un arbol vacio y le insertamos las palabras
  BSTree arbol = bstee_crear();
  for (int i = 0; i < N_PALABRAS; i++)
    arbol = bstree_insertar(arbol, palabras[i], copiar_cadena, comparar_cadena);

  // Imprimir el arbol inorden (alfabetico)
  printf("Recorrido inorden: ");
  bstree_recorrer(arbol, BTREE_RECORRIDO_IN, imprimir_cadena, NULL);
  puts("");

  // Buscar elementos
  assert(bstree_buscar(arbol, "farmacia", comparar_cadena) == 1);
  assert(bstree_buscar(arbol, "santa fe", comparar_cadena) == 1);
  assert(bstree_buscar(arbol, "persona", comparar_cadena) == 1);
  assert(bstree_buscar(arbol, "unr", comparar_cadena) == 1);
  assert(bstree_buscar(arbol, "argentina", comparar_cadena) == 1);
  assert(bstree_buscar(arbol, "telefono", comparar_cadena) == 0);
  assert(bstree_buscar(arbol, "mail", comparar_cadena) == 0);
  assert(bstree_buscar(arbol, "parques", comparar_cadena) == 0);
  assert(bstree_buscar(arbol, "EDyA1", comparar_cadena) == 0);

  arbol = bstree_eliminar(arbol, "farmacia", comparar_cadena, destruir_cadena);
  assert(bstree_buscar(arbol, "farmacia", comparar_cadena) == 0);

  // Imprimir el arbol inorden (alfabetico)
  printf("Recorrido inorden: ");
  bstree_recorrer(arbol, BTREE_RECORRIDO_IN, imprimir_cadena, NULL);
  puts("");

  void* k_esimo_menor = bstree_k_esimo_menor(arbol, 2);

  printf("Segundo menor: %s\n", k_esimo_menor ? k_esimo_menor : "NULL");
  printf("Es arbol binario: %d\n", btree_validar(arbol, comparar_cadena));

  bstree_recorrer_intervalo(arbol, "arbol", "celular", comparar_cadena, imprimir_cadena, NULL);

  // --------------------------------

  puts("");
  puts("Convertir array con recorrido preorder a arbol: ");

  int valores[] = {10, 5, 3, 6, 15, 13, 20};
  int size_arr_valores = sizeof(valores) / sizeof(valores[0]);
  void* preorder_array[size_arr_valores];

  for(int i = 0; i<size_arr_valores; i++)
    preorder_array[i] = &valores[i];

  BSTree arbol_preorder = construir_arbol_preorden(preorder_array, size_arr_valores, copiar_entero, comparar_entero);
  bstree_recorrer(arbol_preorder, BTREE_RECORRIDO_PRE, imprimir_entero, NULL);

  // --------------------------------

  puts("");
  puts("Arbol recorrido BFS: ");
  int valores_recorrido_bfs_bst[] = {50, 45, 61, 33, 47, 57, 65, 22, 38};
  int size_rec_bfs_bst = sizeof(valores_recorrido_bfs_bst) / sizeof(valores_recorrido_bfs_bst[0]);
  void* recorrido_bfs_bst[size_rec_bfs_bst];
  for(int i = 0; i<size_rec_bfs_bst; i++)
    recorrido_bfs_bst[i] = &valores_recorrido_bfs_bst[i];

  BSTree bst_construir_bfs = construir_bst_recorrido_bfs(recorrido_bfs_bst, size_rec_bfs_bst, copiar_entero, comparar_entero);

  if(bst_construir_bfs != NULL){
    bstree_recorrer(bst_construir_bfs, BTREE_RECORRIDO_IN, imprimir_entero, NULL);
    bstree_destruir(bst_construir_bfs, destruir_cadena); // destruir el arbol en caso de ser construido
  } else {
    printf("El recorrido bfs no es valido para bst\n");
  }

  // --------------------------------

  puts("");
  puts("Arbol BST a arbol BST completo: ");
  int nums_bst[] = {10, 5, 20, 7, 15, 25, 30};
  int size_bst = sizeof(nums_bst) / sizeof(nums_bst[0]);
  void* arr_nums_bst[size_bst];

  BSTree bst_normal = NULL;

  // añadimos elementos al array
  for(int i = 0; i<size_bst; i++)
    arr_nums_bst[i] = &nums_bst[i];

  // insertamos elementos al bst
  for(int i = 0; i<size_bst; i++)
    bst_normal = bstree_insertar(bst_normal, arr_nums_bst[i], copiar_entero, comparar_entero);

  // convertimos bst normal a completo
  BSTree bst_completo = bst_convertir_completo(bst_normal, copiar_entero);

  bstree_recorrer(bst_completo, BTREE_RECORRIDO_IN, imprimir_entero, NULL);


  // Destruir árboles
  bstree_destruir(arbol, destruir_cadena);
  bstree_destruir(arbol_preorder, destruir_entero);
  bstree_destruir(bst_completo, destruir_cadena);

  return 0;
}
