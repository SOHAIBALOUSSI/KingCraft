
NAME = so_long
CFLAGS = -Wall -Wextra -Werror
MLX_FLAGS = -Lmlx -lmlx -L/usr/lib/X11 -lXext -lX11

$(NAME): $(OBJ)
	$(CC) $(OBJ) -Lmlx -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)


%.o: %.c
	$(CC) -Wall -Wextra -Werror -I/usr/include -Imlx_linux -O3 -c $< -o $@


all : $(NAME)