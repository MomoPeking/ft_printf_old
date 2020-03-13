/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 08:41:29 by qdang             #+#    #+#             */
/*   Updated: 2020/03/10 15:53:50 by qdang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

t_info	*deal_conversion_specifier(t_info *s)
{
	if (*s->fm == '%' && s->signal == 0)
		s = deal_percentage(s);
	if (*s->fm == 'c' && s->signal == 0)
		s = deal_char(s);
	if (*s->fm == 's' && s->signal == 0)
		s = deal_string(s);
	if (*s->fm == 'p' && s->signal == 0)
		s = deal_pointer(s);
	if ((*s->fm == 'i' || *s->fm == 'd') && s->signal == 0)
		s = deal_decimal_integer(s);
	if (*s->fm == 'o' && s->signal == 0)
		s = deal_octal(s);
	if (*s->fm == 'u' && s->signal == 0)
		s = deal_unsigned_int(s);
	if ((*s->fm == 'x' || *s->fm == 'X') && s->signal == 0)
		s = deal_hexadecimal(s);
	if (*s->fm == 'f' && s->length[LONGDOUBLE] != '1' && s->signal == 0)
		s = deal_float(s);
	if (*s->fm == 'f' && s->length[LONGDOUBLE] == '1' && s->signal == 0)
		s = deal_longdouble(s);
	return (s);
}

t_info	*deal_all(t_info *s)
{
	s->fm++;
	s = deal_flags(s);
	s = deal_min_field_width(s);
	s = deal_precision(s);
	s = deal_length(s);
	s = deal_conversion_specifier(s);
	return (s);
}

int		ft_printf(const char *restrict format, ...)
{
	t_info	*s;
	int		len;

	s = (t_info *)malloc(sizeof(t_info));
	s->len = 0;
	va_start(s->ap, format);
	s->fm = format;
	while (*s->fm)
	{
		s->signal = 0;
		while (*s->fm && *s->fm != '%')
		{
			ft_putchar(*s->fm);
			s->len++;
			s->fm++;
		}
		if (*s->fm && *s->fm == '%')
			s = deal_all(s);
	}
	va_end(s->ap);
	len = s->len;
	free(s);
	return (len);
}
