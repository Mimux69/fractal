/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atod.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acronert <acronert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 13:42:17 by acronert          #+#    #+#             */
/*   Updated: 2023/12/12 16:09:10 by acronert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

int	ft_parse_atod_input(char *str)
{
	int	i;
	int	dec_point;

	i = 0;
	dec_point = 0;
	while (str[i])
	{
		if (str[i] == '.')
		{
			if (dec_point || !str[i + 1] || !i)
				return (0);
			else
				dec_point = 1;
		}
		else if (str[i] == '+' || str[i] == '-')
		{
			if (i || !str[i + 1])
				return (0);
		}
		else if (str[i] < '0' || '9' < str[i])
			return (0);
		i++;
	}
	return (1);
}

static int	ft_count_decimals(char *str)
{
	int	i;
	int	ndec;

	i = 0;
	ndec = 0;
	if ((str[0] == '+' || str[0] == '-') && str[1])
		i++;
	while (str[i] && str[i] != '.')
		i++;
	if (str[i] == '.')
		i++;
	while (str[i + ndec])
		ndec++;
	return (ndec);
}

double	ft_atod(const char *str)
{
	int		i;
	double	val;
	int		neg;

	i = 0;
	val = 0;
	neg = 1;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			neg = -neg;
		i++;
	}
	while (('0' <= str[i] && str[i] <= '9') || str[i] == '.')
	{
		if (str[i] != '.')
			val = (10 * val) + (str[i] - '0');
		i++;
	}
	i = ft_count_decimals((char *)str);
	while (i--)
		val /= 10;
	return (neg * val);
}
