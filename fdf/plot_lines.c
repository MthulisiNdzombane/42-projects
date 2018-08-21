/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plot_lines.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mndzomb <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/17 22:57:37 by mndzomb           #+#    #+#             */
/*   Updated: 2018/08/17 22:57:48 by mndzomb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		norm_x(t_coord *vec)
{
	if (vec->x == 0)
	{
		vec->x2 = vec->x1;
		vec->y2 = vec->y1;
	}
	else
	{
		vec->x1 = vec->shift_x + (vec->x * vec->space_x)
		+ (vec->y * vec->space_x);
		vec->y1 = vec->shift_y - (vec->x * vec->space_y)
		+ (vec->y * vec->space_y);
	}
}

void		norm_y(t_mlx *fdf_mlx)
{
	if (fdf_mlx->points.y == 0)
	{
		fdf_mlx->points.x2 = fdf_mlx->points.x1;
		fdf_mlx->points.y2 = fdf_mlx->points.y1;
	}
	else
	{
		fdf_mlx->points.x1 = fdf_mlx->points.shift_x + (fdf_mlx->points.x *
		fdf_mlx->points.space_x)
		+ (fdf_mlx->points.y * fdf_mlx->points.space_x);
		fdf_mlx->points.y1 = fdf_mlx->points.shift_y - (fdf_mlx->points.x *
		fdf_mlx->points.space_y)
		+ (fdf_mlx->points.y * fdf_mlx->points.space_y);
	}
	if (fdf_mlx->map[(int)fdf_mlx->points.y][(int)fdf_mlx->points.x])
	{
		fdf_mlx->points.y1 -=
		fdf_mlx->map[(int)fdf_mlx->points.y][(int)fdf_mlx->points.x];
		linebres(fdf_mlx);
	}
	else
		linebres(fdf_mlx);
	fdf_mlx->points.y++;
	fdf_mlx->points.x2 = fdf_mlx->points.x1;
	fdf_mlx->points.y2 = fdf_mlx->points.y1;
}

static void	fuck(t_mlx *fdf_mlx)
{
	fdf_mlx->points.x = 0;
	fdf_mlx->points.x1 = fdf_mlx->points.shift_x +
	(fdf_mlx->points.space_x * fdf_mlx->points.y);
	fdf_mlx->points.y1 = fdf_mlx->points.shift_y +
	(fdf_mlx->points.space_y * fdf_mlx->points.y);
}

void		plot_lines_x(t_mlx *fdf_mlx)
{
	fdf_mlx->points.space_x = 25 * fdf_mlx->scale;
	fdf_mlx->points.space_y = 20 * fdf_mlx->scale;
	fdf_mlx->points.y = 0;
	while (fdf_mlx->points.y < fdf_mlx->max_y)
	{
		fuck(fdf_mlx);
		while (fdf_mlx->points.x < fdf_mlx->max_x)
		{
			norm_x(&fdf_mlx->points);
			if (fdf_mlx->map[(int)fdf_mlx->points.y][(int)fdf_mlx->points.x])
			{
				fdf_mlx->points.y1 -=
				fdf_mlx->map[(int)fdf_mlx->points.y][(int)fdf_mlx->points.x];
				linebres(fdf_mlx);
			}
			else
				linebres(fdf_mlx);
			fdf_mlx->points.x++;
			fdf_mlx->points.x2 = fdf_mlx->points.x1;
			fdf_mlx->points.y2 = fdf_mlx->points.y1;
		}
		fdf_mlx->points.y++;
		fdf_mlx->points.x2 = fdf_mlx->points.x1 += 1;
		fdf_mlx->points.y2 = fdf_mlx->points.y1 += 1;
	}
}

void		plot_lines_y(t_mlx *fdf_mlx)
{
	fdf_mlx->points.space_x = 25 * fdf_mlx->scale;
	fdf_mlx->points.space_y = 20 * fdf_mlx->scale;
	fdf_mlx->points.x = 0;
	while (fdf_mlx->points.x < fdf_mlx->max_x)
	{
		fdf_mlx->points.y = 0;
		fdf_mlx->points.x1 = fdf_mlx->points.shift_x +
		(fdf_mlx->points.space_x * fdf_mlx->points.x);
		fdf_mlx->points.y1 = fdf_mlx->points.shift_y -
		(fdf_mlx->points.space_y * fdf_mlx->points.x);
		while (fdf_mlx->points.y < fdf_mlx->max_y)
		{
			norm_y(fdf_mlx);
		}
		fdf_mlx->points.x++;
		fdf_mlx->points.x2 = fdf_mlx->points.x1 += 1;
		fdf_mlx->points.y2 = fdf_mlx->points.y1 += 1;
	}
	fdf_mlx->points.y += 10;
}
