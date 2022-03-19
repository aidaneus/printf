/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhildred <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 16:00:33 by nhildred          #+#    #+#             */
/*   Updated: 2021/01/18 16:00:33 by nhildred         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_pointer_if(t_spec spec)
{
	if (spec.precision >= spec.len)
		spec.num = write_sym(' ', spec.width - spec.precision) + spec.num;
	else
		spec.num = write_sym(' ', spec.width - spec.len) + spec.num;
	return (spec.num);
}

int	print_pointer(char *line, t_spec spec)
{
	spec.len = ft_strlen(line);
	if (!spec.precision && spec.dot && line[2] == '0')
		spec.len--;
	if (spec.precision > spec.width && spec.dot)
		spec.len -= 2;
	if (spec.width & !spec.minus && !spec.zero && !spec.dot)
		spec.num = write_sym(' ', spec.width - spec.len) + spec.num;
	else if (spec.width && (spec.dot || !spec.zero) && !spec.minus)
		spec.num = ft_print_pointer_if(spec);
	if (spec.zero && !spec.minus && !spec.dot && spec.width)
		spec.num = find_sym(&line) +
			write_sym('0', spec.width - spec.len) + spec.num;
	if (spec.dot && spec.precision > spec.len)
		spec.num = find_sym(&line) +
		write_sym('0', spec.precision - spec.len) + spec.num;
	spec.num = ft_putstr(line, spec.len) + spec.num;
	if (spec.minus)
		spec.num = ft_print_pointer_if(spec);
	return (spec.num);
}

int	print_d_i(char *line, t_spec spec)
{
	int a;

	if (line[0] == '0' && spec.dot && !spec.precision)
		line[0] = '\0';
	spec.len = ft_strlen(line);
	if (!spec.width && spec.precision && spec.precision > spec.len)
		a = spec.precision - spec.len;
	else if (spec.precision && spec.precision > spec.len && spec.width)
		a = spec.width - spec.precision;
	else
		a = spec.width - spec.len;
	if (line[0] == '-' && spec.precision >= spec.len)
		a--;
	if (spec.width && !spec.minus && (!spec.zero || spec.dot))
		spec.num = write_sym(' ', a) + spec.num;
	if (spec.zero && !spec.minus && !spec.dot)
		spec.num = find_sym(&line) + write_sym('0', a) + spec.num;
	if (spec.dot && spec.precision >= spec.len)
		spec.num = find_sym(&line) + write_sym('0',
			spec.precision - ft_strlen(line)) + spec.num;
	spec.num = ft_putstr(line, ft_strlen(line)) + spec.num;
	if (spec.minus && spec.width)
		spec.num = write_sym(' ', a) + spec.num;
	return (spec.num);
}

int	ft_string_if(t_spec spec, int len)
{
	if (spec.sign_width)
		spec.num = write_sym(' ', (spec.width * (-1)) - spec.len);
	else
		spec.num = write_sym(' ', len);
	return (spec.num);
}

int	ft_string(char *line, t_spec spec)
{
	int len;

	if (!line)
		line = "(null)";
	spec.len = ft_strlen(line);
	if (spec.precision && spec.precision > spec.len)
		spec.precision = spec.len;
	if (spec.dot && spec.precision < spec.len)
		len = spec.width - spec.precision;
	else
		len = spec.width - spec.len;
	if (!spec.minus && !spec.zero && spec.width > 0)
		spec.num = write_sym(' ', len) + spec.num;
	if (spec.zero && !spec.minus)
		spec.num = write_sym('0', len) + spec.num;
	if (spec.dot && !spec.sign_width)
		spec.num = ft_putstr(line, spec.precision) + spec.num;
	else
		spec.num = ft_putstr(line, spec.len) + spec.num;
	if (spec.minus || spec.sign_width)
		spec.num = ft_string_if(spec, len) + spec.num;
	return (spec.num);
}
