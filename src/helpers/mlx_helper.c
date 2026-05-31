
# include "cub3d.h"

void clear_mlx_buff(t_mlx *mlx)
{
	ft_memset(mlx->addr, 0, WINDOW_H * mlx->line_len);
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

	if (x < 0 || x >= WINDOW_W || y < 0 || y >= WINDOW_H) // could use in_bounds but would need to pass t_map
		return ;
	destination = mlx->addr + (y * mlx->line_len + x * (mlx->bits_p_pixel / 8)); // store bytes_p_pixel to save one operation/cycle
	*(unsigned int *)destination = colour;
}
