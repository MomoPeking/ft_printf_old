/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 19:38:53 by qdang             #+#    #+#             */
/*   Updated: 2020/01/17 19:38:54 by qdang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

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
        }
    }
    va_end(s->ap);
    return (s->len);
}

int		main()
{
    int     a;
    int     b;
    char    *temp = "abs";
    int     c = 1;

    a = ft_printf("%0 20do, %#-20x\n", 12346, 31241);
    printf("Return Value of ft_printf: %d\n", a);
    b = printf("%0 20do, %#-20x\n", 12346, 31241);
    printf("Return Value of printf: %d\n", b);
    return (0);
}