/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 23:41:28 by qdang             #+#    #+#             */
/*   Updated: 2020/03/10 23:41:31 by qdang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_putll(long long i)
{
	if ((unsigned long long)i == -9223372036854775808U)
		ft_putstr("9223372036854775808");
	else if (i < 0)
		ft_putll(i * -1);
	else if (i >= 0 && i <= 9)
		ft_putchar('0' + i);
	else
	{
		ft_putll(i / 10);
		ft_putll(i % 10);
	}
}

void	ft_putui(unsigned long long i)
{
	if (i > 9)
	{
		ft_putui(i / 10);
		ft_putchar(i % 10 + '0');
	}
	else
		ft_putchar(i + '0');
}

void	ft_putoct(unsigned long long i)
{
	if (i > 7)
	{
		ft_putoct(i / 8);
		ft_putchar(i % 8 + '0');
	}
	else
		ft_putchar(i + '0');
}

void	ft_puthex(unsigned long long i, char c)
{
	if (i > 15)
	{
		ft_puthex(i / 16, c);
		ft_puthex(i % 16, c);
	}
	else
	{
		if (i <= 9)
			ft_putchar(i + '0');
		else
			c == 'x' ? ft_putchar(i - 10 + 'a') : ft_putchar(i - 10 + 'A');
	}
}

void	ft_putf(t_info *s, long double nbr, int nbrlen)
{
	double	decnbr;
	double	temp;
	int		declen;

	declen = 0;
	if (s->flag[PLUS] == '1' || nbr < 0)
		declen = -1;
	if (nbr < 0)
		nbr *= -1;
	declen += nbrlen - ft_nbrlen(nbr);
	if (s->flag[HASH] == '1' || s->point != 1)
		declen--;
	nbr = round_up(nbr, declen);
	decnbr = nbr - (long long)nbr;
	ft_putll(nbr);
	if (s->flag[HASH] == '1' || s->point != 1)
		ft_putchar('.');
	while (declen > 0 && s->point != 1)
	{
		temp = decnbr * 10;
		decnbr = temp - (long long)temp;
		ft_putnbr((long long)temp);
		declen--;
	}
}
