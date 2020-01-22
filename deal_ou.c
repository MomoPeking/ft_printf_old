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

#include "ft_printf.h"

static int      len_octal(t_info *s, unsigned int nbr)
{
    int     nbrlen;

    nbrlen = 0;
    if (nbr == 0)
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

static void      output_octal(t_info *s, unsigned int nbr)
{
    if (s->flag[HASH] == '1')
        ft_putchar('0');
    ft_putoct(nbr);
}

t_info          *deal_octal(t_info *s)
{
    unsigned int    nbr;
    int             nbrlen;

    nbr = va_arg(s->ap, unsigned int);
    nbrlen = len_octal(s, nbr);
    if (s->flag[MINUS] == '1')
        output_octal(s, nbr);
    if (s->mfw > nbrlen)
    {
        s->len += s->mfw - nbrlen;
        s->mfw++;
        if (s->flag[ZERO] == '1' && s->flag[MINUS] != '1')
            while (--s->mfw > nbrlen)
                ft_putchar('0');
        else
            while (--s->mfw > nbrlen)
                ft_putchar(' ');                
    }
    if (s->flag[MINUS] != '1')
        output_octal(s, nbr);
    s->len += nbrlen;
    s->fm++;
    s->signal = 1;
    return (s);
}

static int  len_unsigned_int(t_info *s, unsigned int nbr)
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
    unsigned int    nbr;   
    int             nbrlen;

    nbr = va_arg(s->ap, unsigned int);
    nbrlen = len_unsigned_int(s, nbr);
    if (s->flag[MINUS] == '1')
        ft_putui(nbr);        
    if (s->mfw > nbrlen)
    {
        s->len += s->mfw - nbrlen;
        s->mfw++;
        if (s->flag[ZERO] == '1' && s->flag[MINUS] != '1')
            while (--s->mfw > nbrlen)
                ft_putchar('0');
        else
            while (--s->mfw > nbrlen)
                ft_putchar(' ');        
    }
    if (s->flag[MINUS] != '1')
        ft_putui(nbr);
    s->len += nbrlen;
    s->fm++;
    s->signal = 1;
    return (s);
}
