![[Pasted image 20260922154930.png]]

**#include "ft_point.h"** = Este archivo debe definir la estructura y el tipo de dato t_point.

**Void set_point(t_point point)** = Define una funcion que recibe un puntero a un tipo de dato llamado t_point.

**Point ->x = 42; y Point ->y = 21;** = Accede a los campos x e y de la estructuraa traves del puntero **point** utiizando el operador **->.**

**t_point point**= Declara una variable **point** directamente con el tipo **t_point**.

**set_point(&point)** = Le pasa a la funcion la direccion de memoria de point para modificar sus miembros x e y directamente en la pila.

![[Pasted image 20260922161110.png]]

**#ifndef FT_POINT_H** = Si no esta definida continua.

**#define FT_POINT_H** = La define

**Typedef struct s_point** = Define una estructura llamada s_point y la combina con la palabra clave typedef, esta le dice que vas a agrupar un conjunto de variables en un solo tipo de dato compuesto.

**T_point** = Aqui se le asigna el alias definitivo t_point.

**#endif** = Cierra la condicion abierta en la linea 1.

[[Makefile]]
