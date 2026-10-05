![[Pasted image 20260922143939.png]]

Me pide hacer un archivo .h que ponga un numero en su valor absoluto.

Como lo hago?

**#define ABS(Value)**

Esto que significa?

Me pide un archivo Header (.h) y no un un archivo de codigo (.c).

![[Pasted image 20260922153004.png]]

**#ifndef FT_ABS_H** = Dice si no esta definido quiero que hagas lo de la siguiente linea.

**#define FT_ABS_H** = Aqui dice que defina FT_ABS_H.

**#define ABS(Value)** = Le dice que cada vez que vea ABS en el codigo replace ese texto con la intruccion que viene a continuacion.

**(Value < 0) ?** = Evalua si Value es un numero negativo.

**(-Value) : (Value)** =Esto es un operador ternario (condicion ? si_verdadero : si_falso), si es negativo le cambio el signo y si es positivo devueve value tal cual.

**#endif** = Cierra la condicion abierta en la linea 1.


Para combrobar que es correcto --> 

![[Pasted image 20260922153850.png]]

[[Ft_Point.h]]
