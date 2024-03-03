
#include "../so_long.h"
#include "../../Libs/libft/libft.h"

void    get_file(char *file)
{
    int fd = open(file, O_RDONLY | O_WRONLY);
    char *curr_line;
    char *lines;

    lines = NULL;
    while (1)
    {
        ft_printf("%d\n", fd); 
        curr_line = get_next_line(fd);
        ft_printf("curr_line: %s", curr_line); // Print curr_line
        if (!curr_line)
            break ;
        lines = ft_strjoin(lines, curr_line);
        free(curr_line);
    }
    // ft_printf("%s\n", lines);
}

int main()
{
    get_file("errors.c");	
}