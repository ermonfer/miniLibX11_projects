NAME 	:= pollock

#Compilador y Flags
CC	:= gcc
CFLAGS	:= -Wall -Werror -Wextra -O3
HEADERS	:= -I/usr/local/include

#Archivos fuente y directorios
SRCDIR	:= src
SRC	:= $(wildcard $(SRCDIR)/*.c)
OBJ	:= ${SRC:.c=.o}

#Librerias necesarias para la minilib y otras 
MLX := -L/usr/local/lib -lmlx_Linux
LIBS := $(MLX) -lXext -lX11 -lm -lbsd

#Archivo final
OUTDIR := .
OUT := $(OUTDIR)/$(NAME)

#Reglas de compilación

all: $(OUT)

$(OUT): $(OBJ)
	$(CC) $(CFLAGS) $(HEADERS) -o $@ $^ $(LIBS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Limpiar los archivos y el ejecutable
clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(OUT)

re: fclean all

.PHONY: all clean fclean re
