#include <stdio.h>
#include <string.h>

typedef struct {
  char* start_time; // Fecha y hora de inicio del viaje (yy/mm/dd - hr:min:sec)
  char* end_time; // Fecha y hora de finalización del viaje (yy/mm/dd - hr:min:sec)
} Viaje;

void imprimir_viaje(Viaje viaje){
  printf("%s, %s\n", viaje.start_time, viaje.end_time);
}

void insertion_sort_viajes(Viaje viajes[], int size){
  int i, j;
  for(i = 1; i<size; i++){
    Viaje key = viajes[i];
    j = i - 1;
    while(j >= 0 && strcmp(key.end_time, viajes[j].end_time) < 0){ // Ordenar por fecha y hora de finalización
      viajes[j + 1] = viajes[j];
      j--;
    }
    viajes[j + 1] = key;
  }
}

void imprimir_viajes(Viaje viajes[], int size){
  for(int i = 0; i<size; i++)
    imprimir_viaje(viajes[i]);
}

int main(){
  // ordenado por la fecha y hora del comienzo del viaje
  Viaje viajes[] = {
    {"2024-04-15 - 10:20:25", "2024-04-15 - 10:20:45"},
    {"2024-04-15 - 12:30:00", "2024-04-15 - 12:30:30"},
    {"2024-04-16 - 18:22:55", "2024-04-16 - 18:50:03"},
    {"2024-04-17 - 07:30:35", "2024-04-17 - 08:00:00"},
    {"2024-04-17 - 22:45:21", "2024-04-17 - 23:10:19"},
  };

  int size = sizeof(viajes) / sizeof(viajes[0]);

  printf("Viajes: \n");

  imprimir_viajes(viajes, size);

  insertion_sort_viajes(viajes, size);

  printf("\n\n");

  imprimir_viajes(viajes, size);

  return 0;
}

/*
  ¿Por qué es esperable que Insertion sort sea más rápido que Quicksort en este caso?
  En el contexto de datos casi ordenados, como los viajes que duran menos de 30 minutos, Insertion Sort es más eficiente que Quicksort debido a su menor overhead y mejor comportamiento en escenarios donde los elementos están cerca de su posición final.
*/