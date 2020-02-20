/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floatplus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 16:15:56 by qdang             #+#    #+#             */
/*   Updated: 2020/02/12 16:16:06 by qdang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int             len_float(t_info *s, long double nbr)
{
    int     nbrlen;

    nbrlen = ft_nbrlen(nbr);
    if (s->point == 1)
        if (s->flag[HASH] == '1')
            nbrlen++;
    if (s->point != 1)    
    {
        if (s->prec == 0)
            nbrlen += 7;
        else
            nbrlen += s->prec + 1;        
    }
    if (s->flag[PLUS] == '1' && nbr >= 0)
        nbrlen++;
    if (s->flag[SPACE] == '1' && s->flag[PLUS] != '1' && nbr >= 0)
        nbrlen++;
    if (nbr <= 0)
        nbrlen++;
    return (nbrlen);
}

static void     ft_putf(t_info *s, long double nbr, int nbrlen)
{
    double  decnbr;
    int     declen;

    declen = 0;
    if (s->flag[PLUS] == '1' || nbr < 0)   
        declen = -1;
	if (nbr < 0)
		nbr *= -1;
    decnbr = nbr - (int)nbr;
    declen += nbrlen - ft_nbrlen(nbr);
    if (s->flag[HASH] == '1' || s->point != 1)
        declen--;
    ft_putnbr(nbr);
    if (s->flag[HASH] == '1' || s->point != 1)
        ft_putchar('.');    
    while (declen > 0)
    {
        decnbr *= 10;
        ft_putnbr(decnbr);
        decnbr = decnbr - (int)decnbr;
        declen--;
    }    
}

void            minus_float(t_info *s, long double nbr, int nbrlen)
{
    if (s->flag[PLUS] == '1' && nbr >= 0)
        ft_putchar('+');
    if (s->flag[SPACE] == '1' && s->flag[PLUS] != '1' && nbr >= 0)
        ft_putchar(' ');
    if (nbr < 0)
        ft_putchar('-');  
    ft_putf(s, nbr, nbrlen);
    if (s->mfw > nbrlen)
        while (--s->mfw > nbrlen)
            ft_putchar(' ');
}

static void     width_float(t_info *s, long double nbr, int nbrlen)
{
    if (s->flag[ZERO] == '1')
    {
        if (s->flag[PLUS] == '1' && nbr >= 0)
            ft_putchar('+');
        if (s->flag[SPACE] == '1' && s->flag[PLUS] != '1' && nbr >= 0)
            ft_putchar(' ');
        if (nbr < 0)
            ft_putchar('-');
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
        if (nbr < 0)
            ft_putchar('-'); 
    }
    ft_putf(s, nbr, nbrlen);
}

void            nonminus_float(t_info *s, long double nbr, int nbrlen)
{
    if (s->mfw > nbrlen)
        width_float(s, nbr, nbrlen);
    else
    {
        if (s->flag[PLUS] == '1' && nbr >= 0)
            ft_putchar('+');
        if (s->flag[SPACE] == '1' && s->flag[PLUS] != '1' && nbr >= 0)
            ft_putchar(' ');
        if (nbr < 0)
            ft_putchar('-');
        ft_putf(s, nbr, nbrlen);
    }
}