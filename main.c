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

void    ft_putui(unsigned int i)
{
    if (i > 9)
    {
        ft_putui(i / 10);
        ft_putchar(i % 10 + '0');
    }
    else
        ft_putchar(i + '0');
}

void    ft_putoct(unsigned int i)
{
    if (i > 7)
    {
        ft_putoct(i / 8);
        ft_putchar(i % 8 + '0');
    }
    else
        ft_putchar(i + '0');
}

void    ft_puthex(unsigned int i, char c)
{
    if (i > 15)
    {
        ft_puthex(i / 16, c);
        ft_puthex(i % 16, c);
    }  
    else
    {
        if (i <= 9)
            ft_putchar(i + '0');
        else
        {
            if (c == 'x')
                ft_putchar(i - 10 + 'a');
            else
                ft_putchar(i - 10 + 'A');  
        }
    }
}

int		ft_printf(const char *restrict format, ...)
{
	va_list         ap;
    int             len;
    char            *t_string;
    int             t_int;
    unsigned int    t_unsigned_int;

    len = 0;
    va_start(ap, format);
    while (*format)
    {
        while (*format && *format != '%')
	    {
		    ft_putchar(*format);
            len++;
            format++;
	    }
        if (*format && *format == '%')
        {
            format++;
            if (*format == '%')
            {
                ft_putchar('%');
                len++;
                format++;
            }
            if (*format == 'c')
            {
                ft_putchar(va_arg(ap, int));
                len++;
                format++;
            }
            if (*format == 's')
            {
                t_string = va_arg(ap, char *);
                ft_putstr(t_string);               
                len += ft_strlen(t_string);
                format++;
            }
            if (*format == 'd' || *format == 'i')
            {
                t_int = va_arg(ap, int);
                ft_putnbr(t_int);             
                if (t_int == 0)
                    len++;
                while (t_int > 0)
                {
                    len++;
                    t_int /= 10;
                }
                format++;
            }
            if (*format == 'o')
            {
                t_unsigned_int = va_arg(ap, unsigned int);
                ft_putoct(t_unsigned_int);
                if (t_unsigned_int == 0)
                    len++;
                while (t_unsigned_int > 0)
                {
                    len++;
                    t_unsigned_int /= 8;
                }
                format++;
            }
            if (*format == 'u')
            {
                t_unsigned_int = va_arg(ap, unsigned int);
                ft_putui(t_unsigned_int);
                if (t_unsigned_int == 0)
                    len++;
                while (t_unsigned_int > 0)
                {
                    len++;
                    t_unsigned_int /= 10;
                }
                format++;
            }
            if (*format == 'x' || *format == 'X')
            {
                t_unsigned_int = va_arg(ap, unsigned int);
                ft_puthex(t_unsigned_int, *format);
                if (t_unsigned_int == 0)
                    len++;
                while (t_unsigned_int > 0)
                {
                    len++;
                    t_unsigned_int /= 16;
                }
                format++;
            }

/*          deal with 'p' after numbers
            if (*format == 'p')
            {
                temp = va_arg(ap, void *);
                ft_putchar(temp);
                format++;
                len += ft_strlen(temp);
            }
*/
        }
    }
    va_end(ap);
    return (len);
}

int		main()
{
    int     a;
    int     b;

    a = ft_printf("%o, %X\n", 0, 0);
    printf("Return Value of ft_printf: %d\n", a);
    b = printf("%o, %X\n", 0, 0);
    printf("Return Value of printf: %d\n", b);
    return (0);
}