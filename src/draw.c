#include "../fdf.h"

static void	ft_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

static void	ft_create_line(t_data data)
{
	float	x_step;
	float	y_step;
	int		max;

	ft_init_dot(&data);
	x_step = data.x1 - data.x;
	y_step = data.y1 - data.y;
	max = ft_max(ft_mod(x_step), ft_mod(y_step));
	x_step /= max;
	y_step /= max;
	while ((int)(data.x - data.x1) || (int)(data.y - data.y1))
	{
		if (data.x >= 0.0 && data.x < W_WIDTH
			&& data.y >= 0.0 && data.y < W_HEIGHT)
			ft_mlx_pixel_put(&data.img, data.x, data.y, data.color);
		data.x += x_step;
		data.y += y_step;
	}
}

void	ft_draw(t_data *data)
{
	ft_init_image(data);
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
				ft_create_line(*data);
			}
			if (data->y < data->height - 1)
			{
				data->x1 = data->x;
				data->y1 = data->y + 1;
				ft_create_line(*data);
			}
			data->x++;
		}
		data->y++;
	}
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img.img, 0, 0);
	ft_customize_window(data);
}
