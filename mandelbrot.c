/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 12:15:54 by alex              #+#    #+#             */
/*   Updated: 2023/12/13 16:49:19 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

int	calculate_mandelbrot_pixel(double xp, double yp, t_fractol *fractol)
{
	double	x;
	double	y;
	double	x2;
	double	y2;
	double	w;
	int		iter;
	t_coord	step;

	y2 = 0;
	x2 = 0;
	x = 0;
	y = 0;
	w = 0;
	iter = 0;
	step.x = 2 * (1 / fractol->zoom) / DISPLAY_W;
	step.y = (2 * (1 / fractol->zoom) * DISPLAY_H / DISPLAY_W) / DISPLAY_H;
	xp = (fractol->center_x - step.x * (DISPLAY_W / 2)) + xp * step.x;
	yp = (fractol->center_y - step.y * (DISPLAY_H / 2)) + yp * step.y;

	while (x2 + y2 <= 4 && iter < fractol->max_iter)
	{
		x = x2 - y2 + xp;
		y = w - x2 - y2 + yp;
		x2 = x * x;
		y2 = y * y;
		w = (x + y) * (x + y);
		iter++;
	}
	return (iter);
}
// int	calculate_mandelbrot_pixel(double xp, double yp, t_fractol *fractol)
// {
// 	double	x;
// 	double	y;
// 	double	xtemp;
// 	int		iter;
// 	t_coord	step;

// 	y = 0;
// 	x = 0;
// 	xtemp = 0;
// 	iter = 0;
// 	step.x = 2 * (1 / fractol->zoom) / DISPLAY_W;
// 	step.y = (2 * (1 / fractol->zoom) * DISPLAY_H / DISPLAY_W) / DISPLAY_H;
// 	xp = (fractol->center_x - step.x * (DISPLAY_W / 2)) + xp * step.x;
// 	yp = (fractol->center_y - step.y * (DISPLAY_H / 2)) + yp * step.y;
// 	while (x * x + y * y <= 2 * 2 && iter < fractol->max_iter)
// 	{
// 		xtemp = x * x - y * y + xp;
// 		y = 2 * x * y + yp;
// 		x = xtemp;
// 		iter++;
// 	}
// 	return (iter);
// }

void	draw_mandelbrot(t_fractol *fractol)
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
		ft_color(calculate_mandelbrot_pixel((double)((i / 4)
				% (DISPLAY_W)), (double)(i / (4 * DISPLAY_W)), fractol),
				fractol->max_iter, fractol->ncolor, &buf[i]);
		i += 4;
	}
	mlx_put_image_to_window(fractol->mlx, fractol->win, fractol->img, 0, 0);
}

void	mandelbrot(t_fractol *fractol)
{
	fractol->fractal_type = MANDELBROT;
	fractol->center_x = -0.75;
	fractol->center_y = 0;
	fractol->zoom = 0.7;
	draw_mandelbrot(fractol);
	mlx_key_hook(fractol->win, ft_get_key, (void *)fractol);
	mlx_mouse_hook(fractol->win, ft_get_mouse, (void *)fractol);
	mlx_hook(fractol->win, 33, 17, ft_exit, (void *)fractol);
	mlx_loop(fractol->mlx);
	free(fractol);
}
