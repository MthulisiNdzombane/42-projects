/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mndzomb <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/30 23:12:29 by mndzomb           #+#    #+#             */
/*   Updated: 2018/08/08 13:57:45 by mndzomb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef FDF_H
# 	define FDF_H

# 	define HEIGHT 1024
# 	define WIDTH 1280

#	include "./get_next_line.h"
#	include "./libft/libft.h"
#	include <fcntl.h>
#	include "mlx.h"

typedef	struct		s_coord
{
	double		y;
	double		x;
	double		x1;
	double		y1;
	double		x2;
	double		y2;
	double		shift_x;
	double		shift_y;
	double		space_x;
	double		space_y;
}					t_coord;

typedef struct		s_mlx
{
	int		len;
	void	*mlx;
	double	max_x;
	double	max_y;
	double	max_z;
	int		color;
	int		colmn;
	double	scale;
	void	*window;
	char	**coord;
	int		line_chars;
	double	map[1024][1024];
	
	t_coord	points;
}					t_mlx;

typedef	struct		s_line
{
	int	x;
	int	y;
	int	dx;
	int	dy;
	int	p_x;
	int	p_y;
	int	twodx;
	int	twody;
	int	x_end;
	int	y_end;
	int	dx_abs;
	int	dy_abs;
	int	twodyminusdx;
}					t_line;

void				zoom(int key, t_coord *vec, t_mlx *fdf_mlx);
int					key_hooks(int key, t_mlx *fdf_mlx);
void				translate(int key, t_mlx *fdf_mlx);
void				grab_map(t_mlx *mlx, char *str);
void				plot_lines_x(t_mlx *fdf_mlx);
void				plot_lines_y(t_mlx *fdf_mlx);
void				linebres (t_mlx *fdf_mlx);

#	endif
