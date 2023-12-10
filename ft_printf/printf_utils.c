/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 13:35:45 by acronert          #+#    #+#             */
/*   Updated: 2023/12/08 17:32:47 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_ulongint(unsigned long int n, char *base, int len)
{
	unsigned int	base_len;

	base_len = ft_strlen_int(base);
	if (n < base_len)
	{
		len += write(1, &base[n], 1);
		return (len);
	}
	else
	{
		len = ft_put_ulongint(n / base_len, base, len);
		return (ft_put_ulongint(n % base_len, base, len));
	}
}

int	ft_put_longint(long int n, int len)
{
	if (n < 0)
	{
		len += ft_print_char('-');
		n = -n;
	}
	if (n < 10)
	{
		len += ft_print_char(n + '0');
		return (len);
	}
	else
	{
		len = ft_put_longint(n / 10, len);
		return (ft_put_longint(n % 10, len));
	}
}

void	ft_strcpy(char *dst, char *src)
{
	while (*src)
	{
		*dst = *src;
		src++;
		dst++;
	}
	*dst = '\0';
}

char	*ft_strdup(const char *s)
{
	char	*dup;
	int		len;

	len = ft_strlen_int((char *)s);
	dup = malloc((len + 1) * sizeof(char));
	if (!dup)
		return (NULL);
	ft_strcpy(dup, (char *)s);
	return (dup);
}

int	ft_strlen_int(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}
