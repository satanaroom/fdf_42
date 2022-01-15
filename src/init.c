#include "../fdf.h"

void	ft_validate_dot(char *dot_line)
{
	if (ft_isalpha(*dot_line))
		ft_error("invalid map's value");
}

void	ft_init_image(t_data *data)
{
	if (data->img.img)
		mlx_destroy_image(data->mlx, data->img.img);
	data->img.img = mlx_new_image(data->mlx, W_WIDTH, W_HEIGHT);
	data->img.addr = mlx_get_data_addr(data->img.img, &data->img.bits_per_pixel,
			&data->img.line_length, &data->img.endian);
}

void	ft_init_map(t_data *data)
{
	data->shift_x = 550;
	data->shift_y = 300;
	data->isometric = 1;
	data->color = 0xffffff;
	data->angle = 0.523599;
	data->angle_x = 0;
	data->angle_y = 0;
	data->angle_z = 0;
	if (data->width > 1000)
		data->zoom = 1;
	else if (data->width > 100)
		data->zoom = 5;
	else
		data->zoom = 30;
}



void	ft_init_dot(t_data *data)
{
	data->z = data->matrix[(int)data->y][(int)data->x];
	data->z1 = data->matrix[(int)data->y1][(int)data->x1];
	data->x *= data->zoom;
	data->y *= data->zoom;
	data->x1 *= data->zoom;
	data->y1 *= data->zoom;
	if (data->z || data->z1)
		data->color = 0xe80c0c;
	if (data->isometric)
		ft_isometric(data);
	data->x += data->shift_x;
	data->x1 += data->shift_x;
	data->y += data->shift_y;
	data->y1 += data->shift_y;
	ft_rotate_map(data);
}
