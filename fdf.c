#include "fdf.h"

int	ft_parse_key(int key, t_data *data)
{
	return (0);
}

void	ft_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	ft_init_img(t_data *data)
{
	if (data->img.img)
		mlx_destroy_image(data->mlx, data->img.img);
	data->img.img = mlx_new_image(data->mlx, 1500.0, 1500.0);
	data->img.addr = mlx_get_data_addr(data->img.img, &data->img.bits_per_pixel,
			&data->img.line_length, &data->img.endian);
}

int	main(int argc, char **argv)
{
	t_data	*data;

	if (argc != 2)
		ft_error("please, use: ./fdf map_name.fdf");
	data = (t_data *)malloc(sizeof(t_data));
	ft_get_map(argv[1], data);
	data->mlx = mlx_init();
	data->mlx_win = mlx_new_window(data->mlx, 1500.0, 1500.0, "Hello world!");
	ft_init_img(data);
	ft_print_map(data);
	mlx_hook(data->mlx_win, 2, 0, ft_parse_key, data);
	mlx_loop(data->mlx);
}
