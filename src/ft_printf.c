/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 08:41:29 by qdang             #+#    #+#             */
/*   Updated: 2020/02/19 08:41:31 by qdang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_printf(const char *restrict format, ...)
{
    t_info      *s;

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
        {
            s->fm++;
            s = deal_flags(s);
            s = deal_min_field_width(s);
            s = deal_precision(s);
            s = deal_length(s);
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
        }
    }
    va_end(s->ap);
    return (s->len);
}
