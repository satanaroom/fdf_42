#include "../fdf.h"

void	ft_isometric(t_data *data)
{
	data->x = (data->x - data->y) * cos(data->angle);
	data->y = (data->x + data->y) * sin(data->angle) - data->z;
	data->x1 = (data->x1 - data->y1) * cos(data->angle);
	data->y1 = (data->x1 + data->y1) * sin(data->angle) - data->z1;
}

static void	ft_rotate_x(t_data *data)
{
	int	old_y;
	int	old_y1;

	old_y = data->y;
	data->y = old_y * cos(data->angle_x) + data->z * sin(data->angle_x);
	data->z = -old_y * sin(data->angle_x) + data->z * cos(data->angle_x);
	old_y1 = data->y1;
	data->y1 = old_y1 * cos(data->angle_x) + data->z1 * sin(data->angle_x);
	data->z1 = -old_y1 * sin(data->angle_x) + data->z1 * cos(data->angle_x);
}

static void	ft_rotate_y(t_data *data)
{
	int	old_x;
	int	old_x1;

	old_x = data->x;
	data->x = old_x * cos(data->angle_y) - data->z * sin(data->angle_y);
	data->z = old_x * sin(data->angle_y) + data->z * cos(data->angle_y);
	old_x1 = data->x1;
	data->x1 = old_x1 * cos(data->angle_y) - data->z1 * sin(data->angle_y);
	data->z1 = old_x1 * sin(data->angle_y) + data->z1 * cos(data->angle_y);
}

static void	ft_rotate_z(t_data *data)
{
	int	old_x;
	int	old_y;
	int	old_x1;
	int	old_y1;

	old_x = data->x;
	old_y = data->y;
	data->x = old_x * cos(data->angle_z) + old_y * sin(data->angle_z);
	data->y = -old_x * sin(data->angle_z) + old_y * cos(data->angle_z);
	old_x1 = data->x1;
	old_y1 = data->y1;
	data->x1 = old_x1 * cos(data->angle_z) + old_y1 * sin(data->angle_z);
	data->y1 = -old_x1 * sin(data->angle_z) + old_y1 * cos(data->angle_z);
}

void	ft_rotate_map(t_data *data)
{
	ft_rotate_x(data);
	ft_rotate_y(data);
	ft_rotate_z(data);
}
