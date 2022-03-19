/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhildred <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 15:51:40 by nhildred          #+#    #+#             */
/*   Updated: 2021/01/18 15:51:40 by nhildred         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_spec		parse_spec(const char **format, va_list arg)
{
	t_spec spec;

	spec = ft_spec();
	(*format)++;
	ft_space(&(*format));
	while (**format && **format != 'c' && **format != 's' && **format != 'd' &&
			**format != 'i' && **format != 'x' && **format != 'X' &&
			**format != 'u' && **format != 'p' && **format != '%')
	{
		if (**format == '-')
			spec.minus = 1;
		else if (**format == '0' && !spec.minus)
			spec.zero = 1;
		else if (**format == '.' && !spec.dot)
			spec.precision = ft_precision(&(*format), arg, &spec);
		else if (ft_isdigit(**format) || **format == '*')
			spec.width = ft_width(&(*format), arg, &spec);
		(*format)++;
	}
	return (spec);
}

t_spec		ft_spec(void)
{
	t_spec spec;

	spec.minus = 0;
	spec.dot = 0;
	spec.zero = 0;
	spec.width = 0;
	spec.precision = 0;
	spec.len = 0;
	spec.num = 0;
	spec.sign_width = 0;
	spec.itoa = 0;
	return (spec);
}

int			ft_precision(const char **format, va_list arg, t_spec *spec)
{
	int a;

	a = 0;
	spec->dot = 1;
	if (*(*format + 1) == '*')
	{
		(*format)++;
		a = va_arg(arg, int);
		if (a < 0)
			spec->dot = 0;
	}
	else if (ft_isdigit(*(*format + 1)))
	{
		(*format)++;
		a = ft_atoi(*format);
		while (ft_isdigit(*(*format + 1)))
			(*format)++;
	}
	return (a);
}

int			ft_width(const char **format, va_list arg, t_spec *spec)
{
	int a;

	a = 0;
	if (**format == '*')
	{
		a = va_arg(arg, int);
		if (a < 0)
		{
			spec->minus = 1;
			a *= -1;
		}
	}
	else if (ft_isdigit(**format))
	{
		a = ft_atoi(*format);
		while (ft_isdigit(*(*format + 1)))
			(*format)++;
	}
	return (a);
}
