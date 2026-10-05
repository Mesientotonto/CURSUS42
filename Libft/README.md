*Este proyecto ha sido creado como parte del currículo de 42 por acornia.*

# Libft

## Descripción
Programar en C puede ser complicado cuando no tenemos acceso a muchas de las funciones habituales de la biblioteca estándar. Libft es un proyecto individual de 42 en el que creamos nuestra propia biblioteca implementando algunas de estas funciones. El objetivo es entender mejor cómo funcionan, aprender a utilizarlas y practicar conceptos básicos de C, como las estructuras de datos y los algoritmos. Además, esta biblioteca nos servirá como herramienta para futuros proyectos, ya que en 42 no siempre podemos utilizar las funciones de la biblioteca estándar.

## Instrucciones
Para compilar la librería, ejecuta `make` en la raíz del repositorio. Esto generará el archivo `libft.a`. 
Las reglas disponibles en el `Makefile` son:
* `make` o `make all`: Compila la parte obligatoria.
* `make bonus`: Compila la parte obligatoria junto con las funciones de listas enlazadas.
* `make clean`: Elimina los archivos objeto (`.o`).
* `make fclean`: Elimina los archivos objeto y el archivo `libft.a`.
* `make re`: Ejecuta `fclean` seguido de `all`.

## Recursos

* **Uso de IA:** Se ha usado la Inteligencia Artificial para documentarse y como apoyo para entender y solucionar problemas de memoria.

---

## <big>Funciones de la librería<big>

### Parte 1 - Funciones de libc

Aquí se recrean funciones clásicas de C respetando sus prototipos y comportamientos originales. El objetivo de este grupo es entender cómo actúan estas utilidades internamente y aprender a implementarlas. En conjunto, asientan el dominio de operaciones fundamentales a bajo nivel, como la manipulación de bytes, la validación de caracteres y el manejo directo de punteros sin dependencias externas.

