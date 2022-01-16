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
	data->shift_y = 150;
	data->isometric = 1;
	data->color = 0xffffff;
	data->angle = 1;
	data->angle_x = 0;
	data->angle_y = 0;
	data->angle_z = 0;
	if (data->width > 400)
		data->zoom = 1.5;
	else if (data->width > 100)
		data->zoom = 5;
	else
		data->zoom = 30;
}

static void	ft_set_color(t_data *data)
{
	if (data->z > 100 || data->z1 > 100)
		data->color = 0x87CEEB;
	else if (data->z > 80 || data->z1 > 80)
		data->color = 0xFF6347;
	else if (data->z > 60 || data->z1 > 60)
		data->color = 0xFFA07A;
	else if (data->z > 40 || data->z1 > 40)
		data->color = 0x90EE90;
	else if (data->z > 20 || data->z1 > 20)
		data->color = 0x7FFF00;
	else if (data->z > 0 || data->z1 > 0)
		data->color = 0x00CED1;
	else if (data->z == 0 || data->z1 == 0)
		data->color = 0xffffff;
	else if (data->z >= -6 || data->z1 >= -6)
		data->color = 0xDA70D6;
	else if (data->z > -11 || data->z1 > -11)
		data->color = 0x9370DB;
	else if (data->z > -21 || data->z1 > -21)
		data->color = 0x6A5ACD;
	else if (data->z > -31 || data->z1 > -31)
		data->color = 0xBA55D3;
}

void	ft_init_dot(t_data *data)
{
	data->z = data->matrix[(int)data->y][(int)data->x];
	data->z1 = data->matrix[(int)data->y1][(int)data->x1];
	data->x *= data->zoom;
	data->y *= data->zoom;
	data->x1 *= data->zoom;
	data->y1 *= data->zoom;
	ft_set_color(data);
	ft_rotate_map(data);
	if (data->isometric)
		ft_isometric(data);
	data->x += data->shift_x;
	data->x1 += data->shift_x;
	data->y += data->shift_y;
	data->y1 += data->shift_y;
}
