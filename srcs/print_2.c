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
	if (spec.p >= spec.len)
		spec.num = write_sym(' ', spec.w - spec.p) + spec.num;
	else
		spec.num = write_sym(' ', spec.w - spec.len) + spec.num;
	return (spec.num);
}

int	print_pointer(char *line, t_spec spec)
{
	spec.len = ft_strlen(line);
	if (!spec.p && spec.dot && line[2] == '0')
		spec.len--;
	if (spec.p > spec.w && spec.dot)
		spec.len -= 2;
	if (spec.w & !spec.m && !spec.z && !spec.dot)
		spec.num = write_sym(' ', spec.w - spec.len) + spec.num;
	else if (spec.w && (spec.dot || !spec.z) && !spec.m)
		spec.num = ft_print_pointer_if(spec);
	if (spec.z && !spec.m && !spec.dot && spec.w)
		spec.num = find_sym(&line) +
			write_sym('0', spec.w - spec.len) + spec.num;
	if (spec.dot && spec.p > spec.len)
		spec.num = find_sym(&line) +
		write_sym('0', spec.p - spec.len) + spec.num;
	spec.num = ft_putstr(line, spec.len) + spec.num;
	if (spec.m)
		spec.num = ft_print_pointer_if(spec);
	return (spec.num);
}

int	print_d_i(char *line, t_spec spec)
{
	int a;

	if (line[0] == '0' && spec.dot && !spec.p)
		line[0] = '\0';
	spec.len = ft_strlen(line);
	if (!spec.w && spec.p && spec.p > spec.len)
		a = spec.p - spec.len;
	else if (spec.p && spec.p > spec.len && spec.w)
		a = spec.w - spec.p;
	else
		a = spec.w - spec.len;
	if (line[0] == '-' && spec.p >= spec.len)
		a--;
	if (spec.w && !spec.m && (!spec.z || spec.dot))
		spec.num = write_sym(' ', a) + spec.num;
	if (spec.z && !spec.m && !spec.dot)
		spec.num = find_sym(&line) + write_sym('0', a) + spec.num;
	if (spec.dot && spec.p >= spec.len)
		spec.num = find_sym(&line) + write_sym('0',
			spec.p - ft_strlen(line)) + spec.num;
	spec.num = ft_putstr(line, ft_strlen(line)) + spec.num;
	if (spec.m && spec.w)
		spec.num = write_sym(' ', a) + spec.num;
	return (spec.num);
}

int	ft_string_if(t_spec spec, int len)
{
	if (spec.sign_w)
		spec.num = write_sym(' ', (spec.w * (-1)) - spec.len);
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
	if (spec.p && spec.p > spec.len)
		spec.p = spec.len;
	if (spec.dot && spec.p < spec.len)
		len = spec.w - spec.p;
	else
		len = spec.w - spec.len;
	if (!spec.m && !spec.z && spec.w > 0)
		spec.num = write_sym(' ', len) + spec.num;
	if (spec.z && !spec.m)
		spec.num = write_sym('0', len) + spec.num;
	if (spec.dot && !spec.sign_w)
		spec.num = ft_putstr(line, spec.p) + spec.num;
	else
		spec.num = ft_putstr(line, spec.len) + spec.num;
	if (spec.m || spec.sign_w)
		spec.num = ft_string_if(spec, len) + spec.num;
	return (spec.num);
}