| <big>Nombre<big> | <big>Prototipo<big> | <big>Descripción<big> |
| :--- | :--- | :--- |
| **[`ft_isalpha`](#)** | `int ft_isalpha(int c);` | Comprueba si un carácter es alfabético (letra minúscula o mayúscula). |
| **[`ft_isdigit`](#)** | `int ft_isdigit(int c);` | Comprueba si un carácter es un dígito decimal (0 al 9). |
| **[`ft_isalnum`](#)** | `int ft_isalnum(int c);` | Comprueba si un carácter es alfanumérico (letra o número). |
| **[`ft_isascii`](#)** | `int ft_isascii(int c);` | Comprueba si un carácter pertenece a la tabla ASCII (0 al 127). |
| **[`ft_isprint`](#)** | `int ft_isprint(int c);` | Comprueba si un carácter es imprimible, incluyendo el espacio. |
| **[`ft_strlen`](#)** | `size_t ft_strlen(const char *s);` | Calcula y devuelve la longitud de una cadena de caracteres. |
| **[`ft_memset`](#)** | `void *ft_memset(void *b, int c, size_t len);` | Rellena los primeros `len` bytes de un bloque de memoria con el byte `c`. |
| **[`ft_bzero`](#)** | `void ft_bzero(void *s, size_t n);` | Escribe ceros (`\0`) en los primeros `n` bytes de un bloque de memoria. |
| **[`ft_memcpy`](#)** | `void *ft_memcpy(void *dst, const void *src, size_t n);` | Copia `n` bytes de un área de memoria a otra (las áreas no deben solaparse). |
| **[`ft_memmove`](#)** | `void *ft_memmove(void *dst, const void *src, size_t len);` | Copia memoria de manera segura, incluso si las áreas de origen y destino se solapan. |
| **[`ft_strlcpy`](#)** | `size_t ft_strlcpy(char *dst, const char *src, size_t size);` | Copia una cadena a un tamaño específico garantizando su terminación con `\0`. |
| **[`ft_strlcat`](#)** | `size_t ft_strlcat(char *dst, const char *src, size_t size);` | Concatena cadenas de forma segura respetando el tamaño total del buffer de destino. |
| **[`ft_toupper`](#)** | `int ft_toupper(int c);` | Convierte un carácter de letra minúscula a su equivalente en mayúscula. |
| **[`ft_tolower`](#)** | `int ft_tolower(int c);` | Convierte un carácter de letra mayúscula a su equivalente en minúscula. |
| **[`ft_strchr`](#)** | `char *ft_strchr(const char *s, int c);` | Encuentra la primera aparición del carácter `c` en la cadena `s`. |
| **[`ft_strrchr`](#)** | `char *ft_strrchr(const char *s, int c);` | Encuentra la última aparición del carácter `c` en la cadena `s`. |
| **[`ft_strncmp`](#)** | `int ft_strncmp(const char *s1, const char *s2, size_t n);` | Compara los primeros `n` bytes de dos cadenas de caracteres. |
| **[`ft_memchr`](#)** | `void *ft_memchr(const void *s, int c, size_t n);` | Busca la primera aparición de un byte en los primeros `n` bytes de un bloque de memoria. |
| **[`ft_memcmp`](#)** | `int ft_memcmp(const void *s1, const void *s2, size_t n);` | Compara los primeros `n` bytes de dos áreas de memoria byte a byte. |
| **[`ft_strnstr`](#)** | `char *ft_strnstr(const char *haystack, const char *needle, size_t len);` | Busca la primera aparición de una subcadena dentro de otra, examinando máximo `len` caracteres. |
| **[`ft_atoi`](#)** | `int ft_atoi(const char *str);` | Convierte la porción inicial de una cadena apuntada por `str` a una representación de número entero. |
| **[`ft_calloc`](#)** | `void *ft_calloc(size_t count, size_t size);` | Reserva memoria para un arreglo de `count` elementos y los inicializa todos a cero. |
| **[`ft_strdup`](#)** | `char *ft_strdup(const char *s1);` | Reserva memoria dinámica y devuelve una copia exacta de la cadena dada. |

---

### Parte 2 - Funciones adicionales

Este bloque agrupa funciones que no pertenecen a la librería estándar original o que operan de forma distinta. Como conjunto, su función es automatizar de forma segura tareas complejas que requieren reserva dinámica de memoria. Centralizan operaciones estructurales como la extracción, concatenación y división de cadenas, abstrayendo la gestión manual de asignaciones y reduciendo la complejidad del código.

| <big>Nombre<big> | <big>Prototipo<big> | <big>Descripción<big> |
| :--- | :--- | :--- |
| **[`ft_substr`](#)** | `char *ft_substr(char const *s, unsigned int start, size_t len);` | Reserva memoria y devuelve una subcadena extraída de `s` a partir del índice `start` con longitud máxima `len`. |
| **[`ft_strjoin`](#)** | `char *ft_strjoin(char const *s1, char const *s2);` | Reserva memoria y devuelve una nueva cadena que resulta de concatenar `s1` y `s2`. |
| **[`ft_strtrim`](#)** | `char *ft_strtrim(char const *s1, char const *set);` | Reserva memoria y devuelve una copia de `s1` sin los caracteres contenidos en `set` al principio ni al final. |
| **[`ft_split`](#)** | `char **ft_split(char const *s, char c);` | Divide la cadena `s` utilizando el delimitador `c` y devuelve un arreglo de cadenas resultante terminado en `NULL`. |
| **[`ft_itoa`](#)** | `char *ft_itoa(int n);` | Reserva memoria y convierte un número entero a su representación en formato de cadena de texto (string). |
| **[`ft_strmapi`](#)** | `char *ft_strmapi(char const *s, char (*f)(unsigned int, char));` | Crea una nueva cadena iterando `s` y aplicando la función `f` a cada carácter pasando su índice y valor. |
| **[`ft_striteri`](#)** | `void ft_striteri(char *s, void (*f)(unsigned int, char*));` | Modifica directamente la cadena `s` aplicando la función `f` a cada carácter mediante referencia. |
| **[`ft_putchar_fd`](#)** | `void ft_putchar_fd(char c, int fd);` | Escribe un único carácter `c` en el descriptor de archivo (file descriptor) dado. |
| **[`ft_putstr_fd`](#)** | `void ft_putstr_fd(char *s, int fd);` | Escribe una cadena de texto completa en el descriptor de archivo indicado. |
| **[`ft_putendl_fd`](#)** | `void ft_putendl_fd(char *s, int fd);` | Escribe una cadena de texto en el descriptor de archivo y le añade un salto de línea (`\n`) al final. |
| **[`ft_putnbr_fd`](#)** | `void ft_putnbr_fd(int n, int fd);` | Escribe la representación en texto de un número entero en el descriptor de archivo dado. |

---

### Parte 3 - Listas enlazadas (Bonus)

Este conjunto introduce la manipulación de listas enlazadas, demostrando que trabajar con este tipo de estructuras puede ser aún más útil que la gestión de arrays estáticos. Su importancia radica en la capacidad de administrar datos cuyo tamaño varía dinámicamente durante la ejecución. En grupo, estas funciones resuelven la lógica necesaria para inicializar, enlazar, recorrer y liberar nodos en memoria no contigua.

| <big>Nombre<big> | <big>Prototipo<big> | <big>Descripción<big> |
| :--- | :--- | :--- |
| **[`ft_lstnew`](#)** | `t_list *ft_lstnew(void *content);` | Reserva memoria y crea un nuevo nodo inicializando `content` con el parámetro y `next` a `NULL`. |
| **[`ft_lstadd_front`](#)** | `void ft_lstadd_front(t_list **lst, t_list *new);` | Añade el nodo `new` al principio de la lista, actualizando el puntero inicial. |
| **[`ft_lstsize`](#)** | `int ft_lstsize(t_list *lst);` | Recorre la lista enlazada y cuenta el número total de nodos que contiene. |
| **[`ft_lstlast`](#)** | `t_list *ft_lstlast(t_list *lst);` | Recorre la lista y devuelve un puntero al último nodo de la misma. |
| **[`ft_lstadd_back`](#)** | `void ft_lstadd_back(t_list **lst, t_list *new);` | Añade el nodo `new` al final de la lista, enlazándolo con el nodo que anteriormente era el último. |
| **[`ft_lstdelone`](#)** | `void ft_lstdelone(t_list *lst, void (*del)(void *));` | Libera la memoria del contenido del nodo usando la función `del` y libera el nodo en sí (no libera el siguiente). |
| **[`ft_lstclear`](#)** | `void ft_lstclear(t_list **lst, void (*del)(void *));` | Elimina y libera la memoria del nodo dado y de todos los nodos consecutivos usando la función `del`. |
| **[`ft_lstiter`](#)** | `void ft_lstiter(t_list *lst, void (*f)(void *));` | Recorre la lista completa y aplica la función `f` al contenido de cada uno de sus nodos. |
| **[`ft_lstmap`](#)** | `t_list *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));` | Crea una nueva lista resultante de aplicar la función `f` al contenido de cada nodo de la lista original. |