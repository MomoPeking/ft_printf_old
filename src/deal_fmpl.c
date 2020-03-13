/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_fmpl.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 11:51:56 by qdang             #+#    #+#             */
/*   Updated: 2020/03/10 16:00:17 by qdang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

t_info	*deal_flags(t_info *s)
{
	ft_bzero(s->flag, 5);
	while (*s->fm == '#' || *s->fm == '0'
			|| *s->fm == '+' || *s->fm == '-' || *s->fm == ' ')
	{
		if (*s->fm == '#')
			s->flag[HASH] = '1';
		if (*s->fm == '0')
			s->flag[ZERO] = '1';
		if (*s->fm == '+')
			s->flag[PLUS] = '1';
		if (*s->fm == '-')
			s->flag[MINUS] = '1';
		if (*s->fm == ' ')
			s->flag[SPACE] = '1';
		s->fm++;
	}
	return (s);
}

t_info	*deal_min_field_width(t_info *s)
{
	s->mfw = 0;
	if (*s->fm == '*')
	{
		s->mfw = va_arg(s->ap, int);
		if (s->mfw < 0)
		{
			s->mfw *= -1;
			s->flag[MINUS] = '1';
		}
		s->fm++;
	}
	if (*s->fm >= '0' && *s->fm <= '9')
		s->mfw = ft_strnbr((char *)s->fm);
	while (*s->fm >= '0' && *s->fm <= '9')
		s->fm++;
	return (s);
}

t_info	*deal_precision(t_info *s)
{
	s->prec = 0;
	s->point = 0;
	if (*s->fm == '.')
	{
		s->point = 1;
		s->fm++;
		if (*s->fm == '*')
		{
			s->prec = va_arg(s->ap, int);
			if (s->prec < 0)
			{
				s->prec = 0;
				s->point = 0;
			}
			s->fm++;
		}
		if (*s->fm >= '0' && *s->fm <= '9' && s->prec == 0)
			s->prec = ft_strnbr((char *)s->fm);
		while (*s->fm >= '0' && *s->fm <= '9')
			s->fm++;
		if (s->prec > 0)
			s->point = 2;
	}
	return (s);
}

t_info	*deal_length(t_info *s)
{
	ft_bzero(s->length, 5);
	if (*s->fm == 'h' && *(s->fm + 1) == 'h')
		s->length[CHAR] = '1';
	if (*s->fm == 'h' && *(s->fm + 1) != 'h')
		s->length[SHORT] = '1';
	if (*s->fm == 'l' && *(s->fm + 1) != 'l')
		s->length[LONG] = '1';
	if (*s->fm == 'l' && *(s->fm + 1) == 'l')
		s->length[LONGLONG] = '1';
	if (*s->fm == 'L')
		s->length[LONGDOUBLE] = '1';
	while (*s->fm == 'h' || *s->fm == 'l' || *s->fm == 'L')
		s->fm++;
	return (s);
}
