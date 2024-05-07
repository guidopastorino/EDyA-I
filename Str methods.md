
----
## <center>STRING FUNCTIONS</center>
----
#### Funciones de strings de la librería <string.h>



<hr />

#### int strcasecmp(const char *str1, const char * str2);
Compara entre dos cadenas de manera insensible a minusculas y mayúsculas. Devuelve 1 si no son iguales y 0 si son iguales.

```C
char *str1 = "Hello";
char *str2 = "heLLo";

if(strcasecmp(str1, str2) == 0){
    printf("Son iguales");
} else {
    printf("No son iguales");
}
```

<hr />

#### char *strcat(const char *dest, const char *src);
Concatena la cadena de origen 'src' al final de la cadena destino 'dest'
```C
char destino[100] = "Hello";
strcat(destino, " World");
printf("%s", destino); // Hello World
```


<hr />

#### errno_t strcat_s(char *dest, rsize_t destsz, const char *src);
Concatena la cadena de origen (src) al final de la cadena de destino (dest) de manera segura. Devuelve un código de error (errno_t) indicando el resultado de la operación
```C
char destino[20] = "Hola";
errno_t err1 = strcat_s(destino, sizeof(destino), ", mundo!");
fprintf(stderr, "%d - %s\n", err1, strerror(err1)); // 0 - No error
errno_t err2 = strcat_s(destino, sizeof(destino), ", mundo Worlddddddddddddddddddddd!");
fprintf(stderr, "%d - %s\n", err2, strerror(err2)); // 34 - Result too large
```


<hr />

#### char *strchr(const char *str, int val);
Busca la primera aparición de un carácter en una cadena. Puntero a la primera ocurrencia del carácter c en la cadena str, o NULL si no se encuentra.
```C
char *pos = strchr("Programming", 'm');
printf("%p", pos);
```


<hr />

#### int strcmp(const char *str1, const char *str2);
Compara dos cadenas de manera sensible a mayusculas y minusculas. Devuelve 0 si son iguales y 1 si no son iguales.

```C
if(strcmp("Hola", "hola") == 0){
    printf("Son iguales");
} else {
    printf("No son iguales");
}
```


<hr />

#### char *strcpy(const char *dest, const char *src);
Copia la cadena de origen (src) en la cadena de destino (dest). Devuelve un puntero a la cadena resultante después de la copia.
```C
char destino[100];
strcpy(destino, "Hola");
printf("%s", destino); // Hola
```


<hr />

#### errno_t strcpy_s(char *dest, rsize_t destsz, const char *src);
Copia la cadena de origen (src) en la cadena de destino (dest) de manera segura. Devuelve un código de error 'errno_t' indicando el resultado de la operación.
```C
char destino[100];
errno_t err = strcpy_s(destino, sizeof(destino), "Hola");

fprintf(stderr, "%d - %s\n", err, strerror(err)); // 0 - No error
printf("%s", destino); // Hola
```


<hr />

#### size_t strcspn(const char *str, const char *reject);
Devuelve la longitud del prefijo de la cadena que no contiene ningún carácter de la cadena de búsqueda.
```C
size_t len = strcspn("abracadabra", "c");
printf("%zu\n", len); // 4, ya que la palabra hasta "abra" no contiene "c"
```


<hr />

#### char *strdup(const char *src);
Duplica cadena en una nueva ubicación de memoria. Devuelve un puntero a una nueva cadena duplicada en memoria dinámica.
```C
char *str1 = "Hola";
char *str2 = strdup(str1);

printf("str1 '%s': %p\n", str1, str1); // str1 'Hola': 00007ff6578e9000
printf("str2 '%s': %p\n", str2, str2); // str2 'Hola': 0000025ee6fa1430
```


<hr />

#### size_t strlen(const char *str);
Devuelve un entero que representa la longitud de la cadena
```C
strlen("Hola"); // 4
```


<hr />

#### char *strlwr(char *str);
Convierte la cadena a minusculas
```C
char cadena[] = "Hola Mundo";
strlwr(cadena);
printf("%s", cadena); // hola mundo
```


<hr />

