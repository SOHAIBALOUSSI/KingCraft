
#include "source/so_long.h"

int main(int ac, char **av)
{
	if (ac == 1)
		error("Use : ./so_long <path_to_map>.ber");
	if (ac > 2)
		error("Too much arguments\nUse : ./so_long <path_to_map>.ber");
	if (ac == 2)
	{
		t_map map;
		init_structs(&map);
		map.ptr = mlx_init();
		mlx_get_screen_size(map.ptr , &map.display_width ,&map.display_height);

		validate_map(av[1], &map);
		printf("%d - %d\n", map.width, map.height);
		map.win = mlx_new_window(map.ptr,map.width * 64, map.height * 64, "batman");
		mlx_loop(map.ptr);

	}


}


