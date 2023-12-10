/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 12:17:02 by alex              #+#    #+#             */
/*   Updated: 2023/12/08 18:52:03 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTAL_H
# define FRACTAL_H

# include <stdlib.h>
# include <stdio.h>
# include "ft_printf.h"
# include "libft.h"

// # define DISPLAY_WIDTH	1920
// # define DISPLAY_HEIGHT	1080
# define DISPLAY_WIDTH	400
# define DISPLAY_HEIGHT	400
# define MAX_ITERATION	232

void	mandelbrot();
void	print_mandelbrot(int **pixel);

typedef struct s_pixel_coord
{
	int	x;
	int	y;
	int	iteration;
}	t_pixel_coord;

#endif