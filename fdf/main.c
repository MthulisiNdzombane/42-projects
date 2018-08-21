/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mndzomb <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/30 23:45:15 by mndzomb           #+#    #+#             */
/*   Updated: 2018/08/12 20:17:19 by mndzomb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "fdf.h"

void		ft_split(char *str, t_mlx *mlx, int y)
{
	int		x;
	int		index;
	char	**cod_line;

	x = 0;
	index = 0;
	cod_line = ft_strsplit(str, ' ');
	while (cod_line[x] != NULL)
		x++;
	x -= 1;
	mlx->max_x = x;
	while (index <= x)
	{
		mlx->map[y][index] = ft_atoi(cod_line[index]);
		index++;
	}
}

void		grab_map(t_mlx *mlx, char *str)
{
	int		y;
	int		fd;
	char	*tmp_line;

	y = 0;
	fd = open(str, O_RDONLY);
	while (get_next_line(fd, &tmp_line) > 0)
	{
		ft_split(tmp_line, mlx, y);
		y++;
		free(tmp_line);
	}
	close(fd);
	mlx->max_y = y;
}

static int	file_exist(char *file)
{
	int		fd;

	fd = open(file, O_RDONLY | O_EXCL, S_IRUSR | S_IWUSR);
	fd = close(fd);
	return (fd);
}

int			main(int ac, char **av)
{
	t_mlx	*fdf_mlx;

	fdf_mlx = (t_mlx *)malloc(sizeof(t_mlx));
	if (!file_exist(av[1]))
	{
		if (ac == 2)
		{
			fdf_mlx->mlx = mlx_init();
			fdf_mlx->window = mlx_new_window(fdf_mlx->mlx,
			WIDTH, HEIGHT, "fdf");
			grab_map(fdf_mlx, av[1]);
			fdf_mlx->scale = 1.0;
			fdf_mlx->points.space_x = 25 * fdf_mlx->scale;
			fdf_mlx->points.space_y = 20 * fdf_mlx->scale;
			fdf_mlx->points.shift_x = 300;
			fdf_mlx->points.shift_y = 500;
			plot_lines_x(fdf_mlx);
			plot_lines_y(fdf_mlx);
		}
	}
	else
		exit(1);
	mlx_key_hook(fdf_mlx->window, key_hooks, fdf_mlx);
	mlx_loop(fdf_mlx->mlx);
	return (0);
}
