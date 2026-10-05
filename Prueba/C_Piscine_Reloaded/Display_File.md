![[Pasted image 20260923121627.png]]

![[Pasted image 20260923121916.png]]

![[Pasted image 20260923123950.png]]

![[Pasted image 20260923124433.png]]

**Void ft_putstr(char \*str)** = Es basicamente para que escriba la frase sin ningun problema.

Para aprender a usar open, read y close.



Prototipo de open -- **int open(char \*path, int flags)** 

  **path** = Aqui se pone el nombre o la variable que guarda el nombre de ese archivo para que lo abra.

  **O_RDONLY** = Modo solo de lectura.

  **O_WRONLY** = Modo solo escritura.

  **O_RDWR** = Modo lectura y escritura.

Si tiene exito en reunir los requisitos, open devuelve un numero entero no negativo que representa el descriptor de texto **(ft >= 0)**.

Si no tiene exito devuelve un **-1**.

Este resultado se guarda en un entero **fd**, asi que si en este caso si falla escribira "Cannot read file".



Prototipo de read -- **ssize_t read(int fd, void \*buf, size_t count)**

  **fd** = Es el descriptor de texto que devolvio open.

  **\*buf** = Es el puntero a la zona de memoria donde se van a guardar los datos leidos.

  **size_t count** = Aqui se pone la cantidad maxima de bytes que se desea leer en ese momento.

En este caso devolvera un numero, si este es **positivo** indica la cantidad de bytes que realmente se han podido leer en esa llamada. Si es **0** indica que se ha alcanzado el final de ese archivo. y por ultimo si es **-1** indica que ocurrio un error al intentar leer el archivo.


Prototipo de close -- **int close(int fd)**

  **fd** = En este caso es el descriptor de texto que se quiera cerrar.

   Este devolvera un numero, **0** si el archivo se cerro correctamente y **-1** si ocurrio un error en el proceso.



**fd** es un entero porque como sabemos el **0** es la entrada estandar, **1** es la salida estandar y el **2** es la error estandar
