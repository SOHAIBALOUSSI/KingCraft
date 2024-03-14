# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sait-alo <sait-alo@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/07 21:22:51 by sait-alo          #+#    #+#              #
#    Updated: 2024/03/07 21:22:54 by sait-alo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = so_long
#CFLAGS = -Wall -Wextra -Werror
BNAME = so_long_bonus
# LIBS PATH
MLX_PATH = ./libs/mlx_linux/

MLX_FLAGS = -Lmlx -lmlx -L/usr/lib/X11 -lXext -lX11
INCLUDES = -I/usr/include -Imlx
LIB_MLX = ./mlx/libmlx.a

SO = .source/map_validity/
LIBFT_SRC = $(addprefix ./libs/libft/, ft_atoi.c ft_lstadd_back_bonus.c ft_memchr.c ft_putendl_fd.c ft_striteri.c ft_strtrim.c \
ft_bzero.c ft_lstadd_front_bonus.c ft_memcmp.c ft_puthex.c ft_strjoin.c ft_substr.c \
ft_calloc.c ft_lstclear_bonus.c ft_memcpy.c ft_putnbr.c ft_strlcat.c ft_tolower.c \
ft_isalnum.c ft_lstdelone_bonus.c ft_memmove.c ft_putnbr_fd.c ft_strlcpy.c ft_toupper.c \
ft_isalpha.c ft_lstiter_bonus.c ft_memset.c ft_putstr.c ft_strlen.c get_next_line.c \
ft_isascii.c ft_lstlast_bonus.c ft_printf.c ft_putstr_fd.c ft_strmapi.c ft_isdigit.c \
ft_lstmap_bonus.c ft_putadress.c ft_split.c ft_strncmp.c ft_isprint.c ft_lstnew_bonus.c \
ft_putchar.c ft_strchr.c ft_strnstr.c ft_itoa.c ft_lstsize_bonus.c ft_putchar_fd.c \
ft_strdup.c ft_strrchr.c ft_base16.c get_next_line_utils.c)

## SO_LONG SRC HERE ..

SRCS =  ./source/main.c $(LIBFT_SRC) $(addprefix ./source/map_validity/, check_fonctions.c errors.c validate_map.c check_valid_path.c errors_helper.c)\
		$(addprefix ./source/initialisation/, init_mlx.c init_xpm.c init_map.c) \
		$(addprefix ./source/game_hooks/, capture_hook.c move_player.c)
OBJS = $(SRCS:.c=.o)

BSRCS = ./bonus_src/main.c $(LIBFT_SRC) $(addprefix ./bonus_src/map_validity/, check_fonctions.c errors.c validate_map.c check_valid_path.c errors_helper.c)\
		$(addprefix ./bonus_src/initialisation/, init_mlx.c init_xpm.c init_map.c) \
		$(addprefix ./bonus_src/game_hooks/, capture_hook.c move_player.c)
BOBJS = $(BSRCS:.c=.o)

all :$(MLX) $(NAME) 

bonus : $(MLX) $(BNAME)

$(MLX):
	@make -C $(MLX_PATH)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@ $(MLX_FLAGS)

$(BNAME) : $(BOBJS)
	$(CC) $(CFLAGS) $^ -o $@ $(MLX_FLAGS)
	
clean:
	@rm -f $(OBJS) $(BOBJS)

fclean: clean
	@rm -f $(NAME) $(BNAME)

re : fclean all
