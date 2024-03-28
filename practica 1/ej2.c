#include <stdio.h>
#include <string.h>

// a)
void string_reverse(char* str){
  int n = strlen(str);
  for(int i = 0; i<n/2; i++){
    char temp = str[i];
    str[i] = str[n-i-1];
    str[n-i-1] = temp;
  }
}

// b)
int string_concat(char str1[], char str2[], int max){
  if(max > strlen(str2)){
    return 0;
  }

  int i = strlen(str1);
  int j;
  for(j = 0; j<max && str2[j] != '\0'; j++){
    str1[i++] = str2[j];
  }
  str1[i] = '\0';

  return j;
}


// c)


// d)


// e)


// f)


// g)



int main(){
  char str1[] = "Hello world";
  char str2[] = "Hello";

  int n = string_concat(str1, str2, 3);
  printf("%s", str1);


  return 0;
}