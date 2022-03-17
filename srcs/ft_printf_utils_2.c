/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhildred <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 15:46:27 by nhildred          #+#    #+#             */
/*   Updated: 2021/01/18 15:46:27 by nhildred         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

void	ft_space(const char **format)
{
	if (**format == ' ')
		ft_putchar(**format);
	while (**format == ' ')
		(*format)++;
}

int		ft_strlen(char *str)
{
	int a;

	a = 0;
	while (str[a])
		a += 1;
	return (a);
}

int		ft_atoi(const char *str)
{
	int	a;
	int	b;
	int	c;

	a = 0;
	b = 0;
	c = 1;
	if (str[a] == '\0')
		return (0);
	while (str[a] == '\n' || str[a] == '\r' || str[a] == '\t'
			|| str[a] == '\v' || str[a] == ' ' || str[a] == '\f')
		a += 1;
	if (str[a] == '-' || str[a] == '+')
	{
		if (str[a] == '-')
			c = -1;
		a++;
	}
	while (str[a] >= '0' && str[a] <= '9')
		b = (b * 10) + (str[a++] - '0');
	return (b * c);
}
