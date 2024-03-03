#include "../so_long.h"


int    validate_map(char *map_path, t_map *map)
{
    int fd;
    char *curr_line;
    char *lines;
    char **all_lines;

    lines = NULL;
    fd = open(map_path, O_RDONLY);
    if (fd < 0)
        error("Failed to open, Try an existing file");
    if (extension_check(map_path) == 0)
        error("Failed to open , Not a '.ber' file");
    lines = read_map(map_path, fd);
    all_lines = ft_split(lines, '\n');
    map->map_lines = all_lines;
    is_rectangle(all_lines);
    component_check(all_lines, map);
    wall_check(all_lines);
    free(all_lines);
}

// int main()
// {
// 	// t_map test;
// 	// test.c_count = 0;
// 	// test.e_count = 0;
// 	// test.p_count = 0;

// 	// char **map;
// 	// map = ft_split("11111\n11C111\n1P111\n11111\n11E11", '\n');
//     // validate_map("map.ber", &test);
//     get_file("map.ber");
	
// }
