/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 13:40:33 by acronert          #+#    #+#             */
/*   Updated: 2023/12/08 17:32:05 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>
# include <stdint.h>

# define DEC_BASE	"0123456789"
# define UHEX_BASE	"0123456789ABCDEF"
# define LHEX_BASE	"0123456789abcdef"

int		ft_printf(const char *format, ...);
int		ft_check_type(char *str, va_list args);
int		read_format(char *str, va_list args);

int		ft_print_char(int n);
int		ft_print_str(char *str);
int		ft_print_ptr(uintptr_t uptr);

int		ft_print_dec(int n);
int		ft_print_int(int n);
int		ft_print_udec(unsigned int n);
int		ft_print_lowhex(unsigned int n);
int		ft_print_upphex(unsigned int n);

int		ft_put_ulongint(unsigned long int n, char *base, int len);
int		ft_put_longint(long int n, int len);
void	ft_strcpy(char *dst, char *src);
char	*ft_strdup(const char *s);
int		ft_strlen_int(char *str);

#endif
