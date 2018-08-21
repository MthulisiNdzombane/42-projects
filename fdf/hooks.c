/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mndzomb <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 18:47:22 by mndzomb           #+#    #+#             */
/*   Updated: 2018/08/08 01:21:14 by mndzomb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	updatedraw(t_mlx *fdf_mlx)
{
	mlx_clear_window(fdf_mlx->mlx, fdf_mlx->window);
	plot_lines_x(fdf_mlx);
	plot_lines_y(fdf_mlx);
}

int			key_hooks(int key, t_mlx *fdf_mlx)
{
	if (key == 53)
		exit(0);
	else if (key == 69)
	{
		fdf_mlx->scale += 0.1;
	}
	else if (key == 78)
	{
		if (fdf_mlx->scale > 0.2)
			fdf_mlx->scale -= 0.1;
	}
	else if (key >= 123 && key <= 126)
		translate(key, fdf_mlx);
	updatedraw(fdf_mlx);
	return (0);
}

void		translate(int key, t_mlx *fdf_mlx)
{
	if (key == 123 || key == 124)
		key == 123 ? (fdf_mlx->points.shift_x -= 10) :
		(fdf_mlx->points.shift_x += 10);
	else if (key == 126 || key == 125)
		key == 125 ? (fdf_mlx->points.shift_y += 10) :
		(fdf_mlx->points.shift_y -= 10);
	updatedraw(fdf_mlx);
}
