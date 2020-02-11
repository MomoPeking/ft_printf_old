/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 20:38:23 by qdang             #+#    #+#             */
/*   Updated: 2020/01/22 11:53:09 by qdang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putll(long long i)
{
	if (i == -9223372036854775807)
		ft_putstr("9223372036854775807");
	else if (i < 0)
		ft_putll(i * -1);
	else if (i >= 0 && i <= 9)
		ft_putchar('0' + i);
	else
	{
        ft_putll(i / 10);
        ft_putll(i % 10);
	}
}

void    ft_putui(unsigned long long i)
{
    if (i > 9)
    {
        ft_putui(i / 10);
        ft_putchar(i % 10 + '0');
    }
    else
        ft_putchar(i + '0');
}

void    ft_putoct(unsigned long long i)
{
    if (i > 7)
    {
        ft_putoct(i / 8);
        ft_putchar(i % 8 + '0');
    }
    else
        ft_putchar(i + '0');
}

void    ft_puthex(unsigned long long i, char c)
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
