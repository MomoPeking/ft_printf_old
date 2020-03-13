/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_p.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 16:03:16 by qdang             #+#    #+#             */
/*   Updated: 2020/03/10 19:15:37 by qdang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void		output(t_info *s, unsigned long long ptr, int ptrlen, int z)
{
	if (s->flag[MINUS] == '1' || (s->flag[ZERO] == '1' && z == 0))
	{
		ft_putstr("0x");
		ft_putnchar('0', z);
	}
	if (s->flag[MINUS] == '1' && (ptr != 0 || s->point != 1))
		ft_puthex(ptr, 'x');
	if (s->mfw > ptrlen && s->mfw > s->prec)
	{
		s->len += s->mfw - ptrlen;
		s->mfw++;
		if (s->flag[ZERO] == '1' && s->flag[MINUS] != '1' && z != 0)
			while (--s->mfw > ptrlen)
				ft_putchar('0');
		else
			while (--s->mfw > ptrlen + z)
				ft_putchar(' ');
	}
	if (s->flag[MINUS] != '1' && (s->flag[ZERO] != '1' || z != 0))
	{
		ft_putstr("0x");
		ft_putnchar('0', z);
	}
	if (s->flag[MINUS] != '1' && (ptr != 0 || s->point != 1))
		ft_puthex(ptr, 'x');
}

t_info			*deal_pointer(t_info *s)
{
	unsigned long long	ptr;
	unsigned long long	temp;
	int					ptrlen;
	int					z;

	ptr = (unsigned long long)va_arg(s->ap, void *);
	temp = ptr;
	ptrlen = 2;
	if (temp == 0 && s->point != 1)
		ptrlen++;
	while (temp > 0)
	{
		ptrlen++;
		temp /= 16;
	}
	z = s->prec - ptrlen + 2;
	if (z < 0)
		z = 0;
	if (s->mfw <= s->prec && z != 0)
		s->len += z;
	output(s, ptr, ptrlen, z);
	s->len += ptrlen;
	s->fm++;
	s->signal = 1;
	return (s);
}
