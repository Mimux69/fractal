/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 21:43:14 by acronert          #+#    #+#             */
/*   Updated: 2023/12/13 16:50:08 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

double	ft_abs(double value)
{
	if (value < 0)
		value = -value;
	return (value);
}

int	calculate_burning_ship_pixel(double xp, double yp, t_fractol *fractol)
{
	double	zx;
	double	zy;
	double	xtemp;
	int		iter;
	t_coord	step;

	zy = 0;
	zx = 0;
	xtemp = 0;
	iter = 0;
	step.x = 2 * (1 / fractol->zoom) / DISPLAY_W;
	step.y = (2 * (1 / fractol->zoom) * DISPLAY_H / DISPLAY_W) / DISPLAY_H;
	xp = (fractol->center_x - step.x * (DISPLAY_W / 2)) + xp * step.x;
	yp = (fractol->center_y - step.y * (DISPLAY_H / 2)) + yp * step.y;
	while (zx * zx + zy * zy <= 2 * 2 && iter < fractol->max_iter)
	{
		xtemp = zx * zx - zy * zy + xp;
		zy = ft_abs(2 * zx * zy) + yp;
		zx = xtemp;
		iter++;
	}
	return (iter);
}

void	draw_burning_ship(t_fractol *fractol)
{
	char	*buf ;
	int		bits_per_pixel;
	int		size_line;
	int		i;
	int		endian;

	endian = 0;
	bits_per_pixel = 32;
	size_line = 4 * DISPLAY_W;
	buf = mlx_get_data_addr(fractol->img, &bits_per_pixel, &size_line, &endian);
	i = 0;
	while (i < DISPLAY_H * size_line)
	{
		ft_color(calculate_burning_ship_pixel((double)((i / 4) % (DISPLAY_W)),
				(double)(i / (4 * DISPLAY_W)), fractol), fractol->max_iter, fractol->ncolor, &buf[i]);
		i += 4;
	}
	mlx_put_image_to_window(fractol->mlx, fractol->win, fractol->img, 0, 0);
}

void	burning_ship(t_fractol *fractol)
{
	fractol->fractal_type = 3;
	fractol->center_x = 0;
	fractol->center_y = 0;
	fractol->zoom = 0.5;
	draw_burning_ship(fractol);
	mlx_key_hook(fractol->win, ft_get_key, (void *)fractol);
	mlx_mouse_hook(fractol->win, ft_get_mouse, (void *)fractol);
	mlx_hook(fractol->win, 33, 17, ft_exit, (void *)fractol);
	mlx_loop(fractol->mlx);
	free(fractol);
}