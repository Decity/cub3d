
# include "cub3d.h"

void clear_mlx_buff(t_mlx *mlx)
{
	ft_memset(mlx->screen.addr, 0, WINDOW_H * mlx->screen.line_len);
}

/**
 * @brief Set the pixel (x,y) inside img buffer to desired colour
 * 
 * @param mlx 
 * @param x 
 * @param y 
 * @param colour 
 */
void set_pixel(t_mlx *mlx, int x, int y, int colour)
{
	char	*destination;

	if (x < 0 || x >= WINDOW_W || y < 0 || y >= WINDOW_H)
		return ;
	destination = mlx->screen.addr + (y * mlx->screen.line_len + x * (mlx->screen.byt_pp));
	*(unsigned int *)destination = colour;
}
