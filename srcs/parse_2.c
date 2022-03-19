/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhildred <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 15:55:23 by nhildred          #+#    #+#             */
/*   Updated: 2021/01/18 15:55:23 by nhildred         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_hex_if(t_spec spec)
{
	if (spec.precision >= spec.len)
		spec.num = write_sym(' ', spec.width - spec.precision) + spec.num;
	else
		spec.num = write_sym(' ', spec.width - spec.len) + spec.num;
	return (spec.num);
}

int		ft_hex(va_list arg, int num, int flag, t_spec spec)
{
	char *line;

	line = ft_trans(va_arg(arg, unsigned int), num, flag);
	spec.len = ft_strlen(line);
	if (spec.precision == 0 && spec.dot && line[0] == '0')
		spec.len--;
	if (spec.width && !spec.minus && !spec.zero && !spec.dot)
		spec.num = write_sym(' ', spec.width - spec.len);
	else if (spec.width && (spec.dot || !spec.zero) && !spec.minus)
		spec.num = ft_hex_if(spec);
	if (spec.zero && !spec.minus && !spec.dot && spec.width)
		spec.num = write_sym('0', spec.width - spec.len);
	if (spec.dot)
		spec.num = write_sym('0', spec.precision - spec.len) + spec.num;
	spec.num = ft_putstr(line, spec.len) + spec.num;
	if (spec.minus)
		spec.num = ft_hex_if(spec);
	free(line);
	return (spec.num);
}

char	*ft_trans(unsigned int arg, int num, int flag)
{
	int		a;
	char	*line;

	a = ft_num(arg, num);
	if (!(line = (char *)malloc((a + 1) * sizeof(char))))
		return (NULL);
	line[a--] = '\0';
	if (arg == 0)
		line[a] = '0';
	while (arg != 0)
	{
		line[a--] = "0123456789abcdef"[arg % num];
		arg = arg / num;
	}
	if (flag)
		while (line[++a] != '\0')
			line[a] = ft_toupper(line[a]);
	return (line);
}

int		ft_pointer(unsigned long int num, t_spec spec)
{
	int		a;
	char	*line;

	a = 2 + ft_num(num, 16);
	if (!(line = (char*)malloc((a + 1) * sizeof(char))))
		return (0);
	line[a--] = '\0';
	if (num == 0)
		line[a--] = '0';
	while (num != 0)
	{
		line[a] = "0123456789abcdef"[num % 16];
		num = num / 16;
		a--;
	}
	line[a--] = 'x';
	line[a] = '0';
	a = print_pointer(line, spec);
	free(line);
	return (a);
}
