
// #include "./mlx/mlx.h"
#include "./Libs/libft/libft.h"

// int main(int ac, char **av)
// {
// 	if (ac == 2)
// 	{
// 		ft_putchar('1');
// 	}
// 	else if (ac != 2)
// 		ft_printf("%sThe program need only 1 arg\n\n./so_long <path/to/map/>.ber", "\033[0;31m");
// }


#include "source/so_long.h"

int main(int ac, char **av)
{
	if (ac == 2)
	{
		t_map map;
		map.c_count = 0;
		map.e_count = 0;
		map.p_count = 0;
		validate_map(av[1], &map);
	}

}


