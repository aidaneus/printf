/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhildred <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 16:03:59 by nhildred          #+#    #+#             */
/*   Updated: 2021/01/18 16:03:59 by nhildred         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

typedef	struct
{
	int m;
	int dot;
	int z;
	int w;
	int p;
	int len;
	int num;
	int sign_w;
	int itoa;
}		t_spec;
int		ft_printf(const char *format, ...);
int		ft_find(va_list arg, const char **format);
t_spec	parse_spec(const char **format, va_list arg);
t_spec	ft_spec(void);
int		ft_precision(const char **format, va_list arg, t_spec *spec);
int		ft_width(const char **format, va_list arg, t_spec *spec);
int		ft_hex(va_list arg, int num, int flag, t_spec spec);
int		ft_hex_if(t_spec spec);
char	*ft_trans(unsigned int arg, int num, int flag);
int		ft_pointer(unsigned long int num, t_spec spec);
int		ft_toupper(int c);
int		ft_itoa(int n, t_spec spec);
int		ft_num(unsigned long int c, int num);
int		ft_isdigit(int c);
void	ft_space(const char **format);
int		ft_strlen(char *str);
int		ft_atoi(const char *str);
int		ft_putstr(char *s, int len);
int		ft_putchar(char c);
int		find_sym(char **line);
int		write_sym(int c, int ch);
int		print_c(char c, t_spec spec);
int		ft_print_pointer_if(t_spec spec);
int		print_pointer(char *line, t_spec spec);
int		print_d_i(char *line, t_spec spec);
int		ft_string_if(t_spec spec, int len);
int		ft_string(char *line, t_spec spec);

#endif
