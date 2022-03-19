/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhildred <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 15:57:51 by nhildred          #+#    #+#             */
/*   Updated: 2021/01/18 15:57:51 by nhildred         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *s, int len)
{
	if (len == 0)
		return (0);
	return (write(1, s, len));
}

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	find_sym(char **line)
{
	int a;

	a = 0;
	if (*line[0] == '-')
		a = ft_putchar(*line[0]);
	if ((*line)[0] == '0' && (*line)[1] == 'x')
		a = ft_putchar('0') + ft_putchar('x');
	*line = a + *line;
	return (a);
}

int	write_sym(int c, int ch)
{
	int a;

	a = 0;
	while (ch-- > 0)
		a = ft_putchar(c) + a;
	return (a);
}

int	print_c(char c, t_spec spec)
{
	if (spec.width && !spec.zero && !spec.minus)
		spec.num = write_sym(' ', spec.width - 1) + spec.num;
	else if (spec.zero && !spec.minus)
		spec.num = write_sym('0', spec.width - 1) + spec.num;
	spec.num = ft_putchar(c) + spec.num;
	if (spec.minus)
		spec.num = write_sym(' ', spec.width - 1) + spec.num;
	return (spec.num);
}
