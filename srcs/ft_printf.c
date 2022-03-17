/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhildred <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 14:17:50 by nhildred          #+#    #+#             */
/*   Updated: 2021/01/18 14:17:50 by nhildred         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_find(va_list arg, const char **format)
{
	t_spec spec;

	spec = parse_spec(&(*format), arg);
	if (**format == 'c')
		return (print_c(va_arg(arg, int), spec));
	else if (**format == 's')
		return (ft_string(va_arg(arg, char*), spec));
	else if (**format == 'p')
		return (ft_pointer(va_arg(arg, unsigned long long int), spec));
	else if (**format == 'd' || **format == 'i')
		return (ft_itoa(va_arg(arg, int), spec));
	else if (**format == 'u')
		return (ft_hex(arg, 10, 0, spec));
	else if (**format == 'x')
		return (ft_hex(arg, 16, 0, spec));
	else if (**format == 'X')
		return (ft_hex(arg, 16, 1, spec));
	else if (**format == '%')
		return (print_c('%', spec));
	else
		return (-1);
}

int		ft_printf(const char *format, ...)
{
	va_list	arg;
	int		a;

	a = 0;
	va_start(arg, format);
	while (*format)
	{
		if (*format == '%')
		{
			a = ft_find(arg, &format) + a;
			if (a == -1)
				break ;
		}
		else
			a = ft_putchar(*format) + a;
		format++;
	}
	va_end(arg);
	return (a);
}
