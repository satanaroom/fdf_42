#include "fdf.h"

static float	ft_mod(float x)
{
	if (x < 0)
		return (-x);
	else
		return (x);
}

static float	ft_make_3d_x(float x, float y, int z)
{
	x = (x - y) * cos(0.523599);
	return (x);
}

static float	ft_make_3d_y(float x, float y, int z)
{
	y = (x + y) * sin(0.523599) - z;
	return (y);
}

static void	ft_join_dots(float x, float y, float x1, float y1, t_data *data)
{
	float	x_step;
	float	y_step;
	float	max;
	float		z;
	float		z1;

	z =  data->matrix[(int)y][(int)x];
	z1 =  data->matrix[(int)y1][(int)x1];
	x *= data->zoom;
	y *= data->zoom;
	x1 *= data->zoom;
	y1 *= data->zoom;
	if (z || z1)
		data->color = 0xe80c0c;
	else
		data->color = 0xffffff;
	// x = ft_make_3d_x(x, y, z);
	// x1 = ft_make_3d_x(x1, y1, z1);
	// y = ft_make_3d_y(x, y, z);
	// y1 = ft_make_3d_y(x1, y1, z1);
	x += 150;
	x1 += 150;
	y += 150;
	y1 += 150;
	x_step = x1 - x;
	y_step = y1 - y;
	if (ft_mod(x_step) > ft_mod(y_step))
		max = x_step;
	else
		max = y_step;
	x_step /= max;
	y_step /= max;
	while ((int)(x - x1) || (int)(y - y1))
	{
		// ft_mlx_pixel_put(data, x, y, data->color);
		x += x_step;
		y += y_step;
	}
}

void	ft_print_map(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < data->height)
	{
		x = 0;
		while (x < data->width)
		{
			if (x < data->width - 1)
				ft_join_dots(x, y, x + 1, y, data);
			if (y < data->height - 1)
				ft_join_dots(x, y, x, y + 1, data);
			x++;
		}
		y++;
	}
}
