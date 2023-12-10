/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 12:15:54 by alex              #+#    #+#             */
/*   Updated: 2023/12/08 18:52:01 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void	free_pixel(int **pixel, int x)
{
	while (x >= 0)
	{
		free(pixel[x]);
		x--;
	}
	free(pixel);
}

	//malloc a double pointer pixel[x][y]
int	**malloc_pixel()
{
	int	**pixel;
	int	x;

	x = 0;
	pixel = malloc(DISPLAY_WIDTH * sizeof(int*));
	if (!pixel)
		return (NULL);
	while (x < DISPLAY_WIDTH)
	{
		pixel[x] = malloc(DISPLAY_HEIGHT * sizeof(int));
		if (!pixel[x])
		{
			free_pixel(pixel, x);
			return (NULL);
		}
		x++;
	}
	return (pixel);
}
	//Z = Z^2 + C;
	//calculate the numbers of iterations of each pixels
int	calculate_mandelbrot(double xp, double yp)
{
	double	x;
	double	y;
	double	xtemp;
	int		iteration;

	y = 0;
	x = 0;
	xtemp = 0;
	iteration = 0;

	//center the view
	// xp -= DISPLAY_WIDTH / 2;
	// yp -= DISPLAY_HEIGHT / 2;
	// xp = xp -  200 * DISPLAY_WIDTH / 100;
	// yp = yp -  60 * DISPLAY_HEIGHT / 100;


	//zoom the view
	// int	zoom = 80;
	// xp /= zoom;
	// yp /= zoom;
	while (x * x + y * y <= 2 * 2 && iteration < MAX_ITERATION)
	{
		xtemp = x * x - y * y + (xp - 3*DISPLAY_WIDTH / 4) / (DISPLAY_HEIGHT / 2);
		y = 2 * x * y + (yp - DISPLAY_HEIGHT / 2) / (DISPLAY_HEIGHT / 2);
		// xtemp = x * x - y * y + xp;
		// y = 2 * x * y + yp;
		x = xtemp;
		iteration++;
	}
	return (iteration);
}

void	mandelbrot()
{
	int	**pixel;
	int	x;
	int	y;
	
	x = 0;
	y = 0;
	pixel = malloc_pixel();
	if (!pixel)
		return ;
	while (y < DISPLAY_HEIGHT)
	{
		x = 0;
		while (x < DISPLAY_WIDTH)
		{
			pixel[x][y] = calculate_mandelbrot(x, y);
			x++;
		}
		y++;
	}
	print_mandelbrot(pixel);
	free_pixel(pixel, DISPLAY_WIDTH - 1);
}


