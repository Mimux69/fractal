/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_types_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 15:22:09 by acronert          #+#    #+#             */
/*   Updated: 2023/12/08 17:32:16 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_char(int c)
{
	write (1, &c, 1);
	return (1);
}

int	ft_print_str(char *str)
{
	if (!str)
		return (ft_print_str("(null)"));
	return (write (1, str, ft_strlen_int(str)));
}

int	ft_print_ptr(uintptr_t uptr)
{
	if (!uptr)
		return (ft_print_str("(nil)"));
	else
		return (write (1, &"0x", 2) + ft_put_ulongint(uptr, LHEX_BASE, 0));
}
