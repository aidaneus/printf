/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhildred <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 14:34:10 by nhildred          #+#    #+#             */
/*   Updated: 2021/01/18 15:42:34 by nhildred         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_toupper(int c)
{
	if (c >= 97 && c <= 122)
		return (c - 32);
	else
		return (c);
}

int		check(unsigned int n)
{
	unsigned int	a;

	a = 1;
	while (n >= 10)
	{
		n /= 10;
		a++;
	}
	return (a);
}

int		ft_itoa(int n, t_spec spec)
{
	char			*a;
	unsigned int	b;
	unsigned int	c;

	c = (n < 0 ? -n : n);
	b = check(c);
	if (!(a = (char *)malloc(sizeof(char) * b + 1 + (n < 0 ? 1 : 0))))
		return (0);
	if (n < 0)
	{
		a[spec.itoa] = '-';
		b++;
	}
	spec.itoa = b - 1;
	while (c >= 10)
	{
		a[spec.itoa] = c % 10 + 48;
		c /= 10;
		spec.itoa--;
	}
	a[spec.itoa] = c % 10 + 48;
	a[b] = '\0';
	b = print_d_i(a, spec);
	free(a);
	return (b);
}

int		ft_num(unsigned long int c, int num)
{
	int		a;

	a = 0;
	if (c == 0)
		return (1);
	while (c != 0)
	{
		c = c / num;
		a++;
	}
	return (a);
}
