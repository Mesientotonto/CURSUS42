## INDICE
* [[#FT_STRCHR--------------------------------------------------------]]
* [[#FT_MEMSET--------------------------------------------------------]]
* [[#FT_MEMMOVE-----------------------------------------------------]]
* [[#FT_CALLOC---------------------------------------------------------]]
* [[#FT_STRDUP---------------------------------------------------------]]
* [[#FT_STRITERI---------------------------------------------------]]
* [[#FT_STRJOIN---------------------------------------------------]]
* [[#FT_STRLCAT---------------------------------------------------]]
* [[#FT_STRNSTR---------------------------------------------------]]
* [[#FT_STRTRIM---------------------------------------------------]]
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


# FT_STRITERI---------------------------------------------------

![[Pasted image 20260928095959.png]]

![[Pasted image 20260928100511.png]]


# FT_STRJOIN---------------------------------------------------

![[Pasted image 20261006102705.png]]

![[Pasted image 20261006102633.png]]

El uso conjunto de `ft_strlcpy` y `ft_strlcat` en `ft_strjoin` responde a un criterio estrictamente técnico de **seguridad, robustez y reutilización de código**:

1. **Reutilización de funciones propias:** Al haber programado previamente `ft_strlcpy` y `ft_strlcat` en las partes obligatorias de la librería, estás utilizando herramientas fiables y ya testeadas para manipular cadenas, evitando reinventar la rueda o duplicar bucles de copia manual dentro de esta función.
    
2. **Control de límites y desbordamientos:** A diferencia de las funciones clásicas de la `libc` (`strcpy` o `strcat`), las versiones seguras con control de tamaño (_BSD style_) reciben por parámetro el tamaño total del búfer. Esto garantiza que nunca se escribirá más allá de la memoria reservada con `malloc`, previniendo de forma nativa los desbordamientos de búfer (_buffer overflows_).
    
3. **Garantía absoluta del byte nulo (`\0`):** Tanto `ft_strlcpy` como `ft_strlcat` aseguran de manera estricta que la cadena resultante termine correctamente con un carácter nulo, minimizando el riesgo de errores lógicos o fallos de lectura al procesar el texto resultante.

# FT_STRLCAT---------------------------------------------------

![[Pasted image 20261006103525.png]]

Vamos a desarmar **`ft_strlcat`** línea a línea a partir de la captura que has subido. El objetivo de esta función no es solo "pegar dos textos", sino hacerlo de forma **100% segura contra desbordamientos de búfer (_buffer overflow_)** y devolviendo un valor matemático preciso que le permite al programador saber si la cadena se tuvo que cortar (truncar) o si cupo entera.

### 1. La firma y el contrato de la función

C

```
size_t  ft_strlcat(char *dst, const char *src, size_t size)
```

- **`char *dst`:** Búfer de destino. Es donde ya hay una cadena guardada y donde vamos a enganchar `src` al final.
    
- **`const char *src`:** Cadena de origen. Llleva `const` porque solo vamos a leer sus caracteres para copiarlos, jamás a modificarlos.
    
- **`size_t size`:** Es el **tamaño total en bytes** que se reservó en memoria para `dst` (no la longitud del texto que contiene ahora, sino el tamaño del espacio en el _heap_ o en el _stack_).
    
- **Retorno `size_t`:** Según la norma de BSD, `strlcat` **siempre devuelve la longitud total que intentó crear**, es decir: `longitud_inicial_de_dst + longitud_de_src`. Si el número que devuelve es mayor o igual a `size`, el programador sabe que el texto no cupo entero y se truncó.
    

### 2. Declaración de variables

C

```
    size_t  dst_len;
    size_t  src_len;
    size_t  i;
```

- **`dst_len` y `src_len`:** Guardarán las longitudes reales de `dst` y `src` medidas con `ft_strlen`.
    
- **`i`:** Contador del bucle de copia que representa cuántos caracteres de `src` llevamos pegados.
    
- Usamos `size_t` en las tres porque van a operarse e igualarse directamente con `size`.
    

### 3. Medición inicial y protección de puntero nulo

C

```
    src_len = ft_strlen(src);
    if (!dst && size == 0)
        return (src_len);
```

- **`src_len = ft_strlen(src);`:** Calculamos de entrada cuánto mide la cadena de origen.
    
- **`if (!dst && size == 0)`:** Es una protección para un caso de borde específico que prueban los testers automáticos (como Francinette): si nos pasan un puntero `dst` que es `NULL` pero nos indican que el tamaño del búfer es `0`, no debemos intentar leer `dst` (causaría un _segmentation fault_ al medir su longitud). La especificación dicta que en ese caso extremo se devuelve la longitud de `src`.
    

### 4. Medición de `dst` y la barrera de seguridad

C

```
    dst_len = ft_strlen(dst);
    if (size <= dst_len)
        return (size + src_len);
```

- **`dst_len = ft_strlen(dst);`:** Obtenemos dónde termina la cadena actual en `dst`.
    
- **`if (size <= dst_len)`:** Esta es una comprobación crítica. Si el tamaño total que nos dicen que tiene el búfer (`size`) es menor o igual que los caracteres que ya hay dentro de `dst`, significa que **no hay espacio para concatenar nada** (o que el `size` proporcionado es incorrecto y no cubre ni la cadena inicial).
    
- **`return (size + src_len);`:** Cuando `size <= dst_len`, la especificación de `strlcat` exige no escribir nada en memoria y devolver exactamente `size + src_len`.
    

### 5. El bucle de copia y la condición `size - 1`

C

```
    i = 0;
    while (src[i] != '\0' && (dst_len + i) < (size - 1))
    {
        dst[dst_len + i] = src[i];
        i++;
    }
```

- **`i = 0;`:** Empezamos a leer `src` desde su posición 0.
    
- **`dst_len + i`:** Es la posición física en el array `dst` donde vamos a escribir. Como `dst` ya tiene `dst_len` caracteres, la primera escritura (`i = 0`) cae exactamente en `dst[dst_len]`, pisando el antiguo `\0` de `dst` para continuar la cadena.
    
- **`(dst_len + i) < (size - 1)` (EL PORQUÉ DEL `- 1`):**
    
    - Queremos copiar el máximo número de caracteres posibles sin desbordar `dst`.
        
    - Si el búfer mide `size`, las posiciones válidas van de `0` a `size - 1`.
        
    - La **última posición del búfer (`dst[size - 1]`) está estrictamente reservada para el byte nulo `\0`**.
        
    - Por eso, para escribir caracteres reales de texto, la posición `dst_len + i` tiene que ser estrictamente menor que `size - 1`. En cuanto la siguiente posición a escribir sea `size - 1`, el bucle se detiene para no invadir la casilla del `\0` final.
        

### 6. Cierre con byte nulo y valor de retorno

C

```
    dst[dst_len + i] = '\0';
    return (dst_len + src_len);
```

- **`dst[dst_len + i] = '\0';`:** Cuando el bucle termina (ya sea porque se acabaron los caracteres de `src` o porque alcanzamos el límite de espacio), colocamos obligatoriamente el carácter nulo en el índice `dst_len + i`. Como el bucle se detuvo como máximo en `dst_len + i == size - 1`, este `\0` quedará escrito dentro del límite del búfer.
    
- **`return (dst_len + src_len);`:** Se devuelve la suma de las dos longitudes originales.
    

### Mapeo mental para programarlo sin ayuda

1. **Obtén las longitudes:** Mide `src` y `dst`.
    
2. **Protege los bordes:** Si `size <= dst_len`, no toques la memoria y devuelve `size + src_len`.
    
3. **Copia con margen para el `\0`:** Escribe `src[i]` en `dst[dst_len + i]` mientras `(dst_len + i) < size - 1`.
    
4. **Cierra siempre la cadena:** Pon el `\0` al final de lo copiado y devuelve `dst_len + src_len`.
# FT_STRNSTR---------------------------------------------------

![[Pasted image 20261006110458.png]]

Entendido. Vamos a destripar **`ft_strnstr`** exactamente con el código de tu captura, analizando la mecánica interna de memoria, la lógica de los índices y por qué cada instrucción está escrita de esa forma específica.

### 1. El objetivo técnico y la firma de la función

```
char    *ft_strnstr(const char *big, const char *little, size_t len)
```

- **`char *` (tipo de retorno):** La función no devuelve un entero ni un booleano; debe devolver un **puntero** que apunta a la dirección exacta dentro de `big` donde comienza la primera coincidencia de `little`. Si no la encuentra, devuelve `NULL`.
    
- **`const char *big` y `const char *little`:** Usamos `const` porque la función solo va a **leer** estas cadenas, nunca a modificarlas.
    
- **`size_t len`:** Define la **frontera máxima de bytes** en la memoria de `big` que tenemos permitido inspeccionar.
    

### 2. Declaración de variables e índices

```
    size_t  s1;
    size_t  s2;
```

- **`size_t` en lugar de `int`:** Como el parámetro `len` es de tipo `size_t` (un entero sin signo para representar tamaños en memoria), las variables que comparemos contra `len` deben ser del mismo tipo para evitar _warnings_ de compilación por comparar signed/unsigned.
    
- **Mecánica de los dos índices:**
    
    - **`s1`:** Es el índice del **bucle externo**. Representa el desplazamiento (_offset_) dentro de `big` desde donde vamos a intentar empezar a buscar la coincidencia.
        
    - **`s2`:** Es el índice del **bucle interno**. Representa la posición dentro de `little` que estamos validando carácter a carácter en ese intento.
        

### 3. La condición de borde o caso límite

```
    if (little[0] == '\0')
        return ((char *)big);
```

- **Por qué se comprueba antes de nada:** Según la especificación del estándar `strnstr`, si la aguja que buscamos (`little`) es una cadena vacía (`""`), se considera encontrada desde el byte 0.
    
- **Por qué `(char *)big`:** `big` entró a la función como `const char *`. Sin embargo, el prototipo de retorno pide `char *` (un puntero no constante). Para evitar un aviso de compilación por descartar el cualificador `const`, se hace un _type cast_ explícito `(char *)big`.
    

### 4. El bucle externo: Recorriendo la cadena principal

```
    s1 = 0;
    while (big[s1] != '\0' && s1 < len)
```

- **`s1 = 0;`:** Inicializamos la búsqueda desde el primer carácter de `big`.
    
- **`big[s1] != '\0'`:** Si llegamos al final de la cadena principal sin encontrar la aguja, no tiene sentido seguir buscando.
    
- **`s1 < len`:** Nos asegura que la cabeza de la búsqueda nunca sobrepase el límite máximo `len` establecido.
    

### 5. El bucle interno: Comprobación de coincidencia carácter a carácter

```
        s2 = 0;
        while (big[s1 + s2] == little[s2] && (s1 + s2) < len)
```

Aquí está la clave algorítmica de la función:

1. **`s2 = 0;`:** Cada vez que `s1` avanza un paso en `big`, **reiniciamos `s2` a 0** para empezar a comparar `little` desde su primer carácter.
    
2. **`big[s1 + s2] == little[s2]`:**
    
    - `s1` nos fija el punto de inicio en `big`.
        
    - `s2` nos sirve de desplazamiento en ambas cadenas simultáneamente.
        
    - Por ejemplo: si `s1 = 3`, comparamos `big[3 + 0]` con `little[0]`. Si coinciden, en la siguiente iteración `s2 = 1` y compararemos `big[3 + 1]` con `little[1]`.
        
3. **`(s1 + s2) < len`:** Es la **protección de memoria estricta**. Comprueba que la posición exacta que estamos leyendo en `big` (`s1 + s2`) no supere el límite `len`. Si la coincidencia requiere leer en el byte equivalente a `len` o superior, el bucle se detiene inmediatamente.
    

### 6. La verificación del éxito

```
            if (little[s2 + 1] == '\0')
                return ((char *)&big[s1]);
            s2++;
```

- **Por qué comprobar `little[s2 + 1] == '\0'`:**
    
    - Si el carácter actual `little[s2]` coincide con `big[s1 + s2]`, miramos si el **siguiente** carácter de `little` (`s2 + 1`) es el fin de cadena `\0`.
        
    - Si el siguiente carácter es `\0`, significa que el carácter actual `little[s2]` era el **último** carácter de la aguja. Por lo tanto, ¡hemos encontrado toda la subcadena completa!
        
- **`return ((char *)&big[s1]);`:**
    
    - No devolvemos `&big[s1 + s2]` (que sería donde terminó la cadena), sino **`&big[s1]`**, que es la dirección de memoria exacta **donde empezó** la coincidencia.
        
    - De nuevo, convertimos `&big[s1]` mediante `(char *)` para cumplir con el tipo de retorno sin _warnings_.
        
- **`s2++;`:** Si aún quedan más caracteres por comprobar en `little`, avanzamos `s2` para evaluar el siguiente par en la próxima iteración del bucle interno.
    

### 7. Avance del bucle externo y fallo de la búsqueda

```
        s1++;
    }
    return (NULL);
```

- **`s1++;`:** Si el bucle interno se rompe (ya sea porque no coincidió un carácter o porque se alcanzó el límite `len`), significa que la posición `s1` no era el inicio de la subcadena. Avanzamos `s1` en 1 byte para probar a buscar desde la siguiente letra de `big`.
    
- **`return (NULL);`:** Si el bucle externo termina completamente (porque llegamos al `\0` de `big` o porque `s1` alcanzó el límite `len`) sin haber activado el `return` del bucle interno, la subcadena no existe dentro del rango permitido. Devolvemos `NULL`.
    

### En resumen: Cómo debes visualizarlo mentalmente para programarlo tú solo

1. **Caso nulo inicial:** Si `little` es `""`, devuelves `big`.
    
2. **Puntero móvil `s1`:** Vas probando letra por letra en `big` mientras no se acabe la cadena y estés dentro del rango `s1 < len`.
    
3. **Puntero de rastreo `s2`:** Desde la posición `s1`, vas mirando hacia adelante en `big` y en `little` a la vez (`s1 + s2` vs `s2`) sin pasarte nunca de `len`.
    
4. **Condición de victoria:** En el momento en que confirmes la coincidencia de un carácter y compruebes que el siguiente en `little` es `\0`, devuelves la dirección de inicio `&big[s1]`.

# FT_STRTRIM---------------------------------------------------

![[Pasted image 20261006123146.png]]

Vamos a desglosar **`ft_strtrim`** línea por línea según la imagen que has adjuntado, analizando la estrategia algorítmica, el manejo de memoria y el porqué matemático de los límites.

### 1. La idea matemática detrás del algoritmo

El objetivo de `ft_strtrim` es eliminar los caracteres contenidos en el conjunto `set` que estén al **inicio** y al **final** de la cadena `s1`.

En lugar de crear un búfer temporal e ir copiando y borrando caracteres sobre la marcha, la forma más elegante y eficiente de resolverlo consta de dos fases:

1. **Calcular los dos límites:** Encontrar el índice donde **empieza** el texto útil (`start`) y el índice donde **termina** (`end`).
    
2. **Extraer el bloque útil:** Delegar la reserva de memoria (`malloc`) y la copia del fragmento resultante a la función `ft_substr(s1, start, len)`.
    

### 2. Firma de la función y tipos de datos

C

```
char    *ft_strtrim(char const *s1, char const *set)
```

- **`char *` (retorno):** Debe devolver un puntero a una **nueva cadena reservada en el _heap_** con `malloc`.
    
- **`char const *s1` y `char const *set`:** Ambos punteros son constantes porque la función únicamente lee los caracteres de entrada; no modifica las cadenas originales.
    

### 3. Declaración de límites

C

```
    size_t  start;
    size_t  end;
```

- Usamos `size_t` porque `start` y `end` van a almacenar índices de posición dentro de una cadena y se compararán contra longitudes devueltas por `ft_strlen`. Evitamos mezclar enteros con signo y sin signo.
    

### 4. Recorte frontal: Búsqueda del índice `start`

C

```
    start = 0;
    while (s1[start] != '\0' && ft_strchr(set, s1[start]))
        start++;
```

- **`start = 0;`:** Empezamos inspeccionando desde el primer carácter de `s1`.
    
- **`s1[start] != '\0'`:** Garantiza que no leamos fuera de la memoria si toda la cadena resulta ser de caracteres pertenecientes a `set` (en cuyo caso recorreríamos `s1` de principio a fin).
    
- **`ft_strchr(set, s1[start])`:**
    
    - Reutiliza tu propia función `ft_strchr`. Busca si el carácter actual `s1[start]` está presente en la cadena de basura `set`.
        
    - Si el carácter **sí** está en `set`, `ft_strchr` devuelve un puntero (que evalúa como _verdadero_ en C), por lo que la condición se cumple.
        
- **`start++;`:** Muestra que mientras el carácter sea "basura", el índice de inicio avanza un byte a la derecha. El bucle se detiene en cuanto encontramos el **primer carácter válido** (o llegamos al `\0`).
    

### 5. Recorte trasero: Búsqueda del índice `end`

C

```
    end = ft_strlen(s1);
    while (end > start && ft_strchr(set, s1[end - 1]))
        end--;
```

- **`end = ft_strlen(s1);`:**
    
    - Inicializamos `end` con la **longitud total** de `s1`.
        
    - Es crucial entender que `end` no apunta al último carácter, sino al byte **inmediatamente posterior** (la posición del `\0` final).
        
- **`end > start`:**
    
    - Es la frontera de seguridad crítica. Evita que el índice `end` retroceda por debajo de `start`.
        
    - Si la cadena entera estaba compuesta por caracteres de `set`, el primer bucle avanzó `start` hasta el final. Esta condición impide que `end` siga decrementando y produzca un desbordamiento de memoria (_underflow_) al restarle a un `size_t`.
        
- **`ft_strchr(set, s1[end - 1])`:**
    
    - Inspecciona el carácter que está justo **antes** del límite actual (`s1[end - 1]`).
        
    - Si ese carácter pertenece a `set`, significa que es basura trasera.
        
- **`end--;`:** Si el carácter pertenece a `set`, retrocedemos el límite `end` un byte a la izquierda.
    

### 6. Extracción y reserva de memoria mediante `ft_substr`

C

```
    return (ft_substr(s1, start, end - start));
```

En lugar de hacer un `malloc` manual, comprobar si es nulo y copiar con un bucle, se delega toda esa lógica en **`ft_substr`**:

- **El prototipo de `ft_substr` es:** `char *ft_substr(char const *s, unsigned int start, size_t len)`
    
- **`s1`:** Le pasamos la cadena original.
    
- **`start`:** Le indicamos el índice desde donde debe empezar a copiar.
    
- **`end - start` (Cálculo de la longitud recortada):**
    
    - La diferencia entre el índice final e inicial representa la **longitud exacta de caracteres útiles** a copiar.
        
    - _Ejemplo práctico:_ Si `s1 = "xxHolaxx"`, `start` acaba valiendo `2` (la `'H'`) y `end` vale `6` (la posición tras la `'a'`). La longitud a extraer es `end - start = 6 - 2 = 4` bytes (exactamente los que ocupa `"Hola"`).
        
- **Manejo automático del `NULL`:** Si la asignación con `malloc` dentro de `ft_substr` falla, `ft_substr` devolverá `NULL`, cumpliendo automáticamente con el contrato de error de `ft_strtrim`.
    

### Resumen para construirlo por tu cuenta

1. **Localiza el inicio (`start`):** Haz avanzar un índice desde `0` mientras el carácter actual pertenezca a `set`.
    
2. **Localiza el final (`end`):** Inicia en la longitud total (`strlen`) y retrocede mientras `end > start` y el carácter en `end - 1` pertenezca a `set`.
    
3. **Corta la subcadena:** Devuelve directamente el resultado de `ft_substr(s1, start, end - start)`.

# FT_SUBSTR----------------------------------------------------

![[Pasted image 20261006124541.png]]

Vamos a desglosar **`ft_substr`** línea por línea según el código exacto de tu captura, analizando la gestión de memoria en el _heap_, la prevención de desbordamientos y el cálculo exacto de tamaños.

### 1. El objetivo algorítmico y la firma

C

```
char    *ft_substr(char const *s, unsigned int start, size_t len)
```

- **`char *` (retorno):** La función crea una nueva cadena independiente en la memoria dinámica (_heap_), por lo que debe devolver un puntero que apunte al primer byte de esa memoria.
    
- **`char const *s`:** Cadena de origen de donde vamos a recortar. Es `const` porque no la vamos a modificar, solo a leer.
    
- **`unsigned int start`:** El índice o posición dentro de `s` a partir del cual empieza la subcadena que queremos extraer.
    
- **`size_t len`:** La cantidad máxima de caracteres que nos piden copiar a partir de `start`.
    

### 2. Declaración de variables

C

```
    char    *substr;
    size_t  s_len;
    size_t  i;
```

- **`substr`:** El puntero donde guardaremos la dirección de memoria que nos devuelva `malloc`.
    
- **`s_len`:** Guardará la longitud total de la cadena original `s` mediante `ft_strlen`.
    
- **`i`:** Índice de control para copiar los caracteres uno a uno dentro del bucle. Usamos `size_t` en `i` y `s_len` para que coincidan con el tipo de `len` al hacer comparaciones matemáticas.
    

### 3. Protección contra puntero nulo inicial

C

```
    if (!s)
        return (NULL);
```

- **Por qué se hace:** Si nos pasan `s = NULL`, intentar calcular su longitud con `ft_strlen(s)` causaría un _segmentation fault_ inmediato al intentar desreferenciar un puntero nulo. Se comprueba de entrada para abortar de manera segura devolviendo `NULL`.
    

### 4. Caso de borde: El índice `start` está fuera de rango

C

```
    s_len = ft_strlen(s);
    if (start >= s_len)
        return (ft_strdup(""));
```

- **`s_len = ft_strlen(s);`:** Obtenemos la longitud de la cadena principal.
    
- **`if (start >= s_len)`:** Si nos piden empezar a cortar en una posición `start` que es mayor o igual a la longitud total de la cadena (por ejemplo, en la posición 10 de un texto que solo mide 5 letras), no hay texto que extraer.
    
- **`return (ft_strdup(""));`:** Según el sujeto de 42, no debemos devolver `NULL` en este caso, sino una **cadena vacía válida y asignada en memoria dinámica**. Usar `ft_strdup("")` ejecuta un `malloc(1)` interno que guarda un único byte `'\0'` y devuelve su puntero, permitiendo que la función receptora pueda hacer `free()` de forma segura.
    

### 5. Ajuste del tamaño `len` (Evitar _over-allocation_ / desbordamiento)

C

```
    if (len > s_len - start)
        len = s_len - start;
```

- **Por qué es clave:** Imagina que la cadena `s` mide 10 caracteres (`s_len = 10`), te piden empezar en `start = 7` y te piden un `len = 100`.
    
- A partir del índice 7 solo quedan **3 caracteres reales** (`10 - 7 = 3`).
    
- Si hiciéramos un `malloc` de 100 bytes, estaríamos desperdiciando memoria RAM inútilmente.
    
- Por eso, la resta `s_len - start` calcula **cuántos caracteres quedan verdaderamente disponibles** desde `start` hasta el final de la cadena. Si el `len` pedido supera ese disponible, **recortamos `len`** para que sea exactamente la cantidad real restante (`len = s_len - start`).
    

### 6. Reserva de memoria e inspección de asignación

C

```
    substr = (char *)malloc(sizeof(char) * (len + 1));
    if (!substr)
        return (NULL);
```

- **`sizeof(char) * (len + 1)`:** Reservamos bytes para la cantidad de caracteres a copiar (`len`) más **1 byte imprescindible para el carácter nulo de cierre (`'\0'`)**.
    
- **`if (!substr)`:** Si el sistema operativo se queda sin memoria, `malloc` falla y devuelve `NULL`. Comprobarlo evita escribir en una dirección inválida y previene cierres inesperados (_crashes_).
    

### 7. Bucle de copia de la subcadena

C

```
    i = 0;
    while (i < len && s[start + i] != '\0')
    {
        substr[i] = s[start + i];
        i++;
    }
```

- **`i = 0;`:** Inicializamos la posición de destino en `substr`.
    
- **`i < len`:** Copiamos únicamente hasta alcanzar la cantidad de caracteres calculada en `len`.
    
- **`s[start + i] != '\0'`:** Es una doble protección por si la cadena de origen se acaba antes de lo esperado.
    
- **`s[start + i]`:** Leemos la cadena original aplicando el desplazamiento `start` más el índice actual `i`. Es decir, `substr[0]` recibe `s[start + 0]`, `substr[1]` recibe `s[start + 1]`, y así sucesivamente.
    

### 8. Cierre de cadena y retorno

C

```
    substr[i] = '\0';
    return (substr);
```

- **`substr[i] = '\0';`:** Al terminar la copia, escribimos explícitamente el byte nulo en la posición `i` (que equivale al índice inmediatamente posterior al último carácter copiado). Esto garantiza que `substr` sea una cadena bien terminada según la norma de C.
    
- **`return (substr);`:** Devolvemos la dirección de la memoria asignada.
    

### Esquema para reproducirlo de memoria

1. **Protege entrada:** Comprueba si `s` es `NULL`.
    
2. **Mide la cadena:** Obtén `s_len`.
    
3. **Comprueba el inicio:** Si `start >= s_len`, devuelve `ft_strdup("")`.
    
4. **Ajusta la longitud:** Si `len > s_len - start`, iguala `len = s_len - start`.
    
5. **Reserva memoria:** `malloc(len + 1)` y protege el puntero asignado.
    
6. **Copia:** Copia `s[start + i]` en `substr[i]` mediante un bucle que finalice al cumplir `i < len`.
    
7. **Termina:** Añade `'\0'` al final (`substr[i] = '\0'`) y devuelve `substr`.
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




typedef

structs

