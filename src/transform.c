/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 11:36:29 by qdang             #+#    #+#             */
/*   Updated: 2020/03/10 22:16:30 by qdang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <stdio.h>

unsigned long long	trans_ull(t_info *s, unsigned long long nbr)
{
	if (s->length[CHAR] == '1')
		nbr = (unsigned char)nbr;
	else if (s->length[SHORT] == '1')
		nbr = (unsigned short)nbr;
	else if (s->length[LONG] == '1')
		nbr = (unsigned long)nbr;
	else if (s->length[LONGLONG] == '1')
		nbr = (unsigned long long)nbr;
	else
		nbr = (unsigned int)nbr;
	return (nbr);
}

long long			trans_ll(t_info *s, long long nbr)
{
	if (s->length[CHAR] == '1')
		nbr = (char)nbr;
	else if (s->length[SHORT] == '1')
		nbr = (short)nbr;
	else if (s->length[LONG] == '1')
		nbr = (long)nbr;
	else if (s->length[LONGLONG] == '1')
		nbr = (long long)nbr;
	else
		nbr = (int)nbr;
	return (nbr);
}

long double			round_up(long double nbr, int declen)
{
	double		temp;
	double		i;
	int			power;

	temp = nbr - (int)nbr;
	if (declen == 0 && temp * 10 >= 5)
		nbr += 1;
	if (declen != 0)
	{
		power = declen;
		while (--declen >= 0)
		{
			temp *= 10;
			temp = temp - (int)temp;
		}
		i = 1;
		if (temp >= 0.5 && temp <= 0.9)
			while (--power >= 0)
				i *= 0.1;
		if (temp > 0.9 && temp < 1)
			while (--power >= -1)
				i *= 0.1;
		if (temp >= 0.5 && temp < 1)
			nbr += i;
	}
	return (nbr);
}
