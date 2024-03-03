
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


#include "mlx/mlx.h"
#include <stdio.h>
#include <stdlib.h>
#include <X11/X.h>
#include <X11/keysym.h>
 

# include <fcntl.h>



void    get_file(char *file_path)
{
	int		fd;
	char	*curr_line;
	char	*full_lines;
	char	**lines_arr;
	int i = 0;

	full_lines = NULL;
	fd = open(file_path, O_RDONLY);
	curr_line = get_next_line(fd);
	while (curr_line)
	{
		full_lines = ft_strjoin(full_lines, curr_line);
		free(curr_line);
		curr_line = get_next_line(fd);
	}
	// lines_arr = ft_split(full_lines, '\n');
    // while (lines_arr[i])
	// 	printf("%s\n", lines_arr[i++]);
	// printf("%s\n", full_lines);
	
}

int main()
{
    get_file("main.c");	
}


