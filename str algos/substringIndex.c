#include <stdio.h>
#include <string.h>

int substring_index(char str[], char sub[]){
  int len_str = strlen(str);
  int len_sub = strlen(sub);
  for(int i = 0; i<=len_str-len_sub; i++){
    int j;
    for(j = 0; j<len_sub; j++){
      if(str[i + j] != sub[j])
        break;
    }
    if(j == len_sub)
      return i;
  }
  return -1;
}

int main(){
  char str[] = "hola";
  char sub[] = "ola";

  int index = substring_index(str, sub);
  printf("%d\n", index);

  return 0;
}