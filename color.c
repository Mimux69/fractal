/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 16:45:41 by acronert          #+#    #+#             */
/*   Updated: 2023/12/13 16:49:48 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void ft_color(int iter, int max_iter, int color_cycle, char *buf)
{
	int color_index;
	double hue;

	if (iter != max_iter)
	{
		color_index = iter % color_cycle;
		hue = (double)color_index / color_cycle;
		buf[1] = (char)(9 * (1 - hue) * pow(hue, 3) * 255);
		buf[2] = (char)(15 * pow((1 - hue), 2) * pow(hue, 2) * 255);
		buf[0] = (char)(8.5 * pow((1 - hue), 3) * hue * 255);
	}
	else
	{
		buf[0] = 0;
		buf[1] = 0;
		buf[2] = 0;
	}
}
