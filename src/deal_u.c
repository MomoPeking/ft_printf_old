/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_u.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 19:42:43 by qdang             #+#    #+#             */
/*   Updated: 2020/03/10 20:30:00 by qdang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int		length(t_info *s, unsigned long long nbr)
{
	int		nbrlen;

	nbrlen = 0;
	if (nbr == 0 && s->point != 1)
		nbrlen++;
	while (nbr > 0)
	{
		nbrlen++;
		nbr /= 10;
	}
	return (nbrlen);
}

static t_info	*deal_unsigned_int_3(t_info *s, int nbrlen, int z)
{
	s->mfw++;
	if (s->flag[ZERO] == '1' && s->flag[MINUS] != '1' && z == 0)
	{
		if (s->point != 0)
			while (--s->mfw > nbrlen)
				ft_putchar(' ');
		else
			while (--s->mfw > nbrlen)
				ft_putchar('0');
	}
	else
	{
		if (s->point != 1)
			while (--s->mfw > nbrlen + z)
				ft_putchar(' ');
		else
			while (--s->mfw > 0)
				ft_putchar(' ');
	}
	return (s);
}

static t_info	*deal_unsigned_int_2
	(t_info *s, unsigned long long nbr, int nbrlen, int z)
{
	if (s->flag[MINUS] == '1' && s->point != 1)
	{
		ft_putnchar('0', z);
		ft_putui(nbr);
	}
	if (s->mfw <= s->prec)
		s->len += z;
	if (s->mfw > nbrlen && s->mfw > s->prec)
		s->len += s->mfw - nbrlen;
	if (s->mfw > nbrlen)
		s = deal_unsigned_int_3(s, nbrlen, z);
	if (s->flag[MINUS] != '1' && s->point != 1)
	{
		ft_putnchar('0', z);
		ft_putui(nbr);
	}
	return (s);
}

t_info			*deal_unsigned_int(t_info *s)
{
	unsigned long long	nbr;
	int					nbrlen;
	int					z;

	nbr = trans_ull(s, va_arg(s->ap, unsigned long long));
	nbrlen = length(s, nbr);
	z = s->prec - nbrlen;
	if (z < 0)
		z = 0;
	s = deal_unsigned_int_2(s, nbr, nbrlen, z);
	s->len += nbrlen;
	s->fm++;
	s->signal = 1;
	return (s);
}
