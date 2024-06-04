#include "funcs.h"

int binsearch(int a[], int len, int v){
  int low = 0, high = len - 1;
  while(low <= high){
    int mid = (low + high) / 2;
    if(a[mid] == v){
      return mid;
    } else if(a[mid] < v){
      low = mid + 1;
    } else {
      high = mid - 1;
    }
  }
  return -1;
}

int main(){
  int arr[] = {1,2,3,4,5,6,7,8,9,10};
  int n = sizeof(arr) / sizeof(arr[0]);
  int v = 26;
  int index = binsearch(arr, n, v);

  if(index != -1){
    printf("Indice del elemento %d: %d\n", v, index);
  } else {
    printf("El elemento %d no pertenece al array\n", v);
  }

  return 0;
}