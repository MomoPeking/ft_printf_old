/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_dio.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 22:19:09 by qdang             #+#    #+#             */
/*   Updated: 2020/03/10 22:19:12 by qdang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

t_info			*deal_decimal_integer(t_info *s)
{
	long long	nbr;
	int			nbrlen;
	int			z;

	nbr = trans_ll(s, va_arg(s->ap, long long));
	nbrlen = di_length(s, nbr);
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
	s->flag[MINUS] == '1' ? di_minus(s, nbr, nbrlen, z) :
		di_nonminus(s, nbr, nbrlen, z);
	s->len += nbrlen;
	s->fm++;
	s->signal = 1;
	return (s);
}

static int		length(t_info *s, unsigned long long nbr)
{
	int		nbrlen;

	nbrlen = 0;
	if (nbr == 0 && s->point != 1)
		nbrlen++;
	if (s->flag[HASH] == '1' && (nbr != 0 || s->point == 1))
		nbrlen++;
	while (nbr > 0)
	{
		nbrlen++;
		nbr /= 8;
	}
	return (nbrlen);
}

static void		output(t_info *s, unsigned long long nbr, int z)
{
	ft_putnchar('0', z);
	if (s->flag[HASH] == '1')
		ft_putchar('0');
	if (nbr != 0 || (s->point != 1 && s->flag[HASH] != '1'))
		ft_putoct(nbr);
}

static t_info	*deal_octal_2
	(t_info *s, unsigned long long nbr, int nbrlen, int z)
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
		else if (s->flag[HASH] != '1' || nbr != 0)
			while (--s->mfw > 0)
				ft_putchar(' ');
		else
			while (--s->mfw > 1)
				ft_putchar(' ');
	}
	return (s);
}

t_info			*deal_octal(t_info *s)
{
	unsigned long long	nbr;
	int					nbrlen;
	int					z;

	nbr = trans_ull(s, va_arg(s->ap, unsigned long long));
	nbrlen = length(s, nbr);
	z = s->prec - nbrlen;
	if (z < 0)
		z = 0;
	if (s->flag[MINUS] == '1')
		output(s, nbr, z);
	if (s->mfw <= s->prec)
		s->len += z;
	if (s->mfw > nbrlen && s->mfw > s->prec)
		s->len += s->mfw - nbrlen;
	if (s->mfw > nbrlen)
		s = deal_octal_2(s, nbr, nbrlen, z);
	if (s->flag[MINUS] != '1')
		output(s, nbr, z);
	s->len += nbrlen;
	s->fm++;
	s->signal = 1;
	return (s);
}
