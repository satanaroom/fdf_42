#include "fdf.h"

static void	ft_validate_dot(char *dot_line)
{
	int	i;

	i = 0;
	if (ft_isalpha(dot_line[i]))
		printf("ERROR: %c\n", dot_line[i]);
	// if (ft_isdigit(dot_line))
	// 	printf("%s", "is digit");
	// else
	// 	printf("%s", "not digit");
}

static int	ft_get_width(char *map_name)
{
	int		width;
	char	*line;
	int		fd;

	fd = open(map_name, O_RDONLY, 0);
	if (fd <= 0)
		ft_error("could't read map");
	line = get_next_line(fd);
	width = ft_word_count(line, ' ');
	free(line);
	close(fd);
	return (width);
}

static int	ft_get_height(char *map_name)
{
	int     height;
	char	*line;
	int		fd;

	fd = open(map_name, O_RDONLY, 0);
	if (fd <= 0)
		ft_error("could't read map");
	height = 0;
	line = get_next_line(fd);
	while (line)
	{
		height++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (height);
}

static void ft_fill_matrix(int *nums_line, char *line)
{
	char	**nums;
	int		i;

	i = 0;
	nums = ft_split(line, ' ');
	while (nums[i])
	{
		ft_validate_dot(nums[i]);
		nums_line[i] = ft_atoi(nums[i]);
		free(nums[i]);
		i++;
	}
	free(nums);
}

void	ft_get_map(char *map_name, t_data *data)
{
	char	*line;
	int		fd;
	int		i;

	data->width = ft_get_width(map_name);
	data->height = ft_get_height(map_name);
	data->matrix = (int **)malloc(sizeof(int *) * (data->height + 1));
	i = 0;
	while (i <= data->height)
	{
		data->matrix[i] = (int *)malloc(sizeof(int) * (data->width + 1));
		i++;
	}
	i = 0;
	fd = open(map_name, O_RDONLY, 0);
	if (fd <= 0)
		ft_error("could't read map");
	line = get_next_line(fd);
	while (line)
	{
		ft_fill_matrix(data->matrix[i], line);
		free(line);
		line = get_next_line(fd);
		i++;
	}
	free(line);
	data->matrix[i] = NULL;
	close(fd);
}
