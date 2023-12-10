/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_types.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acronert <acronert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 15:22:09 by acronert          #+#    #+#             */
/*   Updated: 2023/11/16 15:25:28 by acronert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_dec(int n)
{
	return (ft_put_longint(n, 0));
}

int	ft_print_int(int n)
{
	return (ft_put_longint(n, 0));
}

int	ft_print_udec(unsigned int n)
{
	return (ft_put_longint(n, 0));
}

int	ft_print_lowhex(unsigned int n)
{
	return (ft_put_ulongint(n, LHEX_BASE, 0));
}

int	ft_print_upphex(unsigned int n)
{
	return (ft_put_ulongint(n, UHEX_BASE, 0));
}
