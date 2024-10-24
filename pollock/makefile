NAME 	:= pollock

#Compilador y Flags
CC	:= gcc
CFLAGS	:= -Wall -Werror -Wextra -O3 -fPIE 
LDFLAGS := -pie
HEADERS	:= -I/usr/local/include -I../mlx_linux

#Archivos fuente y directorios
SRCDIR	:= src
SRC	:= $(wildcard $(SRCDIR)/*.c)
OBJ	:= ${SRC:.c=.o}

#Librerias necesarias para la minilib y otras 
MLX := -L/usr/local/lib -L../mlx_linux -lmlx_Linux
LIBS := $(MLX) -lXext -lX11 -lm -lbsd

#Archivo final
OUTDIR := .
OUT := $(OUTDIR)/$(NAME)

#Reglas de compilación

all: $(OUT)

$(OUT): $(OBJ)
	$(CC) $(CFLAGS) $(HEADERS) -o $@ $^ $(LIBS) $(LDFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) $(HEADERS) -c $< -o $@

# Limpiar los archivos y el ejecutable
clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(OUT)

re: fclean all

.PHONY: all clean fclean re
