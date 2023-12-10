/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 12:10:55 by alex              #+#    #+#             */
/*   Updated: 2023/12/08 17:45:05 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"
# include "libft.h"

int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		if (!ft_strncmp(argv[1], "Mandelbrot", ft_strlen("Mandelbrot")))
		{
			mandelbrot();
			return (0);
		}
		else if (!ft_strncmp(argv[1], "Julia", ft_strlen("Julia")))
		{
			//julia();
			return (0);
		}
	}
	printf("Available parameters :\n\t-> Mandelbrot\n\t-> Julia\n");
	return (0);
}