#### int strncmp(const char *str1, const char *str2, size_t n);
Compara las primeras n caracteres de dos cadenas distinguiendo mayúsculas y minúsculas. Devuelve 0 si los primeros n caracteres de las dos cadenas son iguales, 1 si no son iguales
```C
char str1[] = "abcde123";
char str2[] = "abcdefgh123";

if(strncmp(str1, str2, 3) == 0){
    printf("Son iguales\n");
} else {
    printf("No son iguales\n");
}
```


<hr />

#### int strncasecmp(const char *str1, const char *str2, size_t n);
Compara las primeras n caracteres de dos cadenas sin distinguir mayúsculas y minúsculas. Devuelve 0 si los primeros n caracteres de las dos cadenas son iguales, 1 si no son iguales
```C
char str1[] = "abcde123";
char str2[] = "abcdefgh123";

if(strncasecmp(str1, str2, 3) == 0){
    printf("Son iguales\n");
} else {
    printf("No son iguales\n");
}
```


<hr />

#### char *strncat(char *dest, const char *src, size_t n);
Concatena los primeros n caracteres de la cadena de origen (src) al final de la cadena de destino (dest). Devuelve un puntero a la cadena resultante después de la concatenación de los primeros n caracteres de src.
```C
char str1[] = "abcde123";
strncat(str1, "456789", 3);
printf("%s", str1); // abcde123456
```



<hr />

#### char *strncpy(char *dest, const char *src, size_t n);
Copia los primeros n caracteres de la cadena de origen (src) en la cadena de destino (dest).
```C
char destino[100];
strncpy(destino, "Hola, mundo!", 4);
destino[4] = 0;
printf("%s", destino); // Hola
```

<hr />

#### ar *strnset(char *str, char c, size_t n);
Establece los primeros n caracteres de una cadena a un valor específico. Devuelve un puntero a la cadena resultante después de establecer los primeros n caracteres a c.
```C
char cadena[] = "Hola Mundo!";
strnset(cadena, '-', 4);
printf("%s", cadena); // ---- Mundo!
```

<hr />

#### ar *strpbrk(const char *str, const char *accept);
Busca la primera aparición de cualquier carácter de accept en la cadena str. Devuelve un puntero a la primera ocurrencia en str de cualquier carácter de accept, o NULL si no se encuentra.
```C
char *str = "Hola Mundo";
char *pos = strpbrk(str, "Mundo");

if(pos){
    printf("First matching character: %c", *pos);
} else {
    printf("Not first-matching character\n");
}
```


<hr />

#### char *strrchr(const char *str, char c)
Busca la última aparición del caracter 'c' en una cadena 'str'. Devuelve un puntero a la última ocurrencia del carácter c en la cadena str, o NULL si no se encuentra.

```C
char str[] = "abcdeff";
char *ptr = strrchr(str, 'j');

if(ptr){
    *ptr = 'F';
    printf("%s", str); // abcdefF
} else {
    printf("Character not found in the string\n");
}
```


<hr />

#### char *strrev(char *str);
Invierte una cadena
```C
char cadena[] = "Programming";
strrev(cadena);
printf("%s", cadena); // gnimmargorP
```



<hr />

#### char *strset(char *str, char val)
Establece todos los caracteres de una cadena a un valor específico.
```C
char cadena[] = "Programming";
strset(cadena, '*');
printf("%s", cadena); // ***********
```


<hr />

#### size_t strspn(const char *str, const char *accept);
Devuelve la longitud de la subcadena inicial que contiene solo caracteres de 'accept'
```C
char cadena[] = "Programming";
int n = strspn(cadena, "Prog");
printf("%d\n", n); // 5
```



<hr />

#### char *strstr(const char *str, const char *substr);
Busca la primera aparición de una subcadena en otra. Devuelve un puntero al primer caracter de la subcadena 'substr' en 'str', o NULL si no se encuentra.

```C
char str[] = "123abc456";
char *pos = strstr(str, "abc");

if(pos){
    *pos = 'A';
}

printf("%s", str); // 123Abc456
```



<hr />

#### char *strtok(char *str, const char *delimiters);
Divide una cadena en tokens utilizando delimitadores. Devuelve un puntero al siguiente token en la cadena, o NULL si no hay más tokens.
```C
char cadena[] = "Hola a todos buenos dias.";
char *token = strtok(cadena, " ");

while(token != NULL){
    printf("token: %s\n", token);
    token = strtok(NULL, " ");
}
// token: Hola
// token: a
// token: todos
// token: buenos
// token: dias.
```



