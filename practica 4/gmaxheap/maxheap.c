#include "maxheap.h"

struct _BHeap {
  void** arr;
  int capacidad;
  int ultimo; // indice del ultimo elemento agregado
  FuncionComparadora cmp;
};

/*
 *  Devuelve el índice del elemento padre de un elemento en el arreglo pasandole el índice
*/
static int parent(int i){
  return (i - 1) / 2;
}

/*
 *  Devuelve el índice del hijo izquierdo de un elemento en el arreglo pasandole el índice
*/
static int left_child(int i){
  return (2 * i) + 1;
}

/*
 *  Devuelve el índice del hijo derecho de un elemento en el arreglo pasandole el índice
*/
static int right_child(int i){
  return (2 * i) + 2;
}

/*
 *  Intercambia los valores de dos punteros void*
*/
static void swap(void** a, void** b){
  void* temp = *a;
  *a = *b;
  *b = temp;
}

/*
 *  Heapify Up (max-heap): Se usa durante la inserción para mover un nuevo elemento hacia arriba hasta que se restaure la propiedad del heap.
*/
static void heapify_up(BHeap heap, int i){
  while(i != 0 && heap->cmp(heap->arr[parent(i)], heap->arr[i]) < 0){
    swap(&heap->arr[parent(i)], &heap->arr[i]);
    i = parent(i);
  }
}

/*
 *  Heapify Down (max-heap): Se usa durante la eliminación para mover el elemento de la raíz hacia abajo hasta que se restaure la propiedad del heap.
*/
static void heapify_down(BHeap heap, int i){
  int left = left_child(i);
  int right = right_child(i);
  int largest = i;

  if(left <= heap->ultimo + 1 && heap->cmp(heap->arr[left], heap->arr[largest]) > 0){
    largest = left;
  }

  if(right <= heap->ultimo + 1 && heap->cmp(heap->arr[right], heap->arr[largest]) > 0){
    largest = right;
  }

  if(i != largest){
    swap(&heap->arr[i], &heap->arr[largest]);
    heapify_down(heap, largest);
  }
}

/*
 *  Realoca un arreglo dado, adaptando la nueva capacidad al arreglo (con tipo void**). Modificandolo directamente
*/
static void realloc_array(void*** array, int nueva_capacidad){
  assert(nueva_capacidad >= 0);
  *array = (void**)realloc(*array, sizeof(void*) * nueva_capacidad);
  assert(*array != NULL);
}

/*
 *  Crea un heap vacío con una capacidad y una funcion de comparación dadas
*/
BHeap bheap_crear(int capacidad, FuncionComparadora cmp){
  BHeap heap = (BHeap)malloc(sizeof(struct _BHeap));
  assert(heap != NULL);
  heap->arr = (void**)malloc(sizeof(void*) * capacidad);
  assert(heap->arr != NULL);
  // inicializar arreglo en NULL
  for(int i = 0; i<capacidad; i++)
    heap->arr[i] = NULL;
  heap->capacidad = capacidad;
  heap->ultimo = -1;
  heap->cmp = cmp;
  return heap;
}

/*
 *  Destruye el heap
*/
void bheap_destruir(BHeap heap){
  free(heap->arr);
  free(heap);
}

/*
 *  Retorna 1 si el heap está vacío o 0 en caso contrario
*/
int bheap_es_vacio(BHeap heap){
  return heap->ultimo == -1;
}

/*
 *  Recorre los nodos utilizando búsqueda por extensión (bfs), aplicando la función dada en cada elemento
*/
void bheap_recorrer(BHeap heap, FuncionVisitante visit){
  if(bheap_es_vacio(heap)){
    printf("Heap vacío, no se puede recorrer\n");
    return;
  }
  for(int i = 0; i<=heap->ultimo; i++)
    visit(heap->arr[i]);
}

/*
 *  Agrega un elemento al heap, realocando el arreglo en caso de ser necesario. El resultado debe ser nuevamente un heap binario.
*/
BHeap bheap_insertar(BHeap heap, void* dato, FuncionCopia copy){
  if(heap->ultimo == heap->capacidad - 1){ // Heap lleno
    heap->capacidad *= 2; // Aumentamos x2 la capacidad del heap
    realloc_array(&heap->arr, heap->capacidad); // Realocamos el array con la nueva capacidad
  }

  int i = ++heap->ultimo;

  heap->arr[i] = copy(dato);

  // Recuperar la propiedad del heap (max-heap) con heapify-up;
  heapify_up(heap, i);

  return heap;
}

/*
 * Elimina un elemento del heap. El resultado debe ser nuevamente un heap binario.
*/
BHeap bheap_eliminar(BHeap heap, void* dato, FuncionDestructora destr){
  if(bheap_es_vacio(heap)){
    printf("No es posible eliminar, el heap esta vacio\n");
    return heap;
  }
  
  int index = -1;

  for(int i = 0; i<=heap->ultimo && index == -1; i++){
    if(heap->cmp(heap->arr[i], dato) == 0)
      index = i;
  }

  if(index == -1){
    printf("Elemento a eliminar no encontrado\n");
    return heap;
  }

  destr(heap->arr[index]);

  heap->arr[index] = heap->arr[heap->ultimo--];

  heapify_down(heap, index);

  return heap;
}

/*
 * A partir de un arreglo arbitrario cree un heap binario
*/
BHeap bheap_crear_desde_arr(void **arr, int largo, FuncionCopia copiar,FuncionComparadora cmp){
  BHeap heap = bheap_crear(largo, cmp);

  // copiar elementos
  for(int i = 0; i<largo; i++)
    heap->arr[i] = copiar(arr[i]);

  heap->ultimo = largo - 1;

  int start_idx = (largo / 2) - 1; // Indice con el ultimo nodo que no es una hoja

  for(int i = start_idx; i >= 0; i--)
    heapify_down(heap, i);

  return heap;
}

/*
 * Extrae el máximo elemento del heap y lo retorna
*/
void* bheap_extraer_maximo(BHeap heap){
  if(bheap_es_vacio(heap)){
    printf("Heap vacío\n");
    return NULL;
  }
  void* max_elem = heap->arr[0];
  heap->arr[0] = heap->arr[heap->ultimo--];
  heapify_down(heap, 0);
  return max_elem;
}

/*
 * Heap Sort (array-based heap sorting algorithm) - Sorts an array using a heap
*/
void heap_sort(void*** arr, int size, FuncionComparadora cmp, FuncionCopia copy){
  BHeap heap = bheap_crear(size, cmp);
  // copy elements to heap
  for(int i = 0; i<size; i++)
    heap->arr[i] = copy((*arr)[i]);
  heap->ultimo = size - 1;

  // reescribir arr extrayendo el maximo elemento
  for(int i = 0; i<size; i++)
    (*arr)[i] = copy(bheap_extraer_maximo(heap));

  bheap_destruir(heap);
}