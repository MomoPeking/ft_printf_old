/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_ou.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 11:52:12 by qdang             #+#    #+#             */
/*   Updated: 2020/01/22 11:52:16 by qdang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

#include <stdio.h>

static int      len_octal(t_info *s, unsigned long long nbr)
{
    int     nbrlen;

    nbrlen = 0;
    if (nbr == 0 && (nbr != 0 || s->point != 1))
        nbrlen++;
    while (nbr > 0)
    {
        nbrlen++;
        nbr /= 8;
    }
    if (s->flag[HASH] == '1')
        nbrlen++;
    return (nbrlen);
}

static void      output_octal(t_info *s, unsigned long long nbr, int z)
{
    ft_putnchar('0', z);
    if (s->flag[HASH] == '1')
        ft_putchar('0');
    if (nbr != 0 || s->point != 1)
        ft_putoct(nbr);
}

t_info          *deal_octal(t_info *s)
{
    unsigned long long  nbr;
    int                 nbrlen;
    int                 z;

    nbr = trans_ull(s, va_arg(s->ap, unsigned long long));
    nbrlen = len_octal(s, nbr);

    z = s->prec - nbrlen;
    if (z < 0)
        z = 0;    
    if (s->flag[MINUS] == '1')
        output_octal(s, nbr, z);

    s->mfw <= s->prec ? (s->len += z) : (s->len += s->mfw - nbrlen);

    if (s->mfw > nbrlen)
    {
        s->mfw++;
        if (s->flag[ZERO] == '1' && s->flag[MINUS] != '1' && z == 0)
            while (--s->mfw > nbrlen + z)
                ft_putchar('0');
        else
            while (--s->mfw > nbrlen + z)
                ft_putchar(' ');                
    }
    if (s->flag[MINUS] != '1')
        output_octal(s, nbr, z);
    s->len += nbrlen;
    s->fm++;
    s->signal = 1;
    return (s);
}








static int  len_unsigned_int(unsigned long long nbr)
{
    int     nbrlen;

    nbrlen = 0;
    if (nbr == 0)
        nbrlen++;
    while (nbr > 0)
    {
        nbrlen++;
        nbr /= 10;
    }

    return (nbrlen);
}

t_info      *deal_unsigned_int(t_info *s)
{
    unsigned long long  nbr;   
    int                 nbrlen;
    int                 z;

    nbr = trans_ull(s, va_arg(s->ap, unsigned long long));
    nbrlen = len_unsigned_int(nbr);

    z = s->prec - nbrlen;
    if (z < 0)
        z = 0;

    if (s->flag[MINUS] == '1')
    {
        ft_putnchar('0', z);
        ft_putui(nbr); 
    }



    if (s->mfw <= s->prec)
        s->len += z;
    if (s->mfw > nbrlen && s->mfw > s->prec)
    {
        s->len += s->mfw - nbrlen;
        s->mfw++;
    }


    if (s->mfw > nbrlen)
    {
        if (s->flag[ZERO] == '1' && s->flag[MINUS] != '1' && z == 0)
            while (--s->mfw > nbrlen + z)
                ft_putchar('0');
        else
            while (--s->mfw > nbrlen + z)
                ft_putchar(' ');     
    }
    if (s->flag[MINUS] != '1')
    {
        ft_putnchar('0', z);
        ft_putui(nbr); 
    }
    s->len += nbrlen;



    s->fm++;
    s->signal = 1;
    return (s);
}