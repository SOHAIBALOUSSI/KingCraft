#include "../so_long.h"
#include "../../libs/libft/libft.h"

int init_mlx(t_map *mlx)
{

    mlx->ptr = mlx_init();
    if (!mlx->ptr)
        return 1;
    mlx->win = mlx_new_window(mlx->ptr,
            mlx->width, mlx->height, "batman");
    if (!mlx->win)
        return (free(mlx->ptr), 1);
}