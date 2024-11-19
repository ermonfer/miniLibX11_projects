NAME := libft.a
PROJECTS := subject subject_bonus extra ft_printf ft_gnl
INC_DIR := ./include

CC := cc
CFLAGS := -Werror -Wextra -Wall -I$(INC_DIR)
AR := ar -rcs

SRC_EXTRA := ft_insertionsort.c ft_quicksort.c ft_max_min.c ft_abs.c ft_mod.c ft_atoi_signal.c\
	ft_free_split.c ft_free_return.c ft_atod_signal.c ft_lerp.c
DIR_EXTRA := extra/
SRC_EXTRA := $(addprefix $(DIR_EXTRA), $(SRC_EXTRA))
OBJ_EXTRA := $(SRC_EXTRA:.c=.o)

SRC_LIBFT := ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalnum.c ft_isalpha.c\
	ft_isascii.c ft_isdigit.c ft_isprint.c ft_isspace.c ft_itoa.c ft_memchr.c ft_memcmp.c\
	ft_memcpy.c ft_memmove.c ft_memset.c ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c\
	ft_putstr_fd.c ft_split.c ft_strchr.c ft_strdup.c ft_striteri.c ft_strjoin.c ft_strlcat.c\
	ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_strtrim.c\
	ft_substr.c ft_tolower.c ft_toupper.c
DIR_LIBFT := subject/mandatory/
SRC_LIBFT := $(addprefix $(DIR_LIBFT), $(SRC_LIBFT))
OBJ_LIBFT := $(SRC_LIBFT:.c=.o)

SRC_B_LIBFT := ft_lstadd_back_bonus.c ft_lstadd_front_bonus.c ft_lstclear_bonus.c\
	ft_lstdelone_bonus.c ft_lstiter_bonus.c ft_lstlast_bonus.c ft_lstmap_bonus.c\
	ft_lstnew_bonus.c ft_lstsize_bonus.c
DIR_B_LIBFT := subject/bonus/
SRC_B_LIBFT := $(addprefix $(DIR_B_LIBFT), $(SRC_B_LIBFT))
OBJ_B_LIBFT := $(SRC_B_LIBFT:.c=.o) 

SRC_GNL := ft_get_next_line.c
DIR_GNL := ft_gnl/mandatory/
SRC_GNL := $(addprefix $(DIR_GNL), $(SRC_GNL))
OBJ_GNL := $(SRC_GNL:.c=.o)

SRC_PRINTF := ft_printf.c hex_itoa.c uns_itoa.c
DIR_PRINTF := ft_printf/mandatory/
SRC_PRINTF := $(addprefix $(DIR_PRINTF), $(SRC_PRINTF))
OBJ_PRINTF := $(SRC_PRINTF:.c=.o)

OBJS = $(OBJ_EXTRA) $(OBJ_LIBFT) $(OBJ_B_LIBFT) $(OBJ_GNL) $(OBJ_PRINTF) 

all: $(NAME)

$(NAME): $(OBJS)
	@$(AR) $(NAME) $(OBJS)

subject: $(OBJ_LIBFT)
	@$(AR) $(NAME) $(OBJ_LIBFT)

subject_bonus: $(OBJ_B_LIBFT)
	@$(AR) $(NAME) $(OBJ_B_LIBFT)

extra: $(OBJ_EXTRA)
	@$(AR) $(NAME) $(OBJ_EXTRA)

ft_printf: $(OBJ_PRINTF)
	@$(AR) $(NAME) $(OBJ_PRINTF)

ft_gnl: $(OBJ_GNL)
	@$(AR) $(NAME) $(OBJ_GNL)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all build clean fclean re subject subject_bonus extra ft_printf ft_gnl
