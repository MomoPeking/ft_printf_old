/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plus_fl.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 22:36:21 by qdang             #+#    #+#             */
/*   Updated: 2020/03/10 22:49:18 by qdang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int				fl_length(t_info *s, long double nbr)
{
	int		nbrlen;

	nbrlen = ft_nbrlen(nbr);
	if (s->point == 1 && s->flag[HASH] == '1')
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
	if (nbr < 0)
		nbrlen++;
	return (nbrlen);
}

void			fl_minus(t_info *s, long double nbr, int nbrlen)
{
	if (s->flag[PLUS] == '1' && nbr >= 0)
		ft_putchar('+');
	if (s->flag[SPACE] == '1' && s->flag[PLUS] != '1' && nbr >= 0)
	{
		ft_putchar(' ');
		s->mfw--;
	}
	if (nbr < 0)
		ft_putchar('-');
	ft_putf(s, nbr, nbrlen);
	if (s->mfw > nbrlen)
		while (--s->mfw > nbrlen)
			ft_putchar(' ');
}

static void		fl_width(t_info *s, long double nbr, int nbrlen)
{
	if (s->flag[SPACE] == '1' && s->flag[PLUS] != '1' && nbr >= 0)
		s->mfw--;
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

void			fl_nonminus(t_info *s, long double nbr, int nbrlen)
{
	if (s->mfw > nbrlen)
		fl_width(s, nbr, nbrlen);
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
