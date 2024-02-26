
NAME = so_long
#CFLAGS = -Wall -Wextra -Werror

# LIBS PATH
LIBFT_PATH = ./Libs/libft/
MLX_PATH = ./Libs/mlx_linux/

MLX_FLAGS = -Lmlx -lmlx -L/usr/lib/X11 -lXext -lX11
INCLUDES = -I/usr/include -Imlx
LIB_MLX = ./mlx/libmlx.a

LIBFT_SRC = $(addprefix $(LIBFT_PATH), ft_atoi.c ft_lstadd_back_bonus.c ft_memchr.c ft_putendl_fd.c ft_striteri.c ft_strtrim.c \
ft_bzero.c ft_lstadd_front_bonus.c ft_memcmp.c ft_puthex.c ft_strjoin.c ft_substr.c \
ft_calloc.c ft_lstclear_bonus.c ft_memcpy.c ft_putnbr.c ft_strlcat.c ft_tolower.c \
ft_isalnum.c ft_lstdelone_bonus.c ft_memmove.c ft_putnbr_fd.c ft_strlcpy.c ft_toupper.c \
ft_isalpha.c ft_lstiter_bonus.c ft_memset.c ft_putstr.c ft_strlen.c get_next_line.c \
ft_isascii.c ft_lstlast_bonus.c ft_printf.c ft_putstr_fd.c ft_strmapi.c ft_isdigit.c \
ft_lstmap_bonus.c ft_putadress.c ft_split.c ft_strncmp.c ft_isprint.c ft_lstnew_bonus.c \
ft_putchar.c ft_strchr.c ft_strnstr.c ft_itoa.c ft_lstsize_bonus.c ft_putchar_fd.c \
ft_strdup.c ft_strrchr.c ft_base16.c)

SRCS = main.c $(LIBFT_SRC)

## SO_LONG SRC HERE ..

OBJS = $(SRCS:.c=.o)

$(MLX):
	@make -C $(MLX_PATH)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(MLX_FLAGS)


all :$(MLX) $(NAME) 

.c.o :
	$(CC) $(CFLAGS) -c -o $@ $< $(INCLUDES)

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re : fclean all
