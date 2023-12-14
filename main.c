/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 12:10:55 by alex              #+#    #+#             */
/*   Updated: 2023/12/13 17:43:20 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

t_fractol	*init_fractol(double cx, double cy)
{
	t_fractol	*fractol;

	fractol = malloc (sizeof(t_fractol));
	if (!fractol)
		return (NULL);
	fractol->cx = cx;
	fractol->cy = cy;
	fractol->ncolor = COLOR_CYCLE_INIT;
	fractol->max_iter = MAX_ITER_INIT;
	fractol->mlx = mlx_init();
	fractol->win = mlx_new_window(fractol->mlx, DISPLAY_W, DISPLAY_H,
			"fract-ol");
	fractol->img = mlx_new_image(fractol->mlx, DISPLAY_W, DISPLAY_H);
	return (fractol);
}

int	ft_exit(t_fractol *fractol)
{
	mlx_destroy_image(fractol->mlx, fractol->img);
	mlx_destroy_window(fractol->mlx, fractol->win);
	mlx_destroy_display(fractol->mlx);
	free(fractol->mlx);
	free(fractol);
	exit (0);
	return (0);
}

int	main(int argc, char **argv)
{
	if (argc > 1)
	{
		if (argc == 2 && !ft_strncmp(argv[1], "Mandelbrot", 10))
		{
			ft_printf(USER_CONTROLS);
			mandelbrot(init_fractol(0, 0));
			return (0);
		}
		else if (argc == 4 && !ft_strncmp(argv[1], "Julia", 5)
			&& ft_parse_atod_input(argv[2]) && ft_parse_atod_input(argv[3]))
		{
			ft_printf(USER_CONTROLS);
			julia(init_fractol(ft_atod(argv[2]), ft_atod(argv[3])));
			return (0);
		}
		else if (argc == 2 && !ft_strncmp(argv[1], "Burning_ship", 12))
		{
			ft_printf(USER_CONTROLS);
			burning_ship(init_fractol(0, 0));
			return (0);
		}
		else if (argc == 2 && !ft_strncmp(argv[1], "Buddhabrot", 10))
		{
			ft_printf(USER_CONTROLS);
			buddhabrot(init_fractol(0, 0));
			return (0);
		}
	}
	ft_printf("Available parameters :\n\t-> Mandelbrot\n\t-> Julia <cx> <cy>\n\t-> Burning_ship\n");
	return (0);
}
