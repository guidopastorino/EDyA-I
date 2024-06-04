// 4. Estime el costo en tiempo de la siguiente función:
// int buscarX(char *s) {
//  int i;
//  for (i = 0; i < strlen(s); i++) {
//    if (s[i] == 'X')
//      return i;
//  }
//  return -1;
// }
// ¿Se puede mejorar?

/*
  Complejidad temporal:
    - La función strlen(s) tiene una complejidad de O(n), donde n es la longitud de la cadena
    - La función tiene un bucle for que, por cada iteración, se llama a la funcion strlen(s), lo que tiene complejidad de O(n) (peor caso de 'n' iteraciones)
    - Por lo tanto, la complejidad es de O(n^2) en el peor caso

  Es posible mejorar la función calculando previamente el valor de la longitud del string, ya que, por cada iteración, tenemos que calcular el mismo.
  Por lo tanto, la función mejorada quedaría:
  int buscarX(char *s) {
   int i;
   int len = strlen(s);
   for (i = 0; i < len; i++) {
     if (s[i] == 'X')
      return i;
   }
   return -1;
  }

  Al mejorarla de esta forma, reducimos la complejidad de 0(n^2) a O(n).
*/