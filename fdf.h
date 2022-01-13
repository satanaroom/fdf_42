#ifndef FDF_H
# define FDF_H

# include <stdio.h>
# include <fcntl.h>
# include <math.h>
# include "mlx/mlx.h"
# include "minilibft/libft.h"
# include "gnl/get_next_line.h"

typedef struct	s_img {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_img;

typedef struct s_data
{
	int		height;
	int		width;
	int		**matrix;
	float	x;
	float	x1;
	float	y;
	float	y1;
	int		z;
	int		z1;

	int		zoom;
	int		color;

	void	*mlx;
	void	*mlx_win;
	t_img	img;
}				t_data;

void		ft_error(char *err);
size_t		ft_word_count(const char *str, char c);
void		ft_get_map(char *map_name, t_data *data);
void		ft_print_map(t_data *data);
void		ft_mlx_pixel_put(t_img *img, int x, int y, int color);

#endif
