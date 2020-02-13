/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_fl.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 16:05:58 by qdang             #+#    #+#             */
/*   Updated: 2020/02/12 16:06:06 by qdang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_info          	*deal_float(t_info *s)
{
    double  nbr;
    int     nbrlen;

    nbr = va_arg(s->ap, double);
    nbrlen = len_float(s, nbr);
    if (s->mfw > nbrlen)
    {
        s->len += s->mfw - nbrlen;
        s->mfw++;
    }
    s->flag[MINUS] == '1' ? minus_float(s, nbr, nbrlen) :
        nonminus_float(s, nbr, nbrlen);
    s->len += nbrlen;
    s->fm++;
    s->signal = 1;
    return (s);  
}

t_info          	*deal_longdouble(t_info *s)
{
    long double  nbr;
    int         nbrlen;

    nbr = va_arg(s->ap, long double);
    nbrlen = len_float(s, nbr);
    if (s->mfw > nbrlen)
    {
        s->len += s->mfw - nbrlen;
        s->mfw++;
    }
    s->flag[MINUS] == '1' ? minus_float(s, nbr, nbrlen) :
        nonminus_float(s, nbr, nbrlen);
    s->len += nbrlen;
    s->fm++;
    s->signal = 1;
    return (s);  
}