<hr />

#### char *strupr(char *str);
Convierte una cadena a mayúsculas.
```C
char cadena[] = "hola mundo!";
strupr(cadena);
printf("%s", cadena); // HOLA MUNDO!
```



<hr />

#### static inline int sprintf(char *str, const char *format, ...)
Imprime el formato especificado en una cadena. Devuelve el número de caracteres escritos en str o un valor negativo si ocurre un error.
```C
char buffer[50];
sprintf(buffer, "La cadena buffer acepta valores con parametros: %d", 50);
printf("%s", buffer); // La cadena buffer acepta valores con parametros: 50
```



<hr />

#### int snprintf(char *str, size_t size, const char *format, ...);
Imprime el formato especificado en una cadena con un límite de caracteres. Devuelve el número de caracteres que habrían sido escritos en str si size hubiera sido suficiente o el valor negativo si ocurre un error.
```C
char buffer[50];
snprintf(buffer, sizeof(buffer), "La vaca que caminaba sola pesaba %d kilos y ayer estaba en un bosque perdida", 50);
printf("%s", buffer); // La vaca que caminaba sola pesaba 50 kilos y ayer
```

<br />

----
#### <center>MEM FUNCS</center>
----

<br />

#### void *memccpy(void *dest, const void *src, int c, size_t n);

Copia hasta n bytes desde src a dest, deteniéndose si encuentra el carácter c. Devuelve un puntero al primer byte después de c en dest o NULL si c no se encuentra en los primeros n bytes de src.
```C
char dest[50];
char *ptr = memccpy(dest, "abracadabra", 'c', 10);
printf("%s\n", dest); // abrac
*ptr = 'z';
printf("%s\n", dest); // abracz
```

<hr />

#### void *memchr(const void *str, int val, size_t n)
Busca la primera aparición de un byte específico en los primeros n bytes de una memoria. Devuelve un puntero al primer byte de str que contiene 'c' o NULL si 'c' no se encuentra en los primeros 'n' bytes.
```C
char str[] = "Hello World";
char *ptr = memchr(str, 'W', 7);

printf("%s", ptr ? "Caracter encontrado" : "Caracter no encontrado"); // Caracter encontrado
```

<hr />

#### int memcmp(const void *s1, const void *s2, size_t n);
Compara los primeros n bytes de dos bloques de memoria. Devuelve 1 si los primeros n bytes son iguales, en caso contrario, devuelve 0.
```C
char str1[] = "Hello world";
char str2[] = "Hello humans";

printf("%d\n", memcmp(str1, str2, 5) == 0); // 1, ya que "Hello" está presente en los dos strings
```

<hr />

#### void *memcpy(void *dest, const void *src, size_t n);
Copia los primeros n bytes de src a dest.
```C
char dest[50];
char src[] = "Hello world";
memcpy(dest, src, 11);
printf("%s", dest); // Hello world
```

<hr />

#### void *memmove(void *dest, const void *src, size_t n);
Copia los primeros n bytes de src a dest de manera segura incluso si los bloques de memoria se superponen.
```C
char str[] = "Hello";
memmove(str + 1, str + 2, 3);
// - str + 1: "ello" -> lugar a copiar
// - str + 2: "llo" -> lugar donde vienen los caracteres (caracteres que se usan para copiar en 'dest')
// - 3 -> bytes a copiar

printf("%s", str); // Hlloo
```

<hr />

#### void *mempcpy(void *dest, const void *src, size_t n);
Copia los primeros n bytes de src a dest y devuelve un puntero al siguiente byte después de la copia. Devuelve un puntero al byte siguiente al último byte copiado en dest, este mismo, es nulo, ya que apunta a una direccion nula.
```C
char dest[20];
char str[] = "Hello World";
char *pos = mempcpy(dest, str, 10);
printf("%s\n", dest); // Hello Worl
*pos = 'D';
printf("%s\n", dest); // Hello WorlD
```

<hr />

#### id *memset(void *str, int c, size_t n);
Establece los primeros n bytes de memoria apuntados por str al valor c.
```C
char str[10];
memset(str, '-', sizeof(str));

for(int i = 0; i<10; i++){
    printf("%c ", str[i]); // str -> "- - - - - - - - - -"
}
```