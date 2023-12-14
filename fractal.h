/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 12:17:02 by alex              #+#    #+#             */
/*   Updated: 2023/12/13 20:41:43 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTAL_H
# define FRACTAL_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <math.h>
# include "ft_printf.h"
# include "libft.h"
# include "mlx.h"

// # define DISPLAY_WIDTH	1920
// # define DISPLAY_HEIGHT	1080
# define DISPLAY_W			500
# define DISPLAY_H			500
# define MAX_ITER_INIT		10000
# define COLOR_CYCLE_INIT	128
# define ZOOM_STRENGHT		1.5
# define MANDELBROT			1
# define JULIA				2
# define BURNING_SHIP		3
# define BUDDHABROT			4
# define PI					3.1415
# define USER_CONTROLS		"Controls :\n\
   [q]		increase max iterations by 50\n\
   [a]		decrease max iterations by 50\n\
  [LMB]		focus on the cursor position\n\
  [RMB]		draw the Julia set with parameters equal to the cursor position\n\
[mouse wheel]	zoom in / zoom out\n\
  [ESC]		quit\n"

typedef struct s_fractol
{
	void	*mlx;
	void	*win;
	void	*img;
	double	center_x;
	double	center_y;
	double	cx;
	double	cy;
	double	zoom;
	int		ncolor;
	int		max_iter;
	int		fractal_type;
}	t_fractol;

typedef struct s_coord
{
	double	x;
	double	y;
}	t_coord;

void	mandelbrot(t_fractol *fractol);
void	draw_mandelbrot(t_fractol *fractol);

void	julia(t_fractol *fractol);
void	draw_julia(t_fractol *fractol);

void	burning_ship(t_fractol *fractol);
void	draw_burning_ship(t_fractol *fractol);

void	buddhabrot(t_fractol *fractol);
void	draw_buddhabrot(t_fractol *fractol);

void	ft_color(int iteration, int max_iter, int color_cycle, char *buf);

int		ft_parse_atod_input(char *str);
double	ft_atod(const char *str);

int		ft_get_key(int key, t_fractol *fractol);
int		ft_get_key_2(int key, t_fractol *fractol);

int		ft_get_mouse(int button, int x, int y, t_fractol *fractol);
int		ft_get_mouse_2(int button, int x, int y, t_fractol *fractol);

int	ft_exit(t_fractol *fractol);

#endif