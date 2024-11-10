NAME 	:= fractol
MLX_NAME := ../mlx_linux/mlx

#Compilador y Flags
CC	:= gcc
CFLAGS	:= -Wall -Werror -Wextra -O3#-fPIE 
LDFLAGS :=#-pie
HEADERS	:= -I/usr/local/include -I../mlx_linux

#Archivos fuente y directorios
SRCDIR	:= src
SRC	:= $(wildcard $(SRCDIR)/*.c) #Esto recuerdo que luego habrá que incluirlos explicitamente por norma
OBJ	:= ${SRC:.c=.o}

#Librerias 
MLX := -L/usr/local/lib -L../mlx_linux -L./lib/libft
LIBS := $(MLX) -lmlx_Linux -lft -lXext -lX11 -lm -lbsd

#Archivo final
OUTDIR := .
OUT := $(OUTDIR)/$(NAME)

#Reglas de compilación

all: $(OUT)

$(OUT): mlx_linux libft $(OBJ)
	$(CC) $(CFLAGS) $(HEADERS) -o $@ $(OBJ) $(LIBS) $(LDFLAGS)

mlx_linux:
	make -C ../mlx_linux

libft:
	make -C ./lib/libft

%.o: %.c
	@$(CC) $(CFLAGS) $(HEADERS) -c $< -o $@

# Limpiar los archivos y el ejecutable
clean:
	make -C ./lib/libft clean
	rm -f $(OBJ)

fclean: clean
	make -C ./lib/libft fclean
	make -C ../mlx_linux clean
	rm -f $(OUT)

re: fclean $(OUT)

.PHONY: all clean fclean re
