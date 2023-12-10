/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acronert <acronert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 14:02:42 by acronert          #+#    #+#             */
/*   Updated: 2023/11/17 15:44:23 by acronert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_check_type(char *str, va_list args)
{
	size_t	len;

	len = 1;
	if (*str == 'c')
		len = ft_print_char(va_arg(args, int));
	if (*str == 's')
		len = ft_print_str(va_arg(args, char *));
	if (*str == 'p')
		len = ft_print_ptr(va_arg(args, uintptr_t));
	if (*str == 'd')
		len = ft_print_dec(va_arg(args, int));
	if (*str == 'i')
		len = ft_print_int(va_arg(args, int));
	if (*str == 'u')
		len = ft_print_udec(va_arg(args, unsigned int));
	if (*str == 'x')
		len = ft_print_lowhex(va_arg(args, int));
	if (*str == 'X')
		len = ft_print_upphex(va_arg(args, int));
	if (*str == '%')
		write (1, &"%%", 1);
	return (len);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		return_value;
	char	*str;

	if (!format)
		return (-1);
	va_start(args, format);
	str = ft_strdup(format);
	if (!str)
		return (-1);
	return_value = read_format(str, args);
	va_end(args);
	free(str);
	return (return_value);
}

int	read_format(char *str, va_list args)
{
	int		return_value;
	int		i;

	return_value = 0;
	i = -1;
	while (str[++i])
	{
		if (str[i] != '%')
		{
			ft_print_char(str[i]);
			return_value++;
		}
		else
		{
			i++;
			return_value += ft_check_type(&str[i], args);
		}
	}
	return (return_value);
}
