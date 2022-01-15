#ifndef FDF_H
# define FDF_H

# include <stdio.h>
# include <fcntl.h>
# include <math.h>
# include "mlx/mlx.h"
# include "minilibft/minilibft.h"
# include "gnl/get_next_line.h"

# define W_HEIGHT 900.0
# define W_WIDTH 1440.0
# define W_NAME	"FDF"

typedef struct s_img {
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

	int		shift_x;
	int		shift_y;
	int		isometric;
	int		color;
	double	angle;
	double	angle_x;
	double	angle_y;
	double	angle_z;
	int		zoom;

	void	*mlx;
	void	*mlx_win;
	t_img	img;
}				t_data;

float		ft_max(float a, float b);
float		ft_mod(float x);
void		ft_isometric(t_data *data);
void		ft_error(char *err);
size_t		ft_word_count(const char *str, char c);
void		ft_parse_map(char *map_name, t_data *data);
void		ft_draw(t_data *data);
void		ft_init_image(t_data *data);
void		ft_init_map(t_data *data);
void		ft_init_dot(t_data *data);
void		ft_validate_dot(char *dot_line);
void		ft_rotate_map(t_data *data);

#endif
