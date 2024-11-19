NAME 	:= fractol
MLX_NAME := ../mlx_linux/mlx

#Compilador y Flags
CC	:= gcc
CFLAGS	:= -Wall -Werror -Wextra -Ofast -march=native -funroll-loops
HEADERS	:= -I/usr/local/include -I../mlx_linux

#Archivos fuente y directorios
DIR_MANDATORY	:= mandatory
SRC_MAN	:= $(wildcard $(DIR_MANDATORY)/*.c) #Esto recuerdo que luego habrá que incluirlos explicitamente por norma
OBJ_MAN:= ${SRC_MAN:.c=.o}
DIR_BONUS	:= bonus
SRC_BONUS	:= $(wildcard $(DIR_BONUS)/*.c) #Esto recuerdo que luego habrá que incluirlos explicitamente por norma
OBJ_BONUS:= ${SRC_BONUS:.c=.o}

#Librerias 
MLX := -L/usr/local/lib -L../mlx_linux -L./lib/libft
LIBS := $(MLX) -lmlx_Linux -lft -lXext -lX11 -lm -lbsd

#Archivo final
OUTDIR := .
OUT := $(OUTDIR)/$(NAME)

#Reglas de compilación

all: $(OUT)

$(OUT): ../mlx_linux/libmlx_Linux.a lib/libft/libft.a $(OBJ_MAN)
	$(CC) $(CFLAGS) $(HEADERS) -o $@ $(OBJ_MAN) $(LIBS) $(LDFLAGS)

bonus: $(OUTDIR)/.cache_bonus
	@touch $(OUTDIR)/.cache_bonus

$(OUTDIR)/.cache_bonus: ../mlx_linux/libmlx_Linux.a lib/libft/libft.a $(OBJ_BONUS) 
	$(CC) $(CFLAGS) $(HEADERS) -o $(OUT) $(OBJ_BONUS) $(LIBS) $(LDFLAGS)
	
../mlx_linux/libmlx_Linux.a:
	make -C ../mlx_linux

lib/libft/libft.a:
	make -C ./lib/libft

%.o: %.c
	@$(CC) $(CFLAGS) $(HEADERS) -c $< -o $@

# Limpiar los archivos y el ejecutable
clean:
	make -C ./lib/libft clean
	rm -f $(OBJ_MAN) $(OBJ_BONUS)

fclean: clean
	make -C ./lib/libft fclean
	make -C ../mlx_linux clean
	rm -f $(OUT)
	rm -f $(OUTDIR)/.cache_bonus

re: fclean $(OUT)

.PHONY: all bonus clean fclean re
