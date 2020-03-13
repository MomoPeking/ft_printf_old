/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_fl.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 16:05:58 by qdang             #+#    #+#             */
/*   Updated: 2020/03/10 21:49:28 by qdang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <stdio.h>

t_info		*deal_float(t_info *s)
{
	double	nbr;
	int		nbrlen;

	nbr = va_arg(s->ap, double);
	nbrlen = fl_length(s, nbr);
	if (s->mfw > nbrlen)
	{
		s->len += s->mfw - nbrlen;
		s->mfw++;
	}
	s->flag[MINUS] == '1' ? fl_minus(s, nbr, nbrlen) :
		fl_nonminus(s, nbr, nbrlen);
	s->len += nbrlen;
	s->fm++;
	s->signal = 1;
	return (s);
}

t_info		*deal_longdouble(t_info *s)
{
	long double	nbr;
	int			nbrlen;

	nbr = va_arg(s->ap, long double);
	nbrlen = fl_length(s, nbr);
	if (s->mfw > nbrlen)
	{
		s->len += s->mfw - nbrlen;
		s->mfw++;
	}
	s->flag[MINUS] == '1' ? fl_minus(s, nbr, nbrlen) :
		fl_nonminus(s, nbr, nbrlen);
	s->len += nbrlen;
	s->fm++;
	s->signal = 1;
	return (s);
}
