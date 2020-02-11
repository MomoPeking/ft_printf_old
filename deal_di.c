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
#include <stdio.h>

static int      len_decimal_integer(t_info *s, long long nbr)
{
    int     nbrlen;

    nbrlen = ft_nbrlen(nbr);
    if (s->flag[PLUS] == '1' && nbr >= 0)
        nbrlen++;
    if (s->flag[SPACE] == '1' && s->flag[PLUS] != '1' && nbr >= 0)
        nbrlen++;
    if (nbr <= 0)
        nbrlen++;
    return (nbrlen);
}

static void     minus_decimal_integer(t_info *s, long long nbr, int nbrlen, int z)
{
    if (s->flag[PLUS] == '1' && nbr >= 0)
        ft_putchar('+');
    if (s->flag[SPACE] == '1' && s->flag[PLUS] != '1' && nbr >= 0)
        ft_putchar(' ');
    if (nbr < 0)
        ft_putchar('-');
    ft_putnchar('0', z);   
    ft_putll(nbr);
    if (s->mfw > nbrlen)
        while (--s->mfw > nbrlen)
            ft_putchar(' ');
}

static void     width_decimal_integer(t_info *s, long long nbr, int nbrlen, int z)
{
    if (s->flag[ZERO] == '1' && z == 0)
    {
        if (s->flag[PLUS] == '1' && nbr >= 0)
            ft_putchar('+');
        if (s->flag[SPACE] == '1' && s->flag[PLUS] != '1' && nbr >= 0)
            ft_putchar(' ');
        if (nbr < 0)
            ft_putchar('-');
        while (--s->mfw > nbrlen + z)
            ft_putchar('0');
    }
    else
    {
        while (--s->mfw > nbrlen + z)
            ft_putchar(' ');
        if (s->flag[PLUS] == '1' && nbr >= 0)
            ft_putchar('+');
        if (s->flag[SPACE] == '1' && s->flag[PLUS] != '1' && nbr >= 0)
            ft_putchar(' ');
        if (nbr < 0)
            ft_putchar('-'); 
    }
    ft_putnchar('0', z);
    ft_putll(nbr);
}

static void     nonminus_decimal_integer(t_info *s, long long nbr, int nbrlen, int z)
{
    if (s->mfw > nbrlen)
        width_decimal_integer(s, nbr, nbrlen, z);
    else
    {
        if (s->flag[PLUS] == '1' && nbr >= 0)
            ft_putchar('+');
        if (s->flag[SPACE] == '1' && s->flag[PLUS] != '1' && nbr >= 0)
            ft_putchar(' ');
        if (nbr < 0)
            ft_putchar('-');
        ft_putnchar('0', z);
        ft_putll(nbr);
    }
}

t_info          *deal_decimal_integer(t_info *s)
{
    long long   nbr;
    int         nbrlen;
    int         z;

    nbr = trans_ll(s, va_arg(s->ap, long long));
    nbrlen = len_decimal_integer(s, nbr);

    z = s->prec - ft_nbrlen(nbr);
    if (z < 0)
        z = 0;

    if (s->mfw <= s->prec)
        s->len += z;
    if (s->mfw > nbrlen && s->mfw > s->prec)
    {
        s->len += s->mfw - nbrlen;
        s->mfw++;
    }
    
    if (s->flag[MINUS] == '1')
        minus_decimal_integer(s, nbr, nbrlen, z);
    else
        nonminus_decimal_integer(s, nbr, nbrlen, z);
    s->len += nbrlen;
    s->fm++;
    s->signal = 1;
    return (s);
}
