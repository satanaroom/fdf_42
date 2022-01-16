#include "fdf.h"

void	ft_customize_window(t_data *data)
{
	mlx_string_put(data->mlx, data->mlx_win, W_WIDTH * 0.05,
		W_HEIGHT * 0.05, 0x7CFC00, "To interact with the map use");
	mlx_string_put(data->mlx, data->mlx_win, W_WIDTH * 0.05,
		W_HEIGHT * 0.05 + 15, 0x7CFC00, "rotation: X-axis - A and D keys");
	mlx_string_put(data->mlx, data->mlx_win, W_WIDTH * 0.05,
		W_HEIGHT * 0.05 + 30, 0x7CFC00, "rotation: Y-axis - W and S keys");
	mlx_string_put(data->mlx, data->mlx_win, W_WIDTH * 0.05,
		W_HEIGHT * 0.05 + 45, 0x7CFC00, "rotation: Z-axis - Z and C keys");
	mlx_string_put(data->mlx, data->mlx_win, W_WIDTH * 0.05,
		W_HEIGHT * 0.05 + 60, 0x7CFC00, "rotation: All-axis - Q and E keys");
	mlx_string_put(data->mlx, data->mlx_win, W_WIDTH * 0.05,
		W_HEIGHT * 0.05 + 75, 0x7CFC00, "shift: arrows");
	mlx_string_put(data->mlx, data->mlx_win, W_WIDTH * 0.05,
		W_HEIGHT * 0.05 + 90, 0x7CFC00, "zoom: - and + keys");
	mlx_string_put(data->mlx, data->mlx_win, W_WIDTH * 0.05,
		W_HEIGHT * 0.05 + 105, 0x7CFC00, "set 2d or 3d: 2 and 3 keys");
	mlx_string_put(data->mlx, data->mlx_win, W_WIDTH * 0.05,
		W_HEIGHT * 0.05 + 120, 0x7CFC00, "set default 3d position: < key");
	mlx_string_put(data->mlx, data->mlx_win, W_WIDTH * 0.05,
		W_HEIGHT * 0.05 + 135, 0x7CFC00, "set 2d side position: > key");
	mlx_string_put(data->mlx, data->mlx_win, W_WIDTH * 0.05,
		W_HEIGHT * 0.05 + 150, 0x7CFC00, "set 2d other side position: / key");
	mlx_string_put(data->mlx, data->mlx_win, W_WIDTH * 0.05,
		W_HEIGHT * 0.05 + 165, 0x7CFC00, "exit: Esc key");
}

static int	ft_parse_key(int key, t_data *data)
{
	if (key == 53)
		ft_close(data);
	if (key == 24 || key == 27)
		ft_zoom(key, data);
	if (key == 126 || key == 125 || key == 123 || key == 124)
		ft_shift(key, data);
	if (key == 19)
		data->isometric = 0;
	if (key == 20)
		data->isometric = 1;
	if (key == 12)
		data->angle += 0.1;
	if (key == 14)
		data->angle -= 0.1;
	if (key == 13 || key == 1 || key == 0
		|| key == 2 || key == 6 || key == 8)
		ft_angle_rotate(key, data);
	if (key == 43 || key == 47 || key == 44)
		ft_default(key, data);
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
