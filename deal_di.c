/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_di.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 11:51:17 by qdang             #+#    #+#             */
/*   Updated: 2020/01/22 11:51:23 by qdang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int      len_decimal_integer(t_info *s, int nbr)
{
    int     nbrlen;

    nbrlen = 0;
    if (s->flag[PLUS] == '1' && nbr >= 0)
        nbrlen++;
    if (s->flag[SPACE] == '1' && s->flag[PLUS] != '1' && nbr >= 0)
        nbrlen++;
    if (nbr <= 0)
        nbrlen++;
    if (nbr < 0)
        nbr *= -1;
    while (nbr > 0)
    {
        nbrlen++;
        nbr /= 10;
    }
    return (nbrlen);
}

static void     minus_decimal_integer(t_info *s, int nbr, int nbrlen)
{
    if (s->flag[PLUS] == '1' && nbr >= 0)
        ft_putchar('+');
    if (s->flag[SPACE] == '1' && s->flag[PLUS] != '1' && nbr >= 0)
        ft_putchar(' ');
    ft_putnbr(nbr);
    if (s->mfw > nbrlen)
        while (--s->mfw > nbrlen)
            ft_putchar(' ');
}

static void     width_decimal_integer(t_info *s, int nbr, int nbrlen)
{
    if (s->flag[ZERO] == '1')
    {
        if (s->flag[PLUS] == '1' && nbr >= 0)
            ft_putchar('+');
        if (s->flag[SPACE] == '1' && s->flag[PLUS] != '1' && nbr >= 0)
            ft_putchar(' ');
        if (nbr < 0)
        {
            ft_putchar('-');
            nbr *= -1;        
        }
        while (--s->mfw > nbrlen)
            ft_putchar('0');
    }
    else
    {
        while (--s->mfw > nbrlen)
            ft_putchar(' ');
        if (s->flag[PLUS] == '1' && nbr >= 0)
            ft_putchar('+');
        if (s->flag[SPACE] == '1' && s->flag[PLUS] != '1' && nbr >= 0)
            ft_putchar(' ');  
    }
    ft_putnbr(nbr);
}

static void     nonminus_decimal_integer(t_info *s, int nbr, int nbrlen)
{
    if (s->mfw > nbrlen)
        width_decimal_integer(s, nbr, nbrlen);
    else
    {
        if (s->flag[PLUS] == '1' && nbr >= 0)
            ft_putchar('+');
        if (s->flag[SPACE] == '1' && s->flag[PLUS] != '1' && nbr >= 0)
            ft_putchar(' ');
        ft_putnbr(nbr);
    }
}

t_info          *deal_decimal_integer(t_info *s)
{
    int     nbr;
    int     nbrlen;

    nbr = va_arg(s->ap, int);
    nbrlen = len_decimal_integer(s, nbr);
    if (s->mfw > nbrlen)
    {
        s->len += s->mfw - nbrlen;
        s->mfw++;
    }
    if (s->flag[MINUS] == '1')
        minus_decimal_integer(s, nbr, nbrlen);
    else
        nonminus_decimal_integer(s, nbr, nbrlen);
    s->len += nbrlen;
    s->fm++;
    s->signal = 1;
    return (s);
}
