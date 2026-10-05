## INDICE
* [[#FT_STRCHR--------------------------------------------------------]]
* [[#FT_MEMSET--------------------------------------------------------]]
* [[#FT_MEMMOVE-----------------------------------------------------]]
* [[#FT_STRLCAT--------------------------------------------------------]]
* [[#FT_CALLOC---------------------------------------------------------]]
* [[#FT_STRDUP---------------------------------------------------------]]
* [[#FT_SUBSTR---------------------------------------------------------]]
* [[#FT_PUTCHAR_FD---------------------------------------------------]]
* [[#FT_PUTSTR_FD-----------------------------------------------------]]
* [[#FT_PUTENDL_FD----------------------------------------------]]
* [[#FT_STRITERI---------------------------------------------------]]
* [[#FT_PUTNBR_FD-----------------------------------------------]]
* [[#FT_LSTNEW_BONUS------------------------------------------]]
* [[#FT_LSTSIZE_BONUS------------------------------------------]]
* [[#FT_LSTLAST_BONUS------------------------------------------]]
* [[#FT_LSTADD_FRONT_BONUS---------------------------------]]
* [[#FT_LSTADD_BACK_BONUS-----------------------------------]]
* [[#FT_LSTDELONE_BONUS--------------------------------------]]
* [[#FT_LSTITER_BONUS------------------------------------------]]
* [[#FT_LSTCLEAR_BONUS----------------------------------------]]
* [[#FT_LSTMAP_BONUS------------------------------------------]]

https://cdn.intra.42.fr/pdf/pdf/224013/es.subject.pdf

En este ejercicio hay que replicar la librearia libft.h.

## FT_STRCHR--------------------------------------------------------

![[Pasted image 20260923164800.png]]

**while (\*s != (char)c)** =  \*s accede al caracter actual en la posicion de memoria a la que apunta s, (char)c es un casteo de tipo convirtiendo el entero c en un char para poder compararlo de igual a igual con \*s.

**if (\*s == '\0')** = si ha llegado hasta el final sin encontrar el caracter c este retorna nada.

**return ((char \*)s)** = como se declara la variable s como un const char, pero la funcion pide un char, se hace un cambio de variable.

## FT_MEMSET--------------------------------------------------------

La función `memset()` rellena los primeros `n` bytes de la zona de memoria apuntada por `s` con el byte constante `c`.
### Description

This function is what you use to set a region of memory to a particular value, namely `c` converted into `unsigned char`.

The most common usage is to zero out an array or `struct`.

`memset_explicit()` only differs in that it will never be optimized away (like `memset()` might be). The idea is that you could use it to most-definitely remove sensitive information (like passwords) from memory before any nasty hackers get their hands on it.

![[Pasted image 20260924123732.png]]

**void \*ft_memset(void \*b, int c, size_t len)** --
**void \*** = la funcion devolvera la misma direccion de memoria que recibio.
**void \*b** = es el puntero a la memoria que quieres modificar, es un puntero generico, significa "aqui hay una direccion de memoria RAM, pero no se que tipo de dato hay dentro".
**int c** = el valor que vas a escribir en cada byte.
**size_t len** = la cantidad de bytes que se van a llenar.

Basicamente lo que hace es con ptr guardar esa direccion de memoria como texto, para luego sustituir

## FT_MEMMOVE-----------------------------------------------------

DESCRIPTION
       The  memmove() function copies n bytes from memory area src to memory area dest.  The memory ar‐
       eas may overlap: copying takes place as though the bytes in src are first copied into  a  tempo‐
       rary  array  that does not overlap src or dest, and the bytes are then copied from the temporary
       array to dest.

![[Pasted image 20260925103903.png]]

En el caso de memcpy se iba de delante hacia atras, sin tener en cuanta si se solapan los contenidos. Ya que al ser direcciones de memoria pueden a llegar a solapar, entonces haces de derecha a izquierda, en vez de izquierda a derecha.

## FT_STRLCAT--------------------------------------------------------

![[Pasted image 20260925115320.png]]

En este caso el retorno es el tamaño de src y de dest, primero verificamos que si no hay dest o si el tamaño es 0 pues te devuelve el tamaño de src.

Si el tamaño es menor que el tamaño de dest, pues devuelve el tamaño dado mas la longitud de src, esto es basicamente para saber si el tamaño dado no ha sido suficiente.

Y ya por ultimo se concadenan.

## FT_CALLOC---------------------------------------------------------

       The calloc() function allocates memory for an array of nmemb elements of
       size bytes each and returns a pointer to the allocated memory.  The mem‐
       ory is set to zero.  If nmemb or size is 0, then calloc() returns either
       NULL, or a unique pointer value that can later be successfully passed to
       free().  If the multiplication of nmemb and size would result in integer
       overflow, then calloc() returns an error.  By contrast, an integer over‐
       flow would not be detected in the following call to malloc(),  with  the
       result that an incorrectly sized block of memory would be allocated:

Calloc reserve memoria dinamica en la RAM para un numero determinado de elementos de un tamaño concreto, tambien sirve para limpiar la memoria iniciandola a cero en todos sus bytes.

Sirve para que si lees un puntero recien asignado con malloc antes de escribir en el, tu programa leera basura y fallara de forma impredicible, con calloc, sabes seguro que todo empize en cero.

Tambien sirve para simplificar la creacion de estructuras y cadenas ya que al rellenar todo con ceros, los arrays de caracteres ya tienen automaticamente el terminador '\0' al finall, y los punteros en structs quedan inicializados a NULL.

Para crear ft_calloc, necesitas combinar dos funciones que ya conoces de tu libft: malloc y bzero.

![[Pasted image 20260925132804.png]]

**size_t count** = Cuantos elementos queres guardar.

**size_t size** = Cuanto ocupa cada elemento en bytes.

**ptr = malloc(count * size)** = Calculas cuanta memoria reservar teniendo en cuenta la cantidad y el tamaño.

**if (count != 0 && size > (size_t)-1 / count)** = (size_t)-1 es el numero entero sig signo mas grande posible en C, si el tamaño de un elemento es mayor al maximo permitido dividido entre count, significa que la multiplicacion dara error, asi que devolvemos NULL antes de tocar nada.

**if (!ptr)** = Verificas si ptr existe.

**ptr = malloc(count * size)** = Como ptr es una variable que guarda una direccion de memoria RAM, aqui le decimos que se asigne memoria delimitada por malloc.

**ft_bzero(ptr, count * size)** = Aqui le dices que a esa direccion de memoria sobreescribas la informacion por \0.

## FT_STRDUP---------------------------------------------------------

       The  strdup()  function returns a pointer to a new string which is a du‐
       plicate of the string s.  Memory for the new  string  is  obtained  with
       malloc(3), and can be freed with free(3).

![[Pasted image 20260925135017.png]]

**len = ft_strlen(s)** = se calcula la longitud de s.

**dup = (char \*)malloc(sizeof(char) * (len + 1))** = Aqui se asigna memoria en funcion de la longitud de s, para despues convertirla al tipo que usa dup.

**ft_memcpy(dup, s, len + 1)** = Con la memoria ya resrvada copias s en dup.

## FT_SUBSTR---------------------------------------------------------

![[Pasted image 20260925141400.png]]

## FT_PUTCHAR_FD---------------------------------------------------

![[Pasted image 20260925142746.png]]

![[Pasted image 20260925153349.png]]

## FT_PUTSTR_FD-----------------------------------------------------

![[Pasted image 20260925154510.png]]

![[Pasted image 20260928094334.png]]

# FT_PUTENDL_FD----------------------------------------------

![[Pasted image 20260928094536.png]]

![[Pasted image 20260928095652.png]]

# FT_STRITERI---------------------------------------------------

![[Pasted image 20260928095959.png]]

![[Pasted image 20260928100511.png]]

# FT_PUTNBR_FD-----------------------------------------------

![[Pasted image 20260928100621.png]]

![[Pasted image 20261005113122.png]]

Es lo mismo que un putnbr normal y corriente lo unico que cambia es donde mostramos el resultado.
# FT_LSTNEW_BONUS------------------------------------------

![[Pasted image 20261001115756.png]]

Para entender las listas enlazadas desde cero y dominar cómo funcionan en C, no necesitas memorizar código, sino entender cómo conviven los datos en la memoria de tu ordenador.

Aquí tienes toda la teoría explicada de forma clara, sin rodeos y con ejemplos visuales:

### 1. El problema fundamental: ¿Por qué no usar siempre arrays?

Imagina que creas un array normal en C: `int arr[5];`.

- **Ventaja:** Sus elementos están **pegados** en la memoria RAM, uno detrás de otro. Si sabes dónde empieza el índice `0`, con calcular un pequeño desplazamiento (_offset_) encuentras el índice `4` al instante.
    
- **Problema:** Un array tiene un tamaño **estático** (o requiere funciones complejas como `realloc` si quieres redimensionarlo). Si creas un array de 10 elementos y necesitas guardar el undécimo, estás perdido. Además, si quieres insertar un elemento _en medio_ del array, tienes que mover todos los elementos siguientes de sitio uno a uno.
    

Aquí es donde nacen las **listas enlazadas**.

### 2. ¿Qué es una lista enlazada? (La metáfora del tren)

Una lista enlazada es una estructura de datos lineal, pero a diferencia de los arrays, sus elementos **no están contiguos en la memoria**. Se dispersan por la RAM de forma aleatoria.

Imagina un **tren de mercancías**:

- Cada vagón está aparcado en una vía distinta de una ciudad diferente (la RAM).
    
- Cada vagón lleva una carga dentro (el **contenido** o _content_).
    
- Lo único que conecta los vagones es que **el maquinista de cada vagón tiene un papel con la dirección exacta del siguiente vagón** (el puntero **`next`**).
    

Para recorrer el tren, no puedes saltar al vagón 5 directamente. Tienes que subirte a la locomotora (el primer nodo, conocido como **Head** o cabeza), mirar la dirección del siguiente, ir a él, y así sucesivamente hasta que llegues a un vagón cuyo papel de dirección diga **`NULL`** (lo que significa que es el último vagón).

### 3. La anatomía: ¿Cómo se escribe en C? (`t_list`)

En C, un "vagón" se define mediante una estructura (`struct`) que contiene dos cosas indispensables:

C

```
typedef struct s_list
{
    void            *content; // La carga del vagón (datos genéricos)
    struct s_list   *next;    // El puntero que apunta al siguiente nodo
}   t_list;
```

- **`void *content`**: Se usa un puntero genérico para que el nodo pueda guardar cualquier cosa (un entero, una cadena de texto, otra estructura...). El programa no necesita saber qué tipo de dato es exactamente.
    
- **`struct s_list *next`**: Es un puntero que apunta _a otro nodo del mismo tipo_. El último nodo de la lista siempre debe tener este puntero apuntando a **`NULL`** para indicar que ahí se acaba el camino.
    

### 4. Operaciones básicas: ¿Cómo se manipulan?

Para trabajar con listas enlazadas, hay que dominar cuatro acciones lógicas básicas:

1. **Crear un nodo (`ft_lstnew`):** Vas al _heap_ (con `malloc`) y pides espacio para una estructura `t_list`. Metes el contenido que te pasan y obligatoriamente pones su `next` a `NULL` (porque nace siendo un nodo solitario, sin amigos).
    
2. **Recorrer la lista (El bucle clásico):** Para mirar o contar elementos, nunca mueves el puntero principal de la lista (`lst`), porque si lo pierdes, pierdes el acceso a toda la cadena. Lo que haces es crear un puntero auxiliar (por ejemplo, `t_list *ptr = lst;`) y lo vas moviendo: `ptr = ptr->next;` hasta que `ptr` sea `NULL`.
    
3. **Añadir elementos:**
    
    - **Al principio (`ft_lstadd_front`):** Creas el nuevo nodo, haces que su `next` apunte a la antigua cabeza de la lista, y luego reasignas la cabeza para que ahora sea tu nuevo nodo. Es una operación rapidísima (O(1)).
        
    - **Al final (`ft_lstadd_back`):** Tienes que recorrer toda la lista nodo a nodo hasta encontrar el último (el que tiene `next == NULL`) y cambiar ese `NULL` por la dirección del nuevo nodo.
        
4. **Liberar memoria (`ft_lstclear`):** Este es el punto más crítico en C. Si haces un `malloc` por cada nodo y borras la lista de golpe sin liberar nodo por nodo, dejas una **fuga de memoria** (_memory leak_) gigante. Al borrar un nodo, primero tienes que liberar su contenido (con la función `del`), luego liberar la estructura del nodo (`free`), y tener la precaución de guardar el puntero al _siguiente_ nodo antes de borrar el actual, porque una vez haces `free`, ya no puedes leer la memoria de ese nodo para saber dónde estaba el siguiente.
    

### 5. El peligro número uno: El Segmentation Fault

El pan de cada día al programar listas enlazadas es encontrarse con el temido _Segmentation Fault_. Ocurre casi siempre por dos motivos:

- Intentar leer o escribir en un puntero que vale `NULL` (por ejemplo, intentar hacer `lst->next` cuando `lst` ya es `NULL`). **Regla de oro:** Siempre comprueba que el nodo no sea nulo antes de acceder a sus campos (`if (lst != NULL)`).
    
- Perder la referencia al inicio de la lista (_head_), lo que te deja sin saber dónde empieza el tren y corrompe la memoria al intentar buscar punteros perdidos.

![[Pasted image 20261005104955.png]]

Esta es la estructura basica de un **t_list** , un nodo no es mas que una caja en la memoria (usualmente de 16 bytes) que guarda dos cosas: la direccion de tus datos (**content**) y la direccion de la siguiente caja (**next**).

Diferencia entre **t_list \*** y **t_list\*\*** :
	**t_list \*node** - Apunta a un nodo en especifico. Te permite leer o modificar ese nodo y sus campos (node->content, node->next).
	**t_list \*\*node** - Apunta a la variable que guarda la direccion del primer nodo. Si necesitas modificar que nodo es el primero por ejemplo, al insertar delante, o al vaciar la lista entera, estas obligado a pasar un doble puntero. Si pasaras solo **t_list \***, C crearia una copia de la direccion por paso por valor y tus cambios en el puntero principal se perderian al salir de la funcion.



![[Pasted image 20261001115450.png]]

**t_list \*new** = Declaramos un puntero que almacenara la direccion de memoria donde vivira nuestra nueva estructura **t_list**.

**new = (t_list \*)malloc(sizeof(t_list));** = Llamamos a malloc pidiendo el tamaño exacto que ocupa la estructura t_list(16 bytes). Si la reserva es exitosa, malloc devuelve un puntero void \* a esa zona de memoria, el cual casteamos a **(t_list \*)**.

**if (!new) return (NULL)** = Si el sistema se queda sin RAM, malloc devuelve NULL. Si no comprobamos esto e intentamos escribir en new->content, el programa se rompera inmediatamente con un segmentation fault.

**new->content = content** = Asignamos el puntero que nos han pasado por parametro al campo content del nuevo nodo. Nota que no duplicamos los datos, simplemente guardamos la direccion de memoria donde residen.

**new->next = NULL** = Todo nodo recien creado nace huerfano. Inicializamos su puntero next a NULL. Esto indica que, por ahora, no hay nigun nodo detras de el y evita que contenga "basura" de la memoria.

**return (new)** = Devolvemos la direccion de la estructura que acabamos de construir.

Para entender qué significa realmente `new->content = content;`, hay que olvidar por un momento la palabra "variable" y pensar estrictamente en **direcciones de memoria (punteros)**.

`content` en `ft_lstnew(void *content)` no es una variable que guarde un número o un texto dentro, **es una dirección de memoria** (un número hexadecimal como `0x7ffee3b4` que apunta a donde vive ese dato en la RAM).

Cuando escribes `new->content = content;` paso a paso, ocurre lo siguiente:

### 1. El nodo es una "caja vacía" con etiquetas

Cuando pides memoria para un nodo (`t_list *new = malloc(sizeof(t_list));`), creas un bloque en el _heap_ que tiene dos huecos (o etiquetas):

- `new->content` (hueco para guardar un puntero).
    
- `new->next` (hueco para guardar otro puntero).
    

### 2. Copiar el puntero (no el contenido)

Imagina que tienes una hoja de papel (una variable) con un número escrito, y esa hoja está en la dirección de memoria `0x1000`. Cuando haces `new->content = content;`, **no estás copiando el número del papel dentro del nodo**. Lo que estás haciendo es copiar **la dirección** `0x1000` dentro del hueco `content` del nodo.

Es decir, el nodo ahora tiene una flecha que apunta directamente a esa hoja de papel.

### ¿Por qué se usa un `void *`?

Como la estructura `t_list` no sabe si vas a guardar un número entero, una estructura compleja o una cadena de texto, usa un `void *` (un puntero genérico). Significa literalmente: _"Guarda aquí dentro cualquier dirección de memoria que te pase, a mí no me importa qué hay al final de esa dirección, yo solo guardo la ruta"_.

Por eso, cuando quieras recuperar o usar ese contenido en el futuro, tendrás que **hacer un _cast_** (un cambio de tipo explícito) para recordarle al compilador qué hay guardado en esa dirección.
# FT_LSTSIZE_BONUS------------------------------------------

![[Pasted image 20261005112732.png]]

![[Pasted image 20261005112744.png]]

Cuenta cuántos elementos hay encadenados. Al recibir un puntero simple (`t_list *lst`), la función opera con una copia local de la dirección del primer nodo, por lo que podemos avanzar la variable `lst` sin perder la cabeza de la lista en el programa principal.

**count = 0** = Inicializas la variable que acumulará el número de nodos.

**while (lst != NULL)** = El bucle continúa iterando mientras `lst` mantenga una dirección de memoria válida (es decir, mientras estés posicionado en un nodo).

**count ++** = Incrementas en una unidad el contador por cada iteración válida.

**lst = lst->next** = Sobrescribes la variable local `lst` con la dirección guardada en el campo `next` del nodo actual. Esto desplaza la lectura al siguiente elemento.

**return (count)** = Devuelves la suma total.

Para entender `lst = lst->next;`, volvamos a la metáfora del tren de mercancías.

Imagina que estás parado físicamente en un vagón de ese tren.

- El vagón en el que estás ahora mismo es **`lst`**.
    
- Dentro de ese vagón hay un papel (el puntero `next`) que tiene escrita **la dirección exacta del siguiente vagón**.
    

Cuando escribes `lst = lst->next;`, lo que estás haciendo en la vida real es **desplazarte físicamente al siguiente vagón**.

Paso a paso, la instrucción funciona así:

1. **`lst->next`**: Miras el papel que hay en el vagón actual y lees la dirección del vagón de al lado.
    
2. **`lst = ...`**: Agarras esa dirección y se la asignas a tu variable `lst`. Ahora, la variable deja de apuntar al vagón viejo y pasa a apuntar al nuevo. El vagón viejo queda atrás.

# FT_LSTLAST_BONUS------------------------------------------

![[Pasted image 20261005113741.png]]

![[Pasted image 20261005113801.png]]

Encuentra la dirección del último nodo de la lista. La diferencia fundamental respecto a `ft_lstsize` radica en la condición de parada: no evaluamos `lst != NULL` sino `lst->next != NULL`.

**if (!lst) return (NULL)** = Protección explícita contra listas vacías. Si te pasan un puntero nulo de entrada, devuelves `NULL` inmediatamente, evitando evaluar `lst->next` sobre una dirección inexistente.

**while (lst->next != NULL)** = Se evalua si el nodo actual tiene un nodo sucesor. Si `lst->next` es `NULL`, el bucle se detiene de inmediato **sin avanzar**, dejándote situado sobre el último nodo real de la estructura.

**lst = lst->next** = Reasignas lst a la direccion del siguiente nodo mientras exista un encadenamiento posterior.

**return (lst)** = Devuelves el puntero parado en el ultimo nodo cuyo campo next es NULL.
# FT_LSTADD_FRONT_BONUS---------------------------------

![[Pasted image 20261005112244.png]]

![[Pasted image 20261005112307.png]]

Insertar un nodo al inicio exige modificar la variable externa del programa que almacena la cabeza de la lista. Por eso se requiere un **doble puntero (`t_list **lst`)**: para modificar la variable original en el ámbito de quien llama, no una copia local por valor.

**if (lst != NULL)** = Verificas que la direccion que contiene el puntero a la lista no sea NULL. Si la funcion llamante pasa NULL como doble puntero, cualquier intento de leer \*lst provocaria un colapso de memoria.

**if (\*lst != NULL) new->next = \*lst** = Evaluas si la lista ya contenia nodos. Si exitia un nodo inicial 
(\*lst != NULL), conectas el puntero next del nuevo nodo (new->next) hacia ese antiguo primer
nodo (\*lst).

**\*lst = new** = Modificas el contenido de la variable original apuntada por lst. A partir de esta asignacion, la cabeza de la lista apunta formalmente al nuevo nodo.
****
# FT_LSTADD_BACK_BONUS-----------------------------------

![[Pasted image 20261005114746.png]]

![[Pasted image 20261005114803.png]]

Permite enlazar un nuevo nodo al final de la secuencia. Maneja dos escenarios: una lista previamente existente y una lista vacía.

**if (\*lst == NULL)** = Verificas si el puntero que define el primer nodo de la lista contiene NULL.

**\*lst = new; return ;** = Si la lista esta vacia, no hay ningun nodo existente al que conectar new. Por lo tanto, actualizas la cabeza de la lista asignando directamente new a \*lst y finalizas la ejecucion.

**last = ft_lstlast(\*lst)** = Si la lista contiene elementos, llamas a *ft_lstlast* enviandole la cabeza (\*lst) para que recorra la lista y devuelva la direccion del nodo final.

**last->next = new** = Accedes al campo next de ese ultimo nodo y reescribes su valor (que antes era NULL) fijandolo a la direccion de memoria de new.
# FT_LSTDELONE_BONUS--------------------------------------

![[Pasted image 20261005120706.png]]

![[Pasted image 20261005120724.png]]

Se encarga de desasignar la memoria ocupada por un único nodo especificado. Como el puntero `content` apunta a un área de memoria que puede ser de cualquier tipo (texto, estructura personalizada, etc.), delega la liberación de los datos internos a una función auxiliar enviada por parámetro (`del`).

**del(lst->content)** = Ejecutas la funcion recibida como parametro pasandole como argumento la direccion del contenido (lst->content) para que se encargue de desasignar esa zona de memoria.

**free(lst)** = Una vez liberado el contenido interno, pasas el puntero del nodo a la funcion estandar free() para liberar los 16 bytes que ocupaba la estructura t_list en el heap.
# FT_LSTITER_BONUS------------------------------------------

![[Pasted image 20261005121457.png]]

![[Pasted image 20261005121515.png]]

Itera secuencialmente sobre la lista aplicando la función `f` sobre el campo `content` de cada elemento sin alterar la estructura ni la topología de la lista enlazada.

**while (lst != NULL)** = Matiene la iteracion mientras el puntero actual apunte a una estructura valida.

**f(lst->content)** = Invoca la funcion f pasandole la direccion almacenada en el campo content del nodo que se encuentra.

**lst = lst->next** = Actualiza la variable actual para avanzar la lectura al nodo sucesor.
# FT_LSTCLEAR_BONUS----------------------------------------

![[Pasted image 20261005122234.png]]

![[Pasted image 20261005122246.png]]

Vacía por completo una lista enlazada liberando nodo por nodo. Es crítico guardar la referencia al siguiente elemento antes de destruir el actual para no perder el rastreo del _heap_ (_memory leak_).

**t_list \*temp** = Declaras una variable de paso de tipo puntero para almacenar temporalmente la direccion del nodo consecutivo.

**while (\*lst != NULL)** = El bucle se ejecuta mientras la cabeza de la lista mantenga una direccion de memoria valida.

**temp = (\*lst)->next** = Guardas la direccion del siguiente nodo en la variable temp. Si liberaras el nodo actual antes de esta asignacion, la lectura del campo next accederia a memoria ya desasignada (use-after-free).

**ft_lstdelone(\*lst, del)** = Llamas a la funcion *ft_lstdelone* pasandole el nodo actual para que elimine su contenido y su propia estructura.

**\*lst = temp** = Actualizas el puntero de la cabeza fijandolo al nodo sucesor guardado en temp. Cuando la lista queda vacia, \*lst adopta el valor NULL, cumpliendo la norma del proyecto.

# FT_LSTMAP_BONUS------------------------------------------

![[Pasted image 20261005124007.png]]

![[Pasted image 20261005124022.png]]

Construye una **nueva lista independiente** cuyos nodos albergan el resultado de procesar los datos de la lista de origen mediante la función `f`. Implementa una gestión estricta de memoria: si una reserva de memoria en el _heap_ falla durante la mitad del proceso, la función debe abortar y limpiar todo lo reservado con anterioridad.

**new_list = NULL** = Inicializas la variable que apuntara al primer elemento de la nueva lista como NULL.

**while (lst != NULL)** = Recorres secuencialmente cada uno de los nodos de la lista original.

**new_content = f(lst->content)** = Procesas los datos del nodo original con la funcion f y almacenas en new_content la direccion del nuevo dato transformado.

**new_node = ft_lstnew(new_content)** = Intentas empaquetar ese nuevo contenido dentro de una estructura t_list recien creada.

**if (!new_mode)** = Control de fallos de asignacion en el heap:
	**if (new_content) del(new_content)** = Si los datos transformados fueron creados pero ft_lstnew fallo al reservar el nodo, destruyes los datos con la funcion del.
	**ft_lstclear(&new_list, del)** = Liberas todos los nodos que ya se habian aclopado con exito a new_list en iteraciones previas para evitar fugas de memoria.
	**return (NULL)** = Terminas devolviendo NULL para indicar la falla.

**ft_lstadd_back(&new_list, new_node)** = Si la asignacion fue exitosa, acoplas el nodo al final de la nueva cadena en construccion.

**lst = lst->next** = Avanzas la lectura al siguiente elemento de la lista previa.

**return (new_list)** = Devuelves la direccion del primer nodo de la lista generada.