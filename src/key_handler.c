#include "../fdf.h"

void	ft_close(t_data *data)
{
	mlx_destroy_window(data->mlx, data->mlx_win);
	exit(0);
}

void	ft_zoom(int key, t_data *data)
{
	if (key == 24)
		data->zoom += 1;
	else
		data->zoom -= 1;
}

void	ft_shift(int key, t_data *data)
{
	if (key == 126)
		data->shift_y -= 5;
	else if (key == 125)
		data->shift_y += 5;
	else if (key == 123)
		data->shift_x -= 5;
	else
		data->shift_x += 5;
}

void	ft_default(int key, t_data *data)
{
	if (key == 43)
	{
		data->angle = 1;
		data->angle_x = 0;
		data->angle_y = 0;
		data->angle_z = 0;
	}
	if (key == 47)
	{
		data->angle = 0;
		data->angle_x = 0;
		data->angle_y = 0;
		data->angle_z = -0.79;
	}
	if (key == 44)
	{
		data->angle = 0;
		data->angle_x = 0;
		data->angle_y = 0;
		data->angle_z = 0.788;
	}
}

void	ft_angle_rotate(int key, t_data *data)
{
	if (key == 13)
		data->angle_x += 0.1;
	if (key == 1)
		data->angle_x -= 0.1;
	if (key == 0)
		data->angle_y += 0.1;
	if (key == 2)
		data->angle_y -= 0.1;
	if (key == 6)
		data->angle_z += 0.1;
	if (key == 8)
		data->angle_z -= 0.1;
}
