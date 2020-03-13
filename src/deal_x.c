/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_x.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 11:52:47 by qdang             #+#    #+#             */
/*   Updated: 2020/03/10 20:37:34 by qdang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int		length(t_info *s, unsigned long long int nbr)
{
	int		nbrlen;

	nbrlen = 0;
	if (nbr == 0 && s->point != 1)
		nbrlen++;
	if (s->flag[HASH] == '1' && nbr != 0)
		nbrlen += 2;
	while (nbr > 0)
	{
		nbrlen++;
		nbr /= 16;
	}
	return (nbrlen);
}

static void		minus(t_info *s, unsigned long long nbr, int nbrlen, int z)
{
	if (s->flag[HASH] == '1' && nbr != 0)
		*s->fm == 'x' ? ft_putstr("0x") : ft_putstr("0X");
	ft_putnchar('0', z);
	if (s->point != 1)
		ft_puthex(nbr, *s->fm);
	if (s->mfw > nbrlen)
		while (--s->mfw > nbrlen + z)
			ft_putchar(' ');
}

static void		nonminus(t_info *s, unsigned long long nbr, int nbrlen, int z)
{
	if (s->mfw > nbrlen && (s->flag[ZERO] != '1' || s->point != 0))
		while (--s->mfw > nbrlen + z)
			ft_putchar(' ');
	if (s->flag[HASH] == '1' && nbr != 0)
		*s->fm == 'x' ? ft_putstr("0x") : ft_putstr("0X");
	if (s->mfw > nbrlen && s->flag[ZERO] == '1' && s->point == 0)
		while (--s->mfw > nbrlen + z)
			ft_putchar('0');
	ft_putnchar('0', z);
	if (s->point != 1)
		ft_puthex(nbr, *s->fm);
}

t_info			*deal_hexadecimal(t_info *s)
{
	unsigned long long	nbr;
	int					nbrlen;
	int					z;

	nbr = trans_ull(s, va_arg(s->ap, unsigned long long));
	nbrlen = length(s, nbr);
	if (s->flag[HASH] == '1' && nbr != 0)
		z = s->prec - nbrlen + 2;
	else
		z = s->prec - nbrlen;
	if (z < 0)
		z = 0;
	if (s->mfw <= s->prec)
		s->len += z;
	if (s->mfw > nbrlen && s->mfw > s->prec)
	{
		s->len += s->mfw - nbrlen;
		s->mfw++;
	}
	s->flag[MINUS] == '1' ? minus(s, nbr, nbrlen, z) :
		nonminus(s, nbr, nbrlen, z);
	s->len += nbrlen;
	s->fm++;
	s->signal = 1;
	return (s);
}
