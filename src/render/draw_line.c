
# include "cub3d.h"

void	draw_line(t_data *data, int *line_start, int *line_end, int colour)
{
	int		steps;
	int		i;
	double	dx;
	double	dy;

	steps = abs(line_end[0] - line_start[0]);
	if (abs(line_end[1] - line_start[1]) > steps)
		steps = abs(line_end[1] - line_start[1]);
	if (steps == 0)
		return ;
	dx = (double)(line_end[0] - line_start[0]) / steps;
	dy = (double)(line_end[1] - line_start[1]) / steps;


	i = 0;
	while (i <= steps)
	{
		set_pixel(&data->mlx, 
			line_start[0] + (int)(dx * i),
			line_start[1] + (int)(dy * i),
			colour);
		i++;
	}
}

void	draw_line_ivec(t_data *data, t_ivec2 start, t_ivec2 end, int colour)
{
	int start_arr[2];
	int end_arr[2];

	start_arr[0] = start.x;
	start_arr[1] = start.y;
	end_arr[0] = end.x;
	end_arr[1] = end.y;

	draw_line(data, start_arr,  end_arr, int colour);
} // think about whether to pass t_vec2 or directly typed t_ivec2

void	draw_v_line(t_mlx *mlx, t_ivec2 p, int len, int colour)
{
	int	i;
	int step;

	i = 0;
	step = 1;
	if (len < 0)
		step = -1;
	while (i != len + step)
	{
		set_pixel(mlx, p.x, p.y + i, colour);
		i += step;
	}
}

void	draw_h_line(t_mlx *mlx, t_ivec2 p, int len, int colour)
{
	int	i;
	int step;

	i = 0;
	step = 1;
	if (len < 0)
		step = -1;
	while (i != len + step)
	{
		set_pixel(mlx, p.x + i, p.y, colour);
		i += step;
	}
} // a bit redundant, but would probably need an extra arg spot to pass h/v direction -> would require additional line struct?
