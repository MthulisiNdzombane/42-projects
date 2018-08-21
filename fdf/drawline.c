/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmayika <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/13 11:36:57 by kmayika           #+#    #+#             */
/*   Updated: 2018/08/08 07:59:32 by mndzomb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdlib.h>

static void		x_render(t_mlx *fdf_mlx, t_line *draw)
{
	if (fdf_mlx->map[(int)fdf_mlx->points.y][(int)fdf_mlx->points.x] > 0)
		mlx_pixel_put(fdf_mlx, fdf_mlx->window, draw->x, draw->y, 0x0011FF);
	else if (fdf_mlx->map[(int)fdf_mlx->points.y][(int)fdf_mlx->points.x] < 0)
		mlx_pixel_put(fdf_mlx, fdf_mlx->window, draw->x, draw->y, 0xFFFF19);
	else if (fdf_mlx->map[(int)fdf_mlx->points.y][(int)fdf_mlx->points.x] == 0)
		mlx_pixel_put(fdf_mlx, fdf_mlx->window, draw->x, draw->y, 0xFF0019);
}

static void		render_x(t_mlx *fdf_mlx, t_line *draw)
{
	if (draw->dx >= 0)
	{
		draw->x = fdf_mlx->points.x1;
		draw->y = fdf_mlx->points.y1;
		draw->x_end = fdf_mlx->points.x2;
	}
	else
	{
		draw->x = fdf_mlx->points.x2;
		draw->y = fdf_mlx->points.y2;
		draw->x_end = fdf_mlx->points.x1;
	}
	while (++draw->x < draw->x_end)
	{
		if (draw->p_x < 0)
			draw->p_x += draw->twody;
		else
		{
			((draw->dx < 0 && draw->dy < 0)
			|| (draw->dx > 0 && draw->dy > 0)) ? draw->y++ : draw->y--;
			draw->p_x += draw->twodyminusdx;
		}
		x_render(fdf_mlx, draw);
	}
}

static void		y_render(t_mlx *fdf_mlx, t_line *draw)
{
	if (fdf_mlx->map[(int)fdf_mlx->points.y][(int)fdf_mlx->points.x] > 0)
		mlx_pixel_put(fdf_mlx, fdf_mlx->window, draw->x, draw->y, 0x0011FF);
	else if (fdf_mlx->map[(int)fdf_mlx->points.y][(int)fdf_mlx->points.x] < 0)
		mlx_pixel_put(fdf_mlx, fdf_mlx->window, draw->x, draw->y, 0xFFFF19);
	else if (fdf_mlx->map[(int)fdf_mlx->points.y][(int)fdf_mlx->points.x] == 0)
		mlx_pixel_put(fdf_mlx, fdf_mlx->window, draw->x, draw->y, 0xFF0019);
}

static void		render_y(t_mlx *fdf_mlx, t_line *draw)
{
	if (draw->dy >= 0)
	{
		draw->x = fdf_mlx->points.x1;
		draw->y = fdf_mlx->points.y1;
		draw->y_end = fdf_mlx->points.y2;
	}
	else
	{
		draw->x = fdf_mlx->points.x2;
		draw->y = fdf_mlx->points.y2;
		draw->y_end = fdf_mlx->points.y1;
	}
	while (++draw->y < draw->y_end)
	{
		if (draw->p_y <= 0)
			draw->p_y += draw->twodx;
		else
		{
			((draw->dx < 0 && draw->dy < 0) ||
			(draw->dx > 0 && draw->dy > 0)) ? draw->x++ : draw->x--;
			draw->p_y += draw->twodyminusdx;
		}
		y_render(fdf_mlx, draw);
	}
}

void			linebres(t_mlx *fdf_mlx)
{
	t_line	draw;

	draw.dx = (fdf_mlx->points.x2 - fdf_mlx->points.x1);
	draw.dy = (fdf_mlx->points.y2 - fdf_mlx->points.y1);
	draw.dx_abs = abs(draw.dx);
	draw.dy_abs = abs(draw.dy);
	draw.p_x = 2 * draw.dy - draw.dx;
	draw.p_y = 2 * draw.dx - draw.dy;
	draw.twody = 2 * draw.dy_abs;
	draw.twodx = 2 * draw.dx_abs;
	draw.twodyminusdx = 2 * (draw.dy_abs - draw.dx_abs);
	if (draw.dy_abs <= draw.dx_abs)
		render_x(fdf_mlx, &draw);
	else
		render_y(fdf_mlx, &draw);
}
