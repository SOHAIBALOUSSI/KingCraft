#include "../so_long.h"


int    validate_map(char *map_path, t_map *map)
{
    int fd;
    char *lines;
    char **all_lines;
    
    lines = NULL;
    fd = open(map_path, O_RDONLY);
    if (fd < 0)
        error("Failed to open, Try an existing file");
    if (extension_check(map_path) == 0)
        error("Failed to open , Not a '.ber' file");
    lines = read_map(map_path, fd, map);
    all_lines = ft_split(lines, '\n');
    map->map_lines = all_lines;
    is_rectangle(all_lines, map);
    component_check(all_lines, map);
    wall_check(all_lines);
    build_map(map);
    free(all_lines);
    return (0);
}
