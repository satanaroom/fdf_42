#include "fdf.h"

static void	ft_close(int keycode, t_data *data)
{
	mlx_destroy_window(data->mlx, data->mlx_win);
	exit(0);
}

static int	ft_parse_key(int key, t_data *data)
{
	if (key == 53)
		ft_close(53, data);
	if (key == 24)
		data->zoom += 1;
	if (key == 27)
		data->zoom -= 1;
	if (key == 126)
		data->shift_y -= 5;
	if (key == 125)
		data->shift_y += 5;
	if (key == 123)
		data->shift_x -= 5;
	if (key == 124)
		data->shift_x += 5;
	if (key == 19)
		data->isometric = 0;
	if (key == 20)
		data->isometric = 1;
	if (key == 12)
		data->angle += 0.01;
	if (key == 14)
		data->angle -= 0.01;
	if (key == 13)
		data->angle_x += 0.01;
	if (key == 1)
		data->angle_x -= 0.01;
	if (key == 0)
		data->angle_y += 0.01;
	if (key == 2)
		data->angle_y -= 0.01;
	if (key == 6)
		data->angle_z += 0.01;
	if (key == 8)
		data->angle_z -= 0.01;
	if (key == 7)
	{
		data->angle = 1;
		data->angle_x = 0;
		data->angle_y = 0;
		data->angle_z = 0;
	}
	ft_draw(data);
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	*data;

	if (argc != 2)
		ft_error("please, use: ./fdf map_name.fdf");
	data = (t_data *)malloc(sizeof(t_data));
	ft_parse_map(argv[1], data);
	data->mlx = mlx_init();
	data->mlx_win = mlx_new_window(data->mlx, W_WIDTH, W_HEIGHT, W_NAME);
	ft_init_map(data);
	ft_draw(data);
	mlx_hook(data->mlx_win, 2, 0, ft_parse_key, data);
	mlx_loop(data->mlx);
	free(data);
}
