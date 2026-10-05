![[Pasted image 20260922142446.png]]

![[Pasted image 20260922162202.png]]

Aqui lo que quieras que haga la funcion es calcular el rango de manera que no haya que modificarla a cada rato.

**Range = (int \*\)malloc(sizeof(int) \*\(max - min));** = Aqui le dices que el rango es el tamaño de un entero (1 byte) por donde quieres que termine menos por donde quieres que empieze asi calculando el tamaño total.

Ya en el bucle le dices que mientras range en la posicion [i] es igual al minimo para que no haya fugas de memoria. En este bucle aparte se hace **min < max** porque el enunciado lo pide **MIN incluido y MAX excluido.**

Al final le retornas el rango.

[[Ft_abs.h]]
