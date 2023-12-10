/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_mandelbrot.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 12:56:03 by alex              #+#    #+#             */
/*   Updated: 2023/12/08 17:52:55 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"


void	print_mandelbrot(int **pixel)
{
	int	x;
	int	y;
	int	pixel_color;

	y = 0;
	while (y < DISPLAY_HEIGHT)
	{
		x = 0;
		while (x < DISPLAY_WIDTH)
		{
			pixel_color = ((double)pixel[x][y] / MAX_ITERATION) * 232 + 0;
			printf("\x1b[38;5;%dm\u2588\u2588\x1b[0m", (int)pixel_color);
			x++;
		}
		printf ("\n");
		y++;
	}
}