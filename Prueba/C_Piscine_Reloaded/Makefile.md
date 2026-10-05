
![[Pasted image 20260922164545.png]]

Este ejercicio te pide crear un makefile para que compile los archivos **ft_putchar, ft_putstr, ft_strcmp, ft_strlen, ft_swap**.

![[Pasted image 20260923102240.png]]

**NAME = libft.a** = Indica que el nombre del archivo final sera libft.a.

**CC = cc** = Indica que compilador vamos a usar en este caso cc.

**SRCS = srcs/ft_putchar.c \ ...** = Indica que archivos quiere que compile.

**OBJS = $(SRCS:.c=.o)** = Le cambia la extension para que lo lea la maquina.

**INCLUDES = includes** = Le indica que incluya la carpeta includes en este caso no seria necesario.

**all: $(NAME)** = Es la regla por defecto que se ejecuta al escribir simplemente make en la terminal.

**$(NAME): $(OBJS)** = Le indica las dependencias a make. Para poder crear libft.a, primero deben existir todos los archivos objeto .o de la variable OBJS.

**ar rcs $(NAME) $(OBJS)** = Empaqueta los archivos .o para crear la libreria estatica: 
**ar** - Comando de Unix para crear archivos de biblioteca. **r** - Remplaza o añade los archivos .o dentro de la libreria. **c** - Crea la libreria si esta no existe. **s** - Crea un indice interno para que las funciones se encuentren rapido al compilar.

**%.o: %.c** = Le dice a make como convertir cualquier archivo .c en su correspondiente archivo objeto .c.

**$(CC) $(CFLAGS) -I $(INCLUDES) -c $< -o $@** = Llama al compilador para cada archivo fuente usando las variables automaticas.

[[Ft_foreach]]
