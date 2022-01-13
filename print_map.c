#include "fdf.h"

static float	ft_max(float a, float b)
{
	if (a > b)
		return (a);
	return (b);
}

static float	ft_mod(float x)
{
	if (x < 0)
		return (-x);
	return (x);
}

static void	ft_isometric(float *x, float *y, int z)
{
	*x = (*x - *y) * cos(0.8);
	*y = (*x + *y) * sin(0.8) - z;
}

static void ft_make_3d(t_data *data)
{
	ft_isometric(&data->x, &data->y, data->z);
	ft_isometric(&data->x1, &data->y1, data->z1);
}

static void	ft_init_dot(t_data *data)
{
	data->z =  data->matrix[(int)data->y][(int)data->x];
	data->z1 =  data->matrix[(int)data->y1][(int)data->x1];
	data->x *= data->zoom;
	data->y *= data->zoom;
	data->x1 *= data->zoom;
	data->y1 *= data->zoom;
	if (data->z || data->z1)
		data->color = 0xe80c0c;
	else
		data->color = 0xffffff;
	ft_make_3d(data);
	data->x += 150;
	data->x1 += 150;
	data->y += 150;
	data->y1 += 150;
}

static void	ft_join_dots(t_data data)
{
	float	x_step;
	float	y_step;
	int		max;

	data.zoom = 30;
	ft_init_dot(&data);
	x_step = data.x1 - data.x;
	y_step = data.y1 - data.y;
	max = ft_max(ft_mod(x_step), ft_mod(y_step));
	x_step /= max;
	y_step /= max;
	while ((int)(data.x - data.x1) || (int)(data.y - data.y1))
	{
		if (data.x < 1500.0 && data.x >= 0.0
			&& data.y < 1500.0 && data.y >= 0.0)
		ft_mlx_pixel_put(&data.img, data.x, data.y, data.color);
		data.x += x_step;
		data.y += y_step;
	}
}

void	ft_print_map(t_data *data)
{
	data->y = 0;
	while (data->y < data->height)
	{
		data->x = 0;
		while (data->x < data->width)
		{
			if (data->x < data->width - 1)
			{
				data->x1 = data->x + 1;
				data->y1 = data->y;
				ft_join_dots(*data);
			}
			if (data->y < data->height - 1)
			{
				data->x1 = data->x;
				data->y1 = data->y + 1;
				ft_join_dots(*data);
			}
			data->x++;
		}
		data->y++;
	}
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img.img, 0, 0);
}
