/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buddhabrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 20:14:23 by acronert          #+#    #+#             */
/*   Updated: 2023/12/13 18:18:22 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"


void	ft_print_array(int **image)
{
	int x;
	int y;

	y = 0;
	while (y < DISPLAY_H)
	{
		x = 0;
		while (x < DISPLAY_W)
		{
			printf ("%3d ", image[x][y]);
			x++;
		}
		printf ("\n");
		y++;
	}	
}


int	ft_find_big_value(int **image)
{
	int x;
	int y;
	int	big;

	big = 0;
	y = 0;
	while (y < DISPLAY_H)
	{
		x = 0;
		while (x < DISPLAY_W)
		{
			if (image[x][y] > big)
				big = image[x][y];
			x++;
		}
		y++;
	}
	return (big);
}

int	calculate_buddhabrot_pixel(int **image, double xp, double yp, t_fractol *fractol)
{
	double	x;
	double	y;
	double	xtemp;
	int		iter;
	t_coord	step;

	y = 0;
	x = 0;
	xtemp = 0;
	iter = 0;
	step.x = 2 * (1 / fractol->zoom) / DISPLAY_W;
	step.y = (2 * (1 / fractol->zoom) * DISPLAY_H / DISPLAY_W) / DISPLAY_H;
	xp = (fractol->center_x - step.x * (DISPLAY_W / 2)) + xp * step.x;
	yp = (fractol->center_y - step.y * (DISPLAY_H / 2)) + yp * step.y;

	while (x * x + y * y <= 2 * 2 && iter < fractol->max_iter)
	{
		xtemp = x * x - y * y + xp;
		y = 2 * x * y + yp;
		x = xtemp;
		iter++;
	}
	if (iter != fractol->max_iter)
	{
		y = 0;
		x = 0;
		xtemp = 0;
		iter = 0;
		while (x * x + y * y <= 2 * 2 && iter < fractol->max_iter)
		{
			xtemp = x * x - y * y + xp;
			y = 2 * x * y + yp;
			x = xtemp;
			
			if (fractol->center_x - step.x * (DISPLAY_W / 2) < x && x < fractol->center_x + step.x * (DISPLAY_W / 2)
				&& fractol->center_y - step.y * (DISPLAY_H / 2)< y && y <fractol->center_y + step.y * (DISPLAY_H / 2))
			{
				if (image[(int)((x - fractol->center_x + step.x * (DISPLAY_W / 2)) / step.x)][(int)((y - fractol->center_y + step.y * (DISPLAY_H / 2)) / step.y)] < 2147483647)
					image[(int)((x - fractol->center_x + step.x * (DISPLAY_W / 2)) / step.x)][(int)((y - fractol->center_y + step.y * (DISPLAY_H / 2)) / step.y)] += 1;
				// ft_printf("x = %d\n", (int)((x - fractol->center_x + step.x * (DISPLAY_W / 2)) / step.x));
				// ft_printf("y = %d\n", (int)((y - fractol->center_y + step.y * (DISPLAY_H / 2)) / step.y));
			}
			iter++;
			//ft_printf("iter = %d", iter);
		}
		return (iter);
	}
	return (0);
}

void	draw_buddhabrot(t_fractol *fractol)
{
	char	*buf ;
	int		bits_per_pixel;
	int		size_line;
	long int		i;
	int		endian;
	int		**image;

	image = malloc(DISPLAY_W * sizeof(int *));
	//free !!
	int j;
	i = 0;
	while (i < DISPLAY_W)
	{
		image[i] = malloc (DISPLAY_H * (sizeof(int)));
		//free !!
		j = 0;
		while (j < DISPLAY_H)
		{
			image[i][j] = 0;
			j++;
		}
		i++;
	}


	int gradient;

	endian = 0;
	bits_per_pixel = 32;
	size_line = 4 * DISPLAY_W;
	buf = mlx_get_data_addr(fractol->img, &bits_per_pixel, &size_line, &endian);
	i = 0;
	while (i < DISPLAY_W * DISPLAY_H * 4)
	{
		calculate_buddhabrot_pixel(image, (double)((i / 4) % (DISPLAY_W)),
				(double)(i / (4 * DISPLAY_W)), fractol);
		i+=4;
	}
	i = 0;
	int big = ft_find_big_value(image);
	while (i < DISPLAY_H * size_line)
	{
		gradient = (double)(image[(i / 4) % (DISPLAY_W)][i / (4 * DISPLAY_W)] * 255) / big;
		buf[i] = gradient;
		buf[i + 1] = gradient;
		buf[i + 2] = gradient;
		i += 4;
	}
	mlx_put_image_to_window(fractol->mlx, fractol->win, fractol->img, 0, 0);
}

void	buddhabrot(t_fractol *fractol)
{
	fractol->fractal_type = BUDDHABROT;
	fractol->center_x = -0.75;
	fractol->center_y = 0;
	fractol->zoom = 0.7;
	draw_buddhabrot(fractol);
	mlx_key_hook(fractol->win, ft_get_key, (void *)fractol);
	mlx_mouse_hook(fractol->win, ft_get_mouse, (void *)fractol);
	mlx_hook(fractol->win, 33, 17, ft_exit, (void *)fractol);
	mlx_loop(fractol->mlx);
}