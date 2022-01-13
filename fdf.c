#include "fdf.h"

// int	ft_parse_key(int key, t_data *data)
// {
// 	return (0);
// }

// void	ft_mlx_pixel_put(t_data *data, int x, int y, int color)
// {
// 	char	*dst;

// 	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
// 	*(unsigned int*)dst = color;
// }

int	main(int argc, char **argv)
{
	t_data	*data;
	int		i;
	int		j;

	data = (t_data *)malloc(sizeof(t_data));
	if (argc == 2)
		ft_get_map(argv[1], data);
	else
		ft_putstr_fd("Please, use: ./fdf map_name.fdf\n", 2);
	i = 0;
	while (i < data->height)
	{
		j = 0;
		while (j < data->width)
		{
			printf("%3d", data->matrix[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
	// data->mlx = mlx_init();
	// data->mlx_win = mlx_new_window(data->mlx, 1000, 1000, "Hello world!");
	// data->img = mlx_new_image(data->mlx, 1000, 1000);
	// data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel, &data->line_length, &data->endian);
	// data->zoom = 30;
	// ft_print_map(data);
	// mlx_put_image_to_window(data->mlx, data->mlx_win, data->img, 0, 0);
	// mlx_key_hook(data->mlx_win, ft_parse_key, NULL);
	// mlx_loop(data->mlx);
}
