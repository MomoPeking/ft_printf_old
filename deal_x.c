/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_x.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 11:52:47 by qdang             #+#    #+#             */
/*   Updated: 2020/01/22 11:52:51 by qdang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int      len_hexadecimal(t_info *s, unsigned int nbr)
{
    int     nbrlen;

    nbrlen = 0;
    if (nbr == 0)
        nbrlen++;
    while (nbr > 0)
    {
        nbrlen++;
        nbr /= 16;
    }
    if (s->flag[HASH] == '1')
        nbrlen += 2;
    return (nbrlen);
}

static void     minus_hexadecimal(t_info *s, unsigned int nbr, int nbrlen)
{
    if (s->flag[HASH] == '1')
    {
        if (*s->fm == 'x')
            ft_putstr("0x");
        else
            ft_putstr("0X");
    }
    ft_puthex(nbr, *s->fm);
    if (s->mfw > nbrlen)
        while (--s->mfw > nbrlen)
            ft_putchar(' ');
}

static void     nonminus_hexadecimal(t_info *s, unsigned int nbr, int nbrlen)
{
    if (s->mfw > nbrlen && s->flag[ZERO] != '1')
        while (--s->mfw > nbrlen)
            ft_putchar(' ');
    if (s->flag[HASH] == '1')
    {
        if (*s->fm == 'x')
            ft_putstr("0x");
        else
            ft_putstr("0X");
    }
    if (s->mfw > nbrlen && s->flag[ZERO] == '1')
        while (--s->mfw > nbrlen)
            ft_putchar('0');
    ft_puthex(nbr, *s->fm);
}

t_info          *deal_hexadecimal(t_info *s)
{
    unsigned int    nbr;
    int             nbrlen;

    nbr = va_arg(s->ap, unsigned int);
    nbrlen = len_hexadecimal(s, nbr);
    if (s->mfw > nbrlen)
    {
        s->len += s->mfw - nbrlen;
        s->mfw++;
    }
    if (s->flag[MINUS] == '1')
        minus_hexadecimal(s, nbr, nbrlen);
    else
        nonminus_hexadecimal(s, nbr, nbrlen);
    s->len += nbrlen;
    s->fm++;
    s->signal = 1;
    return (s);
}
