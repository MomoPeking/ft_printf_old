/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plus_di.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 22:25:03 by qdang             #+#    #+#             */
/*   Updated: 2020/03/10 22:49:48 by qdang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int				di_length(t_info *s, long long nbr)
{
	int		nbrlen;

	nbrlen = ft_nbrlen(nbr);
	if (s->point == 1 && nbr == 0)
		nbrlen--;
	if (s->flag[PLUS] == '1' && nbr >= 0)
		nbrlen++;
	if (s->flag[SPACE] == '1' && s->flag[PLUS] != '1' && nbr >= 0)
		nbrlen++;
	if (nbr < 0)
		nbrlen++;
	return (nbrlen);
}

void			di_minus(t_info *s, long long nbr, int nbrlen, int z)
{
	if (s->flag[PLUS] == '1' && nbr >= 0)
		ft_putchar('+');
	if (s->flag[SPACE] == '1' && s->flag[PLUS] != '1' && nbr >= 0)
		ft_putchar(' ');
	if (nbr < 0)
		ft_putchar('-');
	ft_putnchar('0', z);
	if (s->point != 1 || nbr != 0)
		ft_putll(nbr);
	if (s->mfw > nbrlen)
		while (--s->mfw > nbrlen + z)
			ft_putchar(' ');
}

static void		di_width_2(t_info *s, long long nbr)
{
	if (s->flag[PLUS] == '1' && nbr >= 0)
		ft_putchar('+');
	if (s->flag[SPACE] == '1' && s->flag[PLUS] != '1' && nbr >= 0)
		ft_putchar(' ');
	if (nbr < 0)
		ft_putchar('-');
}

static void		di_width(t_info *s, long long nbr, int nbrlen, int z)
{
	if (s->flag[ZERO] == '1' && z == 0)
	{
		if (s->point != 0)
			while (--s->mfw > nbrlen)
				ft_putchar(' ');
		di_width_2(s, nbr);
		if (s->point == 0)
			while (--s->mfw > nbrlen)
				ft_putchar('0');
	}
	else
	{
		while (--s->mfw > nbrlen + z)
			ft_putchar(' ');
		di_width_2(s, nbr);
	}
	ft_putnchar('0', z);
	if (s->point != 1 || nbr != 0)
		ft_putll(nbr);
}

void			di_nonminus(t_info *s, long long nbr, int nbrlen, int z)
{
	if (s->mfw > nbrlen)
		di_width(s, nbr, nbrlen, z);
	else
	{
		if (s->flag[PLUS] == '1' && nbr >= 0)
			ft_putchar('+');
		if (s->flag[SPACE] == '1' && s->flag[PLUS] != '1' && nbr >= 0)
			ft_putchar(' ');
		if (nbr < 0)
			ft_putchar('-');
		ft_putnchar('0', z);
		if (s->point != 1 || nbr != 0)
			ft_putll(nbr);
	}
}
