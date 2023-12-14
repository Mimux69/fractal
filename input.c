/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 16:44:17 by acronert          #+#    #+#             */
/*   Updated: 2023/12/13 18:10:57 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void	ft_draw_fractal(t_fractol *fractol)
{
	if (fractol->fractal_type == MANDELBROT)
		draw_mandelbrot(fractol);
	else if (fractol->fractal_type == JULIA)
		draw_julia(fractol);
	else if (fractol->fractal_type == BURNING_SHIP)
		draw_burning_ship(fractol);
	else if (fractol->fractal_type == BUDDHABROT)
		draw_buddhabrot(fractol);
}

int	ft_get_key_2(int key, t_fractol *fractol)
{
	if (key == 'q')
	{
		fractol->max_iter += 50;
		ft_printf("MAX_ITER = %d\n", fractol->max_iter);
	}
	else if (key == 'a' && fractol->max_iter - 10 >= 0)
	{
		fractol->max_iter -= 50;
		ft_printf("MAX_ITER = %d\n", fractol->max_iter);
	}
	else if (key == 'w')
	{
		if (fractol->ncolor < fractol->max_iter)
			fractol->ncolor *= 2; 
	}
	else if (key == 's')
	{
		if (fractol->ncolor > 1)
			fractol->ncolor /= 2; 
	}
	ft_draw_fractal(fractol);
	return (0);

}

int	ft_get_key(int key, t_fractol *fractol)
{
	t_coord	step;

	step.x = 2 * (1 / fractol->zoom) / DISPLAY_W;
	step.y = (2 * (1 / fractol->zoom) * DISPLAY_H / DISPLAY_W) / DISPLAY_H;
	if (key == 65361)
		fractol->center_x -= 40 * step.x;
	else if (key == 65362)
		fractol->center_y -= 40 * step.y;
	else if (key == 65363)
		fractol->center_x += 40 * step.x;
	else if (key == 65364)
		fractol->center_y += 40 * step.y;
	else if (key == 65307)
		ft_exit(fractol);
	else
		ft_get_key_2(key, fractol);
	ft_draw_fractal(fractol);
	return (0);
}

int	ft_get_mouse_2(int button, int x, int y, t_fractol *fractol)
{
	t_coord	step;

	step.x = 2 * (1 / fractol->zoom) / DISPLAY_W;
	step.y = (2 * (1 / fractol->zoom) * DISPLAY_H / DISPLAY_W) / DISPLAY_H;
	if (button == 4)
	{
		fractol->center_x = (fractol->center_x - 1 / fractol->zoom)
			+ x * step.x;
		fractol->center_y = (fractol->center_y - 1 / fractol->zoom
				* DISPLAY_H / DISPLAY_W) + y * step.x;
		fractol->zoom *= ZOOM_STRENGHT;
	}
	else if (button == 5)
	{
		fractol->zoom /= ZOOM_STRENGHT;
	}
	else
		return (0);
	ft_draw_fractal(fractol);
	return (0);
}

int	ft_get_mouse(int button, int x, int y, t_fractol *fractol)
{
	t_coord	step;

	step.x = 2 * (1 / fractol->zoom) / DISPLAY_W;
	step.y = (2 * (1 / fractol->zoom) * DISPLAY_H / DISPLAY_W) / DISPLAY_H;
	if (button == 1)
	{
		fractol->center_x = (fractol->center_x - 1 / fractol->zoom)
			+ x * step.x;
		fractol->center_y = (fractol->center_y - 1 / fractol->zoom
				* DISPLAY_H / DISPLAY_W) + y * step.x;
	}
	else if (button == 3)
	{
		if (fractol->fractal_type == 1)
		{
			fractol->cx = (fractol->center_x - 1 / fractol->zoom) + x * step.x;
			fractol->cy = (fractol->center_y - 1 / fractol->zoom
					* DISPLAY_H / DISPLAY_W) + y * step.x;
			julia(fractol);
		}
		else
			mandelbrot(fractol);
	}
	else
		ft_get_mouse_2(button, x, y, fractol);
	ft_draw_fractal(fractol);
	return (0);
}
