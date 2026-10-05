![[Pasted image 20260922142540.png]]

DESCRIPTION
       The  strdup() function returns a pointer to a new string which is a du‐
       plicate of the string s.  Memory for the new string  is  obtained  with
       malloc(3), and can be freed with free(3).

       The strndup() function is similar, but copies at most n bytes.  If s is
       longer than n, only n bytes are copied, and  a  terminating  null  byte
       ('\0') is added.

       strdupa() and strndupa() are similar, but use alloca(3) to allocate the
       buffer.  They are available only when using the GNU GCC suite, and suf‐
       fer from the same limitations described in alloca(3).

RETURN VALUE
       On  success,  the strdup() function returns a pointer to the duplicated
       string.  It returns NULL if insufficient memory was available, with er‐
       rno set to indicate the cause of the error.


Basicamente en español:

La función **`strdup()`** devuelve un puntero a una nueva cadena de texto que es un duplicado de la cadena **`s`**. La memoria para esta nueva cadena se obtiene utilizando **`malloc(3)`**, y se puede liberar con **`free(3)`**.

Para malloc:

Libreria = **#include <stdlib.h>**

![[Pasted image 20260922163726.png]]

**dup = (char \*\)malloc(sizeof(char) \*\(len + 1));** = Aqui lo que se hace es calcular la cantidad de bytes que le va a pedir para el duplicado.

**if (!dup)** = Aqui se asegura de que si malloc falla termine el programa.

[[Ft_Range.c]